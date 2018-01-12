#include "globaldef.h"
#ifndef __INPUT__
#define __INPUT__
//Init Key Settings
int JumpButton;
int AttackButton;
int SpecialButton;
int StartButton;

int LeftButton;
int RightButton;
int UpButton;
int DownButton;

unsigned char* KeyboardPrevious;
unsigned char* KeyboardCurrent;

void InitKeys();
char keyboard_check(char statetocheck);
char keyboard_check_pressed(char statetocheck);
char keyboard_check_released(char statetocheck);
void UpdateKeys();
#endif
