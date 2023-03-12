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
	int i;
	Tile tile = {1, 0};

	BeginMode2D(gameData->playerCamera);

	for (int y = -20; y < 20; ++y)
		for (int x = -20; x < 20; ++x)
			drawTile(gameData->textureData, tile, (Vector2){x, y});

	EndMode2D();
}
