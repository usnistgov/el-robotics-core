///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRPI
//  Subsystem:       Robot Interface
//  Workfile:        crpi_kuka_lwr.cpp
//  Revision:        1.0 - 13 March, 2014
//                   1.1 - 16 June, 2014   Updated to use ulapi serial drivers
//  Author:          J. Marvel
//
//  Description
//  ===========
//  KUKA LWR 4+ interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core/crpi_kuka_lwr.h"
#include <fstream>

//#define STATIC_ //! Uncomment this line if you want to hard code the serial port (debugging purposes only)

using namespace std;
//#define LWR_NOISY

namespace crpi_robot
{
  void livemanLWR (void *param)
  {
    keepalive *ka = (keepalive*)param;
    robotPose pose;

    while (ka->runThread)
    {
      ((CrpiKukaLWR*)ka->rob)->GetRobotPose (&pose);

      //! Don't slam your processor!  You don't need to poll at full speed.
      Sleep (5000);
    }
    return;
  }


  LIBRARY_API CrpiKukaLWR::CrpiKukaLWR (char *initPath) :
    acceptCRPI_(false)
  {
    mssgBuffer_ = new char[8192];
    int val;

#ifndef OLDSERIAL
    if (ULAPI_OK != ulapi_init())
    {
#ifdef LWR_NOISY
      printf("ulapi_init error\n");
#endif
    }
#endif

#ifndef STATIC_
    //! Open configuration file
    if (initPath != NULL)
    {
      ifstream in(initPath);
      in >> val;

      if (val == 1)
      {
        //! Use serial
        serialUsed_ = true;

#ifdef OLDSERIAL
        serial_ = new serial();
#else
        if (NULL == (serialID_ = ulapi_serial_new()))
        {
#ifdef LWR_NOISY
          printf ("\nCannot create serial object\n");
#endif
        }
#endif

        in >> val;
        sprintf (COMChannel_, "COM%d", val);

#ifdef LWR_NOISY
        printf ("%s : ", COMChannel_);
#endif

#ifdef OLDSERIAL
        serialData_.setChannel (val);
#else
        if (ulapi_serial_open(COMChannel_, serialID_) == ULAPI_OK)
        {
#ifdef LWR_NOISY
          printf ("Opened COM channel\n");
#endif
        }
        else
        {
#ifdef LWR_NOISY
          printf ("Could not open COM channel\n");
#endif
        }
#endif

        in >> val;
#ifdef OLDSERIAL
        serialData_.setBaud (val);
#else
        if (ulapi_serial_baud(serialID_, val) == ULAPI_OK)
        {
#ifdef LWR_NOISY
          printf ("Set BAUD rate successful\n");
#endif
        }
        else
        {
#ifdef LWR_NOISY
          printf ("Could not set BAUD rate\n");
#endif
        }
#endif
        
#ifdef OLDSERIAL
        if (serial_->attach(serialData_))
        {
#ifdef LWR_NOISY
          printf ("serial connection to arm successful\n");
#endif
        }
        else
        {
#ifdef LWR_NOISY
          printf ("serial connection to arm failed\n");
#endif
        }
#else
        if (ulapi_serial_set_nonblocking(serialID_) == ULAPI_OK) //set_nonblocking
        {
#ifdef LWR_NOISY
          printf ("Set serial port blocking okay\n");
#endif
        }
        else
        {
#ifdef LWR_NOISY
          printf ("Could not set serial port blocking\n");
#endif
        }
        val = ulapi_serial_write(serialID_,
                                 "TBx 1.00000000 0.00000000 0.00000000 0.00000000 0.00000000",
                                 strlen("TBx 1.00000000 0.00000000 0.00000000 0.00000000 0.00000000"));
#endif        
      } // if (val == 1)
      else if (val == 2)
      {
        //! Use TCP
        serialUsed_ = false;
        in.getline(IPAddr_, 16);
        in >> val;

        server_ = ulapi_socket_get_client_id (val, IPAddr_);

        task = ulapi_task_new();
        ka_.handle = ulapi_mutex_new(99);
        ka_.rob = this;
        ka_.runThread = true;

        ulapi_task_start((ulapi_task_struct*)task, livemanLWR, &ka_, ulapi_prio_lowest(), 0);
      }
    } // if (initPath != NULL)
    else
    {
      //! Error: must define initialization path
    }
#else
    bool test;
    test = serialData_.setBaud (57600);
    test &= serialData_.setChannel (1);
    serialUsed_ = true;
#endif

    feedback_ = new double[6];
    tempData_ = new vector<string>(6, " ");
  }


  LIBRARY_API CrpiKukaLWR::~CrpiKukaLWR ()
  {
    delete [] mssgBuffer_;
    delete [] feedback_;
    if (serialUsed_)
    {
#ifdef OLDSERIAL
      serial_->closeConnection(serialData_);
#else
      ulapi_serial_close(serialID_);
      ulapi_serial_delete(serialID_);
#endif
    }
    else
    {
      ulapi_socket_close(server_);
    }
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetTool (double percent)
  {
    if (generateTool ('B', percent))
    {
      //! Send message to robot
      if (!send ())
      {
        //! error sending
        return CANON_FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        return CANON_FAILURE;
      }
      if (mssgBuffer_[0] == '1')
      {
        return CANON_SUCCESS;
      }
      else
      {
        return CANON_FAILURE;
      }
    }
    else
    {
      //! Error generating tool actuation message
      return CANON_FAILURE;
    }
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::Couple (const char *targetID)
  {
    if ((strcmp(targetID, "gripper_gear") == 0) || (strcmp(targetID, "gripper_top_cover") == 0) ||

      (strcmp(targetID, "gripper_bottom_cover") == 0))
    {
      generateTool('D', 7);
    }
    else if (strcmp (targetID, "gripper_parallel") == 0)
    {
      generateTool('D', 4);
    }
    else
    {
      return CANON_REJECT;
    }

    //! Send message to robot
    if (!send ())
    {
      //! error sending
      return CANON_FAILURE;
    }
    //! Wait for response from robot
    if (!get ())
    {
      return CANON_FAILURE;
    }
    if (mssgBuffer_[0] == '1')
    {
      return CANON_SUCCESS;
    }
    else
    {
      return CANON_FAILURE;
    }
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::Dwell (int *events, double *params, int numEvents)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! To Do
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::EndCanon (int reason)
  {
    acceptCRPI_ = false;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::InitCanon ()
  {
    acceptCRPI_ = true;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::Message (const char *message)
  {
    //! The KR C2 controller cannot display a message on the teach pendant, it seems
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::MoveStraightTo (robotPose pose)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct message
    vector<double> target;
    target.push_back (pose.x);
    target.push_back (pose.y);
    target.push_back (pose.z);
    target.push_back (pose.zrot);
    target.push_back (pose.yrot);
    target.push_back (pose.xrot);

    //! LIN, Cartesian, Absolute
    if (generateMove ('L', 'C', 'A', target))
    {
      //! Send message to robot
      if (!send ())
      {
        //! error sending
        return CANON_FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        return CANON_FAILURE;
      }
      if (mssgBuffer_[0] == '1')
      {
        return CANON_SUCCESS;
      }
      else
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


  LIBRARY_API CanonReturn CrpiKukaLWR::MoveThroughTo (robotPose *poses,
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


  LIBRARY_API CanonReturn CrpiKukaLWR::MoveTo (robotPose pose)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct message
    vector<double> target;
    target.push_back (pose.x);
    target.push_back (pose.y);
    target.push_back (pose.z);
    target.push_back (pose.zrot);
    target.push_back (pose.yrot);
    target.push_back (pose.xrot);

    //! PTP, Cartesian, Absolute
    //if (generateMove ('P', 'C', 'R', target)) //! JAM:  for initial testing purposes only
    if (generateMove ('P', 'C', 'A', target))
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
      if (mssgBuffer_[0] == '1')
      {
        return CANON_SUCCESS;
      }
      else
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


  LIBRARY_API CanonReturn CrpiKukaLWR::Decouple (const char *targetID)
  {
    //! Our LWR does not have an automatic tool changer or any coupling capabilities
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::GetRobotAxes (robotAxes *axes)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct request for axis information

    if (generateFeedback ('A'))
    {
      if (!send ())
      {
        //! error sending
        return CANON_FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        //! error receiving
        return CANON_FAILURE;
      }
      
      //! Parse data
      if (!parseFeedback ())
      {
        //! Error parsing data
        return CANON_FAILURE;
      }

      try
      {
        for (int i = 0; i < axes->axes; ++i)
        {
          axes->axis[i] = feedback_[i];
        }
      }
      catch (...)
      {
        //! probably an axis violation due to vector missmatch
        return CANON_FAILURE;
      }
    }
    else
    {
      //! Error generating feedback request message
      return CANON_FAILURE;
    }

    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::GetRobotPose (robotPose *pose)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct request for axis information
    if (generateFeedback ('C'))
    {
      if (!send ())
      {
        //! error sending
        return CANON_FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        //! error receiving
        return CANON_FAILURE;
      }
      //! Parse data
      if (!parseFeedback ())
      {
        //! Error parsing data
        return CANON_FAILURE;
      }

      try
      {
        pose->x = feedback_[0];
        pose->y = feedback_[1];
        pose->z = feedback_[2];
        pose->zrot = feedback_[3];
        pose->yrot = feedback_[4];
        pose->xrot = feedback_[5];
      }
      catch (...)
      {
        //! probably an axis violation due to vector missmatch
        return CANON_FAILURE;
      }
    }
    else
    {
      //! Error generating feedback request message
      return CANON_FAILURE;
    }

    return CANON_SUCCESS;
  }

  LIBRARY_API CanonReturn CrpiKukaLWR::GetRobotIO (robotIO *io)
  {
    //! TODO
    return CANON_FAILURE;
  }



  LIBRARY_API CanonReturn CrpiKukaLWR::MoveAttractor (robotPose pose)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct message
    vector<double> target;
    target.push_back (pose.x);
    target.push_back (pose.y);
    target.push_back (pose.z);
    target.push_back (pose.zrot);
    target.push_back (pose.yrot);
    target.push_back (pose.xrot);

    if (generateMove ('F', 'C', 'A', target))
    {
      //! Send message to robot
      if (!send ())
      {
        //! error sending
        return CANON_FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        return CANON_FAILURE;
      }
      if (mssgBuffer_[0] == '1')
      {
        return CANON_SUCCESS;
      }
      else
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


  LIBRARY_API CanonReturn CrpiKukaLWR::MoveToAxisTarget (robotAxes axes)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }
    //! Construct message
    vector<double> target;
    for (int i = 0; i < axes.axes; ++i)
    {
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


  LIBRARY_API CanonReturn CrpiKukaLWR::RunProgram (const char *programName, CRPIProgramParams params)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! TODO
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetAbsoluteAcceleration (double tolerance)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetAbsoluteSpeed (double speed)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }

//  ("degree" or "radian")
  LIBRARY_API CanonReturn CrpiKukaLWR::SetAngleUnits (const char *unitName)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetAxialSpeeds (double *speeds)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetAxialUnits (const char **unitNames)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetEndPoseTolerance (robotPose tolerances)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetLengthUnits (const char *unitName)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetParameter (const char *paramName, void *paramVal)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetRelativeAcceleration (double percent)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetRelativeSpeed (double percent)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::SetRobotIO (robotIO io)
  {
    //! TODO
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrpiKukaLWR::StopMotion (int condition)
  {
    if (!acceptCRPI_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }
  

  LIBRARY_API bool CrpiKukaLWR::generateMove (char moveType, char posType, char deltaType, vector<double> &input)
  {
    bool state = true;
    size_t found;
    int extension = 0,
        currLength = 0,
        i = 0,
        j = 0;

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

    //! Clear variables
    moveMe_.str(string());
    tempString_.str(string());

    if (moveType == 'F')
    {
      //! Overwrite any attempt to do joint angle force motion
      posType = 'C';
    }

    moveMe_ << moveType << posType << deltaType;

    //! Loop through paramaters, completes 10 char string, and adds to command string
    for (i = 0; i < 6 ; ++i)
    {
      //! Adds space delimiter and number to string
      moveMe_ << " ";
    
      tempString_.str(string());
      tempString_ << input[i];

      //! If number is an integer, add a decimal point
      found = tempString_.str().find('.');
      if (found == string::npos)
      {
        tempString_ << ".";
      }

      //! Add trailing 0s to decimal to create 10-char number string
      tempString_.seekg (0, ios::end);
      currLength = (int) tempString_.tellg ();

      for (j = currLength; j < 10; ++j)
      {
        tempString_ << "0";
      }

      moveMe_ << tempString_.str();
      moveMe_ << "\0";
    } // for (i = 0; i < 6; ++i)

    return true;
  }


  LIBRARY_API bool CrpiKukaLWR::generateTool (char mode, double value)
  {
    if (!(mode == 'B' || mode == 'A'  || mode == 'D'))
    {
      return false;
    }
    size_t found;
    int currLength, j;

    moveMe_.str(string());
    moveMe_ << 'T' << mode << "x ";

    //! Convert the input value to a character string of length 10
    tempString_.str(string());
    tempString_ << value;

    //! If number is an integer, add a decimal point
    found = tempString_.str().find('.');
    if (found == string::npos)
    {
      tempString_ << ".";
    }

    //! Add trailing 0s to decimal to create 10-char number string
    tempString_.seekg (0, ios::end);
    currLength = (int) tempString_.tellg ();

    for (j = currLength; j < 10; ++j)
    {
      tempString_ << "0";
    }

    moveMe_ << tempString_.str();
    moveMe_ << " 0.00000000 0.00000000 0.00000000 0.00000000 0.00000000\0";
    return true;
  }


  LIBRARY_API bool CrpiKukaLWR::generateFeedback (char retType)
  {
    if (retType != 'C' && retType != 'A' && retType != 'F' && retType != 'T' && retType != 'S')
    {
      //! Unsupported variable
      return false;
    }

    moveMe_.str(string());
    moveMe_ << retType;
    moveMe_ << "xx 0.00000000 0.00000000 0.00000000 0.00000000 0.00000000 0.00000000\0";
    return true;
  }


  LIBRARY_API bool CrpiKukaLWR::generateParameter (char paramType, char subType, vector<double> &input)
  {
    size_t found;
    int j = 0, currLength = 0;
    
    switch (paramType)
    {
    case 'A':
      //! JAM:  TODO
      if (subType == 'A')
      {
      }
      else if (subType == 'R')
      {
      }
      else
      {
        return false;
      }
      break;
    case 'S':
      if (subType == 'A')
      {
        if (input[0] > 2.0 || input[0] < 0.0)
        {
          return false;
        }
      }
      else if (subType == 'R')
      {
        if (input[0] > 100 || input[0] < 0)
        {
          return false;
        }
      }
      else
      {
        return false;
      }

      moveMe_.str (string());
      moveMe_ << 'V' << paramType << subType << " ";

      tempString_.str(string());
      tempString_ << input[0];

      //! If number is an integer, add a decimal point
      found = tempString_.str().find('.');
      if (found == string::npos)
      {
        tempString_ << ".";
      }

      //! Add trailing 0s to decimal to create 10-char number string
      tempString_.seekg (0, ios::end);
      currLength = (int) tempString_.tellg ();

      for (j = currLength; j < 10; ++j)
      {
        tempString_ << "0";
      }

      moveMe_ << tempString_ << " 0.00000000 0.00000000 0.00000000 0.00000000 0.00000000\0";

      break;
    default:
      return false;
    }
    
    return true;
  }

  
  LIBRARY_API bool CrpiKukaLWR::send ()
  {
    int x;
    
#ifdef LWR_NOISY
    printf ("Sending message %s\n", moveMe_.str().c_str());
    printf ("fflushhhhhh...\n");
#endif
    //fflush(NULL);
#ifdef LWR_NOISY
    printf ("flushed\n");
#endif
    if (serialUsed_)
    {
      //! Use Serial
#ifdef OLDSERIAL
#ifdef LWR_NOISY
    printf ("Sending...\n");
#endif
      serial_->sendData(moveMe_.str().c_str(), serialData_);
#ifdef LWR_NOISY
    printf ("Sent!\n");
#endif
#else
      x = ulapi_serial_write(serialID_, moveMe_.str().c_str(), strlen(moveMe_.str().c_str())+1);
#ifdef LWR_NOISY
      printf ("%i\n", x);
#endif
#endif
      return true;
    }
    else
    {
      //! Use TCP/IP
      x = ulapi_socket_write(server_, moveMe_.str().c_str(), strlen(moveMe_.str().c_str())+1);
#ifdef LWR_NOISY
      printf ("%i\n", x);
#endif
      return true;
    }
  }


  LIBRARY_API bool CrpiKukaLWR::get ()
  {
    int x = 0;

#ifdef LWR_NOISY
      printf ("getting feedback...\n");
#endif

    if (serialUsed_)
    {
      //! Use serial
#ifdef OLDSERIAL
      serial_->getData (mssgBuffer_, serialData_, 285);
#else
      x = ulapi_serial_read(serialID_, mssgBuffer_, 8192);
#endif
#ifdef LWR_NOISY
      printf ("%d %s read\n", x, mssgBuffer_);
#endif
      return true;
    }
    else
    {
      //! Use TCP/IP
      x = ulapi_socket_read(server_, mssgBuffer_, 8192);
#ifdef LWR_NOISY
      printf ("%d %s read\n", x, mssgBuffer_);
#endif
      return false;
    }
  }


  LIBRARY_API bool CrpiKukaLWR::parseFeedback ()
  {
    bool newItem = false;
    int index = -1, i;

    for (i = 0; i < 6; ++i)
    {
      tempData_->at(i) = "";
    }

    //! REQUEST_MSG_SIZE is very large, feedback from robot is limited to 65 characters
    for (i = 0; i < 65; ++i)
    {
      if (mssgBuffer_[i] == ' ')
      {
        newItem = false;
      }
      else
      {
        if (!newItem)
        {
          newItem = true;
          index++;
          if( index >= 6 )
          {
            return false;
          }
        }
        tempData_->at(index).push_back (mssgBuffer_[i]);
      } // if (mssgBuffer_[i] == ' ') ... else
    } //for (int i = 0; i < 65; ++i)
  
    //! Convert strings to floats
    for (i = 0; i < 6; ++i)
    {
      feedback_[i] = stod (tempData_->at(i));
    }
    return true;
  }

} // crpi_robot
