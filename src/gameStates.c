#include "gameStates.h"
#include "game.h"

// States.
#include "states/mainMenu.h"
#include "states/gamePlay.h"

GameState gameStates[STATE_COUNT] = {
	{ // Menu main.
		.updateCallback = mainMenuUpdate,
		.drawCallBack = mainMenuDraw,
		.data = &mainMenuData
	},
	{ // Game play.
		.updateCallback = gamePlayUpdate, 
		.drawCallBack = gamePlayDraw, 
		.data = NULL
	}
};

void updateState(GameData * gameData) {
	GameState * state = gameData->state;
	StateIds stateId;

	if (state == NULL)
		return;
	if (state->updateCallback == NULL)
		return;
		
	// Run update callback.
	stateId = state->updateCallback(gameData, state->data);

	// Set new state.
	setState(stateId, gameData);
}

void drawState(GameData * gameData) {
	GameState * state = gameData->state;

	if (state == NULL)
		return;

	// Run draw callback.
	if (state->drawCallBack != NULL)
		state->drawCallBack(gameData, state->data);
}

void setState(StateIds stateId, GameData * gameData) {
	if (stateId == CURRENT_STATE)
		return;

	gameData->stateId = stateId;
	gameData->state = &gameStates[stateId];
}
