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
		"images/spriteSheet.png",
		"images/evil_puppy_right_1.png",
		"images/player_right_1.png"
	};

	loadTexturesFromFiles(
		&gameData->textureData, 
		textureFiles, 
		3
	);

	Texture2D spriteSheet = getTexture(gameData->textureData, 0);

	Tile tileData[] = {
		{spriteSheet, (Vector2){0.0, 0.0}, 0},
		{spriteSheet, (Vector2){16.0, 0.0}, 0},
		{spriteSheet, (Vector2){0.0, 16.0}, 0},
		{spriteSheet, (Vector2){16.0, 16.0}, 0}
	};

	// Tile map.
	gameData->tileMap = createTileMap(
		200,
		100,
		tileData,
		sizeof(tileData) / sizeof(Tile)
	);

	TileId * tile;
	int x, y;

	for (y = 0; y < gameData->tileMap->height; ++y)
		for (x = 0; x < gameData->tileMap->width; ++x) {
			tile = getTile(gameData->tileMap, (Vector2){x, y});
			*tile = x % 4;
		}

	SetTargetFPS(60);
}

void closeGame(GameData * gameData) {
	closeStates(gameData);
	closeSettings(&gameData->settings);
	closeTextureData(&gameData->textureData);
	closeTileMap(gameData->tileMap);

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
