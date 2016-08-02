
#include <boost/format.hpp>
#include "nist_fanuc.h"
#include <string>
#include "sys/stat.h"
#include "fcntl.h"
#include <iostream>
#include <sstream>

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/XMLGrammarPoolImpl.hpp>

#include "MotionControl.h"
#include "AsioCrclServer.h"
#include "Globals.h"
#include "Controller.h"
#include "CrclInterface.h"
#include "Kinematics.h"
#include "Communication.h"
#include "Setup.h"

#include <ros/package.h>
#include "RvizMarker.h"
// /opt/ros/indigo/include/moveit/robot_state/robot_state.h
// /opt/ros/indigo/include/moveit/move_group_interface/move_group.h

int main(int argc, char** argv) {
    
        // Current robot joints declaration
        sensor_msgs::JointState cjoints;
        
        try {
        // Initialize xercesc used by code synthesis to parse CRCL XML
        xercesc::XMLPlatformUtils::Initialize();
        
        // Find path of executable
        std::string path(argv[0]);
        Globals.ExeDirectory = path.substr(0, path.find_last_of('/') + 1);
        Globals._appproperties["ExeDirectory"] = Globals.ExeDirectory;
        
        // This sets up some application name/value pairs: user, hostname
        SetupAppEnvironment();
        
        // Controller shared objects dependent on ROS - many with abstract interface definition
        boost::shared_ptr<CJointReader>jointReader;
        boost::shared_ptr<CJointWriter>jointWriter;
        boost::shared_ptr<IKinematics> kin;
        boost::shared_ptr<MoveitPlanning> moveitPlanner;
        boost::shared_ptr<RCS::RobotProgram> crclProgramInterpreter;
        boost::shared_ptr<CRvizMarker> pRvizMarker;
        boost::shared_ptr<CLinkReader> pLinkReader;


        // Controller shared objects NOT dependent on ROS 
        boost::shared_ptr<Crcl::CrclDelegateInterface> crcl;
        
        //SetupRosEnvironment - needs to go before ROS!
        SetupRosEnvironment("");
        
        // Initialize ROS
        ros::init(argc, argv, "nist_fanuc");
        ros::NodeHandle nh;
        ros::Rate r(50);  // 10 times a second - 10Hz

        //  Required for multithreaded ROS communication  NOT TRUE: if not ros::spinOnce
        ros::AsyncSpinner spinner(1);
        spinner.start();
  
 
        // This is useful for rosbag i suppose
        //        std::string run_id;
        //        nh.getParam("run_id", run_id);
        //        std::cout << run_id.c_str() << std::endl;

        // ROS config - parameter list - save for comparison later
        std::string params = ReadRosParams(nh);
        Globals.WriteFile(Globals.ExeDirectory + "rosconfig.txt", params);
        path = ros::package::getPath("nist_fanuc");
        Globals._appproperties["nist_fanuc"] = path;
#if 1
        // This sets up the `env` so that ROS can run - has too many hardwired dependencies
        SetupRosEnvironment(path);
#endif
        // Controller instantiatio of shared objects  - dependent on ROS
        jointReader = boost::shared_ptr<CJointReader>(new CJointReader(nh));
        jointWriter = boost::shared_ptr<CJointWriter>(new CJointWriter(nh));
        kin = boost::shared_ptr<IKinematics>(new MoveitKinematics(nh));
        pRvizMarker= boost::shared_ptr<CRvizMarker>(new CRvizMarker(nh));
        pRvizMarker->Init();
        moveitPlanner = boost::shared_ptr<MoveitPlanning>(new MoveitPlanning(nh));
        pLinkReader = boost::shared_ptr<CLinkReader>(new CLinkReader(nh));

        // Controller instantiatio of shared objects - NOT dependent on ROS
        crcl = boost::shared_ptr<Crcl::CrclDelegateInterface>(
                new Crcl::CrclDelegateInterface());

        boost::shared_ptr<CTrajectory> traj = boost::shared_ptr<CTrajectory> (new CTrajectory());
        // Descarte trajectory writer - uses action lib
        //boost::shared_ptr<CTrajectoryWriter> trajWriter = boost::shared_ptr<CTrajectoryWriter>(new CTrajectoryWriter(traj));
  
        // Initializatin of Controller instantiatio of shared objects  
        kin->Init(std::string("manipulator"), std::string("tool0"));

        // CRCl Communication handler - bundles xml into messages
        CAsioCrclServer crclServer(myios);
        CAsioCrclServer::_bTrace = false;
        
        // This initializes the asio crcl socket listener, in theory N clients can connect. Only 1 tested.
        crclServer.Init("127.0.0.1", 64444, "Command GUI");
        
        // Logger
        LogFile.Open(Globals.ExeDirectory + "logfile.log");
        LogFile.DebugLevel() = 5;
        LogFile.Timestamping() = true;
        
        RCS::CController::CsvLogging.Open(Globals.ExeDirectory + "logfile.csv");
        RCS::CController::CsvLogging.DebugLevel() = 5;
        RCS::CController::_debugtype = (unsigned long) RCS::CController::CRCL;

        // Initialize Controller...
        RCS::Controller._NumJoints = 6; // hard code even thought chainrobotmodel will work
        RCS::Controller.status.Init();

        // The crcl thread waits for and handles new XML messages received from  crcl asio socket.
        // It decodes the CRCL gross motion messages and creates gross robot motion commands
        // to be put on motion Q to be interpreted by RCSInterpreter.
        // The gross motion commands are then put through a trajectory generate inside
        // of the rcs interpreter, which creates a list of fine trajectory motions.
        // Who handles the list of fine trajectory motions.
        // The actual "Controller" handles the fine motion trajectories.
        RCS::Controller.CrclDelegate() = crcl;
        RCS::Controller.CrclDelegate()->SetAngleUnits("DEGREE"); // NOT PRE SPEC
        RCS::Controller.CycleTime() = DEFAULT_LOOP_CYCLE;
        

        RCS::Controller.Kinematics() = kin;
        //        RCS::Controller.TrajectoryWriter() = trajWriter;
        RCS::Controller.JointWriter() = jointWriter;
        RCS::Controller.RvizMarker()= pRvizMarker;
        RCS::Controller.EEPoseReader()= pLinkReader;

        // fix me: read actual robot model and use.
        RCS::Controller.links.push_back("/base_link");
        RCS::Controller.links.push_back("/tool0");

        RCS::Controller.MoveitPlanner() = moveitPlanner;
        RCS::Controller.eCartesianMotionPlanner = RCS::CController::BASIC;
        RCS::Controller.eJointMotionPlanner = RCS::CController::BASIC;
        // RCS::CController::MOVEIT;  NOPLANNER=0, MOVEIT, DESCARTES, BASIC, WAYPOINT, GOMOTION         
        RCS::CController::bGenerateProgram = true;
       
#define INITJOINTCONTROLLER
#ifdef INITJOINTCONTROLLER
        // Read latest values, dont start until they are read
        jointReader->Start();
        cjoints = jointReader->GetCurrentReadings();
        while (cjoints.position.size() == 0) {
            //ros::spinOnce();
            cjoints = jointReader->GetCurrentReadings();
            Globals.Sleep(100);
            //r.sleep();
            std::cout << "." << std::flush;
        }
        std::cout << "\nCurrent joints=" << VectorDump<double> (cjoints.position).c_str();
        
        // Store current joint values
        //RosKinematics kin;
        RCS::Controller.status.currentjoints = cjoints;
        std::cout << "Current=" << VectorDump<double> (RCS::Controller.status.currentjoints.position).c_str();
        RCS::Controller.status.currentpose = kin->FK(RCS::Controller.status.currentjoints.position);
        std::cout << DumpPose(RCS::Controller.status.currentpose).c_str();
        RCS::Controller.CrclDelegate()->crclwm.Update(RCS::Controller.status.currentpose);
        RCS::Controller.CrclDelegate()->crclwm.Update(RCS::Controller.status.currentjoints);

        LogFile.LogFormatMessage ("Starting current joints=%s", DumpJoints(cjoints).c_str()); 
        LogFile.LogFormatMessage ("Starting current pose=%s", DumpPose(RCS::Controller.status.currentpose).c_str()); 

        // Removed chained robot model from exe - overkill
        //RCS::Controller.robot_model.RdfFromXmlFile(Globals.ExeDirectory + "lrmate200id.urdf");
#endif
        
#if DESCARTES
        // INitialize this if you are using Descartes
        // Create a robot model and initialize trajectory with it
        const std::string robot_description = "robot_description";
        const std::string group_name = "manipulator"; // name of the kinematic group
        const std::string world_frame = "/base_link"; // Name of frame in which you are expressing poses.
        const std::string tcp_frame = "tool0"; // tool center point frame
        std::vector<std::string> names;
        nh.getParam("controller_joint_names", names);
        RCS::Controller.TrajectoryModel() = traj;
        RCS::Controller.TrajectoryModel()->Init(robot_description, group_name, world_frame, tcp_frame, names);
#endif

#define ROBOTSTATUS
#ifdef ROBOTSTATUS
        RCS::RobotStatus robotstatus;
        robotstatus.CrclDelegate() = crcl;
        robotstatus.Kinematics() = kin;
        robotstatus.JointReader() = jointReader;
        robotstatus.CycleTime() = DEFAULT_LOOP_CYCLE;
#endif
         //#ifdef WIN32
        //		if (!SetConsoleCtrlHandler(consoleHandler, TRUE)) throw std::exception("Could not set console ctrl handler");
        //#endif

        jointWriter->Start();
        robotstatus.Start(); // start the controller status thread

        RCS::Controller.Start(); // start the Controller Session thread
        
#define BOOSTASIO
#ifdef BOOSTASIO
        CAsioCrclServer::_bTrace=true;
        crclServer.Start();
        // start the asio ioserver in a separate thread - kill using stop())
        //boost::thread bt(boost::bind(&boost::asio::io_service::run, &myios));
#endif
        
        // Prime the pump with some CRCL XML
        std::string contents;
        std::string testprog = Globals._appproperties["nist_fanuc"] + "/doc/fanuclrmateprogram.xml";
        crclProgramInterpreter = boost::shared_ptr<RCS::RobotProgram>(new RCS::RobotProgram(1));
        //crclProgramInterpreter->ExecuteProgramFromFile(testprog);
        //crclProgramInterpreter->Start(); 
        //Globals.ReadFile(testprog, contents);
        //RCS::Controller.CrclDelegate()->DelegateCRCLCmd(contents);

        spinner.stop();
        ros::spinOnce();
        do {
            myios.run_one();
            ros::spinOnce();
            myios.run_one();
            r.sleep();
        } while(ros::ok());
        
#if 0
        while (ros::ok()) { //ros::ok()) {
            // This allows asio to run in background - Never ends
            std::cout << "." << std::flush;
            boost::this_thread::yield();
            Globals.Sleep(1000);
            //myios.run_one();
        }
#endif
        std::cout << "Cntrl C pressed \n"<< std::flush;
        
#ifdef BOOSTASIO
        crclServer.Stop();
#endif
        // ^C pressed - stop all threads or will hang
        if(jointReader) 
            jointReader->Stop(); // unsubscribe
         if(jointWriter) 
            jointWriter->Stop(); // unpusblish
       RCS::Thread::StopAll(); // includes thread for Controller, robotstatus
#ifdef BOOSTASIO
        myios.stop();
#endif
    } catch (std::exception e) {
        Logger.Fatal(Logger.StrFormat("%s%s\n", "Abnormal exception end to  CRCL2Robot", e.what()));
    } catch (...) {
        Logger.Fatal("Abnormal exception end to  CRCL2Robot\n");
    }
    xercesc::XMLPlatformUtils::Terminate();
    ros::shutdown();
    return 0;
}


#if 0
// Initialize ROS
ros::init(argc, argv, "descartes_tutorial");
ros::NodeHandle nh;

// Required for communication with moveit components
ros::AsyncSpinner spinner(1);
spinner.start();

// 1. Define sequence of points
TrajectoryVec points;
for (unsigned int i = 0; i < 10; ++i) {
    Eigen::Affine3d pose;
    pose = Eigen::Translation3d(0.0, 0.0, 1.0 + 0.05 * i);
    descartes_core::TrajectoryPtPtr pt = makeTolerancedCartesianPoint(pose);
    points.push_back(pt);
}

for (unsigned int i = 0; i < 5; ++i) {
    Eigen::Affine3d pose;
    pose = Eigen::Translation3d(0.0, 0.04 * i, 1.3);
    descartes_core::TrajectoryPtPtr pt = makeTolerancedCartesianPoint(pose);
    points.push_back(pt);
}

// 2. Create a robot model and initialize it
descartes_core::RobotModelPtr model(new descartes_moveit::MoveitStateAdapter);

// Name of description on parameter server. Typically just "robot_description".
const std::string robot_description = "robot_description";

// name of the kinematic group you defined when running MoveitSetupAssistant
const std::string group_name = "manipulator";

// Name of frame in which you are expressing poses. Typically "world_frame" or "base_link".
const std::string world_frame = "base_link";

// tool center point frame (name of link associated with tool)
const std::string tcp_frame = "tool0";

if (!model->initialize(robot_description, group_name, world_frame, tcp_frame)) {
    ROS_INFO("Could not initialize robot model");
    return -1;
}

// 3. Create a planner and initialize it with our robot model
descartes_planner::DensePlanner planner;
planner.initialize(model);

// 4. Feed the trajectory to the planner
if (!planner.planPath(points)) {
    ROS_ERROR("Could not solve for a valid path");
    return -2;
}

TrajectoryVec result;
if (!planner.getPath(result)) {
    ROS_ERROR("Could not retrieve path");
    return -3;
}

// 5. Translate the result into a type that ROS understands
// Get Joint Names
std::vector<std::string> names;
nh.getParam("controller_joint_names", names);
// Generate a ROS joint trajectory with the result path, robot model, given joint names,
// a certain time delta between each trajectory point
trajectory_msgs::JointTrajectory joint_solution = toROSJointTrajectory(result, *model, names, 1.0);

// 6. Send the ROS trajectory to the robot for execution
if (!executeTrajectory(joint_solution)) {
    ROS_ERROR("Could not execute trajectory!");
    return -4;
}

// Wait till user kills the process (Control-C)
ROS_INFO("Done!");

return 0;
}

descartes_core::TrajectoryPtPtr makeCartesianPoint(const Eigen::Affine3d& pose) {
    using namespace descartes_core;
    using namespace descartes_trajectory;

    return TrajectoryPtPtr(new CartTrajectoryPt(TolerancedFrame(pose)));
}

descartes_core::TrajectoryPtPtr makeTolerancedCartesianPoint(const Eigen::Affine3d& pose) {
    using namespace descartes_core;
    using namespace descartes_trajectory;

    return TrajectoryPtPtr(new AxialSymmetricPt(pose, M_PI / 2.0 - 0.0001, AxialSymmetricPt::Z_AXIS));
}

trajectory_msgs::JointTrajectory
toROSJointTrajectory(const TrajectoryVec& trajectory,
        const descartes_core::RobotModel& model,
        const std::vector<std::string>& joint_names,
        double time_delay) {
    // Fill out information about our trajectory
    trajectory_msgs::JointTrajectory result;
    result.header.stamp = ros::Time::now();
    result.header.frame_id = "world_frame";
    result.joint_names = joint_names;

    // For keeping track of time-so-far in the trajectory
    double time_offset = 0.0;
    // Loop through the trajectory
    for (TrajectoryIter it = trajectory.begin(); it != trajectory.end(); ++it) {
        // Find nominal joint solution at this point

        std::vector<double> joints;
        it->get()->getNominalJointPose(std::vector<double>(), model, joints);

        // Fill out a ROS trajectory point
        trajectory_msgs::JointTrajectoryPoint pt;
        pt.positions = joints;
        // velocity, acceleration, and effort are given dummy values
        // we'll let the controller figure them out
        pt.velocities.resize(joints.size(), 0.0);
        pt.accelerations.resize(joints.size(), 0.0);
        pt.effort.resize(joints.size(), 0.0);
        // set the time into the trajectory
        pt.time_from_start = ros::Duration(time_offset);
        // increment time
        time_offset += time_delay;

        result.points.push_back(pt);
    }

    return result;
}

bool executeTrajectory(const trajectory_msgs::JointTrajectory& trajectory) {
    // Create a Follow Joint Trajectory Action Client
    actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> ac("joint_trajectory_action", true);
    if (!ac.waitForServer(ros::Duration(2.0))) {
        ROS_ERROR("Could not connect to action server");
        return false;
    }

    control_msgs::FollowJointTrajectoryGoal goal;
    goal.trajectory = trajectory;
    goal.goal_time_tolerance = ros::Duration(1.0);

    ac.sendGoal(goal);

    if (ac.waitForResult(goal.trajectory.points[goal.trajectory.points.size() - 1].time_from_start + ros::Duration(5))) {
        ROS_INFO("Action server reported successful execution");
        return true;
    } else {
        ROS_WARN("Action server could not execute trajectory");
        return false;
    }
}
#endif
