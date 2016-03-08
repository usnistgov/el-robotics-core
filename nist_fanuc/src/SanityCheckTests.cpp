       ///////////////////////////////////////////////////////////
        // Test FK IK and other kinematics
        std::vector<double> testjoints;
        std::vector<double> testjoints2;
        double  roll,   pitch,   yaw;
        urdf::Pose testpose;
       
        testjoints = RCS::Controller.Kinematics()->GetJointValues();
        std::cout << "Test Joints2 " << VectorDump<double>(testjoints).c_str();
        cjoints = jointReader->GetCurrentReadings();
        std::cout << "Actual Joints " << VectorDump<double>(cjoints.position).c_str();

        RCS::Controller.Kinematics()->SetJointValues(cjoints.position);
        testjoints = RCS::Controller.Kinematics()->GetJointValues();
        std::cout << "Test All zero Joints after real fetch" << VectorDump<double>(testjoints).c_str();
        testpose = RCS::Controller.Kinematics()->FK(testjoints);
        std::cout << "Dump All zero FK test Pose " << RCS::DumpPose(testpose).c_str();
        _quatToRpy (testpose.rotation,  roll,  pitch,  yaw);
        std::cout << "Dump rotation in RPY" << roll << ":" <<  pitch << ":"<<   yaw << std::endl;
        testjoints2 = RCS::Controller.Kinematics()->IK(testpose, testjoints);
        std::cout << "IK All zero Test Joints " << VectorDump<double>(testjoints2).c_str();
        std::cout << "If you did not get all zeros stop now!\n ";
       
        
        testjoints2 = ToVector<double>(6, 0.0, 1.0, 2.0, 3.0, 0.0, 0.0);
        std::cout << "Set Test Joints " << VectorDump<double>(testjoints2).c_str();
        testpose = RCS::Controller.Kinematics()->FK(testjoints2);
        std::cout << "Dump FK test Pose " << RCS::DumpPose(testpose).c_str();
        testjoints2 = RCS::Controller.Kinematics()->IK(testpose, testjoints);
        std::cout << "IK Test Joints " << VectorDump<double>(testjoints2).c_str();

// CRCL conversion urdf pose test
#if 0
        std::vector<double> terms = ToVector<double>(9, 0.4643, 0.02436, 1.275, 0.01676, 0.08284, 0.9964, 0.2896, 0.9535, -0.08413);
        PoseType test1(Crcl::Init(terms));
        std::cout << "CRCL Pose " << Crcl::DumpPose(test1, ",").c_str() << std::endl;
        urdf::Pose goalpose=Crcl::Convert(test1);
        std::cout << "Urdf Pose " << RCS::DumpPose(goalpose).c_str();
#endif 

/// Program test         

Crcl::CrclDelegateInterface mycrcl;
        std::string contents;
//        Globals.ReadFile("/home/michalos/catkin_ws/src/fanucdemo/doc/commandSetTransSpeed1.xml", contents);
//        mycrcl.DelegateCRCLCmd(contents);
//        contents.clear();
        Globals.ReadFile("/home/michalos/catkin_ws/src/fanucdemo/doc/programExample.xml", contents);
        mycrcl.DelegateCRCLCmd(contents);

