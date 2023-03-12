#include "mainMenu.h"
#include "game.h"
#include <stdbool.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

MainMenuData mainMenuData = {
};

StateIds mainMenuUpdate(GameData * gameData, void * data) {
	MainMenuData * mainMenuData = (MainMenuData*)data;

	return CURRENT_STATE;
}

void mainMenuDraw(GameData * gameData, void * data) {
	MainMenuData * mainMenuData = (MainMenuData*)data;
}
