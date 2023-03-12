#include "gameStates.h"
#include "game.h"

// States.
#include "states/mainMenu.h"
#include "states/gamePlay.h"

GameState gameStates[STATE_COUNT] = {
	{ // Menu main.
		.initCallback = mainMenuInit,
		.closeCallback = mainMenuClose,
		.updateCallback = mainMenuUpdate,
		.drawCallBack = mainMenuDraw,
		.data = &mainMenuData
	},
	{ // Game play.
		.initCallback = gamePlayInit,
		.closeCallback = gamePlayClose,
		.updateCallback = gamePlayUpdate, 
		.drawCallBack = gamePlayDraw, 
		.data = &gamePlayData,
	}
};

#define GAME_STATES_SIZE (sizeof(gameStates) / sizeof(GameState))

void initStates(GameData * gameData) {
	int i;

	for (i = 0; i < GAME_STATES_SIZE; ++i)
		if (gameStates[i].initCallback != NULL)
			gameStates[i].initCallback(gameData, gameStates[i].data);

	TraceLog(LOG_INFO, "States initialization");
}

void closeStates(GameData * gameData) {
	int i;

	for (i = 0; i < GAME_STATES_SIZE; ++i)
		if (gameStates[i].closeCallback != NULL)
			gameStates[i].closeCallback(gameData, gameStates[i].data);

	TraceLog(LOG_INFO, "States closed");
}

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
