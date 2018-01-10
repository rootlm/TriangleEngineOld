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

//void ObjectsUpdate();
void Game_Step();