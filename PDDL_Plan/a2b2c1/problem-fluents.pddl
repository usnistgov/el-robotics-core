(define (problem kitting-problem)
	(:domain kitting-domain)
	(:objects
		robot_1 - Robot
		changing_station_1 - EndEffectorChangingStation
		kit_tray_1 - KitTray
		kit_a2b2c1 - Kit
		empty_kit_tray_supply - LargeBoxWithEmptyKitTrays
		finished_kit_receiver - LargeBoxWithKits 
		work_table_1 - WorkTable
		part_a_tray part_b_tray part_c_tray - PartsTray
		part_a_4 part_a_2 part_a_3 part_a_1 part_b_1 part_b_2 part_b_3 part_b_4 part_c_1 part_c_2 part_c_3 part_c_4 - Part 
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
		(partstray-not-empty part_a_tray)
		(partstray-not-empty part_b_tray) 
		(partstray-not-empty part_c_tray)
		(endeffector-location-endeffectorholder part_gripper part_gripper_holder)
		(endeffector-location-endeffectorholder tray_gripper tray_gripper_holder) 
		(endeffectorholder-holds-endeffector part_gripper_holder part_gripper)
		(endeffectorholder-holds-endeffector tray_gripper_holder tray_gripper)
		(worktable-empty work_table_1) 
		(kittray-location-lbwekt kit_tray_1 empty_kit_tray_supply)

		
		(part-location-partstray part_a_2 part_a_tray) 
		(part-location-partstray part_a_3 part_a_tray)
		(part-location-partstray part_a_4 part_a_tray)
		(part-location-partstray part_a_1 part_a_tray) 
		(part-location-partstray part_b_1 part_b_tray)
		(part-location-partstray part_b_2 part_b_tray)
		(part-location-partstray part_b_3 part_b_tray)
		(part-location-partstray part_b_4 part_b_tray)
		(part-location-partstray part_c_1 part_c_tray)
		(part-location-partstray part_c_2 part_c_tray) 
		(part-location-partstray part_c_3 part_c_tray) 
		(part-location-partstray part_c_4 part_c_tray)  
		
		(endeffector-type-part part_gripper part_a_1)
		(endeffector-type-part part_gripper part_a_2)
		(endeffector-type-part part_gripper part_a_3)
		(endeffector-type-part part_gripper part_a_4)
		(endeffector-type-part part_gripper part_b_1)
		(endeffector-type-part part_gripper part_b_2)
		(endeffector-type-part part_gripper part_b_3)
		(endeffector-type-part part_gripper part_b_4)
		(endeffector-type-part part_gripper part_c_1)
		(endeffector-type-part part_gripper part_c_2)
		(endeffector-type-part part_gripper part_c_3)
		(endeffector-type-part part_gripper part_c_4)
		(endeffector-type-kittray tray_gripper kit_tray_1)
		(endeffector-type-kit tray_gripper kit_a2b2c1)
		
		(= (capacity-kit kit_a2b2c1 part_a_tray) 2)
		(= (capacity-kit kit_a2b2c1 part_b_tray) 2)
		(= (capacity-kit kit_a2b2c1 part_c_tray) 1)
		(= (quantity-kit kit_a2b2c1 part_a_tray) 0)
		(= (quantity-kit kit_a2b2c1 part_b_tray) 0)
		(= (quantity-kit kit_a2b2c1 part_c_tray) 0)
		(= (quantity-partstray part_a_tray) 4)
		(= (quantity-partstray part_b_tray) 4)
		(= (quantity-partstray part_c_tray) 4)
		
		(origin-part part_a_2 part_a_tray)
		(origin-part part_a_3 part_a_tray)
		(origin-part part_a_4 part_a_tray)
		(origin-part part_a_1 part_a_tray)
		(origin-part part_b_1 part_b_tray)
		(origin-part part_b_2 part_b_tray)
		(origin-part part_b_3 part_b_tray)
		(origin-part part_b_4 part_b_tray)
		(origin-part part_c_1 part_c_tray)
		(origin-part part_c_2 part_c_tray)
		(origin-part part_c_3 part_c_tray)
		(origin-part part_c_4 part_c_tray)
	)

(:goal
    (and
	(= (quantity-kit kit_a2b2c1 part_a_tray) (capacity-kit kit_a2b2c1 part_a_tray))
	(= (quantity-kit kit_a2b2c1 part_b_tray) (capacity-kit kit_a2b2c1 part_b_tray))
	(= (quantity-kit kit_a2b2c1 part_c_tray) (capacity-kit kit_a2b2c1 part_c_tray))
	(kit-location-lbwk kit_a2b2c1 finished_kit_receiver)
)
)

)
