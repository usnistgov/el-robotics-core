#!/bin/bash

#Generate domain and problem files
java -jar $PATH_OWL2PDDL_FILE
#sleep 5

[ ! -f "$PATH_DOMAIN_OUTPUT_FILE" ] && { echo "Error: $PATH_DOMAIN_OUTPUT_FILE file not found."; exit 2; }
[ ! -f "$PATH_PROBLEM_OUTPUT_FILE" ] && { echo "Error: $PATH_PROBLEM_OUTPUT_FILE file not found."; exit 2; }


if [ -s "$PATH_DOMAIN_OUTPUT_FILE" ]
  then
    if [ -s "$PATH_PROBLEM_OUTPUT_FILE" ]
      then
	cd $PLANNER_DIRECTORY
	#Run the plan
	./plan $PATH_DOMAIN_OUTPUT_FILE $PATH_PROBLEM_OUTPUT_FILE $PATH_GENERATED_PLAN_FILE >/dev/null 2>/dev/null
	sleep 5
      else
      echo "$PATH_PROBLEM_OUTPUT_FILE is empty."
      exit 2;
    fi
  else
	echo "$PATH_DOMAIN_OUTPUT_FILE is empty."
	exit 2;
fi

[ ! -f "$PATH_INPUT_PDDL_PLAN_FILE" ] && { echo "Error: $PATH_INPUT_PDDL_PLAN_FILE file not found."; exit 2; }
if [ -s "$PATH_INPUT_PDDL_PLAN_FILE" ]
  then
    # Clean the generated plan file
    java -jar $PATH_PLAN_CLEANER_FILE
    sleep 5
  else
	echo "$PATH_INPUT_PDDL_PLAN_FILE is empty."
	exit 2;
fi

[ ! -f "$PATH_OUTPUT_PDDL_PLAN_FILE" ] && { echo "Error: $PATH_OUTPUT_PDDL_PLAN_FILE file not found."; exit 2; }
if [ -s "$PATH_OUTPUT_PDDL_PLAN_FILE" ]
  then
    # Remove the old plan
    rm -f $PATH_INPUT_PDDL_PLAN_FILE
    #tput clear
    echo "--------------------------------------------------------------------------------------------------------------"
    echo "                                             PDDL PLAN                                                        "
    echo "--------------------------------------------------------------------------------------------------------------"
    more $PATH_OUTPUT_PDDL_PLAN_FILE
  else
	echo "$PATH_OUTPUT_PDDL_PLAN_FILE is empty."
	exit 2;
fi



exit #  The right and proper method of "exiting" from a script.
     #  A bare "exit" (no parameter) returns the exit status
     #+ of the preceding command. 