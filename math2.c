#include <math.h>

float degtorad(float degtoconv) {
return ((degtoconv * 3.14) / 180);
}

float radtodeg(float radtoconv) {
return ((radtoconv * 180) / 3.14);
}

float point_direction(float x1, float y1, float x2, float y2) {
return radtodeg(atan2(x2-x1, y2-y1))+180;
}

float dsin(float dsinarg) {
return sin(degtorad(dsinarg));
}

float dcos(float dcosarg) {
return cos(degtorad(dcosarg));
}

float point_distance(float x1,float y1,float x2,float y2) {

	float xdist = (x1-x2);
	xdist = xdist * xdist;

	float ydist = (y1-y2);
	ydist = ydist * ydist;

return sqrt(xdist + ydist);
}

int clamp(int val,int min,int max) {
	if (val < min) {
		val=min;
	}
	if (val > max) {
		val=max;
	}
return val;
}

float lengthdir_x(float len, float angle) {
return len * dcos(angle);
}

float lengthdir_y(float len, float angle) {
return len * -dsin(angle);
}

/*float clampfloat(float val,float min,float max) {

return val;
}*/