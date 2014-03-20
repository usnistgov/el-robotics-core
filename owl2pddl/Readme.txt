This directory includes 2 files:
-OWL2PDDL.zip: Eclipse version of the tool
-owl2pddl.jar: Runnable version of the same tool. To run the jar file:

java -jar owl2pddl.jar owl2pddl-config.ini

owl2pddl-config.ini is the relative path to owl2pddl-config.ini. You may want to open owl2pddl-config.ini to see its content 

IMPORTANT: Before running the command line above, modify the import path in soapInstances.owl and in soapClasses.owl
In soapInstances.owl: replace Import(<file:soapClasses.owl>) with Import(<file:<absolute path to soapClasses.owl>/soapClasses.owl>)
In soapClasses.owl: replace Import(<file:kittingWorkstationClasses.owl>) with Import(<file:<absolute path to kittingWorkstationClasses.owl>/soapClasses.owl>)

IMPORTANT: Before running the command line above, modify the import path in kittingInstancesInit1.owl and in kittingInstancesGoal1.owl
In those two files:
- replace Import(<file:kittingWorkstationClasses.owl>) with Import(<file:<absolute path to kittingWorkstationClasses.owl>/kittingWorkstationClasses.owl>)
