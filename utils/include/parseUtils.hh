/*
DISCLAIMER:
This software was produced by the National Institute of Standards
and Technology (NIST), an agency of the U.S. government, and by statute is
not subject to copyright in the United States. Recipients of this software
assume all responsibility associated with its operation, modification,
maintenance, and subsequent redistribution.

See NIST Administration Manual 4.09.07 b and Appendix I. 
*/

/*!
\file parseUtils.hh

\brief Common declarations for the parser 

\author Stephen Balakirsky
\date 6 April 2011
*/


#ifndef __parseUtils__
#define __parseUtils__

#define MAX_TOKEN_LEN 1024

extern const char *getKey(const char *msg, char *key);
extern const char *getValue(const char *msg, char *value);
extern const char *getVector(const char *msg, double *dblArray, int length);
extern const char *getBone(const char *msg, double *dblArray);
extern const char *expect(const char *expectString, const char *msg);
extern const char *getInteger(const char *msg, int *intValue);
extern const char *getDouble( const char *msg, double *dblValue);
#endif

/* Sample output from humanoid robot
{Name GenericMan_0} {Class GenericMan} {Time 176.1948} {Location 6.78,-1.66,3.84
} {Rotation -0.00,0.00,1.60} {Bone Main} {Parent None} {Location 0.00,0.00,-0.0
0} {Orientation 0.00,0.00,0.00} {Bone Pelvis} {Parent None} {Location -0.00,0.00
,-1.03} {Orientation 0.00,-0.00,0.00} {Bone Spine} {Parent Pelvis} {Location 0.0
4,0.00,-1.23} {Orientation 0.00,0.00,0.00} {Bone Chest} {Parent Spine} {Location
0.05,0.00,-1.43} {Orientation 0.00,-0.10,0.00} {Bone Neck} {Parent Chest} {Loca
tion -0.01,0.00,-1.55} {Orientation 0.00,-0.10,0.00} {Bone head} {Parent Neck} {
Location 0.02,0.00,-1.61} {Orientation 0.00,0.05,0.00} {Bone RT_Shoulder} {Paren
t Chest} {Location 0.01,0.20,-1.43} {Orientation 0.70,-0.10,0.00} {Bone RT_Forea
rm} {Parent RT_Shoulder} {Location -0.01,0.23,-1.20} {Orientation 0.70,0.06,-0.1
9} {Bone RT_Hand} {Parent RT_Forearm} {Location 0.00,0.29,-0.94} {Orientation 0.
73,0.25,-0.03} {Bone LT_Shoulder} {Parent Chest} {Location 0.01,-0.20,-1.43} {Or
ientation -0.70,-0.10,0.00} {Bone LT_Forearm} {Parent LT_Shoulder} {Location -0.
01,-0.24,-1.19} {Orientation -0.70,0.06,0.19} {Bone LT_Hand} {Parent LT_Forearm}
{Location 0.00,-0.29,-0.94} {Orientation -0.71,-0.13,0.35} {Bone RT_Thigh} {Par
ent Pelvis} {Location -0.00,0.10,-0.91} {Orientation 3.04,0.00,3.14} {Bone RT_Sh
in} {Parent RT_Thigh} {Location -0.00,0.11,-0.49} {Orientation 0.10,0.00,0.00} {
Bone RT_Foot} {Parent RT_Shin} {Location -0.02,0.13,-0.08} {Orientation 0.10,0.0
0,0.00} {Bone LT_Thigh} {Parent Pelvis} {Location -0.00,-0.10,-0.91} {Orientatio
n -0.10,0.00,0.00} {Bone LT_Shin} {Parent LT_Thigh} {Location -0.00,-0.12,-0.48}
{Orientation -0.10,0.00,0.00} {Bone LT_Foot} {Parent LT_Shin} {Location -0.02,-
0.14,-0.07} {Orientation -0.09,0.00,0.00}

*/
