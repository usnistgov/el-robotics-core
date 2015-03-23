///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRPI
//  Subsystem:       Robot Interface
//  Workfile:        crpi_universal.cpp
//  Revision:        1.0 - 24 June, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  Universal Robot UR10 interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core/crpi_universal.h"
#include <fstream>
#include <iostream>

#define BLOCKING_MOTION
//#define VERIFY_MOVING
#define USE_TIMEOUT

using namespace std;

namespace crpi_robot
{
  int readInt (char *buffer, int &index, bool little)
  {
    static char ucval[sizeof(int)];
    static int x;
    static int returnMe;

    for (x = 0; x < sizeof(int); ++x)
    {
      ucval[x] = (little ? buffer[index+(sizeof(int) - (x+1))] : buffer[index + x]);
    }
    index += sizeof(int);
    memcpy(&returnMe, ucval, sizeof(int));
    return returnMe;
  }


  double readDouble (char *buffer, int &index, bool little)
  {
    static char ucval[sizeof(double)];
    static int x;
    static double returnMe;

    for (x = 0; x < sizeof(double); ++x)
    {
      ucval[x] = (little ? buffer[index+(sizeof(double) - (x+1))] : buffer[index + x]);
    }
    index += sizeof(double);
    memcpy(&returnMe, ucval, sizeof(double));
    return returnMe;
  }


  long readLong (char *buffer, int &index, bool little)
  {
    static char ucval[sizeof(double)];
    static int x;
    static long returnMe;

    for (x = 0; x < sizeof(long); ++x)
    {
      ucval[x] = (little ? buffer[index+(sizeof(long) - (x+1))] : buffer[index + x]);
    }
    index += sizeof(long);
    memcpy(&returnMe, ucval, sizeof(long));
    return returnMe;
  }

  bool parseFeedback (int bytes, char *buffer, robotPose &pose, robotAxes &axes, robotIO &io)
  {
    double dval;
    int ival;
    bool little = false;

    //! JAM:  Note that the UR sends feedback in big endian format.  Test for endianess.
    int i = 0x01234567;
    int j;
    char* c = (char*)&i;
    little = (c[0] == 'g');
    //for (j = 0; j < sizeof(int); j++)
    //{
    //  printf(" %.2x", c[j]);
    //}
    //printf("\n");
       
    //! If big endian:  01 23 45 67
    //! If little endian: 67 45 23 01

    //cout << bytes << endl;
    if (bytes != 1044 && bytes != 812)
    {
      //! unknown byte length
      return false;
    }

    int index = 0;
    //! Number of bytes sent
    ival = readInt(buffer, index, little);

    //! Time
    dval = readDouble(buffer, index, little);

    //! Target joint positions
    for (j = 0; j < 6; ++j)
    {
      //dval = readDouble(buffer, index, little);
      axes.axis[j] = readDouble(buffer, index, little);
    }

    //! Target joint velocities
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Target joint accelerations
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Target joint current
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Target joint moments
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Actual joint positions
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Actual joint velocities
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Actual joint currents
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Joint control currents
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Actual Cartesian coordinates of TCP
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Actual speed of TCP in Cartesian space
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Forces at TCP
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! TCP target coordinates
    /*
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }
    */
    pose.x = readDouble(buffer, index, little);
    pose.y = readDouble(buffer, index, little);
    pose.z = readDouble(buffer, index, little);
    pose.xrot = readDouble(buffer, index, little);
    pose.yrot = readDouble(buffer, index, little);
    pose.zrot = readDouble(buffer, index, little);


    //! TCP target speed
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Digital input states
    ival = (int)(readDouble(buffer, index, little));
    for (j = (CRPI_IO_MAX-1); j >= 0; j--)
    {
      io.dio[j] = (ival >= (1 << j));
      if (io.dio[j])
      {
        ival -= (int)(1 << j);
      }
    }

    //! Motor temperatures
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! Controller timer
    dval = readDouble(buffer, index, little);

    //! Test value
    dval = readDouble(buffer, index, little);

    //! Robot mode
    dval = readDouble(buffer, index, little);

    //! Joint modes
    for (j = 0; j < 6; ++j)
    {
      dval = readDouble(buffer, index, little);
    }

    //! 1044 bytes beyond this point
    if (ival > 812)
    {
      //! Safety mode
      dval = readDouble(buffer, index, little);

      //! Reserved
      for (j = 0; j < 6; ++j)
      {
        dval = readDouble(buffer, index, little);
      }

      //! Tool accelerometer
      for (j = 0; j < 3; ++j)
      {
        dval = readDouble(buffer, index, little);
      }

      //! Reserved
      for (j = 0; j < 6; ++j)
      {
        dval = readDouble(buffer, index, little);
      }

      //! Speed scaling
      dval = readDouble(buffer, index, little);

      //! Linear momentum norm
      dval = readDouble(buffer, index, little);

      //! Reserved
      dval = readDouble(buffer, index, little);

      //! Reserved
      dval = readDouble(buffer, index, little);

      //! Main voltage
      dval = readDouble(buffer, index, little);

      //! Robot voltage
      dval = readDouble(buffer, index, little);

      //! Robot current
      dval = readDouble(buffer, index, little);

      //! Joint voltages
      for (j = 0; j < 6; ++j)
      {
        dval = readDouble(buffer, index, little);
      }
    } // if (ival > 812)

    return true;
  }

  void feedbackThread (void *param)
  {
    universalHandler *uH = (universalHandler*)param;
    bool connected = false;
    char *buffer;
    int get;
    robotPose pose;
    robotAxes axes;
    robotIO io;

    buffer = new char[1044];

    while (uH->runThread)
    {
      /*
      HOST = "169.254.152.50" //! The remote host
      PORT = 30003            //! 125 Hz update of robot state
      PORT = 30002            //! Control port
      */
      uH->clientID = ulapi_socket_get_client_id (30003, uH->robotIP);
      ulapi_socket_set_nonblocking(uH->clientID);

      if (uH->clientID > 0)
      {
        //! Read feedback from robot
        get = ulapi_socket_read(uH->clientID, buffer, 1044);
        ulapi_socket_close(uH->clientID);
        //! Parse feedback from robot
        if (parseFeedback(get, buffer, pose, axes, io))
        {
          ulapi_mutex_take(uH->handle);
          //! Store feedback from robot
          uH->curPose = pose;
          uH->curAxes = axes;
          uH->curIO = io;
          ulapi_mutex_give(uH->handle);

          //cout << "(" << pose.x << ", " << pose.y << ", " << pose.z << ", " << pose.xrot << ", " << pose.yrot << ", " << pose.zrot << ")" << endl;
          //cout << "(" << axes.axis[0] << ", " << axes.axis[1] << ", " << axes.axis[2] << ", " << axes.axis[3] << ", " << axes.axis[4] << ", " << axes.axis[5] << ")" << endl;
        }
      }

      //! Don't slam your processor!  You don't need to poll at full speed. 10 Hz
      Sleep (100);
    }
    delete [] buffer;
    return;
  }


  LIBRARY_API CrpiUniversal::CrpiUniversal (char *initPath) :
    acceptCRPI_(false)
  {
    double xr, yr, zr;

    //! Open configuration file
    if (initPath != NULL)
    {
      ifstream in(initPath);
      in.getline(handle_.robotIP, 16);
      in >> xr >> yr >> zr;
      in.close();
    }

    maxSpeed_ = 1.0f;
    maxAccel_ = 3.0f;

    //! These are nominal values defined by trial and error.  Use the SetAbsoluteSpeed and
    //! SetAbsoluteAcceleration commands to override
    speed_ = 1.0f;
    acceleration_ = 0.2f;

    mssgBuffer_ = new char[8192];
    ulapi_init();

    angleUnits_ = RADIAN;
    lengthUnits_ = METER;
    for (int i = 0; i < 6; ++i)
    {
      axialUnits_[i] = RADIAN;
    }

    task = ulapi_task_new();
    handle_.handle = ulapi_mutex_new(99);
    handle_.rob = this;
    handle_.runThread = true;

    ulapi_task_start((ulapi_task_struct*)task, feedbackThread, &handle_, ulapi_prio_lowest(), 0);
 
    forward_ = new matrix(3,3);
    backward_ = new matrix(3,3);
    pin_ = new matrix(3,1);
    pout_ = new matrix(3,1);

    //! TODO: Read in from external file
    Xtheta_ = xr * (3.141592657 / 180.0f);
    Ytheta_ = yr * (3.141592657 / 180.0f);
    Ztheta_ = zr * (3.141592657 / 180.0f);

    //! TODO:  add Y & Z axis rotations, and X, Y, Z axis offsets
    forward_->at(0, 0) = 1.0f;
    forward_->at(0, 1) = 0.0f;
    forward_->at(0, 2) = 0.0f;
    forward_->at(1, 0) = 0.0f;
    forward_->at(1, 1) = cos(Xtheta_);
    forward_->at(1, 2) = -sin(Xtheta_);
    forward_->at(2, 0) = 0.0f;
    forward_->at(2, 1) = sin(Xtheta_);
    forward_->at(2, 2) = cos(Xtheta_);

    backward_->at(0, 0) = 1.0f;
    backward_->at(0, 1) = 0.0f;
    backward_->at(0, 2) = 0.0f;
    backward_->at(1, 0) = 0.0f;
    backward_->at(1, 1) = cos(-Xtheta_);
    backward_->at(1, 2) = -sin(-Xtheta_);
    backward_->at(2, 0) = 0.0f;
    backward_->at(2, 1) = sin(-Xtheta_);
    backward_->at(2, 2) = cos(-Xtheta_);
  }


  LIBRARY_API CrpiUniversal::~CrpiUniversal ()
  {
    handle_.runThread = false;
    delete forward_;
    delete backward_;
    delete pin_;
    delete pout_;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetTool (double percent)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::Couple (const char *targetID)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::Dwell (int *events, double *params, int numEvents)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::EndCanon (int reason)
  {
    acceptCRPI_ = false;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::InitCanon ()
  {
    acceptCRPI_ = true;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::Message (const char *message)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::MoveStraightTo (robotPose pose)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct message
    vector<double> target;
    robotPose temp = pose;
    double dist, dist2, tim;
    int count;

    if (lengthUnits_ == MM)
    {
      temp.x *= 0.001f;
      temp.y *= 0.001f;
      temp.z *= 0.001f;
    }
    else if (lengthUnits_ == INCH)
    {
      //! TODO: CONVERT TO METERS
    }

    if (angleUnits_ == DEGREE)
    {
      temp.xrot *= (3.141592654f / 180.0f);
      temp.yrot *= (3.141592654f / 180.0f);
      temp.zrot *= (3.141592654f / 180.0f);
    }

    pin_->at(0,0) = temp.x;
    pin_->at(1,0) = temp.y;
    pin_->at(2,0) = temp.z;
    pin_->matrixMult (*backward_, *pin_, *pout_);
    temp.x = pout_->at(0,0);
    temp.y = pout_->at(1,0);
    temp.z = pout_->at(2,0);

    target.push_back (temp.x);
    target.push_back (temp.y);
    target.push_back (temp.z);
    target.push_back (temp.xrot);
    target.push_back (temp.yrot);
    target.push_back (temp.zrot);

    //! LIN, Cartesian, Absolute
    if (generateMove ('L', 'C', 'A', target))
    {
      //! Send message to robot
      if (!send())
      {
        //! error sending
        return CANON_FAILURE;
      }
#ifdef BLOCKING_MOTION     
      //! ROBOT DOES NOT BLOCK:  WAIT FOR RESPONSE
      dist2 = 1000.0;
      count = 0;
      tim = ulapi_time();
      while (true)
      {
        ulapi_mutex_take(handle_.handle);
        dist = handle_.curPose.distance(temp);
        ulapi_mutex_give(handle_.handle);

#ifdef VERIFY_MOVING
        if (dist >= dist2)
        {
          ++count;

          if (count >= 30)
          {
            //! Robot is not moving.  Retry.
            return CANON_FAILURE;
          }
        }
#endif

#ifdef USE_TIMEOUT
        if ((ulapi_time() - tim) > 15)
        {
          return CANON_FAILURE;
        }
#endif

        if (dist <= 0.0005f)
        {
          break;
        }
        ulapi_wait(5000);
        dist2 = dist;
      }
#endif
    }
    else
    {
      //! Error generating motion message
      return CANON_FAILURE;
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::MoveThroughTo (robotPose *poses,
                                                        int numPoses,
                                                        robotPose *accelerations,
                                                        robotPose *speeds,
                                                        robotPose *tolerances)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    bool status = true;

    //! This is a temporary function definition until the KRL code has been updated to properly handle
    //! this method
    for (int x = 0; x < numPoses; ++x)
    {
      status &= (MoveTo (poses[x]) == CANON_SUCCESS);
      if (!status)
      {
        //! Error when executing multi move
        return CANON_FAILURE;
      }
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::MoveTo (robotPose pose)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct message
    vector<double> target;
    robotPose temp = pose;
    double dist, dist2, tim;
    int count;

    if (lengthUnits_ == MM)
    {
      temp.x *= 0.001f;
      temp.y *= 0.001f;
      temp.z *= 0.001f;
    }
    else if (lengthUnits_ == INCH)
    {
      //! TODO: CONVERT TO METERS
    }

    if (angleUnits_ == DEGREE)
    {
      temp.xrot *= (3.141592654f / 180.0f);
      temp.yrot *= (3.141592654f / 180.0f);
      temp.zrot *= (3.141592654f / 180.0f);
    }

    pin_->at(0,0) = temp.x;
    pin_->at(1,0) = temp.y;
    pin_->at(2,0) = temp.z;
    pin_->matrixMult (*backward_, *pin_, *pout_);
    temp.x = pout_->at(0,0);
    temp.y = pout_->at(1,0);
    temp.z = pout_->at(2,0);

    target.push_back (temp.x);
    target.push_back (temp.y);
    target.push_back (temp.z);
    target.push_back (temp.xrot);
    target.push_back (temp.yrot);
    target.push_back (temp.zrot);

    //! PTP, Cartesian, Absolute
    //if (generateMove ('P', 'C', 'R', target))
    if (generateMove ('P', 'C', 'A', target))
    {
      //! Send message to robot
      if (!send())
      {
        //! error sending
        return CANON_FAILURE;
      }
#ifdef BLOCKING_MOTION     
      //! ROBOT DOES NOT BLOCK:  WAIT FOR RESPONSE
      dist2 = 1000.0;
      count = 0;
      tim = ulapi_time();
      while (true)
      {
        ulapi_mutex_take(handle_.handle);
        dist = handle_.curPose.distance(temp);
        ulapi_mutex_give(handle_.handle);

#ifdef VERIFY_MOVING
        if (dist >= dist2)
        {
          ++count;

          if (count >= 30)
          {
            //! Robot is not moving.  Retry.
            return CANON_FAILURE;
          }
        }
#endif

#ifdef USE_TIMEOUT
        if ((ulapi_time() - tim) > 15)
        {
          return CANON_FAILURE;
        }
#endif

        if (dist <= 0.0005f)
        {
          break;
        }
        ulapi_wait(5000);
        dist2 = dist;
      }
#endif

    }
    else
    {
      //! Error generating motion message
      return CANON_FAILURE;
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::Decouple (const char *targetID)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::GetRobotAxes (robotAxes *axes)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    ulapi_mutex_take(handle_.handle);
    *axes = handle_.curAxes;

    for (int i = 0; i < 6; ++i)
    {
      if (axialUnits_[i] == DEGREE)
      {
        axes->axis[i] *= (180.0f / 3.141592654f);
      }
    }

    ulapi_mutex_give(handle_.handle);

    //! Not yet implemented
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::GetRobotPose (robotPose *pose)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    ulapi_mutex_take(handle_.handle);
    *pose = handle_.curPose;
    ulapi_mutex_give(handle_.handle);

    pin_->at(0,0) = pose->x;
    pin_->at(1,0) = pose->y;
    pin_->at(2,0) = pose->z;

    pin_->matrixMult (*forward_, *pin_, *pout_);
    pose->x = pout_->at(0,0);
    pose->y = pout_->at(1,0);
    pose->z = pout_->at(2,0);

    if (lengthUnits_ == MM)
    {
      //! Convert units to mm
      pose->x *= 1000.0f;
      pose->y *= 1000.0f;
      pose->z *= 1000.0f;
    }
    else if (lengthUnits_ == INCH)
    {
      //! TODO: CONVERT TO INCH
    }
    
    if (angleUnits_ = DEGREE)
    {
      pose->xrot *= (180.0f / 3.141592654f);
      pose->yrot *= (180.0f / 3.141592654f);
      pose->zrot *= (180.0f / 3.141592654f);
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::GetRobotIO (robotIO *io)
  {
    ulapi_mutex_take(handle_.handle);
    *io = handle_.curIO;
    ulapi_mutex_give(handle_.handle);
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::MoveAttractor (robotPose pose)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    vector<double> ins;
    ins.push_back(0);
    ins.push_back(0);
    ins.push_back(0);
    ins.push_back(0);
    ins.push_back(0);
    ins.push_back(0);

    if (generateParameter ('F', 'E', ins))
    {
      if (send())
      {
        //! Okay
        
      }
      else
      {
        //! Oops
      }
    }
    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::MoveToAxisTarget (robotAxes axes)
{
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct message
    vector<double> target;
    for (int i = 0; i < axes.axes; ++i)
    {
      //! TODO: SET AXES TO CORRECT UNITS
      target.push_back (axes.axis[i]);
    }

    //! PTP, Angular, Absolute
    if (generateMove ('P', 'A', 'A', target))
    {
      //! Send message to robot
      if (!send())
      {
        //! error sending
        return CANON_FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        return CANON_FAILURE;
      }
    }
    else
    {
      //! Error generating motion message
      return CANON_FAILURE;
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::RunProgram (const char *programName, CRPIProgramParams params)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetAbsoluteAcceleration (double acceleration)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    if (acceleration > maxAccel_ || acceleration < 0.0f)
    {
      return CANON_REJECT;
    }

    acceleration_ = acceleration;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetAbsoluteSpeed (double speed)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    if (speed > maxSpeed_ || speed < 0.0f)
    {
      return CANON_FAILURE;
    }

    speed_ = speed;
    return CANON_SUCCESS;
  }

  //  ("degree" or "radian")
  LIBRARY_API CanonReturn CrpiUniversal::SetAngleUnits (const char *unitName)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    if (strcmp(unitName, "degree") == 0)
    {
      angleUnits_ = DEGREE;
    }
    else if (strcmp(unitName, "radian") == 0)
    {
      angleUnits_ = RADIAN;
    }
    else
    {
      CANON_FAILURE;
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetAxialSpeeds (double *speeds)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! TODO
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetAxialUnits (const char **unitNames)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetEndPoseTolerance (robotPose tolerances)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetLengthUnits (const char *unitName)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    if (strcmp(unitName, "meter") == 0)
    {
      lengthUnits_ = METER;
    }
    else if (strcmp(unitName, "mm") == 0)
    {
      lengthUnits_ = MM;
    }
    else if (strcmp(unitName, "inch") == 0)
    {
      lengthUnits_ = INCH;
    }
    else
    {
      CANON_FAILURE;
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetParameter (const char *paramName, void *paramVal)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetRelativeAcceleration (double percent)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    if (percent > 1.0f || percent < 0.0f)
    {
      return CANON_FAILURE;
    }

    acceleration_ = maxAccel_ * percent;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetRelativeSpeed (double percent)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    if (percent > 1.0f || percent < 0.0f)
    {
      return CANON_FAILURE;
    }

    speed_ = maxSpeed_ * percent;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiUniversal::SetRobotIO (robotIO io)
  {
    //! TODO
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiUniversal::StopMotion (int condition)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }
  

  LIBRARY_API bool CrpiUniversal::generateMove (char moveType, char posType, char deltaType, vector<double> &input)
  {
    bool state = true;

    //! Check validity of inputs...
    //!   Check movement type
    state &= (moveType == 'P' || moveType == 'L' || moveType == 'F');
    //!   Check position type
    state &= (posType == 'C' || posType == 'A');
    //!   Check absolute or relative motion
    state &= (deltaType == 'A' || deltaType == 'R');
    //!   Check PTP-only angle movements
    state &= !(posType == 'A' && moveType == 'L');
    //!   Check for proper amount of input arguments
    state &= (input.size() == 6);

    if (!state)
    {
      //! Invalid arguments generating move
      return false;
    }
    
    ulapi_mutex_take(handle_.handle);
    handle_.moveMe.str(string());

    handle_.moveMe << "move" << (moveType == 'P' ? "j(" : "l(");
    handle_.moveMe << (posType == 'C' ? "p[" : "[") << ((deltaType == 'A' ? 0.0f : curPose_[0]) + input.at(0)) << ", "
                   << ((deltaType == 'A' ? 0.0f : curPose_[1]) + input.at(1)) << ", " 
                   << ((deltaType == 'A' ? 0.0f : curPose_[2]) + input.at(2)) << ", "
                   << ((deltaType == 'A' ? 0.0f : curPose_[3]) + input.at(3)) << ", "
                   << ((deltaType == 'A' ? 0.0f : curPose_[4]) + input.at(4)) << ", "
                   << ((deltaType == 'A' ? 0.0f : curPose_[5]) + input.at(5))
                   << "], a=" << acceleration_ << ", v=" << speed_ << ")\n";
    /*
    handle_.moveMe << "while(True):\nforcem" << (moveType == 'P' ? "j(" : "l(");
    handle_.moveMe << (posType == 'C' ? "p[" : "[") << ((deltaType == 'A' ? 0.0f : curPose_[0]) + input.at(0)) << ", "
                   << ((deltaType == 'A' ? 0.0f : curPose_[1]) + input.at(1)) << ", " 
                   << ((deltaType == 'A' ? 0.0f : curPose_[2]) + input.at(2)) << ", "
                   << ((deltaType == 'A' ? 0.0f : curPose_[3]) + input.at(3)) << ", "
                   << ((deltaType == 'A' ? 0.0f : curPose_[4]) + input.at(4)) << ", "
                   << ((deltaType == 'A' ? 0.0f : curPose_[5]) + input.at(5))
                   << "], a=" << acceleration_ << ", v=" << speed_ << ")\nsync()\nend\n";
    */
    ulapi_mutex_give(handle_.handle);

    return true;
  }


  LIBRARY_API bool CrpiUniversal::generateTool (char mode, double value)
  {
    if (!(mode == 'B' || mode == 'A'  || mode == 'D'))
    {
      //! Value must be between 0 and 1
      return false;
    }

    //! TODO:  Populate variables 
    //moveMe_.str(string());
    //moveMe_ << "(0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000)";
    return true;
  }


  LIBRARY_API bool CrpiUniversal::generateFeedback (char retType)
  {
    if (retType != 'C' && retType != 'A' && retType != 'F' && retType != 'T' && retType != 'S')
    {
      //! Unsupported variable
      return false;
    }



    //! TODO:  Popluate variables
    //moveMe_.str(string());
    //moveMe_ << "(0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000, 0.00000000)";
    return true;
  }


  LIBRARY_API bool CrpiUniversal::generateParameter (char paramType, char subType, vector<double> &input)
  {
    bool state = true;

    //! Check validity of inputs...
    //!   Check movement type
    state &= (paramType == 'A' || paramType == 'S' || paramType == 'F');
    //!   Check position type
    state &= (subType == 'A' || subType == 'R' || subType == 'E' || subType == 'D');

    if (paramType == 'F')
    {
      state &= (subType == 'E' || subType == 'D');
    }
    else
    {
      state &= (subType == 'A' || subType == 'R');
    }

    if (!state)
    {
      //! Invalid arguments generating move
      return false;
    }

    ulapi_mutex_take(handle_.handle);
    handle_.moveMe.str(string());
    switch (paramType)
    {
    case 'A':
      break;
    case 'S':
      break;
    case 'F':
      if (subType == 'E')
      {
        //! Enable force mode
        if (input.size() == 6)
        {
          handle_.moveMe << "force_mode(p[0,0,0,0,0,0], [1,1,1,1,1,1], [" << input.at(0) << ", " 
                         << input.at(1) << ", " << input.at(2) << ", " << input.at(3) << ", "
                         << input.at(4) << ", "<< input.at(5) << "], 1, [0.3,0.3,0.3,1.0471975511965976,1.0471975511965976,1.0471975511965976])\n";
        }
        else
        {
          handle_.moveMe << "force_mode(p[0,0,0,0,0,0], [1,1,1,1,1,1], [0,0,0,0,0,0], 1, [0.3,0.3,0.3,1.0471975511965976,1.0471975511965976,1.0471975511965976])\n";
        }
      }
      else
      {
        //! Disable force mode
        handle_.moveMe << "end_force_mode()\n";
      }
      break;
    default:
      //! Shouldn't get here.  We checked for this already.
      break;
    }
    ulapi_mutex_give(handle_.handle);

    return true;


    
    return true;
  }


  LIBRARY_API bool CrpiUniversal::send ()
  {
    //! Send cmd
    //! get ack
    //! Send subcmd 
    //! get ack
    //! Send tertiary
    //! get ack
    //! send moveMe

    /*
    HOST = "169.254.152.50" //! The remote host
    PORT = 30003            //! 125 Hz update of robot state
    PORT = 30002            //! Control port
    */
    ulapi_mutex_take(handle_.handle);
    ulapi_integer client = ulapi_socket_get_client_id (30003, handle_.robotIP);
    ulapi_mutex_give(handle_.handle);
    ulapi_socket_set_nonblocking(client);

    int sent;
    if (client > 0)
    {
      ulapi_mutex_take(handle_.handle);
      sent = ulapi_socket_write (client, handle_.moveMe.str().c_str(), strlen(handle_.moveMe.str().c_str()) + 1);
      ulapi_mutex_give(handle_.handle);
//      cout << handle_.moveMe.str().c_str() << endl;
//      cout << endl << "sent " << sent << " bytes" << endl;
    }
    else
    {
      cout << endl << "cannot connect" << endl;
      return false;
    }

    ulapi_socket_close(client);

    return true;
  }


  LIBRARY_API bool CrpiUniversal::get ()
  {
    int x = 0;
    if (serialUsed_)
    {
      printf ("getting feedback...\n");
      x = ulapi_serial_read(serialID_, mssgBuffer_, 8192);
      printf ("%d read\n", x);
      return true;
    }
    else
    {
      //! TODO
      return false;
    }
  }


  void UniversalThread (void *param)
  {
    /*
    keepalive *ka = (keepalive*)param;
    int val;

    while (ka->runThread)
    {
      ((CrpiRobotiq*)ka->rob)->SetParameter("STATUS", &val);

      //! Don't slam your processor!  You don't need to poll at full speed.
      Sleep (5000);
    }
    return;
    */
  }

} // crpi_robot
