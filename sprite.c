#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
 
#include <stdbool.h>
#include "math2.h"
#include "sprite.h"
#include "globaldef.h"

#ifdef RENDERER_SDL
	#include <SDL.h>
#endif

void LoadSpriteData(const char* spritedatafname) {
	FILE* file = fopen(spritedatafname,"r");
		unsigned short i = 0;
		unsigned char i2 = 0;
		unsigned char* tempchar = calloc(2,sizeof(unsigned char));// = malloc(sizeof(unsigned char));
		unsigned char* fname = calloc(24+strlen(sprfolder)+strlen(sprfextension),sizeof(unsigned char));
		strcat(fname,sprfolder);
		bool loadedstr = false;
		if (file != NULL) {
			fseek(file,6,0); //ignore the header for now
			fread(&SpriteSheetAmount,2,1,file); //read spritesheet amount
			SpriteSheets = (Engine_Texture *) calloc(SpriteSheetAmount,sizeof(Engine_Texture*));
			printf("SpriteSheetAmount:%i\n",SpriteSheetAmount);
			while (i < SpriteSheetAmount) {
				i2=0;
				loadedstr=false;
				while (!loadedstr && i2 < 24) {
					fread(tempchar,1,1,file);
					//printf("%i\n",ftell(file));
					//printf("tempchar:%s",tempchar);
					if (!strcmp(tempchar,"|")) {
						loadedstr=true;
					}
					else {
						strcat(fname,tempchar);
					}
				i2++;
				}
				//printf("%s\n",fname);
				strcat(fname,sprfextension);
				SpriteSheets[i] = Engine_LoadGraphic(fname);
				free(fname);
				fname = calloc(24+strlen(sprfolder)+strlen(sprfextension),sizeof(unsigned char));
				strcat(fname,sprfolder);
			i++;
			}
			printf("Loaded spritesheet filenames!\n");
			//load spritedata
			fread(&MAXSPRITES,2,1,file); //read sprite amount
			printf("MAXSPRITES:%i\n",MAXSPRITES);
			i=0;
			i2=0;
			while (i < MAXSPRITES) {
				fread(&SpriteData[i].framerect.x,2,1,file);
				fread(&SpriteData[i].framerect.y,2,1,file);
				fread(&SpriteData[i].framerect.w,2,1,file);
				fread(&SpriteData[i].framerect.h,2,1,file);
				fread(&SpriteData[i].animlength,1,1,file);
				fread(&SpriteData[i].sheet,2,1,file);
				fread(&SpriteData[i].xoff,2,1,file);
				fread(&SpriteData[i].yoff,2,1,file);
				if (SpriteData[i].animlength > 0) {
					i2=0;
					SpriteData[i].anim = calloc(SpriteData[i].animlength,sizeof(unsigned char));
					while (i2 <= SpriteData[i].animlength) {
						fread(&SpriteData[i].anim[i2],1,1,file);
					i2++;
					}
				}
			i++;
			}
			fclose(file);
		}
		else {
			printf("Error loading sprite data file %s!",spritedatafname);
		}
		free(tempchar);
		free(fname);
}

void InitSprites() {
	MAXSPRITES = 512;
	//SpriteSheets = (Engine_Texture *) calloc(10,sizeof(Engine_Texture*));
	SpriteData = (sprite *) calloc(MAXSPRITES,sizeof(sprite));

	LoadSpriteData("spritedata.dat");

	/*SpriteData[0].animlength=0;
	SpriteData[0].sheet=0;
	SpriteData[0].xoff=33;
	SpriteData[0].yoff=33;
	SpriteData[0].framerect.x=0;
	SpriteData[0].framerect.y=0;
	SpriteData[0].framerect.w=66;
	SpriteData[0].framerect.h=66;*/
}

/*typedef struct {
	SDL_Rect framerect;
	unsigned char animlength;
	unsigned char* anim; //array the size of animlength, each frame is a number of how many sprite widths past the framerect
	//if animlength is 0 don't allocate anim i guess, and i'll have drawing functions take that into account..
	SDL_Texture* sheet;
	unsigned short xoff; //offset
	unsigned short yoff;
} sprite;*/