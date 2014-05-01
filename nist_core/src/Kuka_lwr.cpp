///////////////////////////////////////////////////////////////////////////////
//
//  Original System: ISD CRCL
//  Subsystem:       Robot Interface
//  Workfile:        Kuka_lwr.cpp
//  Revision:        1.0 - 13 March, 2014
//  Author:          J. Marvel
//
//  Description
//  ===========
//  KUKA LWR 4+ interface definitions.
//
///////////////////////////////////////////////////////////////////////////////

#include "Kuka_lwr.h"
#include "xml.h"
#include <fstream>

//#define STATIC_ //! Uncomment this line if you want to hard code the serial port (debugging purposes only)

using namespace std;
using namespace Xml;

namespace Robot
{
  LIBRARY_API Kuka_LWR::Kuka_LWR (char *initPath) :
    acceptCRCL_(false)
  {
    mssgBuffer_ = new char[REQUEST_MSG_SIZE];

    //! XML parser 
    KukaLWRParse kp(&serialData_, &socketData_);
    XmlParse<KukaLWRParse> xml(&kp);
    ifstream in;
    char buffer[256];
    
#ifndef STATIC_
    //! Open configuration XML file
    if (initPath != NULL)
    {
      in.open(initPath);
      while (in.getline (buffer, 256))
      {
        xml.parse(buffer);
      }
      in.close ();
    }
    //! Determine if Serial or Socket communication
    serialUsed_ = serialData_.defined;
#else
    bool test;
    test = serialData_.setBaud (57600);
    test &= serialData_.setChannel (1);
    serialUsed_ = true;
#endif

    //! Create socket/serial connection
    if (serialUsed_)
    {
      serial_ = new serial (NULL);
      if (serial_->attach(serialData_))
      {
        //! Connected
      }
      else
      {
        //! Failed to connect
      }
    }
    else
    {
      //! TODO:  Socket communication
    }

    feedback_ = new double[6];
    tempData_ = new vector<string>(6, " ");
  }


  LIBRARY_API Kuka_LWR::~Kuka_LWR ()
  {
    delete [] mssgBuffer_;
    delete [] feedback_;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetTool (double percent)
  {
    if (generateTool ('B', percent))
    {
      //! Send message to robot
      if (!send ())
      {
        //! error sending
        return FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        return FAILURE;
      }
      if (mssgBuffer_[0] == '1')
      {
        return SUCCESS;
      }
      else
      {
        return FAILURE;
      }
    }
    else
    {
      //! Error generating tool actuation message
      return FAILURE;
    }
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::Couple (char *targetID)
  {
    //! Our LWR does not have an automatic tool changer or any coupling capabilities
    return REJECT;
  }


  LIBRARY_API CanonReturn Kuka_LWR::Dwell (int *events, double *params, int numEvents)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! To Do
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::EndCanon (int reason)
  {
    acceptCRCL_ = false;
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::InitCanon ()
  {
    acceptCRCL_ = true;
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::Message (char *message)
  {
    //! The KR C2 controller cannot display a message on the teach pendant, it seems
    return REJECT;
  }


  LIBRARY_API CanonReturn Kuka_LWR::MoveStraightTo (robotPose pose)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
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
        return FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        return FAILURE;
      }
      if (mssgBuffer_[0] == '1')
      {
        return SUCCESS;
      }
      else
      {
        return FAILURE;
      }
    }
    else
    {
      //! Error generating motion message
      return FAILURE;
    }

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::MoveThroughTo (robotPose *poses,
                                                   int numPoses,
                                                   robotPose *accelerations,
                                                   robotPose *speeds,
                                                   robotPose *tolerances)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }

    bool status = true;

    //! This is a temporary function definition until the KRL code has been updated to properly handle
    //! this method
    for (int x = 0; x < numPoses; ++x)
    {
      status &= (MoveTo (poses[x]) == SUCCESS);
      if (!status)
      {
        //! Error when executing multi move
        return FAILURE;
      }
    }

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::MoveTo (robotPose pose)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
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
        return FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        return FAILURE;
      }
      if (mssgBuffer_[0] == '1')
      {
        return SUCCESS;
      }
      else
      {
        return FAILURE;
      }
    }
    else
    {
      //! Error generating motion message
      return FAILURE;
    }

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::Decouple (char *targetID)
  {
    //! Our LWR does not have an automatic tool changer or any coupling capabilities
    return REJECT;
  }


  LIBRARY_API CanonReturn Kuka_LWR::GetRobotAxes (robotAxes *axes)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! Construct request for axis information

    if (generateFeedback ('A'))
    {
      if (!send ())
      {
        //! error sending
        return FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        //! error receiving
        return FAILURE;
      }
      
      //! Parse data
      if (!parseFeedback ())
      {
        //! Error parsing data
        return FAILURE;
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
        return FAILURE;
      }
    }
    else
    {
      //! Error generating feedback request message
      return FAILURE;
    }

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::GetRobotPose (robotPose *pose)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! Construct request for axis information

    if (generateFeedback ('C'))
    {
      if (!send ())
      {
        //! error sending
        return FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        //! error receiving
        return FAILURE;
      }
      
      //! Parse data
      if (!parseFeedback ())
      {
        //! Error parsing data
        return FAILURE;
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
        return FAILURE;
      }
    }
    else
    {
      //! Error generating feedback request message
      return FAILURE;
    }

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::MoveAttractor (robotPose pose)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! TODO
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::MoveToAxisTarget (robotAxes axes)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
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
        return FAILURE;
      }
      //! Wait for response from robot
      if (!get ())
      {
        return FAILURE;
      }
    }
    else
    {
      //! Error generating motion message
      return FAILURE;
    }

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::RunProgram (char *programName, CRCLProgramParams params)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }

    //! TODO
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetAbsoluteAcceleration (double tolerance)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! Construct message
    //! TODO

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetAbsoluteSpeed (double speed)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! Construct message
    //! TODO

    return SUCCESS;
  }

//  ("degree" or "radian")
  LIBRARY_API CanonReturn Kuka_LWR::SetAngleUnits (char *unitName)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! Construct message
    //! TODO

    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetAxialSpeeds (double *speeds)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! TODO
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetAxialUnits (char **unitNames)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetEndPoseTolerance (robotPose tolerances)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetIntermediatePoseTolerance (robotPose *tolerances)
  {
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetLengthUnits (char *unitName)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //("inch," "mm," and "meter")
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetParameter (char *paramName, void *paramVal)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! TODO
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetRelativeAcceleration (double percent)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! TODO
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::SetRelativeSpeed (double percent)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    return SUCCESS;
  }


  LIBRARY_API CanonReturn Kuka_LWR::StopMotion (int condition)
  {
    if (!acceptCRCL_)
    {
      return REJECT;
    }
    //! TODO
    return SUCCESS;
  }
  

  LIBRARY_API bool Kuka_LWR::generateMove (char moveType, char posType, char deltaType, vector<double> &input)
  {
    bool state = true;
    size_t found;
    int extension = 0,
        currLength = 0,
        i = 0,
        j = 0;

    //! Check validity of inputs...
    //!   Check movement type
    state &= (moveType == 'P' || moveType == 'L');
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


  LIBRARY_API bool Kuka_LWR::generateTool (char mode, double value)
  {
    if (!(mode == 'B' || mode == 'A') || (value > 1.0f || value < 0.0f))
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


  LIBRARY_API bool Kuka_LWR::generateFeedback (char retType)
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


  LIBRARY_API bool Kuka_LWR::send ()
  {
      //! Send message to robot via serial
      if (serialUsed_)
      {
        //! Send message
        return serial_->sendData (moveMe_.str().c_str(), serialData_);
      }
      else
      {
        //! TODO
        return false;
      }
  }

  LIBRARY_API bool Kuka_LWR::get ()
  {
    if (serialUsed_)
    {
      return serial_->getData (mssgBuffer_, serialData_);
    }
    else
    {
      //! TODO
      return false;
    }
  }


  LIBRARY_API bool Kuka_LWR::parseFeedback ()
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

} // Robot
