#include <stdio.h>
#include "render.h"
#include "globaldef.h"
#include "sprite.h"

//Renderer includes
#ifdef RENDERER_SDL
	#include <SDL.h>
	#include <SDL_image.h>
#endif

void InitWindow() {

#ifdef RENDERER_SDL
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else {
		printf("SDL Initialized!\n");
		//Create window
		window = SDL_CreateWindow( APPTITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ) {
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else {
			printf("Window created successfully!\n");
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );
		}
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	if( renderer == NULL ) {
			printf( "Renderer could not be created! SDL_Error: %s\n", SDL_GetError() );
	}
	else {
		printf("Renderer created successfully!\n");
	}

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Init SDL_Image
	int initimgflags=IMG_INIT_PNG;
	IMG_Init(initimgflags);
#endif
}

Engine_Texture* Engine_LoadGraphic(const char* loadgfxfilename) {
#ifdef RENDERER_SDL

	Engine_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(loadgfxfilename);

	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

	if (newTexture == NULL) {
		printf( "Texture %s could not be created! SDL_Error: %s\n", loadgfxfilename, SDL_GetError() );
	}
	else {
		printf( "Texture %s loaded! \n", loadgfxfilename );
	}

	SDL_FreeSurface(loadedSurface);

	return newTexture;
#endif
}

void draw_sprite_ext(short dsprite,unsigned short dsfrm,float dsx,float dsy,float dxsc,float dysc,short dsrot) {
#ifdef RENDERER_SDL
	SDL_Point* dspriteoffset; //self explanatory
		dspriteoffset = (SDL_Point *) malloc(sizeof(SDL_Point));
		dspriteoffset->x = SpriteData[dsprite].xoff;
		dspriteoffset->y = SpriteData[dsprite].yoff;
	SDL_Rect* dspriterect; //Destination rectangle (accounts for x and y scale, but origin can only be center right now)
		dspriterect = (SDL_Rect *) malloc(sizeof(SDL_Rect));
		dspriterect->w=SpriteData[dsprite].framerect.w * dxsc;
		dspriterect->h=SpriteData[dsprite].framerect.h * dysc;
		dspriterect->x=dsx-(dspriteoffset->x * dxsc);
		dspriterect->y=dsy-(dspriteoffset->y * dysc);
	SDL_Rect* dspritefrect; //Copy of the framerect that it uses for animation
		dspritefrect = (SDL_Rect *) malloc(sizeof(SDL_Rect));
		dspritefrect->w=SpriteData[dsprite].framerect.w;
		dspritefrect->h=SpriteData[dsprite].framerect.h;
		dspritefrect->x=SpriteData[dsprite].framerect.x;
	if (SpriteData[dsprite].animlength == 0) {
		dsfrm = 0; //modulo by 0 means rip so 
	}
	if (dsfrm > SpriteData[dsprite].animlength) {
		dsfrm = dsfrm % (SpriteData[dsprite].animlength+1); //make sure the frame number is within the animation length!
	}
	if (SpriteData[dsprite].animlength != 0 && SpriteData[dsprite].anim != NULL) {
		dspritefrect->x += SpriteData[dsprite].framerect.w * SpriteData[dsprite].anim[dsfrm];
	}
	dspritefrect->y=SpriteData[dsprite].framerect.y;

	dspriteoffset->x *= dxsc;
	dspriteoffset->y *= dysc;
	SDL_RenderCopyEx(renderer,SpriteSheets[SpriteData[dsprite].sheet],dspritefrect,dspriterect,dsrot,dspriteoffset,SDL_FLIP_NONE);
//SDL_SetRenderDrawColor(renderer,255,255,255,255);
//SDL_RenderDrawRect(renderer,dspritefrect);
	if (dspriterect != NULL) {
		free(dspriterect);
	}
	if (dspritefrect != NULL) {
	free(dspritefrect);
	}
	if (dspriteoffset != NULL) {
	free(dspriteoffset);
	}
#endif
}