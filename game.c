//Includes
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#include "globaldef.h"
#include "math2.h"
#include "input.h"
#include "render.h"
#include "object.h"
#include "sprite.h"
#include "bfont.h"

void Game_Step() {
		Renderer_SetDrawColor(6,127,64,255);
		Renderer_Clear();
		Renderer_SetDrawColor(6,127,64,255);

		draw_text(testfont,0,0,"Hello World! FUCKASS FUCK SHIT TEST ASSSS 69420 haha benis XDDD lol");

		ObjectsUpdate();
		draw_sprite_ext(0,0,objects[0]->x,objects[0]->y,1,1,0);

		Renderer_Present();

		if (keyboard_check(JumpButton)) {
			quit=true;
		}
}

void Game_Quit() {
	unsigned short i = 0;
	//Clear Objects
	while (i < MAXOBJECTS) {
		if (objects[i] != NULL) {
			free(objects[i]);
		}
	i++;
	}

	//Clear Sprites and Animations
	i=0;
	while (i < MAXSPRITES) {
		if (SpriteData[i].anim != NULL) {
			free(SpriteData[i].anim);
		}
	i++;
	}
	free(SpriteData);

	//Clear Spritesheets
	i=0;
	while (i < MAXSPRITESHEETS) {
		if (SpriteSheets[i] != NULL) {
			free(SpriteSheets[i]);
		}
	i++;
	}
	free(SpriteSheets);

	#ifdef RENDERER_SDL
		SDL_Quit();
	#endif
}