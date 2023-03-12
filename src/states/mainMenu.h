#include "gameData.h"
#include "gameStates.h"
#include <raylib.h>

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

typedef struct MainMenuData {
	StateIds nextState;
	Rectangle startButton;
} MainMenuData;

extern MainMenuData mainMenuData;

void mainMenuInit(STATE_CALLBACK_ARGS);
void mainMenuClose(STATE_CALLBACK_ARGS);
StateIds mainMenuUpdate(STATE_CALLBACK_ARGS);
void mainMenuDraw(STATE_CALLBACK_ARGS);

#endif
