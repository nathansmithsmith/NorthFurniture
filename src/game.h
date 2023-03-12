#include "gameData.h"
#include "gameStates.h"
#include "settings.h"
#include "textureLoader.h"

#ifndef GAME_H
#define GAME_H

// Data for the entire game.
typedef struct GameData {

	// Game state.
	StateIds stateId;
	GameState * state;

	Settings settings;

	GameTextureData textureData;

	Camera2D playerCamera;
} GameData;


// Starting and closing.
void initGame(GameData * gameData, int argc, char ** argv);
void closeGame(GameData * gameData);

// Updating and drawing.
void updateGame(GameData * gameData);
void drawGame(GameData * gameData);

void runGame(GameData * gameData, int argc, char ** argv);

#endif
