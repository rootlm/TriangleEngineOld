#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
 
#include <stdbool.h>
#include "globaldef.h"
#include "math2.h"
#include "object.h"
#include "sprite.h"
#include "input.h"
#include "render.h"

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
