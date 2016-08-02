#include "RvizMarker.h"

CRvizMarker::CRvizMarker( ros::NodeHandle & nh ): n(nh) {
    _id = 0;
    scalex = scaley = scalez = 0.005;
    // Set our initial shape type to be a cube
    shape = visualization_msgs::Marker::SPHERE;
    r= 1.0;  g=0.0;  b=0.0;  a=1.0;
}
void CRvizMarker::Init()
{
   _id=0;
   marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
}
int CRvizMarker::Send(RCS::Pose p)
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/base_link";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "nist_fanuc";
    marker.id = _id++;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD and DELETE
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
#if 0
    marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
#endif
    marker.pose.position.x = p.getOrigin().x();
    marker.pose.position.y = p.getOrigin().y();
    marker.pose.position.z = p.getOrigin().z();
    marker.pose.orientation.x = p.getRotation().x();
    marker.pose.orientation.y = p.getRotation().y();
    marker.pose.orientation.z = p.getRotation().z();
    marker.pose.orientation.w = p.getRotation().w();

    // Set the scale of the marker -- 1x1x1 here means 1m on a side!!!
    marker.scale.x = scalex;  
    marker.scale.y = scaley;
    marker.scale.z = scalez;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = r;
    marker.color.g = g;
    marker.color.b = b;
    marker.color.a = a;

    marker.lifetime = ros::Duration();

    // Publish the marker
    marker_pub.publish(marker);

	return 0;
}
void CRvizMarker::SetColor(double r, double g, double b, double a)
{
    this->r=r; this->g=g; this->b=b; this->a=a;
}
uint32_t CRvizMarker::SetShape(uint32_t shape)
{
	uint32_t oldshape=this->shape;
    // Cycle between different shapes
    switch (shape)
    {
    case visualization_msgs::Marker::CUBE:
      this->shape = visualization_msgs::Marker::SPHERE;
      break;
    case visualization_msgs::Marker::SPHERE:
      this->shape = visualization_msgs::Marker::ARROW;
      break;
    case visualization_msgs::Marker::ARROW:
      this->shape = visualization_msgs::Marker::CYLINDER;
      break;
    case visualization_msgs::Marker::CYLINDER:
      this->shape = visualization_msgs::Marker::CUBE;
      break;
    }
	return oldshape;
}
