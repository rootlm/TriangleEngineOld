#include <stdbool.h>
#ifndef __GLOBALDEF__
#define __GLOBALDEF__
//these are global defines
//Screen dimension constants
#define SCREEN_WIDTH 576
#define SCREEN_HEIGHT 672
#define APPTITLE "Triangle Engine"

bool quit;

#define GAME_STATE_INGAME 0
#define GAME_STATE_MENU 10
unsigned char GAME_STATE;

//define data folders
#define sprfolder "data/spr/"
#define fontfolder "data/fonts/"

//and file extensions?
#define sprfextension ".png"

//platform 
#define PLATFORM_PC

//renderer (the idea is that if you don't define a renderer the game will run but you won't be able to see anything obviously)
#define RENDERER_SDL

//renderer typedefs
#ifdef RENDERER_SDL
	#include <SDL.h>
	#define Engine_Texture SDL_Texture
	#define Renderer_Rect SDL_Rect
	#define INPUT_SDL //input is seperate from rendering but if using sdl for rendering might as well use it for keyboard too
#else
	#define Engine_Texture unsigned char
	typedef struct {
	unsigned short x;
	unsigned short y;
	unsigned short w;
	unsigned short h;
	} Renderer_Rect;
#endif

#endif

//GLOBAL INCLUDES

#ifdef RENDERER_SDL
	#include <SDL.h>
	#include <SDL_image.h>
	#ifdef INPUT_SDL //just incase i ever make it use sdl for rendering but not input (probably not but eh)
		#include <SDL_keyboard.h>
	#endif
#endif
