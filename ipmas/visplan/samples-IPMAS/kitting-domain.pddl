(define (domain kitting-domain)
	(:requirements :strips :typing)
	(:types 
		endeffector
		endeffectorchangingstation
		endeffectorholder 
		kitinstance 
		kittray
		largeboxwithemptykittray 
		largeboxwithkit
		part 
		parttray 
		robot 
		worktable)

	(:predicates
	
	;TRUE iff eff is attached to r
	(efflocation ?eff - endeffector ?r - robot)	
		
	;TRUE iff eff is in effh		
	(efflocation ?eff - endeffector ?effh - endeffectorholder)

	;TRUE iff r is equipped with eff
	(r-with-eff ?r - robot ?eff - endeffector)				
		
	;TRUE iff r is not equipped with any end effector
	(r-no-eff ?r - robot)						
		
	;TRUE iff kins is on wtable		
	(onworktable ?wtable - worktable ?kins - kitinstance)
		
	;TRUE iff kt is on wtable
	(onworktable ?wtable - worktable ?kt - kittray)	
	
	;TRUE iff there is nothing on wtable
	(worktable-empty ?wtable - worktable)
	
	;TRUE iff kins is in lbwk
	(kinslocation ?kins - kitinstance ?lbwk - largeboxwithkit)		
	
	;TRUE iff kins is on wtable
	(kinslocation ?kins - kitinstance ?wtable - worktable)	
	
	;TRUE iff kins is being held by r
	(kinslocation ?kins - kitinstance ?r - robot)				
	
	;TRUE iff kt is in lbwekt				
	(ktlocation ?kt - kittray ?lbwekt - largeboxwithemptykittray)	

	;TRUE iff kt is being held by r
	(ktlocation ?kt - kittray ?r - robot)					
		
	;TRUE iff kt is on wtable
	(ktlocation ?kt - kittray ?wtable - worktable)
	
	;TRUE iff p is in pt
	(partlocation ?p - part ?pt - parttray)					
	
	;TRUE iff p is in kins
	(partlocation ?p - part ?kins - kitinstance)			
		
	;TRUE iff p is being held by r
	(partlocation ?p - part ?r - robot)	

	;TRUE iff r is holding kt						
	(rhold ?r - robot ?kt - kittray)	

	;TRUE iff r is holding kins					
	(rhold ?r - robot ?kins - kitinstance)				
		
	;TRUE iff r is holding p
	(rhold ?r - robot ?p - part)					
			
	;TRUE iff r is not holding anything
	(rhold-empty ?r - robot)							
			
	;TRUE iff lbwk is not full
	(lbwk-non-full ?lbwk - largeboxwithkit)
		
	;TRUE iff lbwekt is not empty
	(lbwekt-non-empty ?lbwekt - largeboxwithemptykittray)	
	
	;TRUE iff pt is empty		
	(part-tray-non-empty ?pt - parttray)
	
	;TRUE iff eff is for kt						
	(efftype - endeffector ?kt - kittray)
	
	;TRUE iff eff is holding kins			
	(efftype ?eff - endeffector ?kins - kitinstance)	
	
	;TRUE iff eff is holding p
	(efftype ?eff - endeffector ?p - part)

	;TRUE iff effh is holding eff				
	(effhhold-eff ?effh - endeffectorholder ?eff - endeffector)			
    )
   
	(:action take-kt
		:parameters(
			?r - robot 
			?kt - kittray 
			?lbwekt - largeboxwithemptykittray 
			?eff - endeffector 
			?wtable - worktable)
		:precondition(and 
			(rhold-empty ?r) 
			(lbwekt-non-empty ?lbwekt)
			(r-with-eff ?r ?eff) 
			(ktlocation ?kt ?lbwekt) 
			(efflocation ?eff ?r)
			(worktable-empty ?wtable)
			(efftype ?eff ?kt))
		:effect(and 
			(rhold ?r ?kt) 
			(ktlocation ?kt ?r) 
			(not (rhold-empty ?r)) 
			(not (ktlocation ?kt ?lbwekt))))
			
	(:action put-kt
		:parameters(
			?r - robot 
			?kt - kittray 
			?wtable - worktable)
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
			?r - robot 
			?kins - kitinstance 
			?wtable - worktable 
			?eff - endeffector)
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
			?r - robot 
			?kins - kitinstance 
			?lbwk - largeboxwithkit)
		
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
			?r - robot 
			?part - part 
			?pt - parttray 
			?eff - endeffector 
			?wtable - worktable 
			?kins - kitinstance)
		:precondition 
			(and  
			(partlocation ?part ?pt) 
			(efflocation ?eff ?r) 
			(rhold-empty ?r) 
			(r-with-eff ?r ?eff) 
			(onworktable ?wtable ?kins) 
			(kinslocation ?kins ?wtable)
			(efftype ?eff ?part)
			(part-tray-non-empty ?pt))
		:effect 
			(and  
			(partlocation ?part ?r) 
			(rhold ?r ?part)
			(not (partlocation ?part ?pt))
			(not (rhold-empty ?r)))
	)
			
	(:action put-part
		:parameters(
			?r - robot 
			?p - part 
			?kins - kitinstance  
			?wtable - worktable)
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
			?r - robot 
			?eff - endeffector 
			?effh - endeffectorholder)
		:precondition 
			(and  
			(efflocation ?eff ?effh) 
			(r-no-eff ?r)
			(effhhold-eff  ?effh ?eff)
			)
		:effect 
			(and  
			(rhold-empty ?r)
			(efflocation ?eff ?r) 
			(r-with-eff ?r ?eff)
			(not (efflocation ?eff ?effh)) 
			(not (effhhold-eff  ?effh ?eff))
			(not (r-no-eff ?r)))
	)
	
	(:action remove-eff
		:parameters(
			?r - robot 
			?eff - endeffector 
			?effh - endeffectorholder)
		:precondition 
			(and  
			(efflocation ?eff ?r) 
			(r-with-eff ?r ?eff) 
			(rhold-empty ?r))
		:effect 
			(and
			(not(efflocation ?eff ?r))
			(not(r-with-eff ?r ?eff))
			(efflocation ?eff ?effh)
			(effhhold-eff  ?effh ?eff)
			(r-no-eff ?r) 
			)
	)
			
	(:action create-kins
		:parameters(
			?kins - kitinstance 
			?kt - kittray 
			?wtable - worktable)
		:precondition 
			(onworktable ?wtable ?kt)
		:effect 
			(and 
			(not(onworktable ?wtable ?kt)) 
			(onworktable ?wtable ?kins) 
			(kinslocation ?kins ?wtable))
	)

	;(:action switch-eff	
	;	:parameters(
	;		?r - robot 
	;		?effold ?effnew - endeffector
	;		?effhold ?effhnew - endeffectorholder
	;			)
	;	:precondition 
	;		(and  
	;		(effector-in-effholder ?effnew ?effhnew) 
	;		(efflocation ?effold ?r) 
	;		(robot-with-eff ?r ?effold)
	;		(rhold-empty ?r))
	;	:effect 
	;		(and  
	;		(efflocation ?effnew ?r) 
	;		(robot-with-eff ?r ?effnew)
	;		(not (effector-in-effholder ?effnew ?effhnew))
	;		(not (efflocation ?effold ?r))
	;		(not (robot-with-eff ?r ?effold)))
	;)
)