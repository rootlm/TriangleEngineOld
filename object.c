#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
 
#include <stdbool.h>
#include "math2.h"
#include "object.h"
#include "sprite.h"
#include "input.h"
#include "render.h"

void InitObjects() {
	objects = calloc(MAXOBJECTS,sizeof(void*));
	unsigned short i = 0;
	//null it out!
	while (i < MAXOBJECTS) {
		objects[i]=NULL;
	i++;
	}
}


unsigned short createobject(unsigned short type,float x,float y) {
	unsigned short i = 0;
	while (objects[i] != NULL && i < MAXOBJECTS) {		
	i++;
	}
	if (i < MAXOBJECTS) {
		switch (type) {
			case 0:
					obj_player_create(i);
				break;
			//add other create function calls here
		}
		objects[i]->x = x;
		objects[i]->y = y;
		objects[i]->type = type;
		
	}
	else {
		i=65535;
	}
return i;
}

void deleteobject(unsigned short id) {
	if (id > MAXOBJECTS) {
		printf("deleteobject error:id out of bounds (%i)\n",id);
	}
	else if (objects[id] == NULL) {
		printf("deleteobject error:attempted to delete nonexistent object (%i)\n",id);
	}
	else {
		//obj_example* fuckk=objects[id];
		//printf("t%i\n",fuckk->type);
		free(objects[id]);
		//printf("%i\n",fuckk->type);
		objects[id] = NULL;
	}
}

//-----create

/*void obj_TEMPLATE_create(unsigned short id) {

}*/

void obj_player_create(unsigned short id) {
	objects[id]=calloc(1,sizeof(obj_player));
	objects[id]->hp = 100;
}


//-----step

/*void obj_TEMPLATE_step(unsigned short id) {

}*/

void obj_player_step(unsigned short id) {
	if (((obj_player*)objects[id])->shoottimer != 0) {
		((obj_player*)objects[id])->shoottimer -= 1;
	}
	if (keyboard_check(LeftButton)) {
		objects[id]->x-=7;
	}
	if (keyboard_check(RightButton)) {
		objects[id]->x+=7;
	}
	if (keyboard_check(UpButton)) {
		objects[id]->y-=7;
	}
	if (keyboard_check(DownButton)) {
		objects[id]->y+=7;
	}

}

//---OBJECTUPDATE
void ObjectsUpdate() {
	unsigned short i=0;
		while (i < MAXOBJECTS) {
			if (objects[i] != NULL) {
				switch (objects[i]->type) {
				case 0:
					obj_player_step(i);
					break;
				//add other step function calls here
				}
			}
		i++;
		}
}