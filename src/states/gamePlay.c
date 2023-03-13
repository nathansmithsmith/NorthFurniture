#include "gamePlay.h"
#include "game.h"
#include "playerCamera.h"
#include "tiles.h"

GamePlayData gamePlayData = {
};

void gamePlayInit(STATE_CALLBACK_ARGS) {
	GamePlayData * gamePlayData = (GamePlayData*)data;
}

void gamePlayClose(STATE_CALLBACK_ARGS) {
	GamePlayData * gamePlayData = (GamePlayData*)data;
}

StateIds gamePlayUpdate(STATE_CALLBACK_ARGS) {
	GamePlayData * gamePlayData = (GamePlayData*)data;

	updatePlayerCamera(gameData, &gameData->playerCamera);

	return CURRENT_STATE;
}

void gamePlayDraw(STATE_CALLBACK_ARGS) {
	GamePlayData * gamePlayData = (GamePlayData*)data;

	BeginMode2D(gameData->playerCamera);

	drawTiles(gameData->tileMap, gameData->playerCamera);

	EndMode2D();
}
