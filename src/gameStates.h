#include "gameData.h"

// Things like menus and game play are the different states of the game.

#ifndef GAME_STATES_H
#define GAME_STATES_H

typedef enum StateIds {
	CURRENT_STATE = -1,
	MAIN_MENU_STATE,
	GAME_PLAY_STATE
} StateIds;

// Returns next state.
typedef StateIds (*STATE_UPDATE_CB)(GameData * gameData, void * data);
typedef void (*STATE_DRAW_CB)(GameData * gameData, void * data);

typedef struct GameState {
	STATE_UPDATE_CB updateCallback;
	STATE_DRAW_CB drawCallBack;
	void * data; // Can be used for whatever data the state needs.
} GameState;

// Update can change the game state.
void updateState(GameData * gameData);
void drawState(GameData * gameData);

void setState(StateIds stateid, GameData * gameData);

#define STATE_COUNT 2
extern GameState gameStates[STATE_COUNT];

#endif
