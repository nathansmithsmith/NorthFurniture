#include "game.h"

void initGame(GameData * gameData, int argc, char ** argv) {
	// Open window.
	InitWindow(800, 480, argv[0]);

	// Set state.
	gameData->stateId = MAIN_MENU_STATE;
	setState(MAIN_MENU_STATE, gameData);

	// Settings.
	gameData->settings = defaultSettings;

	dumpSettings("settings.set", &gameData->settings);
	loadSettings("settings.set", &gameData->settings);
}

void closeGame(GameData * gameData) {
	CloseWindow();
}

void updateGame(GameData * gameData) {
	updateState(gameData);
}

void drawGame(GameData * gameData) {
	BeginDrawing();

	ClearBackground(RAYWHITE);
	DrawFPS(0, 0);

	drawState(gameData);

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
