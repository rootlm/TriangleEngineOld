#include "globaldef.h"

#ifndef __RENDER__
#define __RENDER__

#ifdef RENDERER_SDL
//renderer (kek)
SDL_Renderer* renderer;

//The window we'll be rendering to
SDL_Window* window;

//The surface contained by the window
SDL_Surface* screenSurface;

SDL_Event evunion;
#endif

typedef struct {
	unsigned long* data; //the image itself
	unsigned short width;
	unsigned height;
} graphic;

void InitWindow();
void EventHandler();
void draw_sprite_ext(short dsprite,unsigned short dsfrm,float dsx,float dsy,float dxsc,float dysc,short dsrot);
Engine_Texture* Engine_LoadGraphic(const char* loadgfxfilename);
#endif

//RENDERER MACROS
#ifdef RENDERER_SDL
	#define Renderer_SetDrawColor(r,g,b,a) SDL_SetRenderDrawColor(renderer,r,g,b,a)
	#define Renderer_Clear() SDL_RenderClear(renderer)
	#define Renderer_Present() SDL_RenderPresent(renderer)
#endif