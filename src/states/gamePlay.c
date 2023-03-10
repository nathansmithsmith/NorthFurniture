#include "gamePlay.h"

StateIds gamePlayUpdate(GameData * gameData, void * data) {
	return CURRENT_STATE;
}

void gamePlayDraw(GameData * gameData, void * data) {
	DrawText("In game", 100, 100, 10, BLACK);
}
