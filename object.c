#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
 
#include <stdbool.h>
#include "globaldef.h"
#include "math2.h"
#include "object.h"
#include "objectfunctions.h"
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
			case 1:
					obj_playershot_create(i);
				break;
			case 2:
					obj_catfairy_create(i);
				break;
			case 3:
					obj_catfairyshot_create(i);
				break;
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

//---OBJECTUPDATE
void ObjectsUpdate() {
	unsigned short i=0;
		while (i < MAXOBJECTS) {
			if (objects[i] != NULL) {
				switch (objects[i]->type) {
				case 0:
					obj_player_step(i);
					break;
				case 1:
					obj_playershot_step(i);
					break;
				case 2:
					obj_catfairy_step(i);
					break;
				case 3:
					obj_catfairyshot_step(i);
					break;
				}
			}
		i++;
		}
}