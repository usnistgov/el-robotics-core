Right Usage: ./executor -problem <kit/problem.pddl> -plan <kit/plan.txt> -output <crcl.txt>
Real example: ./executor -problem a2b3c5/problem-fluents-a2b3c5.pddl -plan a2b3c5/plan_a2b3c5.txt -output test.txt

<problem.pddl>: The name to the problem file for a specific kit.
The program will automatically search for this file in ../../../PDDLplans/<kit/problem.pddl>

<kit/plan.txt>: The \"name\" of the plan file.
The program will automatically search for this file in ../../../PDDLplans/<kit/plan.txt>

<crcl.txt>: The \"name\" of the output crcl file.
The program will automatically save the new file in ../etc/CanonicalRobotCommands/
