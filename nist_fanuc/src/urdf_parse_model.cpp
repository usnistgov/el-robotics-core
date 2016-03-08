//

//
//
#ifdef STANDALONEURDF
#include "urdf_model/RobotModel.h"
#include "urdf_model/rosmath.h"

#include <string>
#include <map>
#include <fstream>

#include "tinyxml.h"

#if 1
#include <stdarg.h>
static inline std::string FormatString(const char *fmt, va_list ap);
static inline std::string StrFormat(const char *fmt, ...);

// This would require rosconsole - have to cut spaghetti somewhere
#ifdef DEBUG
#define logDebug(str, ...)     std::cerr << str;
#define logError(str, ...)     std::cerr << str;
#define logInform(str, ...)    std::cerr << str;
#else
#define logDebug(str, ...)     
#define logError(str, ...)     
#define logInform(str, ...)    
#endif

static inline std::string StrFormat(const char *fmt, ...) {
    va_list argptr;

    va_start(argptr, fmt);
    std::string str = FormatString(fmt, argptr);
    va_end(argptr);
    return str;
}

static inline std::string FormatString(const char *fmt, va_list ap) {
    int m, n = (int) strlen(fmt) + 1028;
    std::string tmp(n, '0');

    while ((m = vsnprintf(&tmp[0], n - 1, fmt, ap)) < 0) {
        n = n + 1028;
        tmp.resize(n, '0');
    }

    return tmp.substr(0, m);
}
#endif
namespace urdf_export_helpers {

    std::string values2str(unsigned int count, const double *values, double ( *conv)(double)) {
        std::stringstream ss;

        for (unsigned int i = 0; i < count; i++) {
            if (i > 0) {
                ss << " ";
            }
            ss << (conv ? conv(values[i]) : values[i]);
        }
        return ss.str();
    }

    std::string values2str(urdf::Vector3 vec) {
        double xyz[3];

        xyz[0] = vec.x;
        xyz[1] = vec.y;
        xyz[2] = vec.z;
        return values2str(3, xyz);
    }

    std::string values2str(urdf::Rotation rot) {
        double rpy[3];

        rot.getRPY(rpy[0], rpy[1], rpy[2]);
        return values2str(3, rpy);
    }

    std::string values2str(urdf::Color c) {
        double rgba[4];

        rgba[0] = c.r;
        rgba[1] = c.g;
        rgba[2] = c.b;
        rgba[3] = c.a;
        return values2str(4, rgba);
    }

    std::string values2str(double d) {
        return values2str(1, &d);
    }
};

using namespace urdf_export_helpers;
namespace urdf {
    //void Rotation::setFromRPY (double roll, double pitch, double yaw)
    //{
    //	*this=_quatFromRpy(roll,pitch,yaw);
    //}

    void Rotation::getRPY(double & roll, double & pitch, double & yaw) {
        RosMatrix m;
        m = _matrixFromQuat(*this);
        _matrixToRPY(m, roll, pitch, yaw);
    }

    bool parseMaterial(Material & material, TiXmlElement *config, bool only_name_is_ok);
    bool parseLink(Link & link, TiXmlElement *config);
    bool parseJoint(Joint & joint, TiXmlElement *config);

    static std::string GetCSTableStyle() {
        std::string style;

        style += "P\n";
        style += "{\n";
        style += "	FONT-FAMILY: \"Verdana\", sans-serif;\n";
        style += "	FONT-SIZE: 70%;\n";
        style += "	LINE-HEIGHT: 12pt;\n";
        style += "	MARGIN-BOTTOM: 0px;\n";
        style += "	MARGIN-LEFT: 10px;\n";
        style += "	MARGIN-TOP: 10px\n";
        style += "}\n";

        style += "H1\n";
        style += "{\n";
        style += "	BACKGROUND-COLOR: #003366;\n";
        style += "	BORDER-BOTTOM: #336699 6px solid;\n";
        style += "	COLOR: #ffffff;\n";
        style += "	FONT-SIZE: 130%;\n";
        style += "	FONT-WEIGHT: normal;\n";
        style += "	MARGIN: 0em 0em 0em -20px;\n";
        style += "	PADDING-BOTTOM: 8px;\n";
        style += "	PADDING-LEFT: 30px;\n";
        style += "	PADDING-TOP: 16px\n";
        style += "}\n";

        style += "table.gridtable {\n";
        style += "  vertical-align: top;\n";
        style += "  BACKGROUND-COLOR: #f0f0e0;\n";
        style += "	BORDER-BOTTOM: #ffffff 0px solid;\n";
        style += "	BORDER-COLLAPSE: collapse;\n";
        style += "	BORDER-LEFT: #ffffff 0px solid;\n";
        style += "	BORDER-RIGHT: #ffffff 0px solid;\n";
        style += "	BORDER-TOP: #ffffff 0px solid;\n";
        style += "	FONT-SIZE: 70%;\n";
        style += "	MARGIN-LEFT: 10px\n";
        style += "  }\n";

        style += "td.gridtable {\n";
        style += "  vertical-align: top;\n";
        style += "	BACKGROUND-COLOR: #e7e7ce;\n";
        style += "	BORDER-BOTTOM: #ffffff 1px solid;\n";
        style += "	BORDER-LEFT: #ffffff 1px solid;\n";
        style += "	BORDER-RIGHT: #ffffff 1px solid;\n";
        style += "	BORDER-TOP: #ffffff 1px solid;\n";
        style += "	PADDING-LEFT: 3px\n";
        style += "  }\n";

        style += "th.gridtable {\n";
        style += "  vertical-align: top;\n";
        style += "	BACKGROUND-COLOR: #cecf9c;\n";
        style += "	BORDER-BOTTOM: #ffffff 1px solid;\n";
        style += "	BORDER-LEFT: #ffffff 1px solid;\n";
        style += "	BORDER-RIGHT: #ffffff 1px solid;\n";
        style += "	BORDER-TOP: #ffffff 1px solid;\n";
        style += "	COLOR: #000000;\n";
        style += "	FONT-WEIGHT: bold\n";
        style += "  }\n";

        style += "tr.gridtable {\n";
        style += " vertical-align: top;\n";
        style += "  }\n";
        return style;
    }

    /**
    std::string str = urdf::GenerateTable(model);
    Globals.WriteFile(Globals.ExeDirectory+"robotmodel.html", str);
     */
    std::string GenerateTable(ModelInterfaceSharedPtr model) {
        static const char *types[] = {"UNKNOWN", "REV", "CONT", "PRISMATIC", "FLOATING", "PLANAR", "FIXED"};
        std::string str("<HTML><HEAD><STYLE>");

        str += GetCSTableStyle() + "</STYLE></HEAD>";
        str += "<BODY>";
        str += "<H1>" + model->getName() + "</h1>";
        str += "<TABLE class='gridtable'>\n";
        str += "<TR><TH>Joint#</TH><TH>Joint<BR>name</TH><TH>Joint<BR>Type</TH><TH>Parent</TH><TH>Child</TH>\n";
        str += "<TH>Origin<BR>X</TH><TH>Origin<BR>Y</TH><TH>Origin<BR>Z</TH><TH>Origin<BR>R</TH><TH>Origin<BR>P</TH><TH>Origin<BR>Y</TH>\n";
        str += "<TH>Axis<BR>X</TH><TH>Axis<BR>Y</TH><TH>Axis<BR>Z</TH></TR>\n";
        size_t i = 0;

        for (std::map<std::string, urdf::JointSharedPtr>::iterator it = model->joints_.begin(); it != model->joints_.end(); it++) {
            str += "<TR>";
            str += StrFormat("<TD>%d</TD>\n", i);
            str += "<TD>" + (*it).second->name + "</TD>\n";
            str += StrFormat("<TD>%s</TD>\n", types[(*it).second->type]);
            str += "<TD>" + (*it).second->parent_link_name + "</TD>\n";
            str += "<TD>" + (*it).second->child_link_name + "</TD>\n";

            double roll, pitch, yaw;
            (*it).second->parent_to_joint_origin_transform.rotation.getRPY(roll, pitch, yaw);
            str += StrFormat("<TD>%6.4f</TD>\n", (*it).second->parent_to_joint_origin_transform.position.x);
            str += StrFormat("<TD>%6.4f</TD>\n", (*it).second->parent_to_joint_origin_transform.position.y);
            str += StrFormat("<TD>%6.4f</TD>\n", (*it).second->parent_to_joint_origin_transform.position.z);
            str += StrFormat("<TD>%6.4f</TD>\n", roll);
            str += StrFormat("<TD>%6.4f</TD>\n", pitch);
            str += StrFormat("<TD>%6.4f</TD>\n", yaw);

            // axis of rotation - unit vector
            str += StrFormat("<TD>%6.4f</TD>\n", (*it).second->axis.x);
            str += StrFormat("<TD>%6.4f</TD>\n", (*it).second->axis.y);
            str += StrFormat("<TD>%6.4f</TD>\n", (*it).second->axis.z);

            str += "</TR>";
            i++;
        }
        str += "</TABLE></BODY></HTML>";
        return str;
    }
    ModelInterfaceSharedPtr parseURDFFile(const std::string & path);
    ModelInterfaceSharedPtr parseURDF(const std::string & xml_string);

    /** Use:
    std::vector<urdf::JointSharedPtr>   jointinfo;
    GetInOrderJoints(status.robot_model->getRoot(), jointinfo);
    for(size_t i=0; i< jointinfo.size(); i++)
    {
    std::cout << jointinfo[i]->name.c_str() << std::endl;
    }*/
    static bool CheckExists(std::vector<JointSharedPtr> & joints, std::string name) {
        for (size_t i = 0; i < joints.size(); i++) {
            JointSharedPtr item = joints[i];
            if (item->name == name)
                return true;
        }
        return false;
    }

    void GetInOrderJoints(LinkConstSharedPtr link, std::vector<JointSharedPtr> & joints) {
        const char * jointtypes[] = {"UNKNOWN", "REVOLUTE", "CONTINUOUS", "PRISMATIC", "FLOATING", "PLANAR", "FIXED"};
        int count = 0;
        for (std::vector<LinkSharedPtr>::const_iterator child = link->child_links.begin(); child != link->child_links.end(); child++) {
            if (*child) {
                std::cout << "child(" << (count++) + 1 << "):  " << (*child)->name.c_str() << std::endl;
                for (std::vector<JointSharedPtr>::const_iterator jchild = link->child_joints.begin(); jchild != link->child_joints.end(); jchild++) {
                    std::cout << (*jchild)->name.c_str() << " Type : " << jointtypes[(*jchild)->type] << std::endl; //  " Child:" << (*jchild)->child_link_name.c_str() << " Parent:" << (*jchild)->parent_link_name.c_str() << std::endl; 

                    if ((*jchild)->type != Joint::UNKNOWN && (*jchild)->type != Joint::FIXED) {
                        std::string name = (*jchild)->name;
                        if (!CheckExists(joints, name))
                            joints.push_back(*jchild);

                    }
                }
                // first grandchild
                GetInOrderJoints(*child, joints);
            } else {
                std::cout << "root link: " << link->name << " has a null child!" << *child << std::endl;
            }
        }
    }

    void printTree(LinkConstSharedPtr link, int level) {
        level += 2;
        int count = 0;

        for (std::vector<LinkSharedPtr>::const_iterator child = link->child_links.begin(); child != link->child_links.end(); child++) {
            if (*child) {
                for (int j = 0; j < level; j++) {
                    std::cout << "  "; // indent
                }
                std::cout << "child(" << (count++) + 1 << "):  " << (*child)->name << std::endl;

                // first grandchild
                printTree(*child, level);
            } else {
                for (int j = 0; j < level; j++) {
                    std::cout << " "; // indent
                }
                std::cout << "root link: " << link->name << " has a null child!" << *child << std::endl;
            }
        }
    }
    bool parsePose(Pose & pose, TiXmlElement *xml);

    bool parseJointDynamics(JointDynamics & jd, TiXmlElement *config) {
        jd.clear();

        // Get joint damping
        const char *damping_str = config->Attribute("damping");

        if (damping_str == NULL) {
            logDebug("urdfdom.joint_dynamics: no damping, defaults to 0");
            jd.damping = 0;
        } else {
            try {
                jd.damping = boost::lexical_cast<double>(damping_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("damping value (%s) is not a float: %s", damping_str, e.what());
                return false;
            }
        }

        // Get joint friction
        const char *friction_str = config->Attribute("friction");

        if (friction_str == NULL) {
            logDebug("urdfdom.joint_dynamics: no friction, defaults to 0");
            jd.friction = 0;
        } else {
            try {
                jd.friction = boost::lexical_cast<double>(friction_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("friction value (%s) is not a float: %s", friction_str, e.what());
                return false;
            }
        }

        if ((damping_str == NULL) && (friction_str == NULL)) {
            logError("joint dynamics element specified with no damping and no friction");
            return false;
        } else {
            logDebug("urdfdom.joint_dynamics: damping %f and friction %f", jd.damping, jd.friction);
            return true;
        }
    }

    bool parseJointLimits(JointLimits & jl, TiXmlElement *config) {
        jl.clear();

        // Get lower joint limit
        const char *lower_str = config->Attribute("lower");

        if (lower_str == NULL) {
            logDebug("urdfdom.joint_limit: no lower, defaults to 0");
            jl.lower = 0;
        } else {
            try {
                jl.lower = boost::lexical_cast<double>(lower_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("lower value (%s) is not a float: %s", lower_str, e.what());
                return false;
            }
        }

        // Get upper joint limit
        const char *upper_str = config->Attribute("upper");

        if (upper_str == NULL) {
            logDebug("urdfdom.joint_limit: no upper, , defaults to 0");
            jl.upper = 0;
        } else {
            try {
                jl.upper = boost::lexical_cast<double>(upper_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("upper value (%s) is not a float: %s", upper_str, e.what());
                return false;
            }
        }

        // Get joint effort limit
        const char *effort_str = config->Attribute("effort");

        if (effort_str == NULL) {
            logError("joint limit: no effort");
            return false;
        } else {
            try {
                jl.effort = boost::lexical_cast<double>(effort_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("effort value (%s) is not a float: %s", effort_str, e.what());
                return false;
            }
        }

        // Get joint velocity limit
        const char *velocity_str = config->Attribute("velocity");

        if (velocity_str == NULL) {
            logError("joint limit: no velocity");
            return false;
        } else {
            try {
                jl.velocity = boost::lexical_cast<double>(velocity_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("velocity value (%s) is not a float: %s", velocity_str, e.what());
                return false;
            }
        }

        return true;
    }

    bool parseJointSafety(JointSafety & js, TiXmlElement *config) {
        js.clear();

        // Get soft_lower_limit joint limit
        const char *soft_lower_limit_str = config->Attribute("soft_lower_limit");

        if (soft_lower_limit_str == NULL) {
            logDebug("urdfdom.joint_safety: no soft_lower_limit, using default value");
            js.soft_lower_limit = 0;
        } else {
            try {
                js.soft_lower_limit = boost::lexical_cast<double>(soft_lower_limit_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("soft_lower_limit value (%s) is not a float: %s", soft_lower_limit_str, e.what());
                return false;
            }
        }

        // Get soft_upper_limit joint limit
        const char *soft_upper_limit_str = config->Attribute("soft_upper_limit");

        if (soft_upper_limit_str == NULL) {
            logDebug("urdfdom.joint_safety: no soft_upper_limit, using default value");
            js.soft_upper_limit = 0;
        } else {
            try {
                js.soft_upper_limit = boost::lexical_cast<double>(soft_upper_limit_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("soft_upper_limit value (%s) is not a float: %s", soft_upper_limit_str, e.what());
                return false;
            }
        }

        // Get k_position_ safety "position" gain - not exactly position gain
        const char *k_position_str = config->Attribute("k_position");

        if (k_position_str == NULL) {
            logDebug("urdfdom.joint_safety: no k_position, using default value");
            js.k_position = 0;
        } else {
            try {
                js.k_position = boost::lexical_cast<double>(k_position_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("k_position value (%s) is not a float: %s", k_position_str, e.what());
                return false;
            }
        }

        // Get k_velocity_ safety velocity gain
        const char *k_velocity_str = config->Attribute("k_velocity");

        if (k_velocity_str == NULL) {
            logError("joint safety: no k_velocity");
            return false;
        } else {
            try {
                js.k_velocity = boost::lexical_cast<double>(k_velocity_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("k_velocity value (%s) is not a float: %s", k_velocity_str, e.what());
                return false;
            }
        }

        return true;
    }

    bool parseJointCalibration(JointCalibration & jc, TiXmlElement *config) {
        jc.clear();

        // Get rising edge position
        const char *rising_position_str = config->Attribute("rising");

        if (rising_position_str == NULL) {
            logDebug("urdfdom.joint_calibration: no rising, using default value");
            jc.rising.reset();
        } else {
            try {
                jc.rising.reset(new double(boost::lexical_cast<double>(rising_position_str)));
            } catch (boost::bad_lexical_cast & e) {
                logError("risingvalue (%s) is not a float: %s", rising_position_str, e.what());
                return false;
            }
        }

        // Get falling edge position
        const char *falling_position_str = config->Attribute("falling");

        if (falling_position_str == NULL) {
            logDebug("urdfdom.joint_calibration: no falling, using default value");
            jc.falling.reset();
        } else {
            try {
                jc.falling.reset(new double(boost::lexical_cast<double>(falling_position_str)));
            } catch (boost::bad_lexical_cast & e) {
                logError("fallingvalue (%s) is not a float: %s", falling_position_str, e.what());
                return false;
            }
        }

        return true;
    }

    bool parseJointMimic(JointMimic & jm, TiXmlElement *config) {
        jm.clear();

        // Get name of joint to mimic
        const char *joint_name_str = config->Attribute("joint");

        if (joint_name_str == NULL) {
            logError("joint mimic: no mimic joint specified");
            return false;
        } else {
            jm.joint_name = joint_name_str;
        }

        // Get mimic multiplier
        const char *multiplier_str = config->Attribute("multiplier");

        if (multiplier_str == NULL) {
            logDebug("urdfdom.joint_mimic: no multiplier, using default value of 1");
            jm.multiplier = 1;
        } else {
            try {
                jm.multiplier = boost::lexical_cast<double>(multiplier_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("multiplier value (%s) is not a float: %s", multiplier_str, e.what());
                return false;
            }
        }

        // Get mimic offset
        const char *offset_str = config->Attribute("offset");

        if (offset_str == NULL) {
            logDebug("urdfdom.joint_mimic: no offset, using default value of 0");
            jm.offset = 0;
        } else {
            try {
                jm.offset = boost::lexical_cast<double>(offset_str);
            } catch (boost::bad_lexical_cast & e) {
                logError("offset value (%s) is not a float: %s", offset_str, e.what());
                return false;
            }
        }

        return true;
    }

    bool parseJoint(Joint & joint, TiXmlElement *config) {
        joint.clear();

        // Get Joint Name
        const char *name = config->Attribute("name");

        if (!name) {
            logError("unnamed joint found");
            return false;
        }
        joint.name = name;

        // Get transform from Parent Link to Joint Frame
        TiXmlElement *origin_xml = config->FirstChildElement("origin");

        if (!origin_xml) {
            logDebug("urdfdom: Joint [%s] missing origin tag under parent describing transform from Parent Link to Joint Frame, (using Identity transform).", joint.name.c_str());
            joint.parent_to_joint_origin_transform.clear();
        } else {
            if (!parsePose(joint.parent_to_joint_origin_transform, origin_xml)) {
                joint.parent_to_joint_origin_transform.clear();
                logError("Malformed parent origin element for joint [%s]", joint.name.c_str());
                return false;
            }
        }

        // Get Parent Link
        TiXmlElement *parent_xml = config->FirstChildElement("parent");

        if (parent_xml) {
            const char *pname = parent_xml->Attribute("link");

            if (!pname) {
                logInform("no parent link name specified for Joint link [%s]. this might be the root?", joint.name.c_str());
            } else {
                joint.parent_link_name = std::string(pname);
            }
        }

        // Get Child Link
        TiXmlElement *child_xml = config->FirstChildElement("child");

        if (child_xml) {
            const char *pname = child_xml->Attribute("link");

            if (!pname) {
                logInform("no child link name specified for Joint link [%s].", joint.name.c_str());
            } else {
                joint.child_link_name = std::string(pname);
            }
        }

        // Get Joint type
        const char *type_char = config->Attribute("type");

        if (!type_char) {
            logError("joint [%s] has no type, check to see if it's a reference.", joint.name.c_str());
            return false;
        }

        std::string type_str = type_char;

        if (type_str == "planar") {
            joint.type = Joint::PLANAR;
        } else if (type_str == "floating") {
            joint.type = Joint::FLOATING;
        } else if (type_str == "revolute") {
            joint.type = Joint::REVOLUTE;
        } else if (type_str == "continuous") {
            joint.type = Joint::CONTINUOUS;
        } else if (type_str == "prismatic") {
            joint.type = Joint::PRISMATIC;
        } else if (type_str == "fixed") {
            joint.type = Joint::FIXED;
        } else {
            logError("Joint [%s] has no known type [%s]", joint.name.c_str(), type_str.c_str());
            return false;
        }

        // Get Joint Axis
        if ((joint.type != Joint::FLOATING) && (joint.type != Joint::FIXED)) {
            // axis
            TiXmlElement *axis_xml = config->FirstChildElement("axis");

            if (!axis_xml) {
                logDebug("urdfdom: no axis elemement for Joint link [%s], defaulting to (1,0,0) axis", joint.name.c_str());
                joint.axis = Vector3(1.0, 0.0, 0.0);
            } else {
                if (axis_xml->Attribute("xyz")) {
                    try {
                        joint.axis.init(axis_xml->Attribute("xyz"));
                    } catch (ParseError & e) {
                        joint.axis.clear();
                        logError("Malformed axis element for joint [%s]: %s", joint.name.c_str(), e.what());
                        return false;
                    }
                }
            }
        }

        // Get limit
        TiXmlElement *limit_xml = config->FirstChildElement("limit");

        if (limit_xml) {
            joint.limits.reset(new JointLimits());

            if (!parseJointLimits(*joint.limits, limit_xml)) {
                logError("Could not parse limit element for joint [%s]", joint.name.c_str());
                joint.limits.reset();
                return false;
            }
        } else if (joint.type == Joint::REVOLUTE) {
            logError("Joint [%s] is of type REVOLUTE but it does not specify limits", joint.name.c_str());
            return false;
        } else if (joint.type == Joint::PRISMATIC) {
            logError("Joint [%s] is of type PRISMATIC without limits", joint.name.c_str());
            return false;
        }

        // Get safety
        TiXmlElement *safety_xml = config->FirstChildElement("safety_controller");

        if (safety_xml) {
            joint.safety.reset(new JointSafety());

            if (!parseJointSafety(*joint.safety, safety_xml)) {
                logError("Could not parse safety element for joint [%s]", joint.name.c_str());
                joint.safety.reset();
                return false;
            }
        }

        // Get calibration
        TiXmlElement *calibration_xml = config->FirstChildElement("calibration");

        if (calibration_xml) {
            joint.calibration.reset(new JointCalibration());

            if (!parseJointCalibration(*joint.calibration, calibration_xml)) {
                logError("Could not parse calibration element for joint  [%s]", joint.name.c_str());
                joint.calibration.reset();
                return false;
            }
        }

        // Get Joint Mimic
        TiXmlElement *mimic_xml = config->FirstChildElement("mimic");

        if (mimic_xml) {
            joint.mimic.reset(new JointMimic());

            if (!parseJointMimic(*joint.mimic, mimic_xml)) {
                logError("Could not parse mimic element for joint  [%s]", joint.name.c_str());
                joint.mimic.reset();
                return false;
            }
        }

        // Get Dynamics
        TiXmlElement *prop_xml = config->FirstChildElement("dynamics");

        if (prop_xml) {
            joint.dynamics.reset(new JointDynamics());

            if (!parseJointDynamics(*joint.dynamics, prop_xml)) {
                logError("Could not parse joint_dynamics element for joint [%s]", joint.name.c_str());
                joint.dynamics.reset();
                return false;
            }
        }

        return true;
    }

    bool parseMaterial(Material & material, TiXmlElement *config, bool only_name_is_ok) {
        bool has_rgb = false;
        bool has_filename = false;

        material.clear();

        if (!config->Attribute("name")) {
            logError("Material must contain a name attribute");
            return false;
        }

        material.name = config->Attribute("name");

        // texture
        TiXmlElement *t = config->FirstChildElement("texture");

        if (t) {
            if (t->Attribute("filename")) {
                material.texture_filename = t->Attribute("filename");
                has_filename = true;
            }
        }

        // color
        TiXmlElement *c = config->FirstChildElement("color");

        if (c) {
            if (c->Attribute("rgba")) {
                try {
                    material.color.init(c->Attribute("rgba"));
                    has_rgb = true;
                } catch (ParseError & e) {
                    material.color.clear();
                    logError(std::string("Material [" + material.name + "] has malformed color rgba values: " + e.what()).c_str());
                }
            }
        }

        if (!has_rgb && !has_filename) {
            if (!only_name_is_ok) // no need for an error if only name is ok
            {
                if (!has_rgb) {
                    logError(std::string("Material [" + material.name + "] color has no rgba").c_str());
                }

                if (!has_filename) {
                    logError(std::string("Material [" + material.name + "] not defined in file").c_str());
                }
            }
            return false;
        }
        return true;
    }

    bool parseSphere(Sphere & s, TiXmlElement *c) {
        s.clear();

        s.type = Geometry::SPHERE;

        if (!c->Attribute("radius")) {
            logError("Sphere shape must have a radius attribute");
            return false;
        }

        try {
            s.radius = boost::lexical_cast<double>(c->Attribute("radius"));
        } catch (boost::bad_lexical_cast & e) {
            std::stringstream stm;
            stm << "radius [" << c->Attribute("radius") << "] is not a valid float: " << e.what();
            logError(stm.str().c_str());
            return false;
        }

        return true;
    }

    bool parseBox(Box & b, TiXmlElement *c) {
        b.clear();

        b.type = Geometry::BOX;

        if (!c->Attribute("size")) {
            logError("Box shape has no size attribute");
            return false;
        }
        try {
            b.dim.init(c->Attribute("size"));
        } catch (ParseError & e) {
            b.dim.clear();
            logError(e.what());
            return false;
        }
        return true;
    }

    bool parseCylinder(Cylinder & y, TiXmlElement *c) {
        y.clear();

        y.type = Geometry::CYLINDER;

        if (!c->Attribute("length") ||
                !c->Attribute("radius")) {
            logError("Cylinder shape must have both length and radius attributes");
            return false;
        }

        try {
            y.length = boost::lexical_cast<double>(c->Attribute("length"));
        } catch (boost::bad_lexical_cast & /*e*/) {
            std::stringstream stm;
            stm << "length [" << c->Attribute("length") << "] is not a valid float";
            logError(stm.str().c_str());
            return false;
        }

        try {
            y.radius = boost::lexical_cast<double>(c->Attribute("radius"));
        } catch (boost::bad_lexical_cast & /*e*/) {
            std::stringstream stm;
            stm << "radius [" << c->Attribute("radius") << "] is not a valid float";
            logError(stm.str().c_str());
            return false;
        }
        return true;
    }

    bool parseMesh(Mesh & m, TiXmlElement *c) {
        m.clear();

        m.type = Geometry::MESH;

        if (!c->Attribute("filename")) {
            logError("Mesh must contain a filename attribute");
            return false;
        }

        m.filename = c->Attribute("filename");

        if (c->Attribute("scale")) {
            try {
                m.scale.init(c->Attribute("scale"));
            } catch (ParseError & e) {
                m.scale.clear();
                logError("Mesh scale was specified, but could not be parsed: %s", e.what());
                return false;
            }
        } else {
            m.scale.x = m.scale.y = m.scale.z = 1;
        }
        return true;
    }

    GeometrySharedPtr parseGeometry(TiXmlElement *g) {
        GeometrySharedPtr geom;

        if (!g) {
            return geom;
        }

        TiXmlElement *shape = g->FirstChildElement();

        if (!shape) {
            logError("Geometry tag contains no child element.");
            return geom;
        }

        std::string type_name = ((TiXmlNode *) shape)->ValueStr();

        if (type_name == "sphere") {
            Sphere *s = new Sphere();
            geom.reset(s);

            if (parseSphere(*s, shape)) {
                return geom;
            }
        } else if (type_name == "box") {
            Box *b = new Box();
            geom.reset(b);

            if (parseBox(*b, shape)) {
                return geom;
            }
        } else if (type_name == "cylinder") {
            Cylinder *c = new Cylinder();
            geom.reset(c);

            if (parseCylinder(*c, shape)) {
                return geom;
            }
        } else if (type_name == "mesh") {
            Mesh *m = new Mesh();
            geom.reset(m);

            if (parseMesh(*m, shape)) {
                return geom;
            }
        } else {
            logError("Unknown geometry type '%s'", type_name.c_str());
            return geom;
        }

        return GeometrySharedPtr();
    }

    bool parseInertial(Inertial & i, TiXmlElement *config) {
        i.clear();

        // Origin
        TiXmlElement *o = config->FirstChildElement("origin");

        if (o) {
            if (!parsePose(i.origin, o)) {
                return false;
            }
        }

        TiXmlElement *mass_xml = config->FirstChildElement("mass");

        if (!mass_xml) {
            logError("Inertial element must have a mass element");
            return false;
        }

        if (!mass_xml->Attribute("value")) {
            logError("Inertial: mass element must have value attribute");
            return false;
        }

        try {
            i.mass = boost::lexical_cast<double>(mass_xml->Attribute("value"));
        } catch (boost::bad_lexical_cast & /*e*/) {
            std::stringstream stm;
            stm << "Inertial: mass [" << mass_xml->Attribute("value")
                    << "] is not a float";
            logError(stm.str().c_str());
            return false;
        }

        TiXmlElement *inertia_xml = config->FirstChildElement("inertia");

        if (!inertia_xml) {
            logError("Inertial element must have inertia element");
            return false;
        }

        if (!(inertia_xml->Attribute("ixx") && inertia_xml->Attribute("ixy") && inertia_xml->Attribute("ixz") &&
                inertia_xml->Attribute("iyy") && inertia_xml->Attribute("iyz") &&
                inertia_xml->Attribute("izz"))) {
            logError("Inertial: inertia element must have ixx,ixy,ixz,iyy,iyz,izz attributes");
            return false;
        }
        try {
            i.ixx = boost::lexical_cast<double>(inertia_xml->Attribute("ixx"));
            i.ixy = boost::lexical_cast<double>(inertia_xml->Attribute("ixy"));
            i.ixz = boost::lexical_cast<double>(inertia_xml->Attribute("ixz"));
            i.iyy = boost::lexical_cast<double>(inertia_xml->Attribute("iyy"));
            i.iyz = boost::lexical_cast<double>(inertia_xml->Attribute("iyz"));
            i.izz = boost::lexical_cast<double>(inertia_xml->Attribute("izz"));
        } catch (boost::bad_lexical_cast & /*e*/) {
            std::stringstream stm;
            stm << "Inertial: one of the inertia elements is not a valid double:"
                    << " ixx [" << inertia_xml->Attribute("ixx") << "]"
                    << " ixy [" << inertia_xml->Attribute("ixy") << "]"
                    << " ixz [" << inertia_xml->Attribute("ixz") << "]"
                    << " iyy [" << inertia_xml->Attribute("iyy") << "]"
                    << " iyz [" << inertia_xml->Attribute("iyz") << "]"
                    << " izz [" << inertia_xml->Attribute("izz") << "]";
            logError(stm.str().c_str());
            return false;
        }
        return true;
    }

    bool parseVisual(Visual & vis, TiXmlElement *config) {
        vis.clear();

        // Origin
        TiXmlElement *o = config->FirstChildElement("origin");

        if (o) {
            if (!parsePose(vis.origin, o)) {
                return false;
            }
        }

        // Geometry
        TiXmlElement *geom = config->FirstChildElement("geometry");
        vis.geometry = parseGeometry(geom);

        if (!vis.geometry) {
            return false;
        }

        const char *name_char = config->Attribute("name");

        if (name_char) {
            vis.name = name_char;
        }

        // Material
        TiXmlElement *mat = config->FirstChildElement("material");

        if (mat) {
            // get material name
            if (!mat->Attribute("name")) {
                logError("Visual material must contain a name attribute");
                return false;
            }
            vis.material_name = mat->Attribute("name");

            // try to parse material element in place
            vis.material.reset(new Material());

            if (!parseMaterial(*vis.material, mat, true)) {
                logDebug("urdfdom: material has only name, actual material definition may be in the model");
            }
        }

        return true;
    }

    bool parseCollision(Collision & col, TiXmlElement *config) {
        col.clear();

        // Origin
        TiXmlElement *o = config->FirstChildElement("origin");

        if (o) {
            if (!parsePose(col.origin, o)) {
                return false;
            }
        }

        // Geometry
        TiXmlElement *geom = config->FirstChildElement("geometry");
        col.geometry = parseGeometry(geom);

        if (!col.geometry) {
            return false;
        }

        const char *name_char = config->Attribute("name");

        if (name_char) {
            col.name = name_char;
        }

        return true;
    }

    bool parseLink(Link & link, TiXmlElement *config) {
        link.clear();

        const char *name_char = config->Attribute("name");

        if (!name_char) {
            logError("No name given for the link.");
            return false;
        }
        link.name = std::string(name_char);

        // Inertial (optional)
        TiXmlElement *i = config->FirstChildElement("inertial");

        if (i) {
            link.inertial.reset(new Inertial());

            if (!parseInertial(*link.inertial, i)) {
                logError("Could not parse inertial element for Link [%s]", link.name.c_str());
                return false;
            }
        }

        // Multiple Visuals (optional)
        for (TiXmlElement *vis_xml = config->FirstChildElement("visual"); vis_xml; vis_xml = vis_xml->NextSiblingElement("visual")) {
            VisualSharedPtr vis;
            vis.reset(new Visual());

            if (parseVisual(*vis, vis_xml)) {
                link.visual_array.push_back(vis);
            } else {
                vis.reset();
                logError("Could not parse visual element for Link [%s]", link.name.c_str());
                return false;
            }
        }

        // Visual (optional)
        // Assign the first visual to the .visual ptr, if it exists
        if (!link.visual_array.empty()) {
            link.visual = link.visual_array[0];
        }

        // Multiple Collisions (optional)
        for (TiXmlElement *col_xml = config->FirstChildElement("collision"); col_xml; col_xml = col_xml->NextSiblingElement("collision")) {
            CollisionSharedPtr col;
            col.reset(new Collision());

            if (parseCollision(*col, col_xml)) {
                link.collision_array.push_back(col);
            } else {
                col.reset();
                logError("Could not parse collision element for Link [%s]", link.name.c_str());
                return false;
            }
        }

        // Collision (optional)
        // Assign the first collision to the .collision ptr, if it exists
        if (!link.collision_array.empty()) {
            link.collision = link.collision_array[0];
        }

        return true;
    }

    bool parsePose(Pose & pose, TiXmlElement *xml) {
        pose.clear();

        if (xml) {
            const char *xyz_str = xml->Attribute("xyz");

            if (xyz_str != NULL) {
                try {
                    pose.position.init(xyz_str);
                } catch (ParseError & e) {
                    logError(e.what());
                    return false;
                }
            }

            const char *rpy_str = xml->Attribute("rpy");

            if (rpy_str != NULL) {
                try {
                    pose.rotation.init(rpy_str);
                } catch (ParseError & e) {
                    logError(e.what());
                    return false;
                }
            }
        }
        return true;
    }

    ModelInterfaceSharedPtr parseURDFFile(const std::string & path) {
        std::ifstream stream(path.c_str());

        if (!stream) {
            logError(("File " + path + " does not exist").c_str());
            return ModelInterfaceSharedPtr();
        }

        std::string xml_str((std::istreambuf_iterator<char>(stream)),
                std::istreambuf_iterator<char>());
        return urdf::parseURDF(xml_str);
    }

    ModelInterfaceSharedPtr parseURDF(const std::string & xml_string) {
        ModelInterfaceSharedPtr model(new ModelInterface);

        model->clear();

        TiXmlDocument xml_doc;
        xml_doc.Parse(xml_string.c_str());

        if (xml_doc.Error()) {
            logError(xml_doc.ErrorDesc());
            xml_doc.ClearError();
            model.reset();
            return model;
        }

        TiXmlElement *robot_xml = xml_doc.FirstChildElement("robot");

        if (!robot_xml) {
            logError("Could not find the 'robot' element in the xml file");
            model.reset();
            return model;
        }

        // Get robot name
        const char *name = robot_xml->Attribute("name");

        if (!name) {
            logError("No name given for the robot.");
            model.reset();
            return model;
        }
        model->name_ = std::string(name);

        // Get all Material elements
        for (TiXmlElement *material_xml = robot_xml->FirstChildElement("material"); material_xml; material_xml = material_xml->NextSiblingElement("material")) {
            MaterialSharedPtr material;
            material.reset(new Material);

            try {
                parseMaterial(*material, material_xml, false); // material needs to be fully defined here

                if (model->getMaterial(material->name)) {
                    logError("material '%s' is not unique.", material->name.c_str());
                    material.reset();
                    model.reset();
                    return model;
                } else {
                    model->materials_.insert(make_pair(material->name, material));
                    logDebug("urdfdom: successfully added a new material '%s'", material->name.c_str());
                }
            } catch (ParseError & /*e*/) {
                logError("material xml is not initialized correctly");
                material.reset();
                model.reset();
                return model;
            }
        }

        // Get all Link elements
        for (TiXmlElement *link_xml = robot_xml->FirstChildElement("link"); link_xml; link_xml = link_xml->NextSiblingElement("link")) {
            LinkSharedPtr link;
            link.reset(new Link);

            try {
                parseLink(*link, link_xml);

                if (model->getLink(link->name)) {
                    logError("link '%s' is not unique.", link->name.c_str());
                    model.reset();
                    return model;
                } else {
                    // set link visual material
                    logDebug("urdfdom: setting link '%s' material", link->name.c_str());

                    if (link->visual) {
                        if (!link->visual->material_name.empty()) {
                            if (model->getMaterial(link->visual->material_name)) {
                                logDebug("urdfdom: setting link '%s' material to '%s'", link->name.c_str(), link->visual->material_name.c_str());
                                link->visual->material = model->getMaterial(link->visual->material_name.c_str());
                            } else {
                                if (link->visual->material) {
                                    logDebug("urdfdom: link '%s' material '%s' defined in Visual.", link->name.c_str(), link->visual->material_name.c_str());
                                    model->materials_.insert(make_pair(link->visual->material->name, link->visual->material));
                                } else {
                                    logError("link '%s' material '%s' undefined.", link->name.c_str(), link->visual->material_name.c_str());
                                    model.reset();
                                    return model;
                                }
                            }
                        }
                    }

                    model->links_.insert(make_pair(link->name, link));
                    logDebug("urdfdom: successfully added a new link '%s'", link->name.c_str());
                }
            } catch (ParseError & /*e*/) {
                logError("link xml is not initialized correctly");
                model.reset();
                return model;
            }
        }

        if (model->links_.empty()) {
            logError("No link elements found in urdf file");
            model.reset();
            return model;
        }

        // Get all Joint elements
        for (TiXmlElement *joint_xml = robot_xml->FirstChildElement("joint"); joint_xml; joint_xml = joint_xml->NextSiblingElement("joint")) {
            JointSharedPtr joint;
            joint.reset(new Joint);

            if (parseJoint(*joint, joint_xml)) {
                if (model->getJoint(joint->name)) {
                    logError("joint '%s' is not unique.", joint->name.c_str());
                    model.reset();
                    return model;
                } else {
                    model->joints_.insert(make_pair(joint->name, joint));
                    logDebug("urdfdom: successfully added a new joint '%s'", joint->name.c_str());
                }
            } else {
                logError("joint xml is not initialized correctly");
                model.reset();
                return model;
            }
        }

        // every link has children links and joints, but no parents, so we create a
        // local convenience data structure for keeping child->parent relations
        std::map<std::string, std::string> parent_link_tree;
        parent_link_tree.clear();

        // building tree: name mapping
        try {
            model->initTree(parent_link_tree);
        } catch (ParseError & e) {
            logError("Failed to build tree: %s", e.what());
            model.reset();
            return model;
        }

        // find the root link
        try {
            model->initRoot(parent_link_tree);
        } catch (ParseError & e) {
            logError("Failed to find root link: %s", e.what());
            model.reset();
            return model;
        }

        return model;
    }
}

#endif
