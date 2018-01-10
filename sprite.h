#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include "math2.h"
#include "globaldef.h"

#ifdef RENDERER_SDL
	#include <SDL.h>
#endif

#ifndef __SPRITE__
#define __SPRITE__

//#define MAXSPRITES 512
unsigned short MAXSPRITES; //made it configurable because of spritedata file
unsigned short SpriteSheetAmount;

	#define spr_player 0

Engine_Texture** SpriteSheets;

typedef struct {
	Renderer_Rect framerect;
	unsigned char animlength;
	unsigned char* anim; //array the size of animlength, each frame is a number of how many sprite widths past the framerect
	//if animlength is 0 don't allocate anim i guess, and i'll have drawing functions take that into account..
	unsigned short sheet;
	unsigned short xoff; //offset
	unsigned short yoff;
} sprite;

sprite* SpriteData;

void InitSprites();

#endif