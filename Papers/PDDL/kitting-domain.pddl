(define (domain kitting-domain)
	(:requirements :strips :typing)
	(:types 
		VacuumEffectorSingleCup
		EndEffectorChangingStation
		EndEffectorHolder 
		kitinstance 
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
	(onworktable ?wtable - WorkTable ?kins - kitinstance)
		
	;TRUE iff kt is on wtable
	(onworktable ?wtable - WorkTable ?kt - KitTray)	
	
	;TRUE iff there is nothing on wtable
	(worktable-empty ?wtable - WorkTable)
	
	;TRUE iff kins is in lbwk
	(kinslocation ?kins - kitinstance ?lbwk - LargeBoxWithKits)		
	
	;TRUE iff kins is on wtable
	(kinslocation ?kins - kitinstance ?wtable - WorkTable)	
	
	;TRUE iff kins is being held by r
	(kinslocation ?kins - kitinstance ?r - Robot)				
	
	;TRUE iff kt is in lbwekt				
	(ktlocation ?kt - KitTray ?lbwekt - LargeBoxWithEmptyKitTrays)	

	;TRUE iff kt is being held by r
	(ktlocation ?kt - KitTray ?r - Robot)					
		
	;TRUE iff kt is on wtable
	(ktlocation ?kt - KitTray ?wtable - WorkTable)
	
	;TRUE iff p is in pt
	(partlocation ?p - Part ?pt - PartsTray)					
	
	;TRUE iff p is in kins
	(partlocation ?p - Part ?kins - kitinstance)			
		
	;TRUE iff p is being held by r
	(partlocation ?p - Part ?r - Robot)	

	;TRUE iff r is holding kt						
	(rhold ?r - Robot ?kt - KitTray)	

	;TRUE iff r is holding kins					
	(rhold ?r - Robot ?kins - kitinstance)				
		
	;TRUE iff r is holding p
	(rhold ?r - Robot ?p - Part)					
			
	;TRUE iff r is not holding anything
	(rhold-empty ?r - Robot)							
			
	;TRUE iff lbwk is not full
	(lbwk-non-full ?lbwk - LargeBoxWithKits)
		
	;TRUE iff lbwekt is not empty
	(lbwekt-non-empty ?lbwekt - LargeBoxWithEmptyKitTrays)	
	
	;TRUE iff ?pt is empty		
	(part-tray-non-empty ?pt - PartsTray)
	
	;TRUE iff eff is capable of holding ?kt						
	(efftype ?eff - VacuumEffectorSingleCup ?kt - KitTray)
	
	;TRUE iff eff is capable of holding ?kins
	(efftype ?eff - VacuumEffectorSingleCup ?kins - kitinstance)	
	
	;TRUE iff eff is capable of holding ?p
	(efftype ?eff - VacuumEffectorSingleCup ?p - Part)

	;TRUE iff ?effholder is holding eff				
	(effhhold-eff ?effholder - EndEffectorHolder ?eff - VacuumEffectorSingleCup)	

	;TRUE iff ?effholder is empty (?effholder holds no end-effector)		
	(effh-empty ?effholder - EndEffectorHolder)	
    )
   
	(:action take-kt
		:parameters(
			?r - Robot 
			?kt - KitTray 
			?lbwekt - LargeBoxWithEmptyKitTrays 
			?eff - VacuumEffectorSingleCup 
			?wtable - WorkTable)
		:precondition(and 
			(rhold-empty ?r) 
			(lbwekt-non-empty ?lbwekt)
			(r-with-eff ?r ?eff) 
			(ktlocation ?kt ?lbwekt) 
			(eff-location ?eff ?r)
			(worktable-empty ?wtable)
			(efftype ?eff ?kt))
		:effect(and 
			(rhold ?r ?kt) 
			(ktlocation ?kt ?r) 
			(not (rhold-empty ?r)) 
			(not (ktlocation ?kt ?lbwekt))))
			
	(:action put-kt
		:parameters(
			?r - Robot 
			?kt - KitTray 
			?wtable - WorkTable)
		:precondition 
			(and  
			(ktlocation ?kt ?r) 
			(rhold ?r ?kt) 
			(worktable-empty ?wtable))
		:effect(and 
			(not(ktlocation ?kt ?r)) 
			(not(rhold ?r ?kt)) 
			(not(worktable-empty ?wtable)) 
			(ktlocation ?kt ?wtable) 
			(rhold-empty ?r) 
			(onworktable ?wtable ?kt))
	)

	(:action take-kins
		:parameters(
			?r - Robot 
			?kins - kitinstance 
			?wtable - WorkTable 
			?eff - VacuumEffectorSingleCup)
		:precondition 
			(and  
			(kinslocation ?kins ?wtable) 
			(rhold-empty ?r) 
			(onworktable ?wtable ?kins) 
			(r-with-eff ?r ?eff)
			(efftype ?eff ?kins))
		:effect 
			(and 
			(kinslocation ?kins ?r) 
			(rhold ?r ?kins) 
			(worktable-empty ?wtable) 
			(not (kinslocation ?kins ?wtable)) 
			(not (rhold-empty ?r))
			(not(onworktable ?wtable ?kins)))
	)
			
	(:action put-kins
		:parameters(
			?r - Robot 
			?kins - kitinstance 
			?lbwk - LargeBoxWithKits)
		
		:precondition 
			(and  
			(kinslocation ?kins ?r) 
			(rhold ?r ?kins) 
			(lbwk-non-full ?lbwk))
		:effect 
			(and  
			(kinslocation ?kins ?lbwk) 
			(rhold-empty ?r)
			(not (kinslocation ?kins ?r))
			(not (rhold ?r ?kins)))
	)
			
	(:action take-part
		:parameters(
			?r - Robot 
			?p - Part 
			?pt - PartsTray 
			?eff - VacuumEffectorSingleCup 
			?wtable - WorkTable 
			?kins - kitinstance)
		:precondition 
			(and  
			(partlocation ?p ?pt) 
			(eff-location ?eff ?r) 
			(rhold-empty ?r) 
			(r-with-eff ?r ?eff) 
			(onworktable ?wtable ?kins) 
			(kinslocation ?kins ?wtable)
			(efftype ?eff ?p)
			(part-tray-non-empty ?pt))
		:effect 
			(and  
			(partlocation ?p ?r) 
			(rhold ?r ?p)
			(not (partlocation ?p ?pt))
			(not (rhold-empty ?r)))
	)
			
	(:action put-part
		:parameters(
			?r - Robot 
			?p - Part 
			?kins - kitinstance  
			?wtable - WorkTable)
		:precondition 
			(and  
			(partlocation ?p ?r) 
			(rhold ?r ?p) 
			(onworktable ?wtable ?kins)
			(kinslocation ?kins ?wtable))
		:effect 
			(and  
			(not (partlocation ?p ?r))
			(not (rhold ?r ?p))
			(partlocation ?p ?kins) 
			(rhold-empty ?r))
	)
			
	(:action attach-eff
		:parameters(
			?r - Robot 
			?eff - VacuumEffectorSingleCup 
			?effholder - EndEffectorHolder)
		:precondition 
			(and  
			(eff-location ?eff ?effholder) 		; ?eff is in ?effholder
			(r-no-eff ?r)				; ?r is not equipped with an end-effector
			(effhhold-eff  ?effholder ?eff)		; ?effholder is holding ?eff
			(not (effh-empty ?effholder)))		; ?effholder is not empty
		:effect 
			(and  
			(rhold-empty ?r)			; ?r not holding anything
			(eff-location ?eff ?r) 			; ?eff is attached to ?r
			(r-with-eff ?r ?eff)			; ?r is holding ?eff
			(not (eff-location ?eff ?effholder)) 	; ?eff is not in ?effholder
			(not (effhhold-eff ?effholder ?eff)) 	; ?effholder is not holding ?eff 
			(not (r-no-eff ?r))			; ?r is equipped with an end-effector
			(effh-empty ?effholder))		; ?effholder is empty
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
			
	(:action create-kins
		:parameters(
			?kins - kitinstance 
			?kt - KitTray 
			?wtable - WorkTable)
		:precondition 
			(onworktable ?wtable ?kt)
		:effect 
			(and 
			(not(onworktable ?wtable ?kt)) 
			(onworktable ?wtable ?kins) 
			(kinslocation ?kins ?wtable))
	)
)