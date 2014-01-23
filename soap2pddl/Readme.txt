This directory includes 2 files:
-SOAP2PDDL.zip: Eclipse version of the tool that reads soapInstances.owl and generates a PDDL domain file.
-soap2pddl.jar: Runnable version of the same tool. To run the jar file:

java -jar soap2pddl.jar ../Ontology/SOAP/soapInstances.owl domain.pddl

Where ../Ontology/SOAP/soapInstances.owl is the relative path to the input file and domain.pddl is the relative path to the output file.

IMPORTANT: Before running the command line above, modify the import path in soapInstances.owl and in soapClasses.owl
In soapInstances.owl: replace Import(<file:soapClasses.owl>) with Import(<file:<absolute path to soapClasses.owl>/soapClasses.owl>)
In soapClasses.owl: replace Import(<file:kittingWorkstationClasses.owl>) with Import(<file:<absolute path to kittingWorkstationClasses.owl>/soapClasses.owl>)
