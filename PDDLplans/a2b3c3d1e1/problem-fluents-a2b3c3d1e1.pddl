(define (problem kitting-problem)
	(:domain kitting-domain)
	(:objects
		robot_1 - Robot
		changing_station_1 - EndEffectorChangingStation
		kit_tray_5_ir - KitTray
		kit_a2b3c3d1e1 - Kit
		empty_kit_tray_supply - LargeBoxWithEmptyKitTrays
		finished_kit_receiver - LargeBoxWithKits 
		work_table_1 - WorkTable
		part_a_tray_ir part_b_tray_ir part_c_tray_ir part_d_tray_ir part_e_tray_ir - PartsTray
		part_a_1_ir part_a_2_ir part_b_1_ir part_b_2_ir part_b_3_ir part_c_1_ir part_c_2_ir part_c_3_ir part_d_1_ir part_e_1_ir - Part 
		part_gripper tray_gripper - EndEffector
		part_gripper_holder tray_gripper_holder - EndEffectorHolder
	)


	(:init
		(endeffectorholder-location tray_gripper_holder changing_station_1)
		(endeffectorholder-location part_gripper_holder changing_station_1)
		(endeffectorchangingstation-contains-endeffectorholder changing_station_1 tray_gripper_holder)	
		(endeffectorchangingstation-contains-endeffectorholder changing_station_1 part_gripper_holder)
		(robot-with-no-endeffector robot_1)
		(part-not-searched)
		(lbwekt-not-empty empty_kit_tray_supply)	
		(lbwk-not-full finished_kit_receiver)		
		(partstray-not-empty part_a_tray_ir)
		(partstray-not-empty part_b_tray_ir) 
		(partstray-not-empty part_c_tray_ir)
		(partstray-not-empty part_d_tray_ir)
		(partstray-not-empty part_e_tray_ir)
		(endeffector-location-endeffectorholder part_gripper part_gripper_holder)
		(endeffector-location-endeffectorholder tray_gripper tray_gripper_holder) 
		(endeffectorholder-holds-endeffector part_gripper_holder part_gripper)
		(endeffectorholder-holds-endeffector tray_gripper_holder tray_gripper)
		(worktable-empty work_table_1) 
		(kittray-location-lbwekt kit_tray_5_ir empty_kit_tray_supply)

		
		(part-location-partstray part_a_1_ir part_a_tray_ir) 
		(part-location-partstray part_a_2_ir part_a_tray_ir)
		(part-location-partstray part_b_1_ir part_b_tray_ir)
		(part-location-partstray part_b_2_ir part_b_tray_ir)
		(part-location-partstray part_b_3_ir part_b_tray_ir)
		(part-location-partstray part_c_1_ir part_c_tray_ir)
		(part-location-partstray part_c_2_ir part_c_tray_ir)
		(part-location-partstray part_c_3_ir part_c_tray_ir)
		(part-location-partstray part_d_1_ir part_d_tray_ir)
		(part-location-partstray part_e_1_ir part_e_tray_ir)
		
		(endeffector-type-part part_gripper part_a_1_ir)
		(endeffector-type-part part_gripper part_a_2_ir)
		(endeffector-type-part part_gripper part_b_1_ir)
		(endeffector-type-part part_gripper part_b_2_ir)
		(endeffector-type-part part_gripper part_b_3_ir)
		(endeffector-type-part part_gripper part_c_1_ir)
		(endeffector-type-part part_gripper part_c_2_ir)
		(endeffector-type-part part_gripper part_c_3_ir)
		(endeffector-type-part part_gripper part_d_1_ir)
		(endeffector-type-part part_gripper part_e_1_ir)
		(endeffector-type-kittray tray_gripper kit_tray_5_ir)
		(endeffector-type-kit tray_gripper kit_a2b3c3d1e1)
		
		(= (capacity-kit kit_a2b3c3d1e1 part_a_tray_ir) 2)
		(= (capacity-kit kit_a2b3c3d1e1 part_b_tray_ir) 3)
		(= (capacity-kit kit_a2b3c3d1e1 part_c_tray_ir) 3)
		(= (capacity-kit kit_a2b3c3d1e1 part_d_tray_ir) 1)
		(= (capacity-kit kit_a2b3c3d1e1 part_e_tray_ir) 1)

		(= (quantity-kit kit_a2b3c3d1e1 part_a_tray_ir) 0)
		(= (quantity-kit kit_a2b3c3d1e1 part_b_tray_ir) 0)
		(= (quantity-kit kit_a2b3c3d1e1 part_c_tray_ir) 0)
		(= (quantity-kit kit_a2b3c3d1e1 part_d_tray_ir) 0)
		(= (quantity-kit kit_a2b3c3d1e1 part_e_tray_ir) 0)

		(= (quantity-partstray part_a_tray_ir) 2)
		(= (quantity-partstray part_b_tray_ir) 3)
		(= (quantity-partstray part_c_tray_ir) 3)
		(= (quantity-partstray part_d_tray_ir) 1)
		(= (quantity-partstray part_e_tray_ir) 1)
		
		(origin-part part_a_1_ir part_a_tray_ir)
		(origin-part part_a_2_ir part_a_tray_ir)
		(origin-part part_b_1_ir part_b_tray_ir)
		(origin-part part_b_2_ir part_b_tray_ir)
		(origin-part part_b_3_ir part_b_tray_ir)
		(origin-part part_c_1_ir part_c_tray_ir)
		(origin-part part_c_2_ir part_c_tray_ir)
		(origin-part part_c_3_ir part_c_tray_ir)
		(origin-part part_d_1_ir part_d_tray_ir)
		(origin-part part_e_1_ir part_e_tray_ir)
	)

(:goal
    (and
	(= (quantity-kit kit_a2b3c3d1e1 part_a_tray_ir) (capacity-kit kit_a2b3c3d1e1 part_a_tray_ir))
	(= (quantity-kit kit_a2b3c3d1e1 part_b_tray_ir) (capacity-kit kit_a2b3c3d1e1 part_b_tray_ir))
	(= (quantity-kit kit_a2b3c3d1e1 part_c_tray_ir) (capacity-kit kit_a2b3c3d1e1 part_c_tray_ir))
	(= (quantity-kit kit_a2b3c3d1e1 part_d_tray_ir) (capacity-kit kit_a2b3c3d1e1 part_d_tray_ir))
	(= (quantity-kit kit_a2b3c3d1e1 part_e_tray_ir) (capacity-kit kit_a2b3c3d1e1 part_e_tray_ir))
	(kit-location-lbwk kit_a2b3c3d1e1 finished_kit_receiver)
)
)

)
