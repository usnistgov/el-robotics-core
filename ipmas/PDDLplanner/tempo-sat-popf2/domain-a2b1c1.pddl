    (define (domain kitting-domain)
	   (:requirements :strips :typing :derived-predicates :action-costs :fluents :equality)
	    (:types 
		    EndEffector
		    EndEffectorHolder 
		    Kit 
		    KitTray
		    LargeBoxWithEmptyKitTrays 
		    LargeBoxWithKits
		    Part 
		    PartsTray 
		    EndEffectorChangingStation
		    Robot 
		    StockKeepingUnit
		    WorkTable)

    (:predicates
	    ; ?kit exists
	    (isExist-Kit ?kit - Kit)
	    
	    ; ?part has ?sku
	    (hasPart-SkuObject-Sku ?part - Part ?sku - StockKeepingUnit)
	    
	    ; ?kit has ?kittray
	    (hasKit-KitTray ?kit - Kit ?kittray - KitTray)
	    
	    ; ?kittray has ?sku
	    (hasKitTray-SkuObject-Sku ?kittray - KitTray ?sku - StockKeepingUnit)
	    
	    ; ?endeffector is attached to ?robot
	    (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector - EndEffector ?robot - Robot)	
		    
	    ; ?endeffector is in ?endeffectorholder
	    (hasEndEffector-PhysicalLocation-RefObject-EndEffectorHolder ?endeffector - EndEffector ?endeffectorholder - EndEffectorHolder)

	    ;TRUE iff ?robot is equipped with ?endeffector
	    (hasRobot-EndEffector ?robot - Robot ?endeffector - EndEffector)				
		    
	    ;TRUE iff ?robot is not equipped with ?endeffector
	    (hasRobot-No-EndEffector ?robot - Robot)						
		    
	    ;TRUE iff ?kit is on ?worktable		
	    (hasWorkTable-ObjectOnTable-Kit ?worktable - WorkTable ?kit - Kit)
		    
	    ;TRUE iff ?kittray is on ?worktable
	    (hasWorkTable-ObjectOnTable-KitTray ?worktable - WorkTable ?kittray - KitTray)	
	    
	    
	    ;TRUE iff ?worktable is empty (nothing on top of it)
	    (hasWorkTable-ObjectOnTable-None ?worktable - WorkTable)
	    
	    
	    ;TRUE iff ?kit is in ?largeboxwithkits	
	    (hasKit-PhysicalLocation-RefObject-LBWK ?kit - Kit ?largeboxwithkits - LargeBoxWithKits)
	    
	    ;TRUE iff ?kit is on ?worktable
	    (hasKit-PhysicalLocation-RefObject-WorkTable ?kit - Kit ?worktable - WorkTable)
	    
	    ;?kit is held by ?endeffector		
	    (hasKit-PhysicalLocation-RefObject-EndEffector ?kit - Kit ?endeffector - EndEffector)
	    
	    ;TRUE iff ?kittray is in ?largeboxwithemptykittrays
	    (hasKitTray-PhysicalLocation-RefObject-LBWEKT ?kittray - KitTray ?lbwekt - LargeBoxWithEmptyKitTrays)	

	    ;TRUE iff ?kittray is being held by ?robot
	    (hasKitTray-PhysicalLocation-RefObject-EndEffector ?kittray - KitTray ?endeffector - EndEffector)
	    
	    (hasKitTray-PhysicalLocation-RefObject-Kit ?kittray - KitTray ?kit - Kit)
	    
	    ;TRUE iff ?kittray is on ?worktable
	    (hasKitTray-PhysicalLocation-RefObject-WorkTable ?kittray - KitTray ?worktable - WorkTable)
	    
	    ;TRUE iff ?part is in ?partstray
	    (hasPart-PhysicalLocation-RefObject-PartsTray ?part - Part ?partstray - PartsTray)					
	    
	    ;TRUE iff ?part is in ?kit
	    (hasPart-PhysicalLocation-RefObject-Kit ?part - Part ?kit - Kit)			
		    
	    ;TRUE iff ?part is being held by ?robot
	    (hasPart-PhysicalLocation-RefObject-EndEffector ?part - Part ?endeffector - EndEffector)	
	    
	    ;TRUE iff ?robot is holding ?kittray
	    (hasEndEffector-HeldObject-KitTray ?endeffector - EndEffector ?kittray - KitTray)

	    ;TRUE iff ?robot is holding ?kit
	    (hasEndEffector-HeldObject-Kit ?endeffector - EndEffector ?kit - Kit)				
		    
	    ;TRUE iff ?robot is holding ?part
	    (hasEndEffector-HeldObject-Part ?endeffector - EndEffector ?part - Part)					
			    
	    ;TRUE iff ?robot is equipped with an endeffector and the endeffector is not holding anything
	    (hasEndEffector-HeldObject-None ?endeffector - EndEffector)
	    
	    (hasLBWK-Kit ?larboxwithkits - LargeBoxWithKits ?kit - Kit)	

	    
	    ;TRUE iff ?partstray has ?part		
	    (hasPartsVessel-Part ?partstray - PartsTray ?part - Part)
	    
	    ;TRUE iff ?endeffector is capable of holding ?kittray						
	    (hasEndEffector-For-Sku-KitTray ?endeffector - EndEffector ?sku - StockKeepingUnit)

	    ;TRUE iff ?endeffector is capable of holding ?part
	    (hasEndEffector-For-Sku-Part ?endeffector - EndEffector ?sku - StockKeepingUnit)

	    ;TRUE iff ?endeffectorholder is holding endeffector				
	    (hasEndEffectorHolder-EndEffector ?endeffectorholder - EndEffectorHolder ?endeffector - EndEffector)	

	    ;TRUE iff ?endeffectorholder is empty (?endeffectorholder does not hold an endeffector)		
	    (hasEndEffectorHolder-EndEffector-None ?endeffectorholder - EndEffectorHolder)

	    ;TRUE iff ?endeffectorholder is in ?endeffectorchangingstation		
	    (hasEndEffectorHolder-PhysicalLocation-RefObject-ChangingStation ?endeffectorholder - EndEffectorHolder ?changingstation - EndEffectorChangingStation)	

	    ;TRUE iff ?endeffectorchangingstation contains ?endeffectorholder
	    (hasEndEffectorChangingStation-EndEffectorHolder ?changingstation - EndEffectorChangingStation ?endeffectorholder - EndEffectorHolder)	

	    ;TRUE if ?part is found in ?partstray
	    (found-part ?part - Part)
    )

    ;Functions are used to manipulate numbers
    (:functions 

	    (quantity-of-parts-in-partstray ?partstray - PartsTray)
	    (quantity-of-parts-in-kit ?sku - StockKeepingUnit ?kit - Kit)
	    (quantity-of-kittrays-in-lbwekt ?lbwekt - LargeBoxWithEmptyKitTrays)
	    (quantity-of-kits-in-lbwk ?lbwk - LargeBoxWithKits)
	    (current-quantity-kit ?kit - Kit)
	    (final-quantity-kit ?kit - Kit)
	    (capacity-of-parts-in-kit ?partsku - StockKeepingUnit ?kit - Kit)
	    (capacity-of-kits-in-lbwk ?lbwk - LargeBoxWithKits)
	    (part-found-flag)
    )

    ;Take the KitTray ?kittray from the LargeBoxWithEmptyKitTrays ?lbwekt
    ; ?robot must have an effector attached to it that can handle kit trays
    (:action Take-KitTray
	    :parameters(
		    ?robot - Robot 
		    ?kittray - KitTray 
		    ?lbwekt - LargeBoxWithEmptyKitTrays 
		    ?endeffector - EndEffector 
		    ?sku - StockKeepingUnit)
	    :precondition(and 
		    (> (quantity-of-kittrays-in-lbwekt ?lbwekt) 0)
		    (hasEndEffector-HeldObject-None ?endeffector)
		    (hasEndEffector-For-Sku-KitTray ?endeffector ?sku)
		    (hasRobot-EndEffector ?robot ?endeffector) 					
		    (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot)		
		    (hasKitTray-SkuObject-Sku ?kittray ?sku)
		    (hasKitTray-PhysicalLocation-RefObject-LBWEKT ?kittray ?lbwekt) 			
		    )				; objects with ?sku can be handled by ?endeffector
	    :effect(and 
		    (decrease (quantity-of-kittrays-in-lbwekt ?lbwekt) 1)
		    (hasEndEffector-HeldObject-KitTray ?endeffector ?kittray) 				
		    (hasKitTray-PhysicalLocation-RefObject-EndEffector ?kittray ?endeffector) 	
		    (not (hasEndEffector-HeldObject-None ?endeffector)) 				
		    (not (hasKitTray-PhysicalLocation-RefObject-LBWEKT ?kittray ?lbwekt)))		
    )
			    

    ; Put a KitTray on a WorkTable
    (:action Place-KitTray
	    :parameters(
		    ?robot - Robot
		    ?kittray - KitTray 
		    ?worktable - WorkTable
		    ?endeffector - EndEffector)
	    :precondition 
		    (and
		    (hasEndEffector-HeldObject-KitTray ?endeffector ?kittray)
		    (hasKitTray-PhysicalLocation-RefObject-EndEffector ?kittray ?endeffector)
		    (hasRobot-EndEffector ?robot ?endeffector)
		    (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot))
	    :effect(and 
		    (not(hasKitTray-PhysicalLocation-RefObject-EndEffector ?kittray ?endeffector)) 
		    (not(hasEndEffector-HeldObject-KitTray ?endeffector ?kittray)) 
		    (hasKitTray-PhysicalLocation-RefObject-WorkTable ?kittray ?worktable) 
		    (hasEndEffector-HeldObject-None ?endeffector) 
		    (hasWorkTable-ObjectOnTable-KitTray ?worktable ?kittray))
    )
    
        ; Create a Kit from a KitTray		
    (:action Create-Kit
	    :parameters(
		    ?kit - Kit 
		    ?kittray - KitTray
		    ?worktable - WorkTable)
	    :precondition 
		    (and 
		    (hasWorkTable-ObjectOnTable-KitTray ?worktable ?kittray)
		    (hasKitTray-PhysicalLocation-RefObject-WorkTable ?kittray ?worktable)
		    (hasKit-KitTray ?kit ?kittray)
		    )
	    :effect 
		    (and 
		    (hasWorkTable-ObjectOnTable-Kit ?worktable ?kit) 
		    (hasKit-PhysicalLocation-RefObject-WorkTable ?kit ?worktable)
		    (not  (hasWorkTable-ObjectOnTable-KitTray ?worktable ?kittray))
		    (not (hasKitTray-PhysicalLocation-RefObject-WorkTable ?kittray ?worktable))
		    (isExist-Kit ?kit))
    )

    ; Take a Kit from the WorkTable
    (:action Take-Kit
	    :parameters(
		    ?robot - Robot 
		    ?kit - Kit 
		    ?kittray - KitTray
		    ?worktable - WorkTable 
		    ?sku - StockKeepingUnit
		    ?endeffector - EndEffector)
	    :precondition 
		    (and  
		    (= (current-quantity-kit ?kit) (final-quantity-kit ?kit))
		    (hasEndEffector-HeldObject-None ?endeffector) 					; ?endeffector is not holding anything
		    (hasRobot-EndEffector ?robot ?endeffector) 					; ?robot has ?endeffector on
		    (hasKitTray-SkuObject-Sku ?kittray ?sku)
		    (hasEndEffector-For-Sku-KitTray ?endeffector ?sku)
		    (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot)		; ?endeffector is attached to ?robot
		    (isExist-Kit ?kit)
		    (hasKit-KitTray ?kit ?kittray))
	    :effect 
		    (and 
		    (hasKit-PhysicalLocation-RefObject-EndEffector ?kit ?endeffector)
		    (hasEndEffector-HeldObject-Kit ?endeffector ?kit) 
		    (not (hasKit-PhysicalLocation-RefObject-WorkTable ?kit ?worktable)) 
		    (not (hasEndEffector-HeldObject-None ?endeffector) )
		    (not (hasWorkTable-ObjectOnTable-Kit ?worktable ?kit)))
    )
			    
    ; Put a Kit in a LargeBoxWithKits
    (:action Place-Kit
		    :parameters(
			    ?robot - Robot 
			    ?kit - Kit 
			    ?endeffector - EndEffector
			    ?lbwk - LargeBoxWithKits)	
		    :precondition 
		      (and  
		      (< (quantity-of-kits-in-lbwk ?lbwk) (capacity-of-kits-in-lbwk ?lbwk))
		      (hasEndEffector-HeldObject-Kit ?endeffector ?kit)
		      (hasKit-PhysicalLocation-RefObject-EndEffector ?kit ?endeffector)
		      (hasRobot-EndEffector ?robot ?endeffector)
		      (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot)  
		      )
		    :effect 
		      (and  
		      (not (isExist-Kit ?kit))
		      (hasLBWK-Kit ?lbwk ?kit)
		      (increase (quantity-of-kits-in-lbwk ?lbwk) 1)
		      (hasKit-PhysicalLocation-RefObject-LBWK ?kit ?lbwk)
		      (hasEndEffector-HeldObject-None ?endeffector)
		      (not (hasKit-PhysicalLocation-RefObject-EndEffector ?kit ?endeffector))
		      (not (hasEndEffector-HeldObject-Kit ?endeffector ?kit))
		      )
	    )

	    
    ; Looking for a Part given a StockKeepingUnit
    (:action Look-For-Part
	    :parameters(
		    ?robot - Robot 
		    ?part - Part
		    ?partsku - StockKeepingUnit
		    ?endeffectorsku - StockKeepingUnit
		    ?kit - Kit 
		    ?endeffector - EndEffector)
	    :precondition(and
		    (> (part-found-flag) 0)
		    (isExist-Kit ?kit)
		    (hasEndEffector-For-Sku-Part ?endeffector ?partsku)
		    (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot) 
		    (hasRobot-EndEffector ?robot ?endeffector) 
		    (hasEndEffector-HeldObject-None ?endeffector) 
		    (hasPart-SkuObject-Sku ?part ?partsku))
	    :effect(and
	    (found-part ?part)
	    (decrease (part-found-flag) 1)
	    )
    )

    ; Take a Part from a PartsTray
    (:action Take-Part
	    :parameters(
		    ?robot - Robot 
		    ?part - Part 
		    ?partsku - StockKeepingUnit
		    ?partstray - PartsTray 
		    ?endeffector - EndEffector 
		    ?kit - Kit)
	    :precondition 
		    (and  
		    (isExist-Kit ?kit)
		    (hasPart-SkuObject-Sku ?part ?partsku)
		    (hasEndEffector-For-Sku-Part ?endeffector ?partsku)
		    (hasPart-PhysicalLocation-RefObject-PartsTray ?part ?partstray) 
		    (hasPartsVessel-Part ?partstray ?part)
		    (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot) 
		    (hasRobot-EndEffector ?robot ?endeffector) 
		    (hasEndEffector-HeldObject-None ?endeffector)
		    (found-part ?part)
		    (> (quantity-of-parts-in-partstray ?partstray) 0)
		    )
	    :effect 
		    (and  
		    (hasPart-PhysicalLocation-RefObject-EndEffector ?part ?endeffector) 
		    (hasEndEffector-HeldObject-Part ?endeffector ?part)
		    (not (hasPart-PhysicalLocation-RefObject-PartsTray ?part ?partstray))
		    (decrease (quantity-of-parts-in-partstray ?partstray) 1)
		    (not (hasEndEffector-HeldObject-None ?endeffector)))
    )


    ; Put a Part in a Kit			
    (:action Place-Part
	    :parameters(
		    ?robot - Robot 
		    ?part - Part 
		    ?partsku - StockKeepingUnit
		    ?kit - Kit  
		    ?endeffector - EndEffector
		    ?worktable - WorkTable
		    ?partstray - PartsTray)
	    :precondition 
		    (and  
		      (hasRobot-EndEffector ?robot ?endeffector)
		      (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot)  
		    (hasPart-PhysicalLocation-RefObject-EndEffector ?part ?endeffector) 
		    (hasEndEffector-HeldObject-Part ?endeffector ?part) 
		    (isExist-Kit ?kit)
		    (hasPart-SkuObject-Sku ?part ?partsku)
		    (< (quantity-of-parts-in-kit ?partsku ?kit) (capacity-of-parts-in-kit ?partsku ?kit))
		    )
	    :effect 
		    (and  
		    (increase (current-quantity-kit ?kit) 1)
		    (not (hasPart-PhysicalLocation-RefObject-EndEffector ?part ?endeffector))
		    (not (hasEndEffector-HeldObject-Part ?endeffector ?part))
		    (hasPart-PhysicalLocation-RefObject-Kit ?part ?kit)
		    (increase (part-found-flag) 1)
		    (increase (quantity-of-parts-in-kit ?partsku ?kit) 1)
		    (hasEndEffector-HeldObject-None ?endeffector))
    )

    ; Attach an EndEffector to a Robot		
    (:action Attach-EndEffector
	    :parameters(
		    ?robot - Robot 
		    ?endeffector - EndEffector 
		    ?endeffectorholder - EndEffectorHolder
		    ?changingstation - EndEffectorChangingStation)
	    :precondition 
		    (and  
		    (hasEndEffector-PhysicalLocation-RefObject-EndEffectorHolder ?endeffector ?endeffectorholder) 						
		    (hasEndEffectorHolder-EndEffector  ?endeffectorholder ?endeffector)
		    (hasRobot-No-EndEffector ?robot)
		    (hasEndEffectorHolder-PhysicalLocation-RefObject-ChangingStation ?endeffectorholder ?changingstation)
		    (hasEndEffectorChangingStation-EndEffectorHolder ?changingstation ?endeffectorholder)	
    )		
	    :effect 
		    (and  
		    (hasEndEffector-HeldObject-None ?endeffector)			
		    (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot) 			
		    (hasRobot-EndEffector ?robot ?endeffector)			
		    (not (hasEndEffector-PhysicalLocation-RefObject-EndEffectorHolder ?endeffector ?endeffectorholder)) 	
		    (not (hasEndEffectorHolder-EndEffector ?endeffectorholder ?endeffector)) 	
		    (not (hasRobot-No-EndEffector ?robot)))		
    )


    ; Remove an EndEffector from a Robot
    (:action Detach-EndEffector
	    :parameters(
		    ?robot - Robot 
		    ?endeffector - EndEffector 
		    ?endeffectorholder - EndEffectorHolder
		    ?changingstation - EndEffectorChangingStation)
	    :precondition 
		    (and  
		    (hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot) 
		    (hasRobot-EndEffector ?robot ?endeffector) 
		    (hasEndEffector-HeldObject-None ?endeffector)
		    (hasEndEffectorHolder-PhysicalLocation-RefObject-ChangingStation ?endeffectorholder ?changingstation)
		    (hasEndEffectorChangingStation-EndEffectorHolder ?changingstation ?endeffectorholder))
	    :effect 
		    (and
		    (not(hasEndEffector-PhysicalLocation-RefObject-Robot ?endeffector ?robot))
		    (not(hasRobot-EndEffector ?robot ?endeffector))
		    (hasEndEffector-PhysicalLocation-RefObject-EndEffectorHolder ?endeffector ?endeffectorholder)
		    (hasEndEffectorHolder-EndEffector  ?endeffectorholder ?endeffector)
		    (hasRobot-No-EndEffector ?robot))
    )


    )