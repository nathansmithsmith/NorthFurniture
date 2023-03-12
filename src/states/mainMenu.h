#include "gameData.h"
#include "gameStates.h"
#include <raylib.h>

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

typedef struct MainMenuData {
} MainMenuData;

extern MainMenuData mainMenuData;

StateIds mainMenuUpdate(GameData * gameData, void * data);
void mainMenuDraw(GameData * gameData, void * data);

#endif
