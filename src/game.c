#include "game.h"
#include "util.h"
#include "playerCamera.h"

void initGame(GameData * gameData, int argc, char ** argv) {
	// Open window.
	InitWindow(800, 480, argv[0]);

	// Game state.
	initStates(gameData);
	gameData->stateId = MAIN_MENU_STATE;
	setState(MAIN_MENU_STATE, gameData);

	// Settings.
	initSettings(&gameData->settings);

	// Camera.
	initPlayerCamera(&gameData->playerCamera);

	//dumpSettings("settings.set", &gameData->settings);
	//loadSettings("settings.set", &gameData->settings);

	// Test texture loader.
	initTextureData(&gameData->textureData);

	const char * textureFiles[255] = {
		"images/null.png",
		"images/grass.png",
		"images/gravel.png",
		"images/evil_puppy_right_1.png",
		"images/player_right_1.png"
	};

	loadTexturesFromFiles(
		&gameData->textureData, 
		textureFiles, 
		5
	);
}

void closeGame(GameData * gameData) {
	closeStates(gameData);
	closeSettings(&gameData->settings);
	closeTextureData(&gameData->textureData);
	CloseWindow();
}

void updateGame(GameData * gameData) {
	updateState(gameData);
}

void drawGame(GameData * gameData) {
	int i;

	BeginDrawing();

	ClearBackground(RAYWHITE);

	drawState(gameData);
	DrawFPS(0, 0);

	EndDrawing();
}

void runGame(GameData * gameData, int argc, char ** argv) {
	// Start game.
	initGame(gameData, argc, argv);

	// Run update loop
	while (!WindowShouldClose()) {
		updateGame(gameData);
		drawGame(gameData);
	}

	// Close game.
	closeGame(gameData);
}
