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

//main loop flag
bool quit = false;


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
	}


	Game_Quit();
return 0;
}
