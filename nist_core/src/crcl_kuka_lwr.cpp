///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        crcl_kuka_lwr.cpp
//  Revision:        1.0 - 13 March, 2014
//                   1.1 - 16 June, 2014   Updated to use ulapi serial drivers
//  Author:          J. Marvel
//
//  Description
//  ===========
//  KUKA LWR 4+ interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "nist_core/crcl_kuka_lwr.h"
#include <fstream>

//#define STATIC_ //! Uncomment this line if you want to hard code the serial port (debugging purposes only)

using namespace std;

namespace crcl_robot
{
  LIBRARY_API CrclKukaLWR::CrclKukaLWR (char *initPath) :
    acceptCRCL_(false)
  {
    mssgBuffer_ = new char[8192];
    int val;
    ulapi_init();

#ifndef STATIC_
    //! Open configuration file
    if (initPath != NULL)
    {
      ifstream in(initPath);
      in >> val;

      if (val == 1)
      {
        //! Use serial
        in >> val;
        serialUsed_ = true;

        if (NULL == (serialID_ = ulapi_serial_new()))
        {
          printf ("\nCannot create serial object\n");
        }
        sprintf (COMChannel_, "COM%d", val);
        printf (COMChannel_);
        if (ulapi_serial_open(COMChannel_, serialID_) == ULAPI_OK)
        {
          printf ("\nOkay\n");
        }
        else
        {
          printf ("\nNope\n");
        }


        in >> val;

        if (ulapi_serial_baud(serialID_, val) == ULAPI_OK)
        {
          printf ("\nOkay\n");
        }
        else
        {
          printf ("\nNope\n");
        }

        if (ulapi_serial_set_blocking(serialID_) == ULAPI_OK)
        {
          printf ("\nOkay\n");
        }
        else
        {
          printf ("\nNope\n");
        }
      } // if (val == 1)
      else if (val == 2)
      {
        //! Use TCP
        //! TODO
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


  LIBRARY_API CrclKukaLWR::~CrclKukaLWR ()
  {
    delete [] mssgBuffer_;
    delete [] feedback_;
    if (serialUsed_)
    {
      ulapi_serial_close(serialID_);
      ulapi_serial_delete(serialID_);
    }
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetTool (double percent)
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


  LIBRARY_API CanonReturn CrclKukaLWR::Couple (char *targetID)
  {
    //! Our LWR does not have an automatic tool changer or any coupling capabilities
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::Dwell (int *events, double *params, int numEvents)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }
    //! To Do
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::EndCanon (int reason)
  {
    acceptCRCL_ = false;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::InitCanon ()
  {
    acceptCRCL_ = true;
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::Message (char *message)
  {
    //! The KR C2 controller cannot display a message on the teach pendant, it seems
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::MoveStraightTo (robotPose pose)
  {
    if (!acceptCRCL_)
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


  LIBRARY_API CanonReturn CrclKukaLWR::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    if (!acceptCRCL_)
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


  LIBRARY_API CanonReturn CrclKukaLWR::MoveTo (robotPose pose)
  {
    if (!acceptCRCL_)
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


  LIBRARY_API CanonReturn CrclKukaLWR::Decouple (char *targetID)
  {
    //! Our LWR does not have an automatic tool changer or any coupling capabilities
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::GetRobotAxes (robotAxes *axes)
  {
    if (!acceptCRCL_)
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


  LIBRARY_API CanonReturn CrclKukaLWR::GetRobotPose (robotPose *pose)
  {
    if (!acceptCRCL_)
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


  LIBRARY_API CanonReturn CrclKukaLWR::MoveAttractor (robotPose pose)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::MoveToAxisTarget (robotAxes axes)
  {
    if (!acceptCRCL_)
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


  LIBRARY_API CanonReturn CrclKukaLWR::RunProgram (char *programName, CRCLProgramParams params)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! TODO
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetAbsoluteAcceleration (double tolerance)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetAbsoluteSpeed (double speed)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }

//  ("degree" or "radian")
  LIBRARY_API CanonReturn CrclKukaLWR::SetAngleUnits (char *unitName)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetAxialSpeeds (double *speeds)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetAxialUnits (char **unitNames)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetEndPoseTolerance (robotPose tolerances)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return CANON_SUCCESS;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetLengthUnits (char *unitName)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetParameter (char *paramName, void *paramVal)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetRelativeAcceleration (double percent)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::SetRelativeSpeed (double percent)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }


  LIBRARY_API CanonReturn CrclKukaLWR::StopMotion (int condition)
  {
    if (!acceptCRCL_)
    {
      return CANON_REJECT;
    }

    //! Not yet implemented
    return CANON_REJECT;
  }
  

  LIBRARY_API bool CrclKukaLWR::generateMove (char moveType, char posType, char deltaType, vector<double> &input)
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
    } // for (i = 0; i < 6; ++i)

    return true;
  }


  LIBRARY_API bool CrclKukaLWR::generateTool (char mode, double value)
  {
    if (!(mode == 'B' || mode == 'A'  || mode == 'S') || (value > 1.0f || value < 0.0f))
    {
      //! Value must be between 0 and 1
      return false;
    }
    size_t found;
    int currLength, j;

    moveMe_.str(string());
    moveMe_ << 'T' << mode << "? ";

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
    moveMe_ << " 0.00000000 0.00000000 0.00000000 0.00000000 0.00000000";
    return true;
  }


  LIBRARY_API bool CrclKukaLWR::generateFeedback (char retType)
  {
    if (retType != 'C' && retType != 'A' && retType != 'F' && retType != 'T' && retType != 'S')
    {
      //! Unsupported variable
      return false;
    }

    moveMe_.str(string());
    moveMe_ << retType;
    moveMe_ << "?? 0.00000000 0.00000000 0.00000000 0.00000000 0.00000000 0.00000000";
    return true;
  }


  LIBRARY_API bool CrclKukaLWR::send ()
  {
    int x;
      //! Send message to robot via serial
      if (serialUsed_)
      {
        printf ("Sending message %s\n", moveMe_.str().c_str());
        x = ulapi_serial_write(serialID_, moveMe_.str().c_str(), strlen(moveMe_.str().c_str()) + 1);
        printf ("%i\n", x);
        return true;
      }
      else
      {
        //! TODO
        return false;
      }
  }


  LIBRARY_API bool CrclKukaLWR::get ()
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


  LIBRARY_API bool CrclKukaLWR::parseFeedback ()
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

} // crcl_robot
