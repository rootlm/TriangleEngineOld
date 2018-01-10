#ifndef __MATH2H__
#define __MATH2H__
float degtorad(float degtoconv);

float radtodeg(float radtoconv);

float point_direction(int x1, int y1, int x2, int y2);

float dsin(float dsinarg);

float dcos(float dcosarg);

float point_distance(x1,y1,x2,y2);

int clamp(int val,int min,int max);

float lengthdir_x(float len, float angle);

float lengthdir_y(float len, float angle);
#endif