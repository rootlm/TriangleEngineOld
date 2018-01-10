#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
 
#include <stdbool.h>
#include "math2.h"

#ifndef __OBJECT__
#define __OBJECT__

#define MAXOBJECTS 512

//void** objects; //OBJECT ARRAY FUCK

typedef struct {
	unsigned short type;
	float x;
	float y;
	float xspeed;
	float yspeed;
	unsigned char depth;
	unsigned short sprite;
	float frame;
	float framespeed;
	unsigned char state;
	unsigned char hp;
} obj_example;

typedef struct {
	unsigned short type;
	float x;
	float y;
	float xspeed;
	float yspeed;
	unsigned char depth;
	unsigned short sprite;
	float frame;
	float framespeed;
	unsigned char state;
	unsigned char hp;
	unsigned char shoottimer;
} obj_player;

obj_example** objects; //OBJECT ARRAY FUCK

void InitObjects();
unsigned short createobject(unsigned short type,float x,float y);
void deleteobject(unsigned short id);

#endif