#include "globaldef.h"

#ifndef __BFONT__
#define __BFONT__

typedef struct {
	Engine_Texture* fontimage;
	Renderer_Rect* fontrects;
} BitmapFont;

BitmapFont* testfont;

BitmapFont* Engine_LoadFont(const char* fontfname);
void draw_text(BitmapFont* drawfont, short dtx, short dty, const char* drawstr);

#endif