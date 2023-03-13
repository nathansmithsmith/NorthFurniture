#include "tiles.h"
#include "textureLoader.h"
#include "game.h"
#include "util.h"

TileId * getTile(const TileMap * tileMap, Vector2 position) {
	int index;
	index = tileMap->width * position.y + position.x;
	return &tileMap->tiles[index];
}

void drawTile(const TileMap * tileMap, Vector2 position) {
	// Get id and tile.
	TileId * tileId = getTile(tileMap, position);
	Tile tile = tileMap->tileData[*tileId];

	// Draw
	DrawTextureRec(
		tile.texture,
		(Rectangle){tile.texturePosition.x, tile.texturePosition.y, TILE_SIZE, TILE_SIZE},
		(Vector2){position.x * TILE_SIZE, position.y * TILE_SIZE},
		WHITE
	);
}

void drawTiles(const TileMap * tileMap, Camera2D camera) {
	int x, y;
	int startX, startY;
	int endX, endY;

	// Get camera view.
	Rectangle cameraView = {
		(camera.target.x - camera.offset.x) / TILE_SIZE,
		(camera.target.y - camera.offset.y) / TILE_SIZE,
		GetRenderWidth() / camera.zoom / TILE_SIZE,
		GetRenderHeight() / camera.zoom / TILE_SIZE
	};

	// Get start and end values for loop.
	startX = cameraView.x - MAP_X_OVERSCAN;
	startY = cameraView.y - MAP_Y_OVERSCAN;
	endX = cameraView.x + cameraView.width + MAP_X_OVERSCAN;
	endY = cameraView.y + cameraView.height + MAP_Y_OVERSCAN;

	// Clamp them.
	startX = Clamp(startX, 0, tileMap->width - 1);
	startY = Clamp(startY, 0, tileMap->height - 1);
	endX = Clamp(endX, 0, tileMap->width - 1);
	endY = Clamp(endY, 0, tileMap->height - 1);

	/*
	printf(
		"X: (%d %d) Y: (%d %d)\n",
		startX,
		endX,
		startY,
		endY
	);
	*/

	// Loop and draw.
	for (y = startY; y < endY; ++y)
		for (x = startX; x < endX; ++x)
			drawTile(tileMap, (Vector2){x, y});
}

TileMap * createTileMap(int width, int height, Tile * tileData, size_t tileDataSize) {
	TileMap * tileMap = NULL;

	// Allocate 'tileMap'.
	tileMap = (TileMap*)malloc(sizeof(TileMap));

	if (tileMap == NULL) {
		allocationError("tileMap");
		return NULL;
	}

	// Allocate 'tileMap->tiles'.
	tileMap->tiles = (TileId*)calloc(width * height, sizeof(TileId));

	if (tileMap->tiles == NULL) {
		allocationError("tileMap->tiles");
		return NULL;
	}

	// Allocate 'tileMap->tileData'.
	tileMap->tileData = (Tile*)calloc(tileDataSize, sizeof(Tile));

	if (tileMap->tileData == NULL) {
		allocationError("tileMap->tileData");
		return NULL;
	}

	// Fill 'tiles'.
	memset(tileMap->tiles, 0, width * height * sizeof(TileId));

	// Copy 'tileData'.
	memcpy(tileMap->tileData, tileData, tileDataSize * sizeof(Tile));

	tileMap->width = width;
	tileMap->height = height;
	tileMap->tileDataSize = tileDataSize;

	TraceLog(LOG_INFO, "New tile map created. Width: %d, Height: %d, Ids %ld", width, height, tileDataSize);
	return tileMap;
}

void closeTileMap(TileMap * tileMap) {
	// Free memory.
	if (tileMap->tiles != NULL)
		free(tileMap->tiles);
	if (tileMap->tileData != NULL)
		free(tileMap->tileData);

	tileMap->tiles = NULL;
	tileMap->tileData = NULL;

	tileMap->width = 0;
	tileMap->height = 0;
	tileMap->tileDataSize = 0;

	TraceLog(LOG_INFO, "Tile map closed");
}
