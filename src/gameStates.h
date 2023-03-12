#include "gameData.h"

// Things like menus and game play are the different states of the game.

#ifndef GAME_STATES_H
#define GAME_STATES_H

typedef enum StateIds {
	CURRENT_STATE = -1,
	MAIN_MENU_STATE,
	GAME_PLAY_STATE
} StateIds;

#define STATE_CALLBACK_ARGS GameData * gameData, void * data

// Callbacks.
typedef void (*STATE_INIT_CB)(STATE_CALLBACK_ARGS);
typedef void (*STATE_CLOSE_CB)(STATE_CALLBACK_ARGS);
typedef StateIds (*STATE_UPDATE_CB)(STATE_CALLBACK_ARGS); // Returns next state.
typedef void (*STATE_DRAW_CB)(STATE_CALLBACK_ARGS);

typedef struct GameState {
	STATE_INIT_CB initCallback; // For when game is started.
	STATE_CLOSE_CB closeCallback; // For cleaning memory when game ends.
	STATE_UPDATE_CB updateCallback;
	STATE_DRAW_CB drawCallBack;
	void * data; // Can be used for whatever data the state needs.
} GameState;

void initStates(GameData * gameData);
void closeStates(GameData * gameData);

// Update can change the game state.
void updateState(GameData * gameData);
void drawState(GameData * gameData);

void setState(StateIds stateid, GameData * gameData);

#define STATE_COUNT 2
extern GameState gameStates[STATE_COUNT];

#endif
