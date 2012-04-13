(define (problem kitting-problem)
	(:domain kitting-domain)
	(:objects
		r1 - robot
		kt1 - kittray
		kins1 - kitinstance
		lbwekt1 - largeboxwithemptykittray
		lbwk1 - largeboxwithkit 
		wtable - worktable
		ptA ptB ptC - parttray
		partA1 partA2 partB partC - part 
		eff1 eff2 - endeffector
		effh1 effh2 - endeffectorholder
	)


	(:init
		(r-no-eff r1)
		(lbwekt-non-empty lbwekt1)
		(lbwk-non-full lbwk1)
		(part-tray-non-empty ptA)
		(part-tray-non-empty ptB) 
		(part-tray-non-empty ptC)
		(efflocation eff1 effh1)
		(efflocation eff2 effh2) 
		(effhhold-eff effh1 eff1)
		(effhhold-eff effh2 eff2)
		(worktable-empty wtable) 
		(partlocation partA1 ptA)
		(partlocation partA2 ptA) 
		(partlocation partB ptB)
		(partlocation partC ptC) 
		(ktlocation kt1 lbwekt1)
		(efftype eff1 partA1)
		(efftype eff1 partA2)
		(efftype eff1 partB)
		(efftype eff1 partC)
		(efftype eff2 kt1)
		(efftype eff2 kins1)
	)
	
	
	(:goal
	  (and  
	    (partlocation partA1 kins1) 
	    (partlocation partA2 kins1) 
	    (partlocation partB kins1) 
	    (partlocation partC kins1) 
	    (kinslocation kins1 lbwk1)
	   )
	)

	;(:goal
	;(and
	;(onworktable-kins wtable kins1) 
	;(partlocation-kins partA1 kins1)
	;)
	;)
)
