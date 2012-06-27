(define (problem kitting-problem)
	(:domain kitting-domain)
	(:objects
		robot_1 - Robot
		kit_tray_1 - KitTray
		kit_1 - Kit
		empty_kit_tray_supply - LargeBoxWithEmptyKitTrays
		finished_kit_receiver - LargeBoxWithKits 
		work_table_1 - WorkTable
		part_a_tray part_b_tray part_c_tray - PartsTray
		part_a_1 part_a_2 part_b_1 part_c_1 - Part 
		part_gripper tray_gripper - VacuumEffectorSingleCup
		part_gripper_holder tray_gripper_holder - EndEffectorHolder
	)


	(:init
		(r-no-eff robot_1)			
		(lbwekt-not-empty empty_kit_tray_supply)	
		(lbwk-not-full finished_kit_receiver)		
		(part-tray-not-empty part_a_tray)
		(part-tray-not-empty part_b_tray) 
		(part-tray-not-empty part_c_tray)
		(eff-location part_gripper part_gripper_holder)
		(eff-location tray_gripper tray_gripper_holder) 
		(effhhold-eff part_gripper_holder part_gripper)
		(effhhold-eff tray_gripper_holder tray_gripper)
		(worktable-empty work_table_1) 
		(part-location part_a_1 part_a_tray)
		(part-location part_a_2 part_a_tray) 
		(part-location part_b_1 part_b_tray)
		(part-location part_c_1 part_c_tray) 
		(kit-tray-location kit_tray_1 empty_kit_tray_supply)
		(efftype part_gripper part_a_1)
		(efftype part_gripper part_a_2)
		(efftype part_gripper part_b_1)
		(efftype part_gripper part_c_1)
		(efftype tray_gripper kit_tray_1)
		(efftype tray_gripper kit_1)
		;not(effh-empty part_gripper_holder)
		;not(effh-empty tray_gripper_holder)
	)
	
	
	(:goal
	  (and  
	    (part-location part_a_1 kit_1) 
	    (part-location part_a_2 kit_1) 
	    (part-location part_b_1 kit_1) 
	    (part-location part_c_1 kit_1) 
	    (kit-location kit_1 finished_kit_receive)
	   )
	)
)
