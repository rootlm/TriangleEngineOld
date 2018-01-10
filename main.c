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

//main loop flag
bool quit = false;

SDL_Event evunion;
void EventHandler() {
	#ifdef RENDERER_SDL
	while (SDL_PollEvent(&evunion) != 0 )
	{
		//User requests quit
		if (evunion.type == SDL_QUIT)
		{
		quit = true;
		}
	}
	#endif
}


//=======================================================
//Main loop
int main( int argc, char* args[] )
{
	InitWindow();
	InitKeys();
	InitObjects();
	printf("Input Test - Press Z To Quit\n");

	//Test Object
	unsigned short a=createobject(0,420,69);

	InitSprites();

	testfont=Engine_LoadFont("MSG");

	GAME_STATE = GAME_STATE_INGAME;


//------------------------------------------GAME LOOP
	while (!quit) {
		EventHandler();
		UpdateKeys();
		Game_Step();
//SDL_Delay(1000);
	}


	SDL_Quit();
return 0;
}
