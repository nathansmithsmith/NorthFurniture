#include "mainMenu.h"
#include "game.h"

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

StateIds mainMenuUpdate(GameData * gameData, void * data) {
	if (GuiButton((Rectangle){10.0, 10.0, 100.0, 50.0}, "hi")) {
		puts("hihi");
		return GAME_PLAY_STATE;
	}

	return CURRENT_STATE;
}

void mainMenuDraw(GameData * gameData, void * data) {
}
