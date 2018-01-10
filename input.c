#include "globaldef.h"
#include "input.h"
#ifdef INPUT_SDL
	#include <SDL.h>
#endif

void InitKeys() {
#ifdef INPUT_SDL
JumpButton = SDL_SCANCODE_Z;
AttackButton = SDL_SCANCODE_X;
SpecialButton = SDL_SCANCODE_C;
StartButton = SDL_SCANCODE_RETURN;

LeftButton = SDL_SCANCODE_LEFT;
RightButton = SDL_SCANCODE_RIGHT;
UpButton = SDL_SCANCODE_UP;
DownButton = SDL_SCANCODE_DOWN;
#endif

KeyboardPrevious = calloc(127,sizeof(Uint8));
KeyboardCurrent = calloc(127,sizeof(Uint8));
}

char keyboard_check(char statetocheck) {
	if (KeyboardCurrent[statetocheck] == 1) {
		return 1;
	}
else {
	return 0;
}

}

char keyboard_check_pressed(char statetocheck) {
	if (KeyboardCurrent[statetocheck] == 1 && KeyboardPrevious[statetocheck] == 0) {
		return 1;
	}
else {
	return 0;
}

}

char keyboard_check_released(char statetocheck) {
	if (KeyboardCurrent[statetocheck] == 0 && KeyboardPrevious[statetocheck] == 1) {
		return 1;
	}
else {
	return 0;
}

}

void UpdateKeys() {
	#ifdef INPUT_SDL
	const Uint8 *keyboard = SDL_GetKeyboardState(NULL);
	#else //fake a keyboard by making an array every time this function is called if no input method
		Uint8* keyboard = (Uint8 *) calloc(127,sizeof(Uint8));
		unsigned char i2 = 0;
		while (i2 < 127) {
			keyboard[i2]=0;
		i2++;
		}
	#endif
	unsigned char i = 0;
	while (i < 127) {
		KeyboardPrevious[i]=KeyboardCurrent[i];
		i++;
	}
	i = 0;
	while (i < 127) {
		KeyboardCurrent[i]=keyboard[i];
		i++;
	}
	#ifndef INPUT_SDL
		free(keyboard);
	#endif
}