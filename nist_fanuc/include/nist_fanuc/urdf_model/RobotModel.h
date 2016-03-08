//

// RobotModel.h
//

// DISCLAIMER:
// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied
// or intended.

#pragma once
#define URDF_INTERFACE_MODEL_H

#define TIXML_USE_STL
#include <vector>
#include <string>
#include <map>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/pointer_cast.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

/**
urdf::ModelInterfaceSharedPtr  model= urdf::parseURDFFile( Globals.ExeDirectory+"lrmate200id.urdf");
if (!model){
throw ( std::exception("ERROR: Model Parsing the xml failed") );
}
std::cout << "robot name is: " << model->getName() << std::endl;

// get info from parser
std::cout << "---------- Successfully Parsed XML ---------------" << std::endl;
// get root link
urdf::LinkConstSharedPtr root_link=model->getRoot();
if (!root_link) return -1;

std::cout << "root Link: " << root_link->name << " has " << root_link->child_links.size() << " child(ren)" << std::endl;
// print entire tree
urdf::printTree(root_link);

*/

#define _USE_MATH_DEFINES
#include <math.h>       /* isnan, sqrt */
#ifdef _MSC_VER
#if ( _MSC_VER <= 1700 )
inline double round (double value)
{
  return ( value >= 0.0f ) ? ( floor(value + 0.5f) ) : ( ceil(value - 0.5f) );
}
#endif
#endif

namespace urdf
{
  class Box;
  class Collision;
  class Color;
  class Cylinder;
  class Geometry;
  class Inertial;
  class Joint;
  class JointCalibration;
  class JointDynamics;
  class JointLimits;
  class JointMimic;
  class JointSafety;
  class JointState;
  class Link;
  class Material;
  class Mesh;
  class ModelInterface;
  class ModelState;
  class ParseError;
  class Pose;
  class Rotation;
  class Sphere;
  class Time;
  class Twist;
  class Vector3;
  class Visual;

#define URDF_TYPEDEF_CLASS_POINTER(Class)                           \
  class Class;                                                      \
  typedef boost::shared_ptr<Class> Class ##         SharedPtr;      \
  typedef boost::shared_ptr<const Class> Class ##   ConstSharedPtr; \
  typedef boost::weak_ptr<Class> Class ## WeakPtr

  // shared pointer used in joint.h
  typedef boost::shared_ptr<double>                 DoubleSharedPtr;

  URDF_TYPEDEF_CLASS_POINTER(Box);
  URDF_TYPEDEF_CLASS_POINTER(Collision);
  URDF_TYPEDEF_CLASS_POINTER(Cylinder);
  URDF_TYPEDEF_CLASS_POINTER(Geometry);
  URDF_TYPEDEF_CLASS_POINTER(Inertial);
  URDF_TYPEDEF_CLASS_POINTER(Joint);
  URDF_TYPEDEF_CLASS_POINTER(JointCalibration);
  URDF_TYPEDEF_CLASS_POINTER(JointDynamics);
  URDF_TYPEDEF_CLASS_POINTER(JointLimits);
  URDF_TYPEDEF_CLASS_POINTER(JointMimic);
  URDF_TYPEDEF_CLASS_POINTER(JointSafety);
  URDF_TYPEDEF_CLASS_POINTER(Link);
  URDF_TYPEDEF_CLASS_POINTER(Material);
  URDF_TYPEDEF_CLASS_POINTER(ModelInterface);
  URDF_TYPEDEF_CLASS_POINTER(Mesh);
  URDF_TYPEDEF_CLASS_POINTER(Sphere);
  URDF_TYPEDEF_CLASS_POINTER(Visual);

  // create *_pointer_cast functions in urdf namespace
  template<class T, class U>
  boost::shared_ptr<T> const_pointer_cast (boost::shared_ptr<U> const & r)
  {
    return boost::const_pointer_cast<T>(r);
  }
  template<class T, class U>
  boost::shared_ptr<T> dynamic_pointer_cast (boost::shared_ptr<U> const & r)
  {
    return boost::dynamic_pointer_cast<T>(r);
  }
  template<class T, class U>
  boost::shared_ptr<T> reinterpret_pointer_cast (boost::shared_ptr<U> const & r)
  {
    return boost::reinterpret_pointer_cast<T>(r);
  }
  template<class T, class U>
  boost::shared_ptr<T> static_pointer_cast (boost::shared_ptr<U> const & r)
  {
    return boost::static_pointer_cast<T>(r);
  }
  typedef boost::shared_ptr<JointState>   JointStateSharedPtr;
  ModelInterfaceSharedPtr parseURDFFile (const std::string & path);
  ModelInterfaceSharedPtr parseURDF (const std::string & xml_string);
  void                    printTree (LinkConstSharedPtr link, int level = 0);
  std::string             GenerateTable (ModelInterfaceSharedPtr model);
  void GetInOrderJoints(LinkConstSharedPtr link, std::vector<JointSharedPtr> &  joints);

  class ParseError : public std::runtime_error
  {
public:
    ParseError(const std::string & error_msg) : std::runtime_error(error_msg) { }
  };

  class Vector3
  {
public:
    Vector3(double _x, double _y, double _z) { this->x = _x; this->y = _y; this->z = _z; }
    Vector3( ) { this->clear( ); }
    double x;
    double y;
    double z;

    void clear ( ) { this->x = this->y = this->z = 0.0; }
    void init (const std::string & vector_str)
    {
      this->clear( );
      std::vector<std::string> pieces;
      std::vector<double>      xyz;
      boost::split(pieces, vector_str, boost::is_any_of(" ") );

      for ( unsigned int i = 0; i < pieces.size( ); ++i )
      {
        if ( pieces[i] != "" )
        {
          try
          {
            xyz.push_back(boost::lexical_cast<double>(pieces[i].c_str( ) ) );
          }
          catch ( boost::bad_lexical_cast & /*e*/ )
          {
            throw ParseError("Unable to parse component [" + pieces[i] + "] to a double (while parsing a vector value)");
          }
        }
      }

      if ( xyz.size( ) != 3 )
      {
        throw ParseError("Parser found " + boost::lexical_cast<std::string>(xyz.size( ) ) + " elements but 3 expected while parsing vector [" + vector_str + "]");
      }

      this->x = xyz[0];
      this->y = xyz[1];
      this->z = xyz[2];
    }

    Vector3 operator + (Vector3 vec)
    {
      return Vector3(this->x + vec.x, this->y + vec.y, this->z + vec.z);
    }
  };

  class Rotation
  {
public:
    Rotation(double _x, double _y, double _z, double _w) { this->x = _x; this->y = _y; this->z = _z; this->w = _w; }
    Rotation( ) { this->clear( ); }
    void getQuaternion (double & quat_x, double & quat_y, double & quat_z, double & quat_w) const
    {
      quat_x = this->x;
      quat_y = this->y;
      quat_z = this->z;
      quat_w = this->w;
    }

    void getRPY (double & roll, double & pitch, double & yaw) ;
    //{
    //  double sqw;
    //  double sqx;
    //  double sqy;
    //  double sqz;

    //  sqx = this->x * this->x;
    //  sqy = this->y * this->y;
    //  sqz = this->z * this->z;
    //  sqw = this->w * this->w;

    //  // Cases derived from https://orbitalstation.wordpress.com/tag/quaternion/
    //  double sarg = -2 * ( this->x * this->z - this->w * this->y );

    //  if ( sarg <= -0.99999 )
    //  {
    //    pitch = -0.5 * M_PI;
    //    roll  = 0;
    //    yaw   = 2 * atan2(this->x, -this->y);
    //  }
    //  else if ( sarg >= 0.99999 )
    //  {
    //    pitch = 0.5 * M_PI;
    //    roll  = 0;
    //    yaw   = 2 * atan2(-this->x, this->y);
    //  }
    //  else
    //  {
    //    pitch = asin(sarg);
    //    roll  = atan2(2 * ( this->y * this->z + this->w * this->x ), sqw - sqx - sqy + sqz);
    //    yaw   = atan2(2 * ( this->x * this->y + this->w * this->z ), sqw + sqx - sqy - sqz);
    //  }
    //}

    void setFromQuaternion (double quat_x, double quat_y, double quat_z, double quat_w)
    {
      this->x = quat_x;
      this->y = quat_y;
      this->z = quat_z;
      this->w = quat_w;
      this->normalize( );
    }

    void setFromRPY (double roll, double pitch, double yaw)
    {
      double phi, the, psi;

      phi = roll / 2.0;
      the = pitch / 2.0;
      psi = yaw / 2.0;

      this->x = sin(phi) * cos(the) * cos(psi) - cos(phi) * sin(the) * sin(psi);
      this->y = cos(phi) * sin(the) * cos(psi) + sin(phi) * cos(the) * sin(psi);
      this->z = cos(phi) * cos(the) * sin(psi) - sin(phi) * sin(the) * cos(psi);
      this->w = cos(phi) * cos(the) * cos(psi) + sin(phi) * sin(the) * sin(psi);

      this->normalize( );
    }

    double x, y, z, w;

    void init (const std::string & rotation_str)
    {
      this->clear( );
      Vector3 rpy;
      rpy.init(rotation_str);
      setFromRPY(rpy.x, rpy.y, rpy.z);
    }

    void clear ( ) { this->x = this->y = this->z = 0.0; this->w = 1.0; }

    void normalize ( )
    {
      double s = sqrt(this->x * this->x
        + this->y * this->y
        + this->z * this->z
        + this->w * this->w);

      if ( s == 0.0 )
      {
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
        this->w = 1.0;
      }
      else
      {
        this->x /= s;
        this->y /= s;
        this->z /= s;
        this->w /= s;
      }
    }

    // Multiplication operator (copied from gazebo)
    Rotation operator * (const Rotation & qt) const
    {
      Rotation c;

      c.x = this->w * qt.x + this->x * qt.w + this->y * qt.z - this->z * qt.y;
      c.y = this->w * qt.y - this->x * qt.z + this->y * qt.w + this->z * qt.x;
      c.z = this->w * qt.z + this->x * qt.y - this->y * qt.x + this->z * qt.w;
      c.w = this->w * qt.w - this->x * qt.x - this->y * qt.y - this->z * qt.z;

      return c;
    }

    // / Rotate a vector using the quaternion
    Vector3 operator * (Vector3 vec) const
    {
      Rotation tmp;
      Vector3  result;

      tmp.w = 0.0;
      tmp.x = vec.x;
      tmp.y = vec.y;
      tmp.z = vec.z;

      tmp = ( *this ) * ( tmp * this->GetInverse( ) );

      result.x = tmp.x;
      result.y = tmp.y;
      result.z = tmp.z;

      return result;
    }

    // Get the inverse of this quaternion
    Rotation GetInverse ( ) const
    {
      Rotation q;

      double norm = this->w * this->w + this->x * this->x + this->y * this->y + this->z * this->z;

      if ( norm > 0.0 )
      {
        q.w = this->w / norm;
        q.x = -this->x / norm;
        q.y = -this->y / norm;
        q.z = -this->z / norm;
      }

      return q;
    }
  };

  class Pose
  {
public:
    Pose( ) { this->clear( ); }

    Vector3  position;
    Rotation rotation;

    void clear ( )
    {
      this->position.clear( );
      this->rotation.clear( );
    }
  };

  class Twist
  {
public:
    Twist( ) { this->clear( ); }

    Vector3 linear;

    // Angular velocity represented by Euler angles
    Vector3 angular;

    void clear ( )
    {
      this->linear.clear( );
      this->angular.clear( );
    }
  };

  class Color
  {
public:
    Color( ) { this->clear( ); }
    float r;
    float g;
    float b;
    float a;

    void clear ( )
    {
      r = g = b = 0.0f;
      a = 1.0f;
    }

    bool init (const std::string & vector_str)
    {
      this->clear( );
      std::vector<std::string> pieces;
      std::vector<float>       rgba;
      boost::split(pieces, vector_str, boost::is_any_of(" ") );

      for ( unsigned int i = 0; i < pieces.size( ); ++i )
      {
        if ( !pieces[i].empty( ) )
        {
          try
          {
            rgba.push_back(boost::lexical_cast<float>(pieces[i].c_str( ) ) );
          }
          catch ( boost::bad_lexical_cast & /*e*/ )
          {
            return false;
          }
        }
      }

      if ( rgba.size( ) != 4 )
      {
        return false;
      }

      this->r = rgba[0];
      this->g = rgba[1];
      this->b = rgba[2];
      this->a = rgba[3];

      return true;
    }
  };

  class JointDynamics
  {
public:
    JointDynamics( ) { this->clear( ); }
    double damping;
    double friction;

    void clear ( )
    {
      damping  = 0;
      friction = 0;
    }
  };

  class JointLimits
  {
public:
    JointLimits( ) { this->clear( ); }
    double lower;
    double upper;
    double effort;
    double velocity;

    void clear ( )
    {
      lower    = 0;
      upper    = 0;
      effort   = 0;
      velocity = 0;
    }
  };

  // / \brief Parameters for Joint Safety Controllers
  class JointSafety
  {
public:

    // / clear variables on construction
    JointSafety( ) { this->clear( ); }

    // /
    // / IMPORTANT:  The safety controller support is very much PR2 specific, not intended for generic usage.
    // /
    // / Please see wiki for more details: http://www.ros.org/wiki/pr2_controller_manager/safety_limits
    // /
    double soft_upper_limit;
    double soft_lower_limit;
    double k_position;
    double k_velocity;

    void clear ( )
    {
      soft_upper_limit = 0;
      soft_lower_limit = 0;
      k_position       = 0;
      k_velocity       = 0;
    }
  };

  class JointCalibration
  {
public:
    JointCalibration( ) { this->clear( ); }
    double          reference_position;
    DoubleSharedPtr rising, falling;

    void clear ( )
    {
      reference_position = 0;
    }
  };

  class JointMimic
  {
public:
    JointMimic( ) { this->clear( ); }
    double      offset;
    double      multiplier;
    std::string joint_name;

    void clear ( )
    {
      offset     = 0.0;
      multiplier = 0.0;
      joint_name.clear( );
    }
  };

  class Joint
  {
public:

    Joint( ) { this->clear( ); }

    std::string name;
    enum
    {
      UNKNOWN = 0, REVOLUTE, CONTINUOUS, PRISMATIC, FLOATING, PLANAR, FIXED
    }
    type;

    Vector3 axis;

    // / child Link element
    // /   child link frame is the same as the Joint frame
    std::string child_link_name;

    // / parent Link element
    // /   origin specifies the transform from Parent Link to Joint Frame
    std::string parent_link_name;

    // / transform from Parent Link frame to Joint frame
    Pose parent_to_joint_origin_transform;

    // / Joint Dynamics
    JointDynamicsSharedPtr dynamics;

    // / Joint Limits
    JointLimitsSharedPtr limits;

    // / Unsupported Hidden Feature
    JointSafetySharedPtr safety;

    // / Unsupported Hidden Feature
    JointCalibrationSharedPtr calibration;

    // / Option to Mimic another Joint
    JointMimicSharedPtr mimic;

    void clear ( )
    {
      this->axis.clear( );
      this->child_link_name.clear( );
      this->parent_link_name.clear( );
      this->parent_to_joint_origin_transform.clear( );
      this->dynamics.reset( );
      this->limits.reset( );
      this->safety.reset( );
      this->calibration.reset( );
      this->mimic.reset( );
      this->type = UNKNOWN;
    }
  };

  class Geometry
  {
public:
    enum { SPHERE, BOX, CYLINDER, MESH } type;

    virtual ~Geometry(void)
    { }
  };

  class Sphere : public Geometry
  {
public:
    Sphere( ) { this->clear( ); type = SPHERE; }
    double radius;

    void clear ( )
    {
      radius = 0;
    }
  };

  class Box : public Geometry
  {
public:
    Box( ) { this->clear( ); type = BOX; }
    Vector3 dim;

    void clear ( )
    {
      this->dim.clear( );
    }
  };

  class Cylinder : public Geometry
  {
public:
    Cylinder( ) { this->clear( ); type = CYLINDER; }
    double length;
    double radius;

    void clear ( )
    {
      length = 0;
      radius = 0;
    }
  };

  class Mesh : public Geometry
  {
public:
    Mesh( ) { this->clear( ); type = MESH; }
    std::string filename;
    Vector3     scale;

    void clear ( )
    {
      filename.clear( );

      // default scale
      scale.x = 1;
      scale.y = 1;
      scale.z = 1;
    }
  };

  class Material
  {
public:
    Material( ) { this->clear( ); }
    std::string name;
    std::string texture_filename;
    Color       color;

    void clear ( )
    {
      color.clear( );
      texture_filename.clear( );
      name.clear( );
    }
  };

  class Inertial
  {
public:
    Inertial( ) { this->clear( ); }
    Pose   origin;
    double mass;
    double ixx, ixy, ixz, iyy, iyz, izz;

    void clear ( )
    {
      origin.clear( );
      mass = 0;
      ixx  = ixy = ixz = iyy = iyz = izz = 0;
    }
  };

  class Visual
  {
public:
    Visual( ) { this->clear( ); }
    Pose              origin;
    GeometrySharedPtr geometry;

    std::string       material_name;
    MaterialSharedPtr material;

    void clear ( )
    {
      origin.clear( );
      material_name.clear( );
      material.reset( );
      geometry.reset( );
      name.clear( );
    }

    std::string name;
  };

  class Collision
  {
public:
    Collision( ) { this->clear( ); }
    Pose              origin;
    GeometrySharedPtr geometry;

    void clear ( )
    {
      origin.clear( );
      geometry.reset( );
      name.clear( );
    }

    std::string name;
  };

  class Link
  {
public:
    Link( ) { this->clear( ); }

    std::string name;

    // / inertial element
    InertialSharedPtr inertial;

    // / visual element
    VisualSharedPtr visual;

    // / collision element
    CollisionSharedPtr collision;

    // / if more than one collision element is specified, all collision elements are placed in this array (the collision member points to the first element of the array)
    std::vector<CollisionSharedPtr> collision_array;

    // / if more than one visual element is specified, all visual elements are placed in this array (the visual member points to the first element of the array)
    std::vector<VisualSharedPtr> visual_array;

    // / Parent Joint element
    // /   explicitly stating "parent" because we want directional-ness for tree structure
    // /   every link can have one parent
    JointSharedPtr parent_joint;

    std::vector<JointSharedPtr> child_joints;
    std::vector<LinkSharedPtr>  child_links;

    LinkSharedPtr getParent ( ) const
    { return parent_link_.lock( ); }

    void setParent (const LinkSharedPtr & parent)
    { parent_link_ = parent; }

    void clear ( )
    {
      this->name.clear( );
      this->inertial.reset( );
      this->visual.reset( );
      this->collision.reset( );
      this->parent_joint.reset( );
      this->child_joints.clear( );
      this->child_links.clear( );
      this->collision_array.clear( );
      this->visual_array.clear( );
    }

private:
    LinkWeakPtr parent_link_;
  };

  class Time
  {
public:
    Time( ) { this->clear( ); }

    void set (double _seconds)
    {
      this->sec  = (int32_t) ( floor(_seconds) );
      this->nsec = (int32_t) ( round( ( _seconds - this->sec ) * 1e9) );
      this->Correct( );
    }

    operator double ( )
    {
      return static_cast<double>( this->sec )
             + static_cast<double>( this->nsec ) * 1e-9;
    };

    int32_t sec;
    int32_t nsec;

    void clear ( )
    {
      this->sec  = 0;
      this->nsec = 0;
    }

private:
    void Correct ( )
    {
      // Make any corrections
      if ( this->nsec >= 1e9 )
      {
        this->sec++;
        this->nsec = (int32_t) ( this->nsec - 1e9 );
      }
      else if ( this->nsec < 0 )
      {
        this->sec--;
        this->nsec = (int32_t) ( this->nsec + 1e9 );
      }
    }
  };

  class JointState
  {
public:
    JointState( ) { this->clear( ); }

    // / joint name
    std::string joint;

    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> effort;

    void clear ( )
    {
      this->joint.clear( );
      this->position.clear( );
      this->velocity.clear( );
      this->effort.clear( );
    }
  };

  class ModelState
  {
public:
    ModelState( ) { this->clear( ); }

    // / state name must be unique
    std::string name;

    Time time_stamp;

    void clear ( )
    {
      this->name.clear( );
      this->time_stamp.set(0);
      this->joint_states.clear( );
    }

    std::vector<JointStateSharedPtr> joint_states;
  };

  class ModelInterface
  {
public:
    LinkConstSharedPtr getRoot (void) const { return this->root_link_; }
    LinkConstSharedPtr getLink (const std::string & name) const
    {
      LinkConstSharedPtr ptr;

      if ( this->links_.find(name) == this->links_.end( ) )
      {
        ptr.reset( );
      }
      else
      {
        ptr = this->links_.find(name)->second;
      }
      return ptr;
    }

    JointConstSharedPtr getJoint (const std::string & name) const
    {
      JointConstSharedPtr ptr;

      if ( this->joints_.find(name) == this->joints_.end( ) )
      {
        ptr.reset( );
      }
      else
      {
        ptr = this->joints_.find(name)->second;
      }
      return ptr;
    }

    const std::string & getName ( ) const { return name_; }
    void getLinks (std::vector<LinkSharedPtr> & links) const
    {
      for ( std::map<std::string, LinkSharedPtr>::const_iterator link = this->links_.begin( ); link != this->links_.end( ); link++ )
      {
        links.push_back(link->second);
      }
    }

    void clear ( )
    {
      name_.clear( );
      this->links_.clear( );
      this->joints_.clear( );
      this->materials_.clear( );
      this->root_link_.reset( );
    }

    // / non-const getLink()
    void getLink (const std::string & name, LinkSharedPtr & link) const
    {
      LinkSharedPtr ptr;

      if ( this->links_.find(name) == this->links_.end( ) )
      {
        ptr.reset( );
      }
      else
      {
        ptr = this->links_.find(name)->second;
      }
      link = ptr;
    }

    // / non-const getMaterial()
    MaterialSharedPtr getMaterial (const std::string & name) const
    {
      MaterialSharedPtr ptr;

      if ( this->materials_.find(name) == this->materials_.end( ) )
      {
        ptr.reset( );
      }
      else
      {
        ptr = this->materials_.find(name)->second;
      }
      return ptr;
    }

    void initTree (std::map<std::string, std::string> & parent_link_tree)
    {
      // loop through all joints, for every link, assign children links and children joints
      for ( std::map<std::string, JointSharedPtr>::iterator joint = this->joints_.begin( ); joint != this->joints_.end( ); joint++ )
      {
        std::string parent_link_name = joint->second->parent_link_name;
        std::string child_link_name  = joint->second->child_link_name;

        if ( parent_link_name.empty( ) || child_link_name.empty( ) )
        {
          throw ParseError("Joint [" + joint->second->name + "] is missing a parent and/or child link specification.");
        }
        else
        {
          // find child and parent links
          LinkSharedPtr child_link, parent_link;
          this->getLink(child_link_name, child_link);

          if ( !child_link )
          {
            throw ParseError("child link [" + child_link_name + "] of joint [" + joint->first + "] not found");
          }
          this->getLink(parent_link_name, parent_link);

          if ( !parent_link )
          {
            throw ParseError("parent link [" + parent_link_name + "] of joint [" + joint->first + "] not found.  This is not valid according to the URDF spec. Every link you refer to from a joint needs to be explicitly defined in the robot description. To fix this problem you can either remove this joint [" + joint->first + "] from your urdf file, or add \"<link name=\"" + parent_link_name + "\" />\" to your urdf file.");
          }

          // set parent link for child link
          child_link->setParent(parent_link);

          // set parent joint for child link
          child_link->parent_joint = joint->second;

          // set child joint for parent link
          parent_link->child_joints.push_back(joint->second);

          // set child link for parent link
          parent_link->child_links.push_back(child_link);

          // fill in child/parent string map
          parent_link_tree[child_link->name] = parent_link_name;
        }
      }
    }

    void initRoot (const std::map<std::string, std::string> & parent_link_tree)
    {
      this->root_link_.reset( );

      // find the links that have no parent in the tree
      for ( std::map<std::string, LinkSharedPtr>::const_iterator l = this->links_.begin( ); l != this->links_.end( ); l++ )
      {
        std::map<std::string, std::string>::const_iterator parent = parent_link_tree.find(l->first);

        if ( parent == parent_link_tree.end( ) )
        {
          // store root link
          if ( !this->root_link_ )
          {
            getLink(l->first, this->root_link_);
          }

          // we already found a root link
          else
          {
            throw ParseError("Two root links found: [" + this->root_link_->name + "] and [" + l->first + "]");
          }
        }
      }

      if ( !this->root_link_ )
      {
        throw ParseError("No root link found. The robot xml is not a valid tree.");
      }
    }

    // / \brief complete list of Links
    std::map<std::string, LinkSharedPtr> links_;

    // / \brief complete list of Joints
    std::map<std::string, JointSharedPtr> joints_;

    // / \brief complete list of Materials
    std::map<std::string, MaterialSharedPtr> materials_;

    // / \brief The name of the robot model
    std::string name_;

    // / \brief The root is always a link (the parent of the tree describing the robot)
    LinkSharedPtr root_link_;
  };
};

namespace urdf_export_helpers
{
  std::string values2str (unsigned int count, const double *values, double ( *conv )(double) = NULL);
  std::string values2str (urdf::Vector3 vec);
  std::string values2str (urdf::Rotation rot);
  std::string values2str (urdf::Color c);
  std::string values2str (double d);
}
