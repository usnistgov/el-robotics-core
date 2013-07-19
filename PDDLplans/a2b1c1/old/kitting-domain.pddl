(define (domain kitting-domain)
	(:requirements :strips :typing)
	(:types 
		VacuumEffectorSingleCup
		EndEffectorHolder 
		Kit 
		KitTray
		LargeBoxWithEmptyKitTrays 
		LargeBoxWithKits
		Part 
		PartsTray 
		Robot 
		WorkTable)

	(:predicates
	
	;TRUE iff eff is attached to r
	(eff-location ?eff - VacuumEffectorSingleCup ?r - Robot)	
		
	;TRUE iff eff is in effh		
	(eff-location ?eff - VacuumEffectorSingleCup ?effholder - EndEffectorHolder)

	;TRUE iff r is equipped with eff
	(r-with-eff ?r - Robot ?eff - VacuumEffectorSingleCup)				
		
	;TRUE iff r is not equipped with any end effector
	(r-no-eff ?r - Robot)						
		
	;TRUE iff kins is on wtable		
	(onworktable ?wtable - WorkTable ?kit - Kit)
		
	;TRUE iff kt is on wtable
	(onworktable ?wtable - WorkTable ?kt - KitTray)	
	
	;TRUE iff there is nothing on wtable
	(worktable-empty ?wtable - WorkTable)
	
	;TRUE iff kins is in lbwk
	(kit-location ?kit - Kit ?lbwk - LargeBoxWithKits)		
	
	;TRUE iff kins is on wtable
	(kit-location ?kit - Kit ?wtable - WorkTable)	
	
	;TRUE iff kins is being held by r
	(kit-location ?kit - Kit ?r - Robot)				
	
	;TRUE iff kt is in lbwekt				
	(kit-tray-location ?kt - KitTray ?lbwekt - LargeBoxWithEmptyKitTrays)	

	;TRUE iff kt is being held by r
	(kit-tray-location ?kt - KitTray ?r - Robot)					
		
	;TRUE iff kt is on wtable
	(kit-tray-location ?kt - KitTray ?wtable - WorkTable)
	
	;TRUE iff p is in pt
	(part-location ?p - Part ?pt - PartsTray)					
	
	;TRUE iff p is in kins
	(part-location ?p - Part ?kit - Kit)			
		
	;TRUE iff p is being held by r
	(part-location ?p - Part ?r - Robot)	

	;TRUE iff r is holding kt						
	(rhold ?r - Robot ?kt - KitTray)	

	;TRUE iff r is holding kins					
	(rhold ?r - Robot ?kit - Kit)				
		
	;TRUE iff r is holding p
	(rhold ?r - Robot ?p - Part)					
			
	;TRUE iff r is not holding anything
	(rhold-empty ?r - Robot)							
			
	;TRUE iff lbwk is not full
	(lbwk-not-full ?lbwk - LargeBoxWithKits)
		
	;TRUE iff lbwekt is not empty
	(lbwekt-not-empty ?lbwekt - LargeBoxWithEmptyKitTrays)	
	
	;TRUE iff ?pt is not empty		
	(part-tray-not-empty ?pt - PartsTray)
	
	;TRUE iff eff is capable of holding ?kt						
	(efftype ?eff - VacuumEffectorSingleCup ?kt - KitTray)
	
	;TRUE iff eff is capable of holding ?kit
	(efftype ?eff - VacuumEffectorSingleCup ?kit - Kit)	
	
	;TRUE iff eff is capable of holding ?p
	(efftype ?eff - VacuumEffectorSingleCup ?p - Part)

	;TRUE iff ?effholder is holding eff				
	(effhhold-eff ?effholder - EndEffectorHolder ?eff - VacuumEffectorSingleCup)	

	;TRUE iff ?effholder is empty (?effholder holds no end-effector)		
	(effh-empty ?effholder - EndEffectorHolder)	
    )
   
	(:action take-kit-tray
		:parameters(
			?r - Robot 
			?kt - KitTray 
			?lbwekt - LargeBoxWithEmptyKitTrays 
			?eff - VacuumEffectorSingleCup 
			?wtable - WorkTable)
		:precondition(and 
			(rhold-empty ?r) 
			(lbwekt-not-empty ?lbwekt)
			(r-with-eff ?r ?eff) 
			(kit-tray-location ?kt ?lbwekt) 
			(eff-location ?eff ?r)
			(worktable-empty ?wtable)
			(efftype ?eff ?kt))
		:effect(and 
			(rhold ?r ?kt) 
			(kit-tray-location ?kt ?r) 
			(not (rhold-empty ?r)) 
			(not (kit-tray-location ?kt ?lbwekt))))
			
	(:action put-kit-tray
		:parameters(
			?r - Robot 
			?kt - KitTray 
			?wtable - WorkTable)
		:precondition 
			(and  
			(kit-tray-location ?kt ?r) 
			(rhold ?r ?kt) 
			(worktable-empty ?wtable))
		:effect(and 
			(not(kit-tray-location ?kt ?r)) 
			(not(rhold ?r ?kt)) 
			(not(worktable-empty ?wtable)) 
			(kit-tray-location ?kt ?wtable) 
			(rhold-empty ?r) 
			(onworktable ?wtable ?kt))
	)

	(:action take-kit
		:parameters(
			?r - Robot 
			?kit - Kit 
			?wtable - WorkTable 
			?eff - VacuumEffectorSingleCup)
		:precondition 
			(and  
			(kit-location ?kit ?wtable) 
			(rhold-empty ?r) 
			(onworktable ?wtable ?kit) 
			(r-with-eff ?r ?eff)
			(efftype ?eff ?kit))
		:effect 
			(and 
			(kit-location ?kit ?r) 
			(rhold ?r ?kit) 
			(worktable-empty ?wtable) 
			(not (kit-location ?kit ?wtable)) 
			(not (rhold-empty ?r))
			(not(onworktable ?wtable ?kit)))
	)
			
	(:action put-kit
		:parameters(
			?r - Robot 
			?kit - Kit 
			?lbwk - LargeBoxWithKits)
		
		:precondition 
			(and  
			(kit-location ?kit ?r) 
			(rhold ?r ?kit) 
			(lbwk-not-full ?lbwk))
		:effect 
			(and  
			(kit-location ?kit ?lbwk) 
			(rhold-empty ?r)
			(not (kit-location ?kit ?r))
			(not (rhold ?r ?kit)))
	)
			
	(:action take-part
		:parameters(
			?r - Robot 
			?part - Part 
			?pt - PartsTray 
			?eff - VacuumEffectorSingleCup 
			?wtable - WorkTable 
			?kit - Kit)
		:precondition 
			(and  
			(part-location ?part ?pt) 
			(eff-location ?eff ?r) 
			(rhold-empty ?r) 
			(r-with-eff ?r ?eff) 
			(onworktable ?wtable ?kit) 
			(kit-location ?kit ?wtable)
			(efftype ?eff ?part)
			(part-tray-not-empty ?pt))
		:effect 
			(and  
			(part-location ?part ?r) 
			(rhold ?r ?part)
			(not (part-location ?part ?pt))
			(not (rhold-empty ?r)))
	)
			
	(:action put-part
		:parameters(
			?r - Robot 
			?p - Part 
			?kit - Kit  
			?wtable - WorkTable)
		:precondition 
			(and  
			(part-location ?p ?r) 
			(rhold ?r ?p) 
			(onworktable ?wtable ?kit)
			(kit-location ?kit ?wtable))
		:effect 
			(and  
			(not (part-location ?p ?r))
			(not (rhold ?r ?p))
			(part-location ?p ?kit) 
			(rhold-empty ?r))
	)
			
	(:action attach-eff
		:parameters(
			?r - Robot 
			?eff - VacuumEffectorSingleCup 
			?effholder - EndEffectorHolder)
		:precondition 
			(and  
			(eff-location ?eff ?effholder) 		
			(r-no-eff ?r)				
			(effhhold-eff  ?effholder ?eff)	
			(not (effh-empty ?effholder)))		
		:effect 
			(and  
			(rhold-empty ?r)			
			(eff-location ?eff ?r) 			
			(r-with-eff ?r ?eff)			
			(not (eff-location ?eff ?effholder)) 	
			(not (effhhold-eff ?effholder ?eff)) 	
			(not (r-no-eff ?r))			
			(effh-empty ?effholder))		
	)
	
	(:action remove-eff
		:parameters(
			?r - Robot 
			?eff - VacuumEffectorSingleCup 
			?effholder - EndEffectorHolder)
		:precondition 
			(and  
			(eff-location ?eff ?r) 
			(r-with-eff ?r ?eff) 
			(rhold-empty ?r)
			(effh-empty ?effholder))
		:effect 
			(and
			(not(eff-location ?eff ?r))
			(not(r-with-eff ?r ?eff))
			(eff-location ?eff ?effholder)
			(effhhold-eff  ?effholder ?eff)
			(r-no-eff ?r)
			(not(effh-empty ?effholder)))
	)
			
	(:action create-kit
		:parameters(
			?kit - Kit 
			?kt - KitTray 
			?wtable - WorkTable)
		:precondition 
			(onworktable ?wtable ?kt)
		:effect 
			(and 
			(not(onworktable ?wtable ?kt)) 
			(onworktable ?wtable ?kit) 
			(kit-location ?kit ?wtable))
	)
)