class Point;
class Pose;
class VectorIJK;

class Point
{
 public:
  Point(){x=0; y=0; z=0;}
  Point(double xIn, double yIn, double zIn){x=xIn; y=yIn; z=zIn;}
  ~Point(){}
  double x;
  double y;
  double z;
};

class VectorIJK
{
 public:
  VectorIJK(){i=0; j=0; k=0;}
  VectorIJK(double iIn, double jIn, double kIn){i=iIn; j=jIn; k=kIn;}
  ~VectorIJK(){}
  double i;
  double j;
  double k;
};

class Pose
{
 public:
  Pose(){}
  ~Pose(){}
  Point origin;
  VectorIJK zAxis;
  VectorIJK xAxis;
};

