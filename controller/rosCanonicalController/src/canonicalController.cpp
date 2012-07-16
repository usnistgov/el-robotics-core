/*****************************************************************************
  DISCLAIMER:
  This software was produced by the National Institute of Standards
  and Technology (NIST), an agency of the U.S. government, and by statute is
  not subject to copyright in the United States.  Recipients of this software
  assume all responsibility associated with its operation, modification,
  maintenance, and subsequent redistribution.

  See NIST Administration Manual 4.09.07 b and Appendix I. 
*****************************************************************************/
/*!
  \file   test.cc
  \brief  test controller interface library by reading and writing commands to the queue

  \author Stephen Balakirsky
  \date   05/31/2012
*/
#include <stdio.h>
#include <Point.h>
#include <Vector.h>
#include <vector>
#include <sstream>
#include <ros/ros.h>
#include "rosInf.hh"
#include "ulapi.hh"
#include "controller.hh"
#include "canonicalMsg.hh"

void
dequeueThread (void *arg)
{
  Controller *ctrl = reinterpret_cast < Controller *>(arg);
  ros::init(ros::VP_string(), "canonicalController");
  RosInf rosControl;
  ros::start();
  while(ros::ok())
    {
      if( ctrl->dequeueMsg(&rosControl) == 0)
		sleep(1);
	  ros::spinOnce();
    }
    ros::shutdown();
}
int
main ()
{
  
  Controller *ctrl;
  Vector *xAxis = new Vector("down_xaxis");
  xAxis->sethasVector_I(0.0);
  xAxis->sethasVector_J(-1.0);
  xAxis->sethasVector_K(0.0);
  Vector *zAxis = new Vector("down_zaxis");
  zAxis->sethasVector_I(0.0);
  zAxis->sethasVector_J(0.0);
  zAxis->sethasVector_K(-1.0);
  
  PoseLocation *boxPose = new PoseLocation("box_pickup");
  Point *boxPoint = new Point("box_point");
  boxPoint->sethasPoint_X(.577);
  boxPoint->sethasPoint_Y(1.405);
  boxPoint->sethasPoint_Z(0.04);
  boxPose->sethasPoseLocation_Point(boxPoint);
  boxPose->sethasPoseLocation_XAxis(xAxis);
  boxPose->sethasPoseLocation_ZAxis(zAxis);
  
  Point *startPoint = new Point("start_point");
  startPoint->sethasPoint_X(.122);
  startPoint->sethasPoint_Y(1.21);
  startPoint->sethasPoint_Z(-0.707);
  
  PoseLocation *graspPose = new PoseLocation("prep_pose");
  graspPose->sethasPoseLocation_Point(startPoint);
  graspPose->sethasPoseLocation_XAxis(xAxis);
  graspPose->sethasPoseLocation_ZAxis(zAxis);
  
  PoseLocation *boxLift = new PoseLocation("box_lift");
  Point *boxLiftPoint = new Point("box_lift_point");
  boxLiftPoint->sethasPoint_X(.577);
  boxLiftPoint->sethasPoint_Y(1.405);
  boxLiftPoint->sethasPoint_Z(-0.04);
  boxLift->sethasPoseLocation_Point(boxLiftPoint);
  boxLift->sethasPoseLocation_XAxis(xAxis);
  boxLift->sethasPoseLocation_ZAxis(zAxis);
  
  PoseLocation *boxDrop = new PoseLocation("box_drop");
  Point *boxDropPoint = new Point("box_drop_point");
  boxDropPoint->sethasPoint_X(.577);
  boxDropPoint->sethasPoint_Y(1.405);
  boxDropPoint->sethasPoint_Z(-0.15);
  boxDrop->sethasPoseLocation_Point(boxDropPoint);
  boxDrop->sethasPoseLocation_XAxis(xAxis);
  boxDrop->sethasPoseLocation_ZAxis(zAxis);
  
  PoseLocation *array[2];
  array[0] = new PoseLocation("prep_pose");
  array[0]->sethasPoseLocation_Point(startPoint);
  array[0]->sethasPoseLocation_XAxis(xAxis);
  array[0]->sethasPoseLocation_ZAxis(zAxis);
  array[1] = new PoseLocation("box_lift");
  array[1]->sethasPoseLocation_Point(boxLiftPoint);
  array[1]->sethasPoseLocation_XAxis(xAxis);
  array[1]->sethasPoseLocation_ZAxis(zAxis); 
  
  MoveThroughToMsg descendMsg(array, 2);
  MoveToMsg pickupMove(boxPose);
  MoveToMsg liftMove(boxLift);
  MoveToMsg firstMove(graspPose);
  MoveToMsg dropBox(boxDrop);
  
  CloseGripperMsg closeGripper;
  CloseToolChangerMsg closeTool;
  DwellMsg dwell(.5);
  EndCanonMsg endCanon(18);
  InitCanonMsg initCanon;
  OpenGripperMsg openGripper;
  MessageMsg messageMsg("This is a test message");
  void *dequeueTask = NULL;

  ctrl = new Controller();
  // this code uses the ULAPI library to provide portability
  // between different operating systems and architectures
  if (ULAPI_OK != ulapi_init (UL_USE_DEFAULT))
    {
      printf ("can't initialize ulapi");
      return 1;
    }
    
  dequeueTask = ulapi_task_new ();
  ulapi_task_start (dequeueTask, dequeueThread, (void *) ctrl, ulapi_prio_lowest (),
		    1);
		    
  
  printf( "Queue InitCanon\n" );
  ctrl->queueMsg(&initCanon);
  printf( "Queue dwell\n" );
  ctrl->queueMsg(&dwell);
  ctrl->queueMsg(&firstMove);
  ctrl->queueMsg(&descendMsg);
  
  
  /*MoveToMsg *moveMsgs[8];// = new MoveToMsg[8];
  
  for(int x = 0;x<2;x++)
  {
  	for(int y = 0;y<4;y++)
  	{
  		PoseLocation *pose = new PoseLocation("drop_grid_pose");
  		Point *pt = new Point("drop_grid_point");
  		pt->sethasPoint_X(.065 + x*.256);
  		pt->sethasPoint_Y(.637 + y*.256);
  		pt->sethasPoint_Z(0.04);
  		pose->sethasPoseLocation_Point(pt);
		pose->sethasPoseLocation_XAxis(xAxis);
		pose->sethasPoseLocation_ZAxis(zAxis);
		MoveToMsg* poseMsg = new MoveToMsg(pose);
		//moveMsgs[2*y + x] = poseMsg;
		
		ctrl->queueMsg(&pickupMove);
		ctrl->queueMsg(&dwell);
		ctrl->queueMsg(&closeGripper);
		ctrl->queueMsg(&dwell);
		ctrl->queueMsg(&liftMove);
		ctrl->queueMsg(&dwell);
		ctrl->queueMsg(poseMsg);
		ctrl->queueMsg(&dwell);
		ctrl->queueMsg(&openGripper);
		ctrl->queueMsg(&dwell);
  	}
  }
  
  for(int x = 0;x<2;x++)
  {
  	for(int y = 0;y<4;y++)
  	{
  		PoseLocation *pose = new PoseLocation("drop_grid_pose");
  		Point *pt = new Point("drop_grid_point");
  		pt->sethasPoint_X(.065 + x*.256);
  		pt->sethasPoint_Y(.637 + y*.256);
  		pt->sethasPoint_Z(0.04);
  		pose->sethasPoseLocation_Point(pt);
		pose->sethasPoseLocation_XAxis(xAxis);
		pose->sethasPoseLocation_ZAxis(zAxis);
		MoveToMsg* pickupMsg = new MoveToMsg(pose);
		PoseLocation *liftPose = new PoseLocation("lift_grid_pose");
		Point *liftPt = new Point("lift_grid_point");
		liftPt->sethasPoint_X(.065 + x*.256);
  		liftPt->sethasPoint_Y(.637 + y*.256);
  		liftPt->sethasPoint_Z(-0.15);
  		liftPose->sethasPoseLocation_Point(liftPt);
  		liftPose->sethasPoseLocation_XAxis(xAxis);
  		liftPose->sethasPoseLocation_ZAxis(zAxis);
  		MoveToMsg *liftMsg = new MoveToMsg(liftPose);
		//moveMsgs[2*y + x] = poseMsg;
		
		ctrl->queueMsg(pickupMsg);
		ctrl->queueMsg(&dwell);
		ctrl->queueMsg(&closeGripper);
		ctrl->queueMsg(&dwell);
		ctrl->queueMsg(liftMsg);
		ctrl->queueMsg(&dwell);
		ctrl->queueMsg(&dropBox);
		ctrl->queueMsg(&dwell);
		ctrl->queueMsg(&openGripper);
		ctrl->queueMsg(&dwell);
  	}
  }*/
  ctrl->queueMsg(&closeGripper);
  
  printf( "Queue messageMsg\n" );
  ctrl->queueMsg(&messageMsg);
  //sleep(10);
  printf( "Queue endCanon\n" );
  ctrl->queueMsg(&endCanon);
  sleep(300);
  return 1;
}
