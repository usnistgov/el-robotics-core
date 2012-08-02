#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/PointCloud2.h"
#include <iostream>
#include <string>
#include "CImg.h"

//CALIBRATION IS REQUIRED DEPENDING ON THE
//OBSTACLES THAT YOU NEED TO DETECT AS WELL
//AS THE ENVIRONMENT

//X and Z resolution of the image
#define x_res 400 //40
#define z_res 400 //40

//Separation between bins (points of resolution)
#define x_sep 0.01//0.1
#define z_sep 0.01//0.1

//Decrease Rmin to detect higher objects (must be greater than -10)
//Increase Rmax to detect lower objects (must be less than 10)
#define Rmin 1.3 //1.3
#define Rmax 3 //2.3

//Radius around static obstacles (pixels)
#define protectRad 10

//How many registered points per bin to consider that bin as "not noise"
#define set_filt_PC 10//120

//Minimum elevation that the object must be to consider it as an obstacle
//NOTE: A lower value is a greater height
#define minElevation 0.3

//FOR DETECTING OBSTALCES ABOVE STATIC OBSTACLES
//How many points counted above a static obstacle for a height detection to be valid
#define HO_PC 3 //40

//FOR DETECTING OBSTALCES ABOVE STATIC OBSTACLES
//h_tol is the maximum of the dynamic tolerance that increases with distance (z)
//h_tol_min is the minimum tolerance (at z=0)
//maximum tolerance is h_tol_min + h_tol (at z = z_res)
#define h_tol 0.01 //0.01
#define h_tol_min 0.00

//How many initial samples to take to generate mask
#define init_samp_cnt_max 3

//How many times each point appears in the initial sampling to consider it to be valid 
#define min_samp_req 3

//Define the delay between consecutive warning messages (seconds)
#define warn_delay 1

//Enable test_mode to see a detailed display of WARNINGS
//Enable test_point to see a detailed display of selected point
#define test_mode false
#define test_point false
#define test_x 154
#define test_z 158

const unsigned char red[] = {255,0,0};
const unsigned char redfake[] = {254,0,0};
const unsigned char yellow[] = {255,255,0};
const unsigned char yellowfake[] = {254,254,0};
const unsigned char blue[] = {0,0,255};
const unsigned char green[] = {0,255,0};

float h_tolerance = 0;
float maxh_mask[x_res+1][z_res+1];
double end_time = 0;
double warn_end_time = 0;
bool first_run = true;
bool draw_first = true;
bool run = true;
bool poly_done = false;
int init_samp_cnt = 0;
int samp_avg_cnt[x_res+1][z_res+1];
int filt_PC = set_filt_PC/3;//100
int gxrst, gzrst;
double start_time = 0;
double start_exec = 0;

/*
IMAGES USED
img: Constantly updated to reflect the data coming from the sensor as well as the
  points that are triggering warnings.
maskimg: Initialized to hold the original image of the sensor
  AND the user-defined polygons WITH the boundaries created
  around static obstacles.
polyimg: Initialized to hold only the polygonal zones defined by the user.
protectimg: Initialized to hold only the boundaries defined around static obstacles.

DISPLAYS USED
main_disp: Shows the constantly updated image with warning circles.
mask_disp: Initialized to the first sensor image, and can be manipulated by user during
  initialization to define polygonal zones. Will show mask for the duration of the program.
*/

cimg_library::CImg<unsigned char> img(x_res,z_res,1,3,255);
cimg_library::CImg<unsigned char> maskimg(x_res,z_res,1,3,255);
cimg_library::CImg<unsigned char> polyimg(x_res,z_res,1,3,255);
cimg_library::CImg<unsigned char> protectimg(x_res,z_res,1,3,255);
cimg_library::CImgDisplay main_disp(img, "Height Profile");
cimg_library::CImgDisplay mask_disp(maskimg, "Obstacle Mask");

//For Frequency Calculations
//double rts, rte, freq;
//int fcount = 0;

//Finding the channel index for X/Y/Z coordinate data from the pointcloud
inline int32_t findChannelIndex(const sensor_msgs::PointCloud2ConstPtr& cloud, const std::string& channel)
{
  for (size_t i = 0; i < cloud->fields.size(); ++i)
  {
    if (cloud->fields[i].name == channel)
    {
      return i;
    }
  }

  return -1;
}

//Function called each time a PointCloud2 message is received
void incomingCloudCallback(const sensor_msgs::PointCloud2ConstPtr& cloud)
{
  if (run == false)
    run = true;
  else
  { 
      //For frequency calculations
      //rte = ros::Time::now().toSec();
      //fcount++;
      //freq = fcount/(rte-rts);
      //if ((fcount % 250) == 0)
      //ROS_ERROR("Frequency is %f Hz", freq);
      run = false;
      int x_ind, z_ind;
      static bool warn_warn = false;
      float g_PlotArray[x_res+1][z_res+1];
      int PCount[x_res+1][z_res+1];
      int HOCount[x_res+1][z_res+1];
      bool warnlist[x_res+1][z_res+1];
      double t = 0;
      //end_time = ros::Time::now().toSec();
      int Wx,Wz,bright, xrst, zrst;
      unsigned char color[] = {0,0,0};
      //remove("PlotData.dat");

      for(xrst = 0; xrst <= x_res; xrst++)
      {
        for(zrst = 0; zrst <= z_res; zrst++)
        {
          g_PlotArray[xrst][zrst] = 10;
          PCount[xrst][zrst] = 0;
          HOCount[xrst][zrst] = 0;
          warnlist[xrst][zrst] = false;
        }
      }

          // Filter any nan values out of the cloud.  Any nan values that make it through to PointCloudBase
	  // will get their points put off in lala land, but it means they still do get processed/rendered
	  // which can be a big performance hit
	  int32_t xi = findChannelIndex(cloud, "x");
	  int32_t yi = findChannelIndex(cloud, "y");
	  int32_t zi = findChannelIndex(cloud, "z");

	  if (xi == -1 || yi == -1 || zi == -1)
	  {
	    return;
	  }
	  //Finds offset using channel index for X/Y/Z data 
	  const uint32_t xoff = cloud->fields[xi].offset;
	  const uint32_t yoff = cloud->fields[yi].offset;
	  const uint32_t zoff = cloud->fields[zi].offset;
	  const uint32_t point_step = cloud->point_step;
	  const size_t point_count = cloud->width * cloud->height;

	  if (point_count == 0)
	  {
	    return;
	  }

          //Gets X/Y/Z data by offsetting an incremending pointer
	  const uint8_t* ptr = &cloud->data.front();

	  for (size_t i = 0; i < point_count; ++i)
	  {
	    float x = *reinterpret_cast<const float*>(ptr + xoff);
	    float y = *reinterpret_cast<const float*>(ptr + yoff);
	    float z = *reinterpret_cast<const float*>(ptr + zoff);

            //BINNING
 	    if ((((x/x_sep)+(x_res/2)) > 0) && (((x/x_sep)+(x_res/2)) < (x_res)))
              {x_ind = (x/x_sep)+(x_res/2);}
            else
              {x_ind = 0;}

            if (((z/z_sep) > 0) && ((z/z_sep) < z_res))
              {z_ind = z/z_sep;}
	    else 
              {z_ind = 0;}

            //Calculate tolerance for height detection above static obstacles
            h_tolerance = (((float)z_ind*h_tol/(float)z_res)+h_tol_min);
	    
            //Count the valid points per bin to check for noise
	    PCount[x_ind][z_ind] = PCount[x_ind][z_ind] + 1;

            //Count the points per bin that are above static obstacles
            //Similar to noise check, but it is instead to make sure there
            //is actually a reasonably sized obstacle in the way
            //NOTE: y is inverted so a lower y value means a taller object
            if (y < (maxh_mask[x_ind][z_ind] - h_tolerance))
              HOCount[x_ind][z_ind] = HOCount[x_ind][z_ind] + 1;

            //Record only the highest point value in each bin
            if (y < g_PlotArray[x_ind][z_ind])
              {g_PlotArray[x_ind][z_ind] = y;}

            //***Begin STOP/Warn Check***

            //Check to make sure the object is tall enough to worry about and that
            //it is within the user-specified range of height values (Rmin, Rmax)   
            //Don't check for warnings or errors during initialization
            //Check to make sure the point is not noise
            if ((g_PlotArray[x_ind][z_ind] < minElevation) && ((g_PlotArray[x_ind][z_ind]+2) < Rmax) 
            && ((g_PlotArray[x_ind][z_ind]+2) > Rmin) && (first_run == false) && (PCount[x_ind][z_ind] > filt_PC))
            {
              //Check to make sure the point is within a STOP zone in the mask
              if ((maskimg(x_ind, z_res-z_ind, 0, 0) == red[0]) && 
              (maskimg(x_ind, z_res-z_ind, 0, 1) == red[1]) && (maskimg(x_ind, z_res-z_ind, 0, 2) == red[2]))
              {  
                //Check if the points around it (top, left, and diagonal) are also above the minimum height threshold
                if ((x_ind > 0) && (z_ind > 0) && (g_PlotArray[x_ind-1][z_ind] < minElevation)
                && (g_PlotArray[x_ind][z_ind-1] < minElevation) && (g_PlotArray[x_ind-1][z_ind-1] < minElevation))  
                {
                  //Add this point to the warning list
                  warnlist[x_ind][z_ind] = true;
                  
                  //If any of the other points around it (top, left, diagonal) are in the warning list, 
                  //trigger an immediate STOP 
                  if ((x_ind > 0) && (z_ind > 0) && (warnlist[x_ind-1][z_ind] 
                    || warnlist[x_ind][z_ind-1] || warnlist[x_ind-1][z_ind-1]))
                  {  
                    ROS_ERROR("Obstruction: STOP\nPoint is at (%d,%d) with height of [%f]", x_ind, z_res-z_ind, g_PlotArray[x_ind][z_ind]);
                    return;
                  }
                }
              }
              //If the point is in a WARNING zone
              else if ((maskimg(x_ind, z_res-z_ind, 0, 0) == yellow[0]) && (maskimg(x_ind, z_res-z_ind, 0, 1) == yellow[1]) 
              && (maskimg(x_ind, z_res-z_ind, 0, 2) == yellow[2]))
              {  
                //Check if the points around it (top, left, and diagonal) are also above the minimum height threshold
                if ((x_ind > 0) && (z_ind > 0) && (g_PlotArray[x_ind-1][z_ind] < minElevation)
                && (g_PlotArray[x_ind][z_ind-1] < minElevation) && (g_PlotArray[x_ind-1][z_ind-1] < minElevation))  
                {
                  //Add this point to the warning list
                  warnlist[x_ind][z_ind] = true;
                  
                  //If any of the other points around it (top, left, diagonal) are in the warning list, set the program
                  //to send a warning after it finishes processing the pointcloud
                  if ((x_ind > 0) && (z_ind > 0) && (warnlist[x_ind-1][z_ind] || warnlist[x_ind][z_ind-1] 
                  || warnlist[x_ind-1][z_ind-1]))
                    {warn_warn = true;}
                }
              }
 
              //If the point is seen to be higher than another obstacle and is in the zone of protection
              //around the static obstacles (and is not an empty point [when the height = 10])
              else if ((HOCount[x_ind][z_ind] > HO_PC) && (protectimg(x_ind, z_res-z_ind, 0, 0) == green[0]) 
              && (protectimg(x_ind, z_res-z_ind, 0, 1) == green[1]) && (protectimg(x_ind, z_res-z_ind, 0, 2) == green[2]) 
              && g_PlotArray[x_ind][z_ind] != 10)
              {
                //Check if the points around it (top, left, and diagonal) are also above static obstacles
                if ((x_ind > 0) && (z_ind > 0) && (HOCount[x_ind-1][z_ind] > HO_PC)
                && (HOCount[x_ind][z_ind-1] > HO_PC) && (HOCount[x_ind-1][z_ind-1] > HO_PC)) 
                {
                  //If a STOP polygon was defined over this point
                  if ((polyimg(x_ind, z_res-z_ind, 0, 0) == red[0]) && (polyimg(x_ind, z_res-z_ind, 0, 1) == red[1]) 
                  && (polyimg(x_ind, z_res-z_ind, 0, 2) == red[2]))
                  { 
                    //Add this point to the warning list
                    warnlist[x_ind][z_ind] = true;

                    //If any of the other points around it (top, left, diagonal) are in the warning list,
                    //trigger an immediate STOP
                    if ((x_ind > 0) && (z_ind > 0) && (warnlist[x_ind-1][z_ind] || warnlist[x_ind][z_ind-1] 
                    || warnlist[x_ind-1][z_ind-1]))
                    {
                      ROS_ERROR("Obstruction: STOP\nPoint is at (%d,%d) with height of [%f]", x_ind, z_res-z_ind, y);
                      return;
                    }
                  }

                  //If a WARNING polygon was defined over this point
                  else if ((polyimg(x_ind, z_res-z_ind, 0, 0) == yellow[0]) && (polyimg(x_ind, z_res-z_ind, 0, 1) == yellow[1]) 
                  && (polyimg(x_ind, z_res-z_ind, 0, 2) == yellow[2]))
                  { 
                    //Add this point to the warning list
                    warnlist[x_ind][z_ind] = true;
                    
                    //If any of the other points around it (top, left, diagonal) are in the warning list, set the program
                    //to send a warning after it finishes processing the pointcloud
                    if ((x_ind > 0) && (z_ind > 0) && (warnlist[x_ind-1][z_ind] || warnlist[x_ind][z_ind-1] 
                    || warnlist[x_ind-1][z_ind-1]))
                      {warn_warn = true;}
                  }
                }
              }
            }
	    //***End STOP/Warn Check***
	    ptr += point_step;
	  }

      //If the warn_delay has expired, show another message
      t = ros::Time::now().toSec();
      if ((t - warn_end_time) >= warn_delay)
      {
        if (warn_warn)
        {
          ROS_ERROR("Obstruction: WARN\n");
          warn_warn = false;
        }
        warn_end_time = ros::Time::now().toSec();
      }

      //***Start IMAGE DRAWING***
      //If all initialization samples are complete
      if (init_samp_cnt == init_samp_cnt_max)
      {
        //Loop through the array of bins
        for (Wx = 0; Wx <= x_res; Wx++)
        {
          for(Wz = 0; Wz <= z_res; Wz++)
          {
            //If drawing the first (mask) image, use values from mask array
            //to calculate the color of the pixels
            if (draw_first == true)
            {
              //Check that the point was consistent and existed for all samples taken
              if (samp_avg_cnt[Wx][Wz] >= min_samp_req)
                //Average all of the samples
                maxh_mask[Wx][Wz] = maxh_mask[Wx][Wz] / samp_avg_cnt[Wx][Wz];
              else
                //If the point was invalid (noise, inconsistent) set it to 'empty'
                maxh_mask[Wx][Wz] = -10;
              //Use the mask value to calculate pixel color
              bright = ((maxh_mask[Wx][Wz]+2-Rmin)*(255/(Rmax-Rmin)));
            }
            //If drawing regular sensor scans, use the regular image array to
            //calculate pixel color
            else
              {bright = ((g_PlotArray[Wx][Wz]+2-Rmin)*(255/(Rmax-Rmin)));}

            //Limit the color value to 255
            if (bright > 255)
              {bright = 255;}
 
            //Invert the color so that lower height values are darker and higher height values are brigher
            bright = 255-bright;

            //Set to shades of grey
            color[0] = (char)bright;
            color[1] = (char)bright;
            color[2] = (char)bright;
                
            //If the point is within the specified boundaries and is either not a noise
            //value or is above an existing object, keep the calculated color or 
            //set it to red/yellow if there is a STOP/WARNING on that point
            if (((g_PlotArray[Wx][Wz]+2) > Rmin) && ((g_PlotArray[Wx][Wz]+2) < Rmax) 
            && ((PCount[Wx][Wz] > filt_PC) || (HOCount[Wx][Wz] > HO_PC)))
            {
              /*if (IN STOP BOUNDARY)
	      {
                color[0] = redfake[0];
                color[1] = redfake[1];
                color[2] = redfake[2];
              }*/
              if (warnlist[Wx][Wz] == true)
              {
                color[0] = yellowfake[0];
                color[1] = yellowfake[1];
                color[2] = yellowfake[2];
              }
            }
 
            //If the point is invalid then set it to blue
            else if ((draw_first == false) || !(((maxh_mask[Wx][Wz]+2) > Rmin) && ((maxh_mask[Wx][Wz]+2) < Rmax) 
            && (PCount[Wx][Wz] > filt_PC)))
            {
	      color[0] = blue[0];
	      color[1] = blue[1];
	      color[2] = blue[2];
            } 
 
            //Draw the point with the specified color
            img.draw_point(Wx, z_res-Wz, color);
          }
        }
    
        //After the image is complete, 'top' it with circles around warnings
        for (Wx = 0; Wx <= x_res; Wx++)
        {
          for(Wz = 0; Wz <= z_res; Wz++)
          {
            if (warnlist[Wx][Wz] == true)
            {
              img.draw_circle(Wx, z_res-Wz, 2, yellowfake, 1, 0);
              if (test_mode == true)
                {
                  ROS_ERROR("\n***Warning at (%d,%d)***", Wx, Wz);
                  ROS_ERROR("\nPoint Height: %f\nObstacle Height: %f\nTolerance: %f\nHOCount: %d\nPCount: %d", 
                    g_PlotArray[Wx][Wz], maxh_mask[Wx][Wz], 
                    (((float)Wz*h_tol/(float)z_res)+h_tol_min), HOCount[Wx][Wz], PCount[Wx][Wz]);
                }
             }
             if (Wx == test_x && Wz == test_z && test_point == true)
               {img.draw_circle(Wx, z_res-Wz, 2, redfake, 1, 0);}
          }
        }
      }
      //***End IMAGE DRAWING***

      if(test_point == true)
        ROS_ERROR("\nPoint Height: %f\nObstacle Height: %f\nTolerance: %f\nHOCount: %d\nPCount: %d", 
          g_PlotArray[test_x][test_z], maxh_mask[test_x][test_z], 
          (((float)test_z*h_tol/(float)z_res)+h_tol_min), HOCount[test_x][test_z], PCount[test_x][test_z]);
 
      //***Start FIRST RUN INITIALIZATION***
      if (first_run == true)
      {
        //If all required samples are taken, set the maskimg to the current img,
        //display the maskimg, set the next image drawn to be from the sensor,
        //and increase the noise threshold to the user-specified value
        if (init_samp_cnt == init_samp_cnt_max)
        {
          maskimg = img;
          mask_disp.display(maskimg);
          draw_first = false;
          filt_PC = set_filt_PC;
        }

        //If the initialization is not yet complete, take another sample of the pointcloud and
        //add it to the mask array
        else
        {
          for(xrst = 0; xrst <= x_res; xrst++)
          {
            for(zrst = 0; zrst <= z_res; zrst++)
            {
              if (g_PlotArray[xrst][zrst] != 10)
              {  
                maxh_mask[xrst][zrst] += g_PlotArray[xrst][zrst];
                samp_avg_cnt[xrst][zrst] = samp_avg_cnt[xrst][zrst] + 1;
              }
            }
          }
          init_samp_cnt++; 
        }
      }

      //If initialization is already complete, display img and rezise windows to user-set size
      else
      {
        main_disp.display(img);
        if (main_disp.is_resized() == true)
          main_disp.resize(main_disp.window_width(),main_disp.window_height());
        if (mask_disp.is_resized() == true)
          mask_disp.resize(mask_disp.window_width(),mask_disp.window_height());
      }
     
      //For frequency calculations
      end_time = ros::Time::now().toSec();

      //If initialization is not yet complete but all samples are taken, 
      //create a point image and start the GUI for polygon creation
      if ((first_run == true) && (init_samp_cnt == init_samp_cnt_max) && (draw_first == false))
      {
        cimg_library::CImg<int> pointImage(x_res,2,1,1);
        protectimg = img;
        int point = 0;
        int Px, Pz;
        char select = 'x';
        unsigned char rstcolor[3];

        //Draw boundaries of protection around points of existing objects to differentiate between 
        //obstacles that are above or around the initial static objects
        for(Px = 0; Px < (x_res); Px++)
        {  
          for(Pz = 0; Pz < (z_res); Pz++)
          {
            if ((maskimg(Px, z_res-Pz, 0, 0) == maskimg(Px, z_res-Pz, 0, 1)) 
            && (maskimg(Px, z_res-Pz, 0, 1) == maskimg(Px, z_res-Pz, 0, 2)))
              protectimg.draw_circle(Px, z_res-Pz, (Pz*((float)protectRad/(float)z_res)+3), green);
          }
        }

        ROS_ERROR("\nClick to make points or drag for curves (800 point MAX)\nW for Warn\nS for Stop\nC for Clear\nD for Done");
        
        //As long as the user hasn't specified that he is finished with his polygons, keep the GUI running
        while(!poly_done)
        { 
          select = 'x';
          while(select != 'd' && select != 'w' && select != 's' && select != 'c')
          {
            //Wait for a user to perform an action (keypress or click) inside the GUI window (mask_disp)
            mask_disp.wait();
            select = mask_disp.key();

            //User selects 'Done': set GUI to close
            if (select == 'd' || mask_disp.is_closed())
              {poly_done = true;}

            //User selects 'Warning': draw WARNING polygon in polyimg
            else if ((select == 'w') && (point != 0))
            {
              for(point=point; point < pointImage.size()/2; point++)
              {
                pointImage(point,0) = pointImage(point-1,0);
                pointImage(point,1) = pointImage(point-1,1);
              }
              polyimg.draw_polygon(pointImage, yellow);
            }
 
            //User selects 'Stop': draw STOP polygon in polyimg
            else if ((select == 's') && (point != 0))
            {
              for(point=point; point < pointImage.size()/2; point++)
              {
                pointImage(point,0) = pointImage(point-1,0);
                pointImage(point,1) = pointImage(point-1,1);
              }
              polyimg.draw_polygon(pointImage, red);
            }
            
            //User selects 'Clear': remove the user-defined area in polyimg selected by the polygon
            else if ((select == 'c') && (point != 0))
            {
              for(point=point; point < pointImage.size()/2; point++)
              {
                pointImage(point,0) = pointImage(point-1,0);
                pointImage(point,1) = pointImage(point-1,1);
              }
              polyimg.draw_polygon(pointImage, blue);
            }

            //else if (mask_disp.is_resized() == true)
              //{mask_disp.resize(mask_disp.window_width(),mask_disp.window_height());}
            //Can't resize because pointson  an expanded window and points in the polyimg are not in the same place
            //unless you resize polyimg, which would throw off the program's ability

            //If there is a mouse-click, add the point clicked to the point image
            //NOTE: There is an 800 point limit to each polygon and if that is readched the user must redraw
            else if (mask_disp.button() && (mask_disp.mouse_y()>=0) && (mask_disp.mouse_x()>=0))
            {
              if (point == pointImage.size()/2)
              {
                ROS_ERROR("MAX POLYGON SIZE EXCEEDED! MUST REDRAW!");
                point = 0;
              }
              else 
              {
                pointImage(point,0) = mask_disp.mouse_x();
                pointImage(point,1) = mask_disp.mouse_y();
                point++;
              }
            }
          }

          //Fill maskimg with the polygons while avoiding the boundary zones
          for(Px = 0; Px <= x_res; Px++)
          {
            for(Pz = 0; Pz <= z_res; Pz++)
            {
              //If the point of the polygon in polyimg is not in the boundary area, draw it in maskimg
              if (!((protectimg(Px, z_res-Pz, 0, 0) == green[0]) && (protectimg(Px, z_res-Pz, 0, 1) == green[1]) 
              && (protectimg(Px, z_res-Pz, 0, 2) == green[2])))
              {  
                if ((polyimg(Px, z_res-Pz, 0, 0) == red[0]) && (polyimg(Px, z_res-Pz, 0, 1) == red[1]) 
                && (polyimg(Px, z_res-Pz, 0, 2) == red[2]))
                  {maskimg.draw_point(Px, z_res-Pz, red);}
                else if ((polyimg(Px, z_res-Pz, 0, 0) == yellow[0]) && (polyimg(Px, z_res-Pz, 0, 1) == yellow[1]) 
                && (polyimg(Px, z_res-Pz, 0, 2) == yellow[2]))
                  {maskimg.draw_point(Px, z_res-Pz, yellow);}
                else if ((polyimg(Px, z_res-Pz, 0, 0) == blue[0]) && (polyimg(Px, z_res-Pz, 0, 1) == blue[1]) 
                && (polyimg(Px, z_res-Pz, 0, 2) == blue[2]))
                  {maskimg.draw_point(Px, z_res-Pz, blue);}
              }
 
              //If the point of the polygon in polyimg is in the boundary area, draw the object underneath it
              //and then shade in the yellow/red depending on the polygon color
              else 
              {
                //Draw static object
                rstcolor[0] = img(Px, z_res-Pz, 0, 0);
                rstcolor[1] = img(Px, z_res-Pz, 0, 1);
                rstcolor[2] = img(Px, z_res-Pz, 0, 2);
                maskimg.draw_point(Px, z_res-Pz, rstcolor);

                //Shade in color: if the point next to it is colored, don't color this point
                if ((polyimg(Px, z_res-Pz, 0, 0) == red[0]) && (polyimg(Px, z_res-Pz, 0, 1) == red[1]) 
                && (polyimg(Px, z_res-Pz, 0, 2) == red[2]))
                {
                  if (!((maskimg(Px-1, z_res-Pz, 0, 0) == redfake[0]) && (maskimg(Px-1, z_res-Pz, 0, 1) == redfake[1]) 
                  && (maskimg(Px-1, z_res-Pz, 0, 2) == redfake[2])) && !((maskimg(Px, z_res-Pz+1, 0, 0) == redfake[0]) 
                  && (maskimg(Px-1, z_res-Pz+1, 0, 1) == redfake[1]) && (maskimg(Px-1, z_res-Pz+1, 0, 2) == redfake[2])))
                  {
                    maskimg.draw_point(Px, z_res-Pz, redfake);
                  }
                }
                else if ((polyimg(Px, z_res-Pz, 0, 0) == yellow[0]) && (polyimg(Px, z_res-Pz, 0, 1) == yellow[1]) 
                && (polyimg(Px, z_res-Pz, 0, 2) == yellow[2]))
                {
                  if (!((maskimg(Px-1, z_res-Pz, 0, 0) == yellowfake[0]) && (maskimg(Px-1, z_res-Pz, 0, 1) == yellowfake[1]) 
                  && (maskimg(Px-1, z_res-Pz, 0, 2) == yellowfake[2])) && !((maskimg(Px, z_res-Pz+1, 0, 0) == yellowfake[0]) 
                  && (maskimg(Px-1, z_res-Pz+1, 0, 1) == yellowfake[1]) && (maskimg(Px-1, z_res-Pz+1, 0, 2) == yellowfake[2])))  
                  {
                    maskimg.draw_point(Px, z_res-Pz, yellowfake);
                  }
                }
              }
            }
          }
          //Display the mask image
          mask_disp.display(maskimg);
          point = 0;
        } 
        //Make sure to not run this initialization again
        first_run = false;
        return;
      }
      //***End FIRST RUN INITIALIZATION***
  }
  return;
}

int main(int argc, char **argv)
{
  for (gxrst = 0; gxrst <= x_res; gxrst++)
    for (gzrst = 0; gzrst <= z_res; gzrst++)
    {
      maxh_mask[gxrst][gzrst] = 0;
      samp_avg_cnt[gxrst][gzrst] = 0;
    }
  //main_disp.resize(400,400).display(img);
  //mask_disp.resize(400,400).display(maskimg);
  ros::init(argc, argv, "obst_det");
  ros::NodeHandle get;
  //Topic Subscription
  ros::Subscriber sub = get.subscribe("points", 1, incomingCloudCallback); //For Simulation
  //ros::Subscriber sub = get.subscribe("/camera/depth/points", 1, incomingCloudCallback); //For Real Kinect

  //Must wait 60s after subscribing to topic
  /*ROS_ERROR("Please wait for initialization (60s)...");
  start_time = ros::Time::now().toSec();
  while(start_exec < (start_time + 60))
  {    
    start_exec = ros::Time::now().toSec();
  }*/
  ROS_ERROR("Generating mask image...");
  while(!mask_disp.is_closed() && !main_disp.is_closed())
    ros::spinOnce();
  return 0;
}

