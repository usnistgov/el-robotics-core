#include "Pose.h"
#include <math.h>           // sqrt
#include <stdio.h>          // fprintf
#include <stdlib.h>         // exit

/********************************************************************/

/* VectorIJK::normalize

This normalizes the vector. If the length of the vector is zero, this
prints an error message and exits.

*/

void VectorIJK::normalize()
{
  double length;
  length = sqrt((i*i) + (j*j) + (k*k));
  if (length == 0.0)
    {
      fprintf(stderr, "cannot normalize zero length vector; exiting");
      exit(1);
    }
  i = i/length;
  j = j/length;
  k = k/length;
}

/********************************************************************/

/* Pose::checkYAxis

This normalizes the xAxis and the zAxis and checks that they are
orthogonal by checking that the cross product (which is the Y axis)
has a length close to 1.

If the vectors are not orthogonal, this prints an error message and exits.

*/

void Pose::checkYAxis()
{
  xAxis.normalize();
  zAxis.normalize();
  double yi = ((zAxis.j * xAxis.k) - (xAxis.j * zAxis.k));
  double yj = ((zAxis.k * xAxis.i) - (xAxis.k * zAxis.i));
  double yk = ((zAxis.i * xAxis.j) - (xAxis.i * zAxis.j));
  double length = sqrt((yi * yi) + (yj * yj) + (yk * yk));
  if ((length > 1.0000001) || (length < 0.9999999))
    {
      fprintf(stderr,
	      "in Pose, X axis and Z axis are not orthogonal; exiting\n");
      exit(1);
    }
}

/********************************************************************/
