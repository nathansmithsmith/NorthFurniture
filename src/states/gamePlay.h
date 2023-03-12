#include "gameData.h"
#include "gameStates.h"

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

typedef struct GamePlayData {
} GamePlayData;

extern GamePlayData gamePlayData;

void gamePlayInit(STATE_CALLBACK_ARGS);
void gamePlayClose(STATE_CALLBACK_ARGS);
StateIds gamePlayUpdate(STATE_CALLBACK_ARGS);
void gamePlayDraw(STATE_CALLBACK_ARGS);

#endif
