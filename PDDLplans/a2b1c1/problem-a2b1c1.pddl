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
		part_c_tray part_b_tray part_a_tray - PartsTray
		part_b_1 part_a_2 part_a_1 part_c_1 - Part
		part_gripper tray_gripper - EndEffector
		part_gripper_holder tray_gripper_holder - EndEffectorHolder
		stock_keeping_unit_part_c stock_keeping_unit_part_b stock_keeping_unit_part_a stock_keeping_unit_kit_tray - StockKeepingUnit
	)
	(:init
		(endEffector-has-physicalLocation-refObject-robot tray_gripper robot_1)
		(endEffectorHolder-has-physicalLocation-refObject-changingStation part_gripper_holder changing_station_1)
		(endEffectorHolder-has-physicalLocation-refObject-changingStation tray_gripper_holder changing_station_1)
		(endEffector-has-physicalLocation-refObject-endEffectorHolder part_gripper part_gripper_holder)
		(endEffector-has-no-heldObject tray_gripper)
		(endEffector-is-for-partSKU part_gripper stock_keeping_unit_part_b)
		(endEffector-is-for-partSKU part_gripper stock_keeping_unit_part_a)
		(endEffector-is-for-partSKU part_gripper stock_keeping_unit_part_a)
		(endEffector-is-for-partSKU part_gripper stock_keeping_unit_part_c)
		(endEffectorHolder-has-endEffector part_gripper_holder part_gripper)
		(endEffectorChangingStation-has-endEffectorHolder changing_station_1 part_gripper_holder)
		(endEffectorChangingStation-has-endEffectorHolder changing_station_1 tray_gripper_holder)
		(robot-has-endEffector robot_1 tray_gripper)
		(kit-has-kitTray kit_1 kit_tray_1)
		(partsVessel-has-part  part_c_tray part_c_1)
		(partsVessel-has-part  part_b_tray part_b_1)
		(partsVessel-has-part  part_a_tray part_a_2)
		(partsVessel-has-part  part_a_tray part_a_1)
		(workTable-has-no-objectOnTable work_table_1)
		(kitTray-has-physicalLocation-refObject-lbwekt kit_tray_1 empty_kit_tray_supply)
		(kitTray-has-physicalLocation-refObject-kit kit_tray_1 kit_1)
		(kitTray-has-skuObject-sku kit_tray_1 stock_keeping_unit_kit_tray)
		(part-has-physicalLocation-refObject-partsTray part_b_1 part_b_tray)
		(part-has-physicalLocation-refObject-partsTray part_a_2 part_a_tray)
		(part-has-physicalLocation-refObject-partsTray part_a_1 part_a_tray)
		(part-has-physicalLocation-refObject-partsTray part_c_1 part_c_tray)
		(part-has-skuObject-sku part_b_1 stock_keeping_unit_part_b)
		(part-has-skuObject-sku part_a_2 stock_keeping_unit_part_a)
		(part-has-skuObject-sku part_a_1 stock_keeping_unit_part_a)
		(part-has-skuObject-sku part_c_1 stock_keeping_unit_part_c)
		(endEffector-is-for-kitTraySKU tray_gripper stock_keeping_unit_kit_tray)
		(= (capacity-of-parts-in-kit  stock_keeping_unit_part_c kit_1) 1)
		(= (capacity-of-parts-in-kit  stock_keeping_unit_part_b kit_1) 1)
		(= (capacity-of-parts-in-kit  stock_keeping_unit_part_a kit_1) 2)
		(= (quantity-of-parts-in-kit  stock_keeping_unit_part_b kit_1) 0)
		(= (quantity-of-parts-in-kit  stock_keeping_unit_part_a kit_1) 0)
		(= (quantity-of-parts-in-kit  stock_keeping_unit_part_c kit_1) 0)
		(= (quantity-of-parts-in-partstray  part_c_tray) 1)
		(= (quantity-of-parts-in-partstray  part_b_tray) 1)
		(= (quantity-of-parts-in-partstray  part_a_tray) 2)
		(= (part-found-flag) 1)
		(= (capacity-of-kits-in-lbwk finished_kit_receiver) 12)
		(= (quantity-of-kittrays-in-lbwekt empty_kit_tray_supply) 1)
		(= (quantity-of-kits-in-lbwk finished_kit_receiver) 0)
		(= (current-quantity-of-parts-in-kit kit_1) 0)
		(= (final-quantity-of-parts-in-kit kit_1) 4)
	)
	(:goal
		(and
		(kit-has-physicalLocation-refObject-lbwk kit_1 finished_kit_receiver)
		(lbwk-has-kit finished_kit_receiver kit_1)
		)
	)
)
