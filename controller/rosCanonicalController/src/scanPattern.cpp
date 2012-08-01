#include <Point.h>
#include <Vector.h>
#include <PoseLocation.h>
#include "canonicalMsg.hh"
#include "rosInf.hh"
void generateScanPattern(MoveThroughToMsg *scanPattern, RosInf* rosInf, Point *initPoint, double length, double width)
{
	Vector *xAxis = new Vector("x_axis");
	xAxis->sethasVector_I(-1.0);
	xAxis->sethasVector_J(0.0);
	xAxis->sethasVector_K(0.0);
	Vector *zAxis = new Vector("z_axis");
	zAxis->sethasVector_I(0.0);
	zAxis->sethasVector_J(0.0);
	zAxis->sethasVector_K(1.0);
	//for now, assume arm is .5 m above scan area
	double sensorHeight = .5;
	printf("sensor FOV is %f\n", rosInf->getSensorFOV());
	double senseWidth = sin(rosInf->getSensorFOV()/2) * 2 * sensorHeight;
	bool downstroke = true;
	double startX = initPoint->gethasPoint_X();
	double startY = initPoint->gethasPoint_Y();
	double sensorZ = initPoint->gethasPoint_Z() - sensorHeight;
	
	int numPoses = ceil(width/senseWidth) * 2 + 1;
	printf("%d poses\n", numPoses);
	PoseLocation** poses = new PoseLocation*[numPoses];
	
	int index = 1;
	
	Point *lastPoint = new Point("path_pt");
	lastPoint->sethasPoint_X(startX);
	lastPoint->sethasPoint_Y(startY + senseWidth/2);
	lastPoint->sethasPoint_Z(sensorZ);
	
	PoseLocation *firstPose = new PoseLocation("start_pose");
	firstPose->sethasPoseLocation_Point(lastPoint);
	firstPose->sethasPoseLocation_XAxis(xAxis);
	firstPose->sethasPoseLocation_ZAxis(zAxis);
	
	poses[0] = firstPose;
	
	do
	{
		Point *verticalPoint = new Point("vertical_point");
		if(downstroke)
			verticalPoint->sethasPoint_X(startX + length);
		else
			verticalPoint->sethasPoint_X(startX);
		downstroke = !downstroke;
		verticalPoint->sethasPoint_Y(lastPoint->gethasPoint_Y());
		verticalPoint->sethasPoint_Z(sensorZ);
		PoseLocation *verticalStroke = new PoseLocation("vertical_pose");
		verticalStroke->sethasPoseLocation_Point(verticalPoint);
		verticalStroke->sethasPoseLocation_XAxis(xAxis);
		verticalStroke->sethasPoseLocation_ZAxis(zAxis);
		
		poses[index] = verticalStroke;
		index++;
		
		Point *horizontalPoint = new Point("horizontal_point");
		horizontalPoint->sethasPoint_X(verticalPoint->gethasPoint_X());
		horizontalPoint->sethasPoint_Y(verticalPoint->gethasPoint_Y() + senseWidth);
		horizontalPoint->sethasPoint_Z(sensorZ);
		PoseLocation *horizontalStroke = new PoseLocation("horizontal_pose");
		horizontalStroke->sethasPoseLocation_Point(horizontalPoint);
		horizontalStroke->sethasPoseLocation_XAxis(xAxis);
		horizontalStroke->sethasPoseLocation_ZAxis(zAxis);
		
		poses[index] = horizontalStroke;
		index++;
		
		lastPoint = horizontalPoint;
	}while(lastPoint->gethasPoint_Y() - senseWidth/2 < startY + width);
	printf("INDEX=%d\nNUM=%d\n",index, numPoses);
	
	scanPattern->num = numPoses;
	scanPattern->poseLocations = poses;
}

