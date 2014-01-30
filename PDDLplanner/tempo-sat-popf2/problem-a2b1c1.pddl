(define (problem kitting-problem)
	(:domain kitting-domain)
	(:objects
		robot_1 - Robot
		changing_station_1 - EndEffectorChangingStation
		kit_tray_1 - KitTray
		kit_1 - Kit
		empty_kit_tray_supply - LargeBoxWithEmptyKitTrays
		finished_kit_receiver - LargeBoxWithKits 
		work_table_1 - WorkTable
		part_a_tray part_b_tray part_c_tray part_d_tray - PartsTray
		part_a_1 part_a_2 part_b_1 part_c_1 part_d_1 - Part 
		part_gripper tray_gripper - EndEffector
		part_gripper_holder tray_gripper_holder - EndEffectorHolder
		stock_keeping_unit_part_a stock_keeping_unit_part_b stock_keeping_unit_part_c stock_keeping_unit_part_d stock_keeping_unit_kit_tray - StockKeepingUnit
	)
		    
	(:init
	  (hasPart-SkuObject-Sku part_a_1 stock_keeping_unit_part_a)
	  (hasPart-SkuObject-Sku part_a_2 stock_keeping_unit_part_a)
	  (hasPart-SkuObject-Sku part_b_1 stock_keeping_unit_part_b)
	  (hasPart-SkuObject-Sku part_c_1 stock_keeping_unit_part_c)
	  (hasPart-SkuObject-Sku part_d_1 stock_keeping_unit_part_d)
	  
	  (hasKit-KitTray kit_1 kit_tray_1)
	  
	  (hasKitTray-SkuObject-Sku kit_tray_1 stock_keeping_unit_kit_tray)
	   
	  
	  
	  (hasEndEffector-PhysicalLocation-RefObject-EndEffectorHolder part_gripper part_gripper_holder)
	  (hasEndEffector-PhysicalLocation-RefObject-EndEffectorHolder tray_gripper tray_gripper_holder)
	  
	  (hasRobot-No-EndEffector robot_1)
	  
	  (hasWorkTable-ObjectOnTable-None work_table_1)
	  
	  (hasKitTray-PhysicalLocation-RefObject-LBWEKT kit_tray_1 empty_kit_tray_supply)	
	  
	  (hasPart-PhysicalLocation-RefObject-PartsTray part_a_1 part_a_tray)
	  (hasPart-PhysicalLocation-RefObject-PartsTray part_a_2 part_a_tray)
	  (hasPart-PhysicalLocation-RefObject-PartsTray part_b_1 part_b_tray)
	  (hasPart-PhysicalLocation-RefObject-PartsTray part_c_1 part_c_tray)
	  (hasPart-PhysicalLocation-RefObject-PartsTray part_d_1 part_d_tray)
	  
	  (hasEndEffector-HeldObject-None  part_gripper)
	  (hasEndEffector-HeldObject-None  tray_gripper)
	  
	  (hasPartsVessel-Part part_a_tray part_a_1)
	  (hasPartsVessel-Part part_a_tray part_a_2)
	  (hasPartsVessel-Part part_b_tray part_b_1)
	  (hasPartsVessel-Part part_c_tray part_c_1)
	  (hasPartsVessel-Part part_d_tray part_d_1)
	  
	  (hasEndEffector-For-Sku-KitTray tray_gripper stock_keeping_unit_kit_tray)
	  
	  (hasEndEffector-For-Sku-Part part_gripper stock_keeping_unit_part_a)
	  (hasEndEffector-For-Sku-Part part_gripper stock_keeping_unit_part_b)
	  (hasEndEffector-For-Sku-Part part_gripper stock_keeping_unit_part_c)
	  (hasEndEffector-For-Sku-Part part_gripper stock_keeping_unit_part_d)
	  
	  (hasEndEffectorHolder-EndEffector part_gripper_holder part_gripper)
	  (hasEndEffectorHolder-EndEffector tray_gripper_holder tray_gripper)
	  
	  (hasEndEffectorHolder-PhysicalLocation-RefObject-ChangingStation part_gripper_holder changing_station_1)
	  (hasEndEffectorHolder-PhysicalLocation-RefObject-ChangingStation tray_gripper_holder changing_station_1)
	  
	  (hasEndEffectorChangingStation-EndEffectorHolder changing_station_1 part_gripper_holder)
	  (hasEndEffectorChangingStation-EndEffectorHolder changing_station_1 tray_gripper_holder)

	  
	  (= (quantity-of-parts-in-partstray part_a_tray) 2)
	  (= (quantity-of-parts-in-partstray part_b_tray) 1)
	  (= (quantity-of-parts-in-partstray part_c_tray) 1)
	  (= (quantity-of-parts-in-partstray part_d_tray) 1)
	  
	  (= (quantity-of-parts-in-kit stock_keeping_unit_part_a kit_1) 0)
	  (= (quantity-of-parts-in-kit stock_keeping_unit_part_b kit_1) 0)
	  (= (quantity-of-parts-in-kit stock_keeping_unit_part_c kit_1) 0)
	  (= (quantity-of-parts-in-kit stock_keeping_unit_part_d kit_1) 0)
	  
	  (= (quantity-of-kittrays-in-lbwekt empty_kit_tray_supply) 1)
	  
	  (= (quantity-of-kits-in-lbwk finished_kit_receiver) 0)
	  
	  (= (capacity-of-parts-in-kit stock_keeping_unit_part_a kit_1) 2)
	  (= (capacity-of-parts-in-kit stock_keeping_unit_part_b kit_1) 1)
	  (= (capacity-of-parts-in-kit stock_keeping_unit_part_c kit_1) 1)
	  (= (capacity-of-parts-in-kit stock_keeping_unit_part_d kit_1) 0)
	  
	  (= (capacity-of-kits-in-lbwk finished_kit_receiver) 12)
	  (= (current-quantity-kit kit_1) 0)
	  (= (final-quantity-kit kit_1) 4)
	    
	  (= (part-found-flag) 1)
	)
	
(:goal
    (and
	(hasKit-PhysicalLocation-RefObject-LBWK kit_1 finished_kit_receiver)
	(hasLBWK-Kit finished_kit_receiver kit_1)
) 
)

)
