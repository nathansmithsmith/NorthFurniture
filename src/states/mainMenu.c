#include "mainMenu.h"
#include "game.h"
#include <stdbool.h>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

MainMenuData mainMenuData = {
	.nextState = CURRENT_STATE,
	.startButton = {0.0, 0.0, 100.0, 50.0}
};

void mainMenuInit(STATE_CALLBACK_ARGS) {
	MainMenuData * mainMenuData = (MainMenuData*)data;

	int winWidth = GetRenderWidth();
	int winHeight = GetRenderHeight();

	mainMenuData->startButton.x = winWidth / 2.0 - mainMenuData->startButton.width / 2.0;
	mainMenuData->startButton.y = winHeight / 2.0 - mainMenuData->startButton.height / 2.0;
}

void mainMenuClose(STATE_CALLBACK_ARGS) {
}

StateIds mainMenuUpdate(STATE_CALLBACK_ARGS) {
	MainMenuData * mainMenuData = (MainMenuData*)data;

	return mainMenuData->nextState;
}

void mainMenuDraw(STATE_CALLBACK_ARGS) {
	MainMenuData * mainMenuData = (MainMenuData*)data;

	if (GuiButton(mainMenuData->startButton, "Start"))
		mainMenuData->nextState = GAME_PLAY_STATE;
}
