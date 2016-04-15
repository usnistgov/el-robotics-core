// Controller.h

/*
 * DISCLAIMER:
 * This software was produced by the National Institute of Standards
 * and Technology (NIST), an agency of the U.S. government, and by statute is
 * not subject to copyright in the United States.  Recipients of this software
 * assume all responsibility associated with its operation, modification,
 * maintenance, and subsequent redistribution.
 *
 * See NIST Administration Manual 4.09.07 b and Appendix I.
 */

#pragma once
#include <boost/shared_ptr.hpp>
#include <list>

#include "AsioCrclServer.h"
#include "RCSThreadTemplate.h"
#include "CrclInterface.h"
#include "RCSInterpreter.h"
#include "ChainRobotModel.h"
#include "Trajectory.h"
#include "Communication.h"
#include "moveit.h"
#include "RvizMarker.h"
namespace RCS {

    extern boost::mutex cncmutex;

    /**
     * \brief The CController provides a collection for all the relevant controller pieces.
     *  The CController is the main controller class to collect all the references/pointers to instances in the project.
     * A global instance of this class, called "Controller", is created and is used throughout the code to reference various instances of 
     * control objects (e.g., kinematics, joint writer, joint reader, etc.)
     *
     */
    struct CController : public RCS::Thread {
        typedef std::list<RCS::CanonCmd> xml_message_list;

        /*!
         * \brief CController constructor that requires a cycle time for RCS thread timing.
         * \param cycletime  in seconds.
         */
        CController(double cycletime);

        ~CController(void);
        static bool bSimulation; /**< simulation flag - not connected to robot */
        static RCS::CanonWorldModel wm; /**< the world model of the controller */
        static RCS::CanonWorldModel status; /**< current status of controller */
        static RCS::CanonWorldModel laststatus; /**< last status of controller */
        static RCS::CMessageQueue<RCS::CanonCmd> cmds; /**< queue of commands interpreted from Crcl messages */
        static xml_message_list donecmds; /**< list of commands interpreted from Crcl messages that have completed*/
        static RCS::CMessageQueue<RCS::CanonCmd> robotcmds; /**< list of commands to be sent to robot */
        static size_t _NumJoints; /**< number of joints in controller robot - assuming serial link manipulator */
        static bool bGenerateProgram; /**< global flag to create program from Crcl XML */
        /*!
         *\brief Verifies that all the pointer references in the controller have been instantiated (i.e., not null).
         */
        bool Verify();

        /*!
         *\brief Cyclic loop for the controller. Reads Crcl input mexsage queue, interprets into canon cmds if any, reads canon
         * cmds queue, interprets into robot command messages.
         */
        virtual int Action();

        /*!
         *\brief Initialization routine for the controller..
         */
        virtual void Init();

        /*!
         *\brief Creates a comma separated string of current state of robot. (Can use other separator). 
         */
        std::string Dump(std::string separator = ",");

        /*!
         *\brief Creates a header line containing names of comma separated string fields that describes the current state of robot. (Can use other separator). 
         */
        std::string DumpHeader(std::string separator = ",");

        NVAR(CrclDelegate, boost::shared_ptr<Crcl::CrclDelegateInterface>, crclinterface);
        VAR(Kinematics, boost::shared_ptr<IKinematics>);
        VAR(TrajectoryModel, boost::shared_ptr<CTrajectory>);
        VAR(JointWriter, boost::shared_ptr<CJointWriter>);
        VAR(MoveitPlanner, boost::shared_ptr<MoveitPlanning>);
        VAR(RvizMarker, boost::shared_ptr<CRvizMarker> )
        VAR(EEPoseReader, boost::shared_ptr<CLinkReader> )

        /*!
         *\brief Routine to set the kinematics reference pointer. Uses the interface class IKinematics, but can have any implementation instance. 
         */
        void SetKinematics(boost::shared_ptr<IKinematics> k) {
            Kinematics() = k;
            _interpreter._kinematics = k;
        }

        RCSInterpreter _interpreter; /**<  interprets canon commands into robot commands */

        /**<  current new canon command to interpret*/
        NVAR(NewCC, RCS::CanonCmd, _newcc);

        /**<  last canon command interpreted */
        NVAR(LastCC, RCS::CanonCmd, _lastcc);

        //RCS::CanonCmd _newcc; /**<  current new canon command to interpret*/
        //RCS::CanonCmd _lastcc; /**<  last canon command interpreted */
        RCS::CanonCmd GetLastRobotCommand();

        /*!
         *\brief Get the last joint state, if no motion, last actual joint reading, else last joints on robot motion queue. 
         */
        JointState GetLastJointState();

        /*!
         *\brief Get the last commanded , if no motion, use last actual joint reading to compute FK, 
         * else use last joints on robot motion queue to compute FK. 
         */
        RCS::Pose GetLastCommandedPose();


        std::string lastlogstatus;
        static std::vector<std::string> links;

        enum DebugLevel {
            FATAL = 0, WARNING = 2, INFORM = 4, FULL = 5
        }; // ERROR, DEBUG #defines

        enum DebugType {
            CRCL = 0, RPY
        };
        static unsigned long _debugtype; /**<  output crcl xz rotation or roll,pitch, yaw */
        static unsigned long _debuglevel; /**<  level of debugging, 0 least, 5 most */
        static unsigned long _csvlogFlag;
        static ALogger CsvLogging; /**< controller status csv logging instance */

        enum MotionPlannerEnum {
            NOPLANNER = 0, MOVEIT, DESCARTES, BASIC, WAYPOINT, GOMOTION
        };
        MotionPlannerEnum eCartesianMotionPlanner; /**< type of cartesian motion to use */
        MotionPlannerEnum eJointMotionPlanner; /**< type of joint motion to use */
    };
    extern CController Controller; /**< global declaration of ONE controller */

    //* The RobotCommands is currently a dummy class. The CController thread 

    /**
     * \brief  The RobotStatus is a thread that reads the status of the robot and updates the world model. 
     * The RobotStatus is a separate thread that reads the robot status using ROS communication mechanisms
     * and updates the controller world model based on these values.
     * Currently, it uses an instance of the class JointReader to read joint values from the controller. 
     * It uses a Kinematics pointer reference to compute the current robot pose 
     * using the forward kinematics (FK) routine.
     * It also uses a CrclDelegate pointer reference to update the status reported by CRCL.
     */
    class RobotStatus : public RCS::Thread {
    public:

        /*!
         * \brief RobotStatus constructor that requires a cycle time for RCS thread timing.
         * \param cycletime  in seconds.
         */
        RobotStatus(double cycletime = DEFAULT_LOOP_CYCLE);

        NVAR(CrclDelegate, boost::shared_ptr<Crcl::CrclDelegateInterface>, _crclinterface);
        VAR(JointReader, boost::shared_ptr<CJointReader>);
        VAR(Kinematics, boost::shared_ptr<IKinematics>);

        /*!
         * \brief Action is the main loop in the RCS thread timing.
         * Get latest robot joint readings. Use forward kinematics to get current pose.
         * Then, updates the CRCL world model with the latest readings. 
         * \fixme Should it keep track of the command id also - in theory only one CRCl command at a time.
         */
        virtual int Action();

        /*!
         * \brief method to determine if the instance is valid, i.e., has all reference pointers.
         * \return boolean to signify whether component is valid.
         */
        bool Verify() {
            assert(CrclDelegate() != NULL);
            assert(JointReader() != NULL);
            assert(Kinematics() != NULL);
        }
    };

    /**
     * \brief  The RobotProgram is a thread to handle crcl programs.
     * Crcl programs are not in fact legitimate, however, debugging and verification are assisted by programs.
     * However, program as in the Crcl XSD specification, so it doesn't hurt to handle.
     * They require special handling as only one command should be done at a time.
     * Uses codesynthesis to parse Crcl xml into C++ data structures.
     */
    class RobotProgram : public RCS::Thread {
    public:

        /*!
         * \brief RobotProgram constructor that requires a cycle time for RCS thread timing.
         * \param cycletime  in seconds.
         */
        RobotProgram(double cycletime = DEFAULT_LOOP_CYCLE);

        /*!
         * \brief ExecuteProgramFromFile reads a file path for CRCL XML program. 
         * It will set up interpreting the program. It is thread safe.
         * \param programpath  path of file containing crcl xml program.
         */
        virtual void ExecuteProgramFromFile(std::string programpath);
        
        /*!
         * \brief ExecuteProgram reads and interprets a CRCL XML program string. 
         * It will set up interpreting the program. It is thread safe.
         * \param programpath  str containing crcl xml program.
         */        
        virtual void ExecuteProgram(std::string programstr);

        /*!
         * \brief  Action is the main loop in the RobotProgram RCS thread.
         * 
         * Executes one program command at a time. \fixme needs to wait until current
         * command is done before moving on to next command.
         */
        virtual int Action();
        //////////////////////////////////////
        static boost::mutex _progmutex; /**< mutex for thread safe access to RobotProgram commands  */
        std::string _programname; /**< saved RobotProgram program file path  */
        Crcl::CrclDelegateInterface _delegate; /**< crcl delegate used to interpret Crcl XML command  */
        std::istringstream istr; /**< input stream interface for codesynthesis parsing */
        //int cmdnum; /**< index of Crcl XML command to execute */
        //int lastcmdnum; /**< last index of Crcl XML command to execute */
        ::CRCLProgramType::MiddleCommand_sequence& cmds; /**< reference to crcl program XML commands (from codesynthesis parsing)  */
    };
}
