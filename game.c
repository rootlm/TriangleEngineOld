//Includes
#include <stdio.h>
#include <stdbool.h>

#include "globaldef.h"
#include "math2.h"
#include "input.h"
#include "render.h"
#include "object.h"
#include "sprite.h"
#include "bfont.h"

#ifdef RENDERER_SDL
	#include <SDL.h>
	#include <SDL_image.h>
	#include <SDL_rwops.h>
	#include <SDL_keyboard.h>
#endif

void Game_Step() {
		//temppl->y+=0.05;
		//printf("%f\n",temppl->y);
		#ifdef RENDERER_SDL
		SDL_SetRenderDrawColor(renderer, 6,127,64, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 6,127,64, 255);
		//SDL_RenderDrawPoint(renderer, temppl->x,temppl->y);
		//SDL_RenderDrawPoint(renderer, temppl->x + lengthdir_x(32,fuck*4),temppl->y + lengthdir_y(32,fuck*4));

		draw_text(testfont,0,0,"Hello World! FUCKASS FUCK SHIT TEST ASSSS 69420 haha benis XDDD lol");

		ObjectsUpdate();
		draw_sprite_ext(0,0,objects[0]->x,objects[0]->y,1,1,0);

		unsigned short fuck=0;
		SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
		/*while (fuck < objects[0]->hp) {
			//SDL_RenderDrawLine(renderer, temppl->x+lengthdir_x(32,fuck),temppl->y+lengthdir_y(32,fuck),temppl->x+lengthdir_x(48,fuck),temppl->y+lengthdir_y(48,fuck));
			//SDL_RenderDrawLine(renderer, temppl->x+lengthdir_x(32,fuck*45),temppl->y+lengthdir_y(32,fuck*45),temppl->x+lengthdir_x(48,(fuck+1)*45),temppl->y+lengthdir_y(48,(fuck+1)*45));
			SDL_RenderDrawPoint(renderer, temppl->x+lengthdir_x(32,fuck*3.6),temppl->y+lengthdir_y(32,fuck*3.6));
		fuck+=1;
		}*/

		SDL_SetRenderDrawColor(renderer, 255,0,0, 255);
		//SDL_RenderDrawLine(renderer, temppl->x,temppl->y,temppl->x+lengthdir_x(32,45),temppl->y+lengthdir_y(32,45));

		//draw image
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		//Update the surface
		SDL_RenderPresent(renderer);
		#endif

		if (keyboard_check(JumpButton)) {
			quit=true;
		}
}