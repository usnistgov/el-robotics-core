#!/bin/bash

#if owl2pddl.jar exists
if [ -f $PATH_OWL2PDDL_FILE ];
then
   #Generate domain and problem files
   java -jar $PATH_OWL2PDDL_FILE
else
   echo "File $PATH_OWL2PDDL_FILE does not exist... exits"
   exit 2;
fi

#wait for the domain and problem files to be generated
sleep 5

#check if the domain file exists
[ ! -f "$PATH_DOMAIN_OUTPUT_FILE" ] && { echo "Error: $PATH_DOMAIN_OUTPUT_FILE file not found."; exit 2; }
#check if the problem file exists
[ ! -f "$PATH_PROBLEM_OUTPUT_FILE" ] && { echo "Error: $PATH_PROBLEM_OUTPUT_FILE file not found."; exit 2; }

#if the domain file exists and is not empty
if [ -s "$PATH_DOMAIN_OUTPUT_FILE" ]
  then
    #if the problem file exists and is not empty
    if [ -s "$PATH_PROBLEM_OUTPUT_FILE" ]
      then
	#go to the planner directory
	cd $PLANNER_DIRECTORY
	#Run the plan
	./plan $PATH_DOMAIN_OUTPUT_FILE $PATH_PROBLEM_OUTPUT_FILE $PATH_GENERATED_PLAN_FILE >/dev/null 2>/dev/null
	#wait for the plan to be generated
	sleep 5
      else
      echo "$PATH_PROBLEM_OUTPUT_FILE is empty."
      exit 2;
    fi
  else
	echo "$PATH_DOMAIN_OUTPUT_FILE is empty."
	exit 2;
fi

#check if $PATH_INPUT_PDDL_PLAN_FILE exists and is not empty
[ ! -f "$PATH_INPUT_PDDL_PLAN_FILE" ] && { echo "Error: $PATH_INPUT_PDDL_PLAN_FILE file not found."; exit 2; }
if [ -s "$PATH_INPUT_PDDL_PLAN_FILE" ]
  then
  #if pddlcleaner.jar exists
  if [ -f $PATH_PLAN_CLEANER_FILE ];
    then
      # Clean the generated plan file
      java -jar $PATH_PLAN_CLEANER_FILE
      # wait for the plan to be cleaner
      sleep 5
    else
      echo "File $PATH_PLAN_CLEANER_FILE does not exist... exits"
      exit 2;
  fi

  else
	echo "$PATH_INPUT_PDDL_PLAN_FILE is empty."
	exit 2;
fi

#check if $PATH_OUTPUT_PDDL_PLAN_FILE exists and is not empty
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