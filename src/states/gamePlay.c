#include "gamePlay.h"

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

	return CURRENT_STATE;
}

void gamePlayDraw(STATE_CALLBACK_ARGS) {
	GamePlayData * gamePlayData = (GamePlayData*)data;

	DrawText("In game", 100, 100, 10, BLACK);
}
