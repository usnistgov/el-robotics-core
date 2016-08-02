

#include "Kinematics.h"
#include <eigen_conversions/eigen_msg.h>
#include "RosConversions.h"
#include <iostream>
#include "Conversions.h"
#include "Globals.h"
// DISCLAIMER:
// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

// Could find basics explained here: http://aeswiki.datasys.swri.edu/rositraining/Exercises/3.6

// https://github.com/ros-planning/moveit_pr2/blob/hydro-devel/pr2_moveit_tutorials/planning/src/motion_planning_api_tutorial.cpp
// http://moveit.ros.org/wiki/Motion_Planning/C%2B%2B_API
// http://docs.ros.org/indigo/api/pr2_moveit_tutorials/html/planning/src/doc/motion_planning_api_tutorial.html
// http://docs.ros.org/api/moveit_core/html/classmoveit_1_1core_1_1RobotState.html#aa28a400ac63222f07598c53c685d7144

RosKinematics::RosKinematics() {
    _bInit = false;
}

void RosKinematics::Init(
        std::string groupname,
        std::string eelinkname) {
    _eelinkname = eelinkname;
    _groupname = groupname;
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");
    kinematic_model = robot_model_loader.getModel();
    ROS_INFO("Model frame: %s", kinematic_model->getModelFrame().c_str());
    kinematic_state = robot_state::RobotStatePtr(new robot_state::RobotState(kinematic_model));
    joint_model_group = kinematic_model->getJointModelGroup(_groupname.c_str());
    joint_names = joint_model_group->getJointModelNames();
    _bInit = true;
    assert(kinematic_model != NULL);
    assert(kinematic_state != NULL);
    assert(joint_model_group != NULL);
}

std::vector<double> RosKinematics::GetJointValues() {
    assert(_bInit);
    std::vector<double> joint_values;
    kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
    return joint_values;
}
void RosKinematics::SetJointValues(std::vector<double> joint_values) {
    assert(kinematic_state != NULL);
    // setJointGroupPositions() does not enforce joint limits by itself, but a call to enforceBounds() will do it.
    kinematic_state->setJointGroupPositions(joint_model_group, joint_values);
}
bool RosKinematics::SatisfiesBounds() {
    assert(kinematic_state != NULL);
    /* Check whether any joint is outside its joint limits */
    return (kinematic_state->satisfiesBounds()) ;
}
void RosKinematics::EnforceBounds() {
    assert(kinematic_state != NULL);
   /* Enforce the joint limits for this state */
    kinematic_state->enforceBounds();
}
RCS::Pose RosKinematics::FK(std::vector<double> jv) {
     boost::mutex::scoped_lock lock(kinmutex);
   // gearing kludge for now - this should be override for each robot
    //jv[2] = jv[1] + jv[2];
    // This creates a unique robot model/kinematics, loads joints, computes FK
    assert(kinematic_model != NULL);
    robot_state::RobotStatePtr ks = robot_state::RobotStatePtr(
            new robot_state::RobotState(kinematic_model));
    assert(ks != NULL);
    for (size_t i = 0; i < jv.size(); i++)
        ks->setJointPositions(kinematic_model->getJointModel(i), &jv[i]);

    Eigen::Affine3d end_effector_state = Eigen::Affine3d(
            ks->getGlobalLinkTransform(_eelinkname));
//   std::cout << "end_effector_state=" << end_effector_state.translation() << std::endl;
    RCS::Pose pose;
    pose = Affine3d2UrdfPose(end_effector_state);
    return pose;
}

std::vector<double> RosKinematics::IK(RCS::Pose & pose, std::vector<double> oldjoints) {
    boost::mutex::scoped_lock lock(kinmutex);
    std::vector<double> joints;
#if 0
    const Eigen::Affine3d &end_effector_state1 =
            kinematic_state->getGlobalLinkTransform("joint_6_link");
#endif
    Eigen::Affine3d end_effector_state = UrdfPose2Affine3d(pose);
    //      end_effector_state.translation()=pose.translation;
    //      end_effector_state.rotation()=pose.rotation ;

    bool found_ik = kinematic_state->setFromIK(joint_model_group, end_effector_state, 10, 0.1);
    if (found_ik) {
        kinematic_state->copyJointGroupPositions(joint_model_group, joints);
    }
    return joints;
}


// --------------------------------------------------
// http://moveit.ros.org/code-api/
MoveitKinematics::MoveitKinematics(ros::NodeHandle &nh): _nh(nh) {
    _bInit = false;
}

void MoveitKinematics::Init(
        std::string groupname,
        std::string eelinkname) {

    _groupname = groupname;
    _eelinkname=eelinkname;
    _nh.getParam("controller_joint_names", joint_names);
    robot_model_loader::RobotModelLoader robot_model_loader("robot_description");

    kinematic_model = robot_model_loader.getModel(); 
    kinematic_state = robot_state::RobotStatePtr(
            new robot_state::RobotState(kinematic_model));
    joint_model_group =  kinematic_model->getJointModelGroup( _groupname.c_str());
    group = boost::shared_ptr< moveit::planning_interface::MoveGroup>(new moveit::planning_interface::MoveGroup(_groupname.c_str()));
    std::cout << "Reference frame " << group->getPlanningFrame().c_str();
    std::cout << "EE frame " << group->getEndEffectorLink().c_str();
   _bInit = true;

    assert(kinematic_model != NULL);
    assert(kinematic_state != NULL);
    assert(joint_model_group != NULL);
}

std::vector<double> MoveitKinematics::GetJointValues() {
   assert(_bInit); 
    std::vector<double> joint_values;
    kinematic_state->copyJointGroupPositions(joint_model_group, joint_values);
    return joint_values;
}
void MoveitKinematics::SetJointValues(std::vector<double> joint_values) {
    assert(kinematic_state != NULL);
 //   std::cout << "MoveitKinematics::SetJointValues" << VectorDump<double>(joint_values);
    // setJointGroupPositions() does not enforce joint limits by itself, but a call to enforceBounds() will do it.
    kinematic_state->setJointGroupPositions(joint_model_group, joint_values);
}
#if 0
bool MoveitKinematics::SatisfiesBounds() {
    assert(kinematic_state != NULL);
    /* Check whether any joint is outside its joint limits */
    return (kinematic_state->satisfiesBounds()) ;
}
void MoveitKinematics::EnforceBounds() {
    assert(kinematic_state != NULL);
   /* Enforce the joint limits for this state */
    kinematic_state->enforceBounds();
}
#endif
RCS::Pose MoveitKinematics::FK(std::vector<double> jv) {
    boost::mutex::scoped_lock lock(kinmutex);
    if(jv.size()==0)
    {
        jv=ToVector<double>(6, 0,0,0,0,0,0);
        DebugBreak();
    }
    SetJointValues(jv);
    Eigen::Affine3d end_effector_state = Eigen::Affine3d(
            kinematic_state->getGlobalLinkTransform(group->getEndEffectorLink().c_str()));
    return Affine3d2UrdfPose(end_effector_state);
}
// http://docs.ros.org/jade/api/moveit_core/html/classmoveit_1_1core_1_1RobotState.html
std::vector<double> MoveitKinematics::IK(RCS::Pose & pose, std::vector<double> oldjoints) {
    boost::mutex::scoped_lock lock(kinmutex);
    std::vector<double> joints;

    //    const Eigen::Affine3d &end_effector_state1 =
    //            kinematic_state->getGlobalLinkTransform(_eelinkname.c_str());
    Eigen::Affine3d end_effector_state = UrdfPose2Affine3d(pose);

    //geometry_msgs::Pose end_effector_state=  UrdfPose2PoseMsg(pose);
    bool found_ik = kinematic_state->setFromIK(joint_model_group, end_effector_state, 10, 0.1);
    if (found_ik) {
        kinematic_state->copyJointGroupPositions(joint_model_group, joints);
    } else {
        std::cout << "MoveitKinematics::IK not found\n";
    }
    std::cout << "New IK Joints " << VectorDump<double>(joints).c_str();
    return joints;
}

// http://docs.ros.org/jade/api/moveit_core/html/classmoveit_1_1core_1_1RobotState.html
bool MoveitKinematics::IsSingular(RCS::Pose & pose,
            double threshold){
    double MIN_DETERMINANT_VALUE = threshold;
    //The reference point position (with respect to the link specified in link_name) - Base?
    Eigen::Vector3d reference_point_position(0.0, 0.0, 0.0); // or with z offset?
    Eigen::MatrixXd jacobian;
    Eigen::Affine3d end_effector_state = UrdfPose2Affine3d(pose);
    bool found_ik = kinematic_state->setFromIK(joint_model_group, 
            end_effector_state, 
            1/*attempts*/, 
            0.1/*timeout*/);
    if (!found_ik)
        return false;
    kinematic_state->getJacobian(joint_model_group, 
            kinematic_state->getLinkModel(joint_model_group->getLinkModelNames().back()),
            reference_point_position, 
            jacobian);

    return std::abs(jacobian.determinant()) < MIN_DETERMINANT_VALUE;
}
        
#if 0

class CPrimitive {
    typedef moveit::planning_interface::MoveItErrorCode RosErrorCode;
    robot_model::RobotModelPtr kinematic_model;
    robot_state::RobotStatePtr kinematic_state;
    robot_state::JointModelGroup* joint_model_group;
    std::vector<double> joint_values;
    const std::vector<std::string> *joint_names;
    Eigen::Affine3d &end_effector_state;
    std::string _groupname;
    Eigen::Affine3d dummy;
    moveit::planning_interface::MoveGroup movegroup;
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    ros::NodeHandle &node;

    bool _bAllow_trajectory_execution;
    bool _bAllowed_execution_duration_scaling;
    double _dJiggle_fraction;
    std::vector<std::string> _capabilities;
    std::string _sCapabilities;
    std::string _sController_list;
    double _d_longest_valid_segment_fraction;

public:

    CPrimitive(ros::NodeHandle nh,
            robot_model_loader::RobotModelLoader & robotmodel,
            std::string groupname) :
    node(nh), kinematic_model(robotmodel.getModel()), movegroup(
    groupname.c_str()), _groupname(groupname), end_effector_state(
    dummy) {
        //robot_model::RobotModelPtr kinematic_model = robot_model_loader.getModel();
        kinematic_state = robot_state::RobotStatePtr(
                new robot_state::RobotState(kinematic_model));
        kinematic_state->setToDefaultValues();
        planning_scene::PlanningScene planning_scene(kinematic_model);
        joint_model_group = kinematic_model->getJointModelGroup(
                _groupname.c_str());
        joint_names = &joint_model_group->getJointModelNames();
        GetJointValues();
        ros::param::param<bool>("/move_group/allow_trajectory_execution",
                _bAllow_trajectory_execution, true);
        ros::param::param<bool>(
                "/move_group/allowed_execution_duration_scaling",
                _bAllowed_execution_duration_scaling, false);
        ros::param::param<double>("/move_group/jiggle_fraction",
                _dJiggle_fraction, 0.0);
        ros::param::param<std::string>("/move_group/capabilities",
                _sCapabilities, "nothing");
        ros::param::param<std::string>("/move_group/controller_list",
                _sController_list, "nothing");
        ros::param::param<double>(
                "/move_group/manipulator/longest_valid_segment_fraction",
                _d_longest_valid_segment_fraction, 0.0);
    }

    std::string ToString() {
        std::stringstream str;
        str << "Allow_trajectory_execution = " << _bAllow_trajectory_execution
                << std::endl;
        str << "Allowed_execution_duration_scaling = "
                << _bAllowed_execution_duration_scaling << std::endl;
        str << "Jiggle fraction = " << _dJiggle_fraction << std::endl;
        // Mess that is capability strings
        str << "Capabilities = " << std::endl;
        ReplaceAll(_sCapabilities, "\n ", " ");
        ReplaceAll(_sCapabilities, "\r ", " ");
        ReplaceAll(_sCapabilities, "  ", " ");
        _capabilities = TrimmedTokenize(_sCapabilities, " ");
        for (size_t i = 0; i < _capabilities.size(); i++) {
            _capabilities[i] = Trim(_capabilities[i]);
            if (_capabilities[i].empty()) {
                _capabilities.erase(_capabilities.begin() + i);
                i--;
                continue;
            }
            str << "     " << _capabilities[i] << std::endl;

        }

        str << "controller_list = " << _sController_list << std::endl;
        str << "_longest_valid_segment_fraction = "
                << _d_longest_valid_segment_fraction << std::endl;

        return str.str();
    }

    void GetJointValues() {
        kinematic_state->copyJointGroupPositions(joint_model_group,
                joint_values);
        PrintJoints(joint_values, *joint_names);
    }

    geometry_msgs::Pose GetRobotState_pose(
            const robot_state::RobotState &state) {
        Eigen::Affine3d eef_transform = state.getGlobalLinkTransform(
                movegroup.getEndEffectorLink());
        geometry_msgs::Pose pose;
        tf::poseEigenToMsg(eef_transform, pose);
        return pose;
    }

    void ForwardKinematics() {
        end_effector_state = Eigen::Affine3d(
                kinematic_state->getGlobalLinkTransform("joint_6_link"));
        ROS_INFO_STREAM("Translation: " << end_effector_state.translation());
        ROS_INFO_STREAM("Rotation: " << end_effector_state.rotation());
    }
    // Set all joints to random values. Values will be within default bounds.

    std::vector<double> SetRandomJoints() {
        robot_state::RobotStatePtr ks = robot_state::RobotStatePtr(
                new robot_state::RobotState(kinematic_model));
        ks->setToRandomPositions(joint_model_group);
        std::vector<double> joints;
        ks->copyJointGroupPositions(joint_model_group, joints);
        return joints;
    }

    Eigen::Affine3d ComputeForwardKinematics(std::vector<double> jointvalues) {
        robot_state::RobotStatePtr ks = robot_state::RobotStatePtr(
                new robot_state::RobotState(kinematic_model));
        for (size_t i = 0; i < jointvalues.size(); i++)
            ks->setJointPositions(kinematic_model->getJointModel(i), &jointvalues[i]);
        const Eigen::Affine3d & fk = Eigen::Affine3d(
                ks->getGlobalLinkTransform("joint_6_link"));
        //ROS_INFO_STREAM("Translation: " << end_effector_state.translation());
        //ROS_INFO_STREAM("Rotation: " << end_effector_state.rotation());
        return fk;
    }

    std::vector<double> InverseKinematics() {
        std::vector<double> joints;
        const Eigen::Affine3d &end_effector_state1 =
                kinematic_state->getGlobalLinkTransform("joint_6_link");
        bool found_ik = kinematic_state->setFromIK(joint_model_group,
                end_effector_state1, 10, 0.1);
        if (found_ik) {
            kinematic_state->copyJointGroupPositions(joint_model_group, joints);
            PrintJoints(joints, *joint_names);
        }
        return joints;
    }

    void RandomGoal() {
        SetRandomJoints();
        const Eigen::Affine3d &end_effector_state1 =
                kinematic_state->getGlobalLinkTransform("joint_6_link");
        bool found_ik = kinematic_state->setFromIK(joint_model_group,
                end_effector_state1, 10, 0.1);
        //return const_cast < Eigen::Affine3d > ( end_effector_state1);
    }

    void PlanPath(geometry_msgs::Pose &pose, double dGoalTolerance,
            int bMoveFlag = 1, int bRandomFlag = 1) {
        RosErrorCode ec;
        //moveit::planning_interface::MoveGroup movegroup(_groupname.c_str());
        moveit_msgs::DisplayTrajectory display_trajectory;
        moveit::planning_interface::MoveGroup::Plan my_plan;
        movegroup.setPoseTarget(pose);
        if (bRandomFlag) {
            std::vector<double> joints = SetRandomJoints();
            Eigen::Affine3d cart = this->ComputeForwardKinematics(joints);

            //  After this call, the JointValueTarget is used instead of any
            //  previously set Position, Orientation, or Pose targets
            //movegroup.setRandomTarget();

            //const robot_state::RobotState& state = movegroup.getJointValueTarget();
            //state.copyJointGroupPositions(joint_model_group, joints);
            //PrintJoints(joints, *joint_names);
            geometry_msgs::Pose target_pose1;
            // Not sure what coordinate frame planning is in - if end-effector, not world
            target_pose1.orientation.w = 1.0;
            target_pose1.position.x = cart.translation().x(); // end_effector_state.translation().x();
            target_pose1.position.y = cart.translation().y(); // end_effector_state.translation().y();
            target_pose1.position.z = cart.translation().z(); //  end_effector_state.translation().z();
            movegroup.setPoseTarget(target_pose1);
        }
        PrintPose();
        movegroup.setGoalTolerance(dGoalTolerance);
        movegroup.setPlanningTime(10.0); // assuming obstacles
        bool success = movegroup.plan(my_plan);
        if (success & bMoveFlag)
            ec = movegroup.move();
    }

    void PrintPose() {
        const geometry_msgs::PoseStamped& msg = movegroup.getPoseTarget();
        ROS_INFO("Pose x=%f y=%f z=%f %f %f %f %f\n", msg.pose.position.x,
                msg.pose.position.y,
                msg.pose.position.z,
                msg.pose.orientation.x,
                msg.pose.orientation.y,
                msg.pose.orientation.z,
                msg.pose.orientation.w);
    }

    static void PrintJoints(std::vector<double> &joint_values,
            const std::vector<std::string> &joint_names) {
        for (std::size_t i = 0; i < joint_names.size(); ++i) {
            ROS_INFO("Joint %s: %f", joint_names[i].c_str(), joint_values[i]);
        }
    }

    static void SaveJointInfo(sensor_msgs::JointState & joint_state,
            std::vector<double> &joint_values,
            const std::vector<std::string> &joint_names) {
        joint_state.name.resize(joint_names.size());
        joint_state.position.resize(joint_names.size());
        for (std::size_t i = 0; i < joint_names.size(); ++i) {
            joint_state.name[i] = joint_names[i];
            joint_state.position[i] = joint_values[i];
        }
    }

    void AddObstacle(std::string id) {
        moveit_msgs::CollisionObject collision_object;
        collision_object.header.frame_id = movegroup.getPlanningFrame();
http: //docs.ros.org/api/moveit_core/html/classmoveit_1_1core_1_1RobotState.html#aa28a400ac63222f07598c53c685d7144
        /* The id of the object is used to identify it. */
        collision_object.id = id.c_str(); // "box1";

        /* Define a box to add to the world. */
        shape_msgs::SolidPrimitive primitive;
        primitive.type = primitive.BOX;
        primitive.dimensions.resize(3);
        primitive.dimensions[0] = 0.4;
        primitive.dimensions[1] = 0.1;
        primitive.dimensions[2] = 0.4;

        /* A pose for the box (specified relative to frame_id) */
        geometry_msgs::Pose box_pose;
        box_pose.orientation.w = 1.0;
        box_pose.position.x = 0.6;
        box_pose.position.y = -0.4;
        box_pose.position.z = 1.2;

        //http:docs.ros.org/api/moveit_core/html/classmoveit_1_1core_1_1RobotState.html#aa28a400ac63222f07598c53c685d7144		
        collision_object.primitives.push_back(primitive);
        collision_object.primitive_poses.push_back(box_pose);
        collision_object.operation = collision_object.ADD;

        std::vector<moveit_msgs::CollisionObject> collision_objects;
        collision_objects.push_back(collision_object);
        //Now, let’s add the collision object into the world 		ROS_INFO("Add an object into the world");
        planning_scene_interface.addCollisionObjects(collision_objects);
    }

    void RemoveObstacle(std::string id) {
        ROS_INFO("Remove the object from the world");
        std::vector < std::string > object_ids;
        object_ids.push_back(id.c_str()); // collision_object.id);
        planning_scene_interface.removeCollisionObjects(object_ids);
        /* Sleep to give Rviz time to show the object is no longer there. */
        sleep(4.0);
    }
};

int main(int argc, char** argv) {

    ros::init(argc, argv, "primitive_node");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1); // Hz - once per second
    std::string robot_description("robot_description");

    // Dont need flush after every ROS_INFO command
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    //
    // Complete robot URDF description...
    //	ros::param::param<std::string>("/robot_description", robot_description, "robot_description");
    //	ROS_INFO("%s", robot_description.c_str());
    //
    // ABSOLUTELY Needed 
    ros::AsyncSpinner spinner(1);
    spinner.start();

    robot_model_loader::RobotModelLoader robot_model_loader(
            robot_description.c_str());
    CPrimitive prim(nh, robot_model_loader, "manipulator");
    ROS_INFO("%s", prim.ToString().c_str());

    /* A desired pose */
    geometry_msgs::Pose finalpose2;
    geometry_msgs::Quaternion quat;
    std::string path = ExtractDirectory(argv[0]);
    ROS_INFO("argv[0]= %s", argv[0]);
    ROS_INFO("Path= %s", path.c_str());
    // Read file of xyzq poses
    path = "/home/michalos/catkin_ws/devel/lib/trajectory";
    //std::ifstream infile((path + "/KittingQuaterianPts.txt").c_str());
    std::ifstream infile((path + "/KittingWorking.txt").c_str());
    //std::ifstream infile((path+ "/KittingRPYPts.txt").c_str());

    std::string line;
    for (size_t i = 0; ros::ok(); i++) {
#if 1
        //PlanPath(geometry_msgs::Pose &pose, double dGoalTolerance, int bMoveFlag=1, int bRandomFlag=1)
        std::getline(infile, line);

        if (infile.eof()) {
            infile.clear();
            infile.seekg(0);
            infile.tellg();
            continue;
        }
        std::istringstream iss(line);
        float x, y, z, qx, qy, qz, qw;
        //float x,y,z, roll, pitch, yaw;
        //if (!(iss >> x >> y >> z >> roll >> pitch >> yaw ))
        if (iss >> x >> y >> z >> qx >> qy >> qz >> qw) {
            finalpose2.position.x = x; //postion related to wrist frame
            finalpose2.position.y = y;
            finalpose2.position.z = z;
            /*			finalpose2.orientation.x = qx;
            finalpose2.orientation.y = qy;
            finalpose2.orientation.z = qz;
            finalpose2.orientation.w = qw;*/
            finalpose2.orientation.x = 0;
            finalpose2.orientation.y = 0;
            finalpose2.orientation.z = 0;
            finalpose2.orientation.w = 1;
            prim.PlanPath(finalpose2, 0.01, 1, 0);

            //			quat = tf::createQuaternionFromRPY( roll, pitch, yaw );
            //			finalpose2.pose.orientation = quat; // Eigen::Quaternion<float,0>(qw,qx,qy,qz);;  
        }
#else
        geometry_msgs::Pose target_pose1;
        // Not sure what coordinate frame planning is in - if end-effector, not world
        target_pose1.orientation.w = 1.0;
        target_pose1.position.x = 0.2; // end_effector_state.translation().x();
        target_pose1.position.y = 0.1; // end_effector_state.translation().y();
        target_pose1.position.z = -0.1; //  end_effector_state.translation().z();

        //prim.AddObstacle("box1");		prim.PlanPath(target_pose1, 0.01, 1, 1);
        /*		if(i%20) prim.RemoveObstacle("box1");*/

#endif		
        loop_rate.sleep();
    }

    ros::shutdown();
    return 0;
}
#if 0
//
// Find Trajectory planner
robot_model::RobotModelPtr robot_model = robot_model_loader.getModel();
planning_scene::PlanningScenePtr planning_scene(new planning_scene::PlanningScene(robot_model));
// We will now construct a loader to load a planner, by name. Note that we are using the ROS pluginlib library here.
boost::scoped_ptr<pluginlib::ClassLoader<planning_interface::PlannerManager> > planner_plugin_loader;
planning_interface::PlannerManagerPtr planner_instance;
std::string planner_plugin_name;
//We will get the name of planning plugin we want to load from the ROS param server, and then load the planner making sure to catch all exceptions.
if (!nh.getParam("/move_group/planning_plugin", planner_plugin_name))
    ROS_FATAL_STREAM("Could not find planner plugin name");
try {
    planner_plugin_loader.reset(new pluginlib::ClassLoader<planning_interface::PlannerManager>("moveit_core", "planning_interface::PlannerManager"));
} catch (pluginlib::PluginlibException& ex) {
    ROS_FATAL_STREAM("Exception while creating planning plugin loader " << ex.what());
}
try {
    planner_instance.reset(planner_plugin_loader->createUnmanagedInstance(planner_plugin_name));
    if (!planner_instance->initialize(robot_model, nh.getNamespace()))
        ROS_FATAL_STREAM("Could not initialize planner instance");
    ROS_INFO_STREAM("Using planning interface '" << planner_instance->getDescription() << "'");
} catch (pluginlib::PluginlibException& ex) {
    const std::vector<std::string> &classes = planner_plugin_loader->getDeclaredClasses();
    std::stringstream ss;
    for (std::size_t i = 0; i < classes.size(); ++i)
        ss << classes[i] << " ";
    ROS_ERROR_STREAM("Exception while loading planner '" << planner_plugin_name << "': " << ex.what() << std::endl
            << "Available plugins: " << ss.str());
}
//
// Cartesian planning and move?
planning_interface::MotionPlanRequest req;
planning_interface::MotionPlanResponse res;
geometry_msgs::PoseStamped pose;
pose.header.frame_id = "base_link";
pose.pose.position.x = 0.75;
pose.pose.position.y = 0.0;
pose.pose.position.z = 0.0;
pose.pose.orientation.w = 1.0;
std::vector<double> tolerance_pose(3, 0.01);
std::vector<double> tolerance_angle(3, 0.01);
req.group_name = "manipulator";
moveit_msgs::Constraints pose_goal = kinematic_constraints::constructGoalConstraints("joint_6_link", pose, tolerance_pose, tolerance_angle);
req.goal_constraints.push_back(pose_goal);
planning_interface::PlanningContextPtr context = planner_instance->getPlanningContext(planning_scene, req, res.error_code_);
context->solve(res);
if (res.error_code_.val != res.error_code_.SUCCESS) {
    ROS_ERROR("Could not compute plan successfully");
    return 0;
}
//
// Visualize moveit cartesian planning
ros::Publisher display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
moveit_msgs::DisplayTrajectory display_trajectory;
moveit_msgs::MotionPlanResponse response;
res.getMessage(response);
display_trajectory.trajectory_start = response.trajectory_start;
display_trajectory.trajectory.push_back(response.trajectory);
display_publisher.publish(display_trajectory);
#endif
#if 0
// Pose Goal
// ^^^^^^^^^http://docs.ros.org/indigo/api/pr2_moveit_tutorials/html/planning/src/doc/motion_planning_api_tutorial.html
// We will now create a motion plan request for the right arm of the PR2
// specifying the desired pose of the end-effector as input.
planning_interface::MotionPlanRequest req;
planning_interface::MotionPlanResponse res;
geometry_msgs::PoseStamped pose;
pose.header.frame_id = "torso_lift_link";
pose.pose.position.x = 0.75;
pose.pose.position.y = 0.0;
pose.pose.position.z = 0.0;
pose.pose.orientation.w = 1.0;
// A tolerance of 0.01 m is specified in position
// and 0.01 radians in orientation
std::vector<double> tolerance_pose(3, 0.01);
std::vector<double> tolerance_angle(3, 0.01);
// We will create the request as a constraint using a helper function available
// from the
// `kinematic_constraints`_
// package.
//
// .. _kinematic_constraints: http://docs.ros.org/api/moveit_core/html/namespacekinematic__constraints.html#a88becba14be9ced36fefc7980271e132
req.group_name = "manipulator";
moveit_msgs::Constraints pose_goal = kinematic_constraints::constructGoalConstraints("r_wrist_roll_link", pose, tolerance_pose, tolerance_angle);
req.goal_constraints.push_back(pose_goal);
// We now construct a planning context that encapsulate the scene,
// the request and the response. We call the planner using this
// planning context
planning_interface::PlanningCostd::vector<double> Current()ntextPtr context = planner_instance->getPlanningContext(planning_scene, req, res.error_code_);
context->solve(res);
if (res.error_code_.val != res.error_code_.SUCCESS) {
    ROS_ERROR("Could not compute plan successfully");
    return 0;
}
#endif

#if 0
Eigen::Vector3d reference_point_position(0.0, 0.0, 0.0);
Eigen::MatrixXd jacobian;
kinematic_state->getJacobian(joint_model_group, kinematic_state->getLinkModel(joint_model_group->getLinkModelNames().back()),
        reference_point_position,
        jacobian);
ROS_INFO_STREAM("Jacobian: " << jacobian);
#endif

// More rosparams for move group to be 
#if 0

/ move_group / manipulator / planner_configs
        / move_group / manipulator / projection_evaluator
        / move_group / max_range
        / move_group / max_safe_path_cost
        / move_group / moveit_controller_manager
        / move_group / moveit_manage_controllers
        / move_group / octomap_resolution
        / move_group / ompl / display_random_valid_states
        / move_group / ompl / link_for_exploration_tree
        / move_group / ompl / maximum_waypoint_distance
        / move_group / ompl / minimum_waypoint_count
        / move_group / ompl / simplify_solutions
        / move_group / plan_execution / max_replan_attempts
        / move_group / plan_execution / record_trajectory_state_frequency
#endif
#endif
