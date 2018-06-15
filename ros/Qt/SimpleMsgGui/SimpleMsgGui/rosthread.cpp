#include "rosthread.h"
#include "NIST/Globals.h"
#include "NIST/Debug.h"
#include <boost/bind.hpp>
#include <ros/master.h>

#include <simple_message/simple_message.h>
#include <simple_message/socket/tcp_socket.h>
#include <simple_message/socket/tcp_client.h>
#include <simple_message/socket/tcp_server.h>
#include <simple_message/messages/joint_message.h>
#include <simple_message/messages/joint_traj_pt_message.h>
#include <simple_message/messages/robot_status_message.h>
#include <simple_message/joint_data.h>
#include <simple_message/joint_traj_pt.h>
#include <simple_message/typed_message.h>
#include <simple_message/joint_traj.h>
#include <simple_message/robot_status.h>

using namespace industrial::simple_message;
using namespace industrial::tcp_socket;
using namespace industrial::tcp_client;
using namespace industrial::tcp_server;
using namespace industrial::joint_data;
using namespace industrial::joint_message;
using namespace industrial::joint_traj_pt;
using namespace industrial::joint_traj_pt_message;
using namespace industrial::typed_message;
using namespace industrial::joint_traj;
using namespace industrial::robot_status;
using namespace industrial::robot_status_message;

#define TEST_PORT_BASE 51000
// Message passing routine, used to send and receive a typed message
// Useful for checking the packing and unpacking of message data.
void fakeMessagePassing(TypedMessage &send, TypedMessage &recv)
{
  const int tcpPort = TEST_PORT_BASE+401;
  char ipAddr[] = "127.0.0.1";

  TcpClient tcpClient;
  TcpServer tcpServer;
  SimpleMessage msgSend, msgRecv;

  send.toTopic(msgSend);

  // Construct server

  tcpServer.init(tcpPort);

  // Construct a client
  tcpClient.init(&ipAddr[0], tcpPort);
  tcpClient.makeConnect();  // make tcp client connection

  tcpServer.makeConnect();      // make tcp server connection

  tcpClient.sendMsg(msgSend);   // send message
  tcpServer.receiveMsg(msgRecv); // physically receive message
  recv.init(msgRecv); // copy received message into reference
}

RosThread::RosThread(QObject *parent) :
    QThread(parent)
  , abort(false)
{
    val.resize(2);
}
void RosThread::setTableItems(QTableItems * tableitems)
{
    this->_tableitems=tableitems;
}

static RVector<double> PoseValues(tf::Pose & pose) {
   RVector<double> values;
    values.push_back( pose.getOrigin().x());
    values.push_back( pose.getOrigin().y());
    values.push_back( pose.getOrigin().z());
    double roll, pitch, yaw;
    tf::Quaternion q = pose.getRotation();
    tf::Matrix3x3(q).getRPY(roll, pitch, yaw );
    values.push_back( roll );
    values.push_back( pitch );
    values.push_back( yaw );
    return values;
}

tf::Pose  RosThread::xform(std::string world, std::string eelink)
{
    try {
        ros::Time now = ros::Time::now() - ros::Duration(1);
        listener->lookupTransform( eelink.c_str(), world.c_str(),  now, *transform);
        tf::Transform ttransform = transform->inverse();

        tf::Pose pose(ttransform.getRotation(), ttransform.getOrigin());
        //std::cout << "tf pose = " << RCS::DumpPoseSimple(pose).c_str() << "\n";
        ros::spinOnce();
        return pose;

    } catch (tf::TransformException ex) {
        ROS_ERROR("%s", ex.what());
        ros::Duration(1.0).sleep();
    }
    return tf::Pose();
}

void RosThread::posecallback(const geometry_msgs::Pose::ConstPtr &msg, std::string &topic)
{
    tf::Pose pose;
    pose.setOrigin(Convert<geometry_msgs::Point, tf::Vector3>(msg->position)) ; //msg->orientation, msg->position)
    pose.setRotation(Convert<geometry_msgs::Quaternion, tf::Quaternion>(msg->orientation)) ; //msg->orientation, msg->position)
    qDebug("tf pose from topic [%s] = %s\n" , topic.c_str(), RCS::DumpPoseSimple(pose).c_str() );
    posevalues[topic]=pose;
    _tableitems->Fill<double>(PoseValues(pose), topic);
}


void RosThread::callback(const sensor_msgs::JointState::ConstPtr& msg) {

    for(size_t i=0; i< msg->name.size(); i++)
    {
       robots.jointposvalues[msg->name[i]]= msg->position[i];
    }
    std::map<std::string, std::vector<std::string> >::iterator it;
    size_t i=1;
    for(it=robots.jointnames.begin(); it!= robots.jointnames.end(); it++)
    {
        std::vector<double> pos;
        for(size_t j=0; j< robots.jointnames[(*it).first].size(); j++)
        {
            pos.push_back(robots.jointposvalues[robots.jointnames[(*it).first][j]]);
        }
        // THis only works because fanuc < motoman
        _jnttableitems->Fill<double>(pos, i);
        i=i+2;
    }
   //qDebug("%s\n", RCS::MapDump<double>(robots.jointposvalues).c_str());
}
void RosThread::run()
{
//    std::vector<char *> argv;
//    int argc=0;
    std::string envstr = Globals.ExecuteShellCommand("env");
    std::cout << envstr << "\n";

    ros::NodeHandle nh;
    ros::Rate r(50); // 10 times a second - 10Hz
    listener = new tf::TransformListener();
    transform = new tf::StampedTransform();

    sub = nh.subscribe("/joint_states", 10, &RosThread::callback, this);

    for(size_t i=0; i< poses.size(); i++)
    {
        qDebug("subscribe to topic [%s] \n" , poses[i].c_str() );
        subs.push_back(nh.subscribe<geometry_msgs::Pose>(poses[i], 10, boost::bind(&RosThread::posecallback, this, _1, poses[i])));
       // subs.push_back(nh.subscribe(poses[i], 10, &RosThread::aposecallback, this));
    }
    while (true)
    {
        //usleep(100000);
        ::sleep(2);
        //std::cout <<"ROS Thread" << i++ << "\n";
        if (abort)
        {
            break;
        }
        if (!ros::ok())
        {
            //emit(master_found_signal(QMessageBox::Ok));
            break;
        }
        tf::Pose fanuc=  xform("world", "fanuc_link_6");
        tf::Pose motoman =  xform("world", "motoman_link_u");
        val[0] = PoseValues(fanuc);
        val[1] = PoseValues(motoman);
        if(_tableitems!=NULL)
            _tableitems->Fill(val);
    }
}
