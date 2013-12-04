(define (domain kitting-domain)
	(:requirements :strips :typing :derived-predicates :action-costs :fluents)
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
		WorkTable)

(:predicates
	
	;TRUE iff ?endeffector is attached to ?robot
	(endeffector-location-robot ?endeffector - EndEffector ?robot - Robot)	
		
	;TRUE iff ?endeffector is in ?endeffectorholder
	(endeffector-location-endeffectorholder ?endeffector - EndEffector ?endeffectorholder - EndEffectorHolder)

	;TRUE iff ?robot is equipped with ?endeffector
	(robot-with-endeffector ?robot - Robot ?endeffector - EndEffector)				
		
	;TRUE iff ?robot is not equipped with ?endeffector
	(robot-with-no-endeffector ?robot - Robot)						
		
	;TRUE iff ?kit is on ?worktable		
	(on-worktable-kit ?worktable - WorkTable ?kit - Kit)
		
	;TRUE iff ?kittray is on ?worktable
	(on-worktable-kittray ?worktable - WorkTable ?kittray - KitTray)	
	
	;TRUE iff ?worktable is empty (nothing on top of it)
	(worktable-empty ?worktable - WorkTable)
	
	;TRUE iff ?kit is in ?largeboxwithkits
	(kit-location-lbwk ?kit - Kit ?largeboxwithkits - LargeBoxWithKits)		
	
	;TRUE iff ?kit is on ?worktable
	(kit-location-worktable ?kit - Kit ?worktable - WorkTable)	
	
	;TRUE iff ?kit is being held by ?robot
	(kit-location-robot ?kit - Kit ?robot - Robot)				
	
	;TRUE iff ?kittray is in ?largeboxwithemptykittrays
	(kittray-location-lbwekt ?kittray - KitTray ?largeboxwithemptykittrays - LargeBoxWithEmptyKitTrays)	

	;TRUE iff ?kittray is being held by ?robot
	(kittray-location-robot ?kittray - KitTray ?robot - Robot)					
		
	;TRUE iff ?kittray is on ?worktable
	(kittray-location-worktable ?kittray - KitTray ?worktable - WorkTable)
	
	;TRUE iff ?part is in ?partstray
	(part-location-partstray ?part - Part ?partstray - PartsTray)					
	
	;TRUE iff ?part is in ?kit
	(part-location-kit ?part - Part ?kit - Kit)			
		
	;TRUE iff ?part is being held by ?robot
	(part-location-robot ?part - Part ?robot - Robot)	

	;TRUE iff ?robot is holding ?kittray
	(robot-holds-kittray ?robot - Robot ?kittray - KitTray)	

	;TRUE iff ?robot is holding ?kit
	(robot-holds-kit ?robot - Robot ?kit - Kit)				
		
	;TRUE iff ?robot is holding ?part
	(robot-holds-part ?robot - Robot ?part - Part)					
			
	;TRUE iff ?robot is not holding anything
	(robot-empty ?robot - Robot)							
			
	;TRUE iff ?larboxwithkits is not full
	(lbwk-not-full ?larboxwithkits - LargeBoxWithKits)
		
	;TRUE iff ?largeboxwithemptykittrays is not empty
	(lbwekt-not-empty ?largeboxwithemptykittrays - LargeBoxWithEmptyKitTrays)	
	
	;TRUE iff ?partstray is not empty		
	(partstray-not-empty ?partstray - PartsTray)
	
	;TRUE iff ?partstray has ?part		
	(partstray-has-part ?partstray - PartsTray ?part - Part)
	
	;TRUE iff ?endeffector is capable of holding ?kittray						
	(endeffector-type-kittray ?endeffector - EndEffector ?kittray - KitTray)
	
	;TRUE iff ?endeffector is capable of holding ?kit
	(endeffector-type-kit ?endeffector - EndEffector ?kit - Kit)	
	
	;TRUE iff ?endeffecor is capable of holding ?part
	(endeffector-type-part ?endeffector - EndEffector ?part - Part)

	;TRUE iff ?endeffectorholder is holding endeffecor				
	(endeffectorholder-holds-endeffector ?endeffectorholder - EndEffectorHolder ?endeffector - EndEffector)	

	;TRUE iff ?endeffectorholder is empty (?endeffectorholder does not hold an endeffector)		
	(endeffectorholder-empty ?endeffectorholder - EndEffectorHolder)

	;TRUE iff ?endeffectorholder is in ?endeffectorchangingstation		
	(endeffectorholder-location ?endeffectorholder - EndEffectorHolder ?endeffectorchangingstation - EndEffectorChangingStation)	

	;TRUE iff ?endeffectorchangingstation contains ?endeffectorholder
	(endeffectorchangingstation-contains-endeffectorholder ?endeffectorchangingstation - EndEffectorChangingStation ?endeffectorholder - EndEffectorHolder)	

	;TRUE if ?part is found in ?partstray
	(found-part ?part - Part ?partstray - PartsTray)
	
	;Flag used to tell if any part has been searched yet
	;TRUE if any part has not been searched yet
	;This predicate is used to trigger the action look-for-part right before the action take-part.
	;Without using this predicate, look-for-part is called multiple times at the beginning of the plan
	(part-not-searched)
	
	;TRUE if ?part is from ?partstray
	(origin-part ?part - Part ?partstray - PartsTray)
)

;Functions are used to manipulate numbers
(:functions 
	;Quantity of parts in ?partstray (quantity set in the init section in the problem file)
	(quantity-partstray ?partstray - PartsTray)
	
	;Quantity of parts from ?partstray that is in ?kit
	(quantity-kit ?kit - Kit ?partstray - PartsTray)
	
	;TRUE if capacity of a kit is equal to the quantity of parts tray
	(capacity-kit ?kit - Kit ?partstray - PartsTray) 
)

;Take a KitTray from a LargeBoxWithEmptyKitTrays
(:action take-kittray
	:parameters(
		?robot - Robot 
		?kittray - KitTray 
		?largeboxwithemptykittrays - LargeBoxWithEmptyKitTrays 
		?endeffector - EndEffector 
		?worktable - WorkTable)
	:precondition(and 
		(robot-empty ?robot) 
		(lbwekt-not-empty ?largeboxwithemptykittrays)
		(robot-with-endeffector ?robot ?endeffector) 
		(kittray-location-lbwekt ?kittray ?largeboxwithemptykittrays) 
		(endeffector-location-robot ?endeffector ?robot)
		(worktable-empty ?worktable)
		(endeffector-type-kittray ?endeffector ?kittray))
	:effect(and 
		(robot-holds-kittray ?robot ?kittray) 
		(kittray-location-robot ?kittray ?robot) 
		(not (robot-empty ?robot)) 
		(not (kittray-location-lbwekt ?kittray ?largeboxwithemptykittrays)))
)
			
; Put a KitTray on a WorkTable
(:action put-kittray
	:parameters(
		?robot - Robot 
		?kittray - KitTray 
		?worktable - WorkTable)
	:precondition 
		(and  
		(kittray-location-robot ?kittray ?robot) 
		(robot-holds-kittray ?robot ?kittray) 
		(worktable-empty ?worktable))
	:effect(and 
		(not(kittray-location-robot ?kittray ?robot)) 
		(not(robot-holds-kittray ?robot ?kittray)) 
		(not(worktable-empty ?worktable)) 
		(kittray-location-worktable ?kittray ?worktable) 
		(robot-empty ?robot) 
		(on-worktable-kittray ?worktable ?kittray))
)

; Take a Kit from the WorkTable
(:action take-kit
	:parameters(
		?robot - Robot 
		?kit - Kit 
		?worktable - WorkTable 
		?endeffector - EndEffector)
	:precondition 
		(and  
		(kit-location-worktable ?kit ?worktable) 
		(robot-empty ?robot) 
		(on-worktable-kit ?worktable ?kit) 
		(robot-with-endeffector ?robot ?endeffector)
		(endeffector-type-kit ?endeffector ?kit))
	:effect 
		(and 
		(kit-location-robot ?kit ?robot) 
		(robot-holds-kit ?robot ?kit) 
		(worktable-empty ?worktable) 
		(not (kit-location-worktable ?kit ?worktable)) 
		(not (robot-empty ?robot))
		(not(on-worktable-kit ?worktable ?kit)))
)
			
; Put a Kit in a LargeBoxWithKits
(:action put-kit
		:parameters(
			?robot - Robot 
			?kit - Kit 
			?largeboxwithkits - LargeBoxWithKits)	
		:precondition 
			(and  
			(kit-location-robot ?kit ?robot) 
			(robot-holds-kit ?robot ?kit) 
			(lbwk-not-full ?largeboxwithkits))
		:effect 
			(and  
			(kit-location-lbwk ?kit ?largeboxwithkits) 
			(robot-empty ?robot)
			(not (kit-location-robot ?kit ?robot))
			(not (robot-holds-kit ?robot ?kit)))
	)
	
; Looking for a Part in a PartsTray
(:action look-for-part
	:parameters(
		?robot - Robot 
		?part - Part 
		?partstray - PartsTray 
		?kit - Kit 
		?worktable - WorkTable 
		?endeffector - EndEffector)
	:precondition(and
		(endeffector-location-robot ?endeffector ?robot) 
		(robot-empty ?robot) 
		(robot-with-endeffector ?robot ?endeffector) 
		(on-worktable-kit ?worktable ?kit)
		(part-not-searched)
		(part-location-partstray ?part ?partstray)
		(kit-location-worktable ?kit ?worktable)
		(endeffector-type-part ?endeffector ?part)
		(partstray-not-empty ?partstray))
	:effect(and 
		(not (part-not-searched))
		(found-part ?part ?partstray))
)

; Take a Part from a PartsTray
(:action take-part
	:parameters(
		?robot - Robot 
		?part - Part 
		?partstray - PartsTray 
		?endeffector - EndEffector)
	:precondition 
		(and  
		(part-location-partstray ?part ?partstray) 
		(endeffector-location-robot ?endeffector ?robot) 
		(robot-empty ?robot) 
		(robot-with-endeffector ?robot ?endeffector)
		(endeffector-type-part ?endeffector ?part)
		(found-part ?part ?partstray)
		(partstray-not-empty ?partstray)
		(partstray-has-part ?partstray ?part))
	:effect 
		(and  
		(part-location-robot ?part ?robot) 
		(robot-holds-part ?robot ?part)
		(not (part-location-partstray ?part ?partstray))
		(decrease (quantity-partstray ?partstray) 1)
		(not (robot-empty ?robot)))
)

; Put a Part in a Kit			
(:action put-part
	:parameters(
		?robot - Robot 
		?part - Part 
		?kit - Kit  
		?worktable - WorkTable
		?partstray - PartsTray)
	:precondition 
		(and  
		(part-location-robot ?part ?robot) 
		(robot-holds-part ?robot ?part) 
		(on-worktable-kit ?worktable ?kit)
		(origin-part ?part ?partstray)
		(< (quantity-kit ?kit ?partstray) (capacity-kit ?kit ?partstray))
		(kit-location-worktable ?kit ?worktable))
	:effect 
		(and  
		(not (part-location-robot ?part ?robot))
		(not (robot-holds-part ?robot ?part))
		(part-not-searched)
		(not (found-part ?part ?partstray))
		(part-location-kit ?part ?kit) 
		(increase (quantity-kit ?kit ?partstray) 1)
		(robot-empty ?robot))
)

; Attach an EndEffector to a Robot		
(:action attach-endeffector
	:parameters(
		?robot - Robot 
		?endeffector - EndEffector 
		?endeffectorholder - EndEffectorHolder
		?endeffectorchangingstation - EndEffectorChangingStation)
	:precondition 
		(and  
		(endeffector-location-endeffectorholder ?endeffector ?endeffectorholder) 		
		(robot-with-no-endeffector ?robot)				
		(endeffectorholder-holds-endeffector  ?endeffectorholder ?endeffector)
		(endeffectorholder-location ?endeffectorholder ?endeffectorchangingstation)
		(endeffectorchangingstation-contains-endeffectorholder ?endeffectorchangingstation ?endeffectorholder)	
)		
	:effect 
		(and  
		(robot-empty ?robot)			
		(endeffector-location-robot ?endeffector ?robot) 			
		(robot-with-endeffector ?robot ?endeffector)			
		(not (endeffector-location-endeffectorholder ?endeffector ?endeffectorholder)) 	
		(not (endeffectorholder-holds-endeffector ?endeffectorholder ?endeffector)) 	
		(not (robot-with-no-endeffector ?robot))			
		(endeffectorholder-empty ?endeffectorholder))		
)


; Remove an EndEffector from a Robot
(:action remove-endeffector
	:parameters(
		?robot - Robot 
		?endeffector - EndEffector 
		?endeffectorholder - EndEffectorHolder
		?endeffectorchangingstation - EndEffectorChangingStation)
	:precondition 
		(and  
		(endeffector-location-robot ?endeffector ?robot) 
		(robot-with-endeffector ?robot ?endeffector) 
		(robot-empty ?robot)
		(endeffectorholder-location ?endeffectorholder ?endeffectorchangingstation)
		(endeffectorchangingstation-contains-endeffectorholder ?endeffectorchangingstation ?endeffectorholder)	
		(endeffectorholder-empty ?endeffectorholder))
	:effect 
		(and
		(not(endeffector-location-robot ?endeffector ?robot))
		(not(robot-with-endeffector ?robot ?endeffector))
		(endeffector-location-endeffectorholder ?endeffector ?endeffectorholder)
		(endeffectorholder-holds-endeffector  ?endeffectorholder ?endeffector)
		(robot-with-no-endeffector ?robot)
		(not(endeffectorholder-empty ?endeffectorholder)))
)

; Create a Kit from a KitTray		
(:action create-kit
	:parameters(
		?kit - Kit 
		?kittray - KitTray 
		?worktable - WorkTable)
	:precondition 
		(on-worktable-kittray ?worktable ?kittray)
	:effect 
		(and 
		(not(on-worktable-kittray ?worktable ?kittray)) 
		(on-worktable-kit ?worktable ?kit) 
		(kit-location-worktable ?kit ?worktable))
)

)