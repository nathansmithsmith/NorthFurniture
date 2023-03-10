#include "gameData.h"
#include "gameStates.h"

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

StateIds gamePlayUpdate(GameData * gameData, void * data);
void gamePlayDraw(GameData * gameData, void * data);

#endif
