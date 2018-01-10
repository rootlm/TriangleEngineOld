#include "globaldef.h"
#include "render.h"
#include "bfont.h"
#include <stdio.h>

#ifdef RENDERER_SDL
	#include <SDL.h>
#endif

BitmapFont* Engine_LoadFont(const char* fontfname) {
	BitmapFont* loadfont;
	loadfont = (BitmapFont *) malloc(sizeof(BitmapFont));
		//add png to the filename
		unsigned char* fucking = calloc(strlen(fontfolder)+strlen(fontfname)+4,sizeof(unsigned char));
		strcpy(fucking,fontfolder);
		strcat(fucking,fontfname);
		strcat(fucking,".png");
	loadfont->fontimage=Engine_LoadGraphic(fucking);
		//add fnt to it as well
		strcpy(fucking,fontfolder);
		strcat(fucking,fontfname);
		strcat(fucking,".fnt");
	FILE* loadfontrectsfile=fopen(fucking,"r");
	if (loadfontrectsfile != NULL) { //if file actually exists
		unsigned short fontnumchars;
		fread(&fontnumchars,2,1,loadfontrectsfile);
		loadfont->fontrects= (SDL_Rect *) calloc(fontnumchars,sizeof(Renderer_Rect));
		unsigned short fontloadi=0;
		//load rects
		while (fontloadi < fontnumchars) {
			fread(&loadfont->fontrects[fontloadi].x,2,1,loadfontrectsfile);
			fread(&loadfont->fontrects[fontloadi].y,2,1,loadfontrectsfile);
			fread(&loadfont->fontrects[fontloadi].w,1,1,loadfontrectsfile);
			fread(&loadfont->fontrects[fontloadi].h,1,1,loadfontrectsfile);
			fontloadi += 1;
		}
		fclose(loadfontrectsfile);
		free(fucking);
	}
	else {
		printf("Error loading font file %s!\n",fucking);
		free(fucking);
	}
return loadfont;
}

void draw_text(BitmapFont* drawfont, short dtx, short dty, const char* drawstr) {
#ifdef RENDERER_SDL
	unsigned char i=0;
	SDL_Rect* drawcharrect;
	drawcharrect = (SDL_Rect *) malloc(sizeof(SDL_Rect));
	drawcharrect->x=dtx;
	drawcharrect->y=dty;
		//while (i <= 11) {
		while (drawstr[i] >= 32) {
			drawcharrect->w=drawfont->fontrects[drawstr[i]].w;
			drawcharrect->h=drawfont->fontrects[drawstr[i]].h;
			SDL_RenderCopyEx(renderer,drawfont->fontimage,&drawfont->fontrects[drawstr[i]],drawcharrect,0,NULL,SDL_FLIP_NONE);
			drawcharrect->x += drawcharrect->w;
		i+=1;
		}
	if (drawcharrect != NULL) {
		free(drawcharrect);
	}
#else
	printf("No renderer. Draw_text:%i\n",drawstr);
#endif
}