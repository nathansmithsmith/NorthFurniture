#include "gameData.h"
#include "textureLoader.h"
#include <raylib.h>

#ifndef TILES_H
#define TILES_H

#define TILE_SIZE 16

#define MAP_X_OVERSCAN 2
#define MAP_Y_OVERSCAN 2

typedef enum TileTypes {
	TILE_NONE = 0,
	TILE_NONWALKABLE = 0x1
} TileTypes;

typedef uint16_t TileId;

typedef struct Tile {
	Texture2D texture;
	Vector2 texturePosition;
	uint16_t type;
} Tile;

typedef struct TileMap {
	TileId * tiles; // A grid of every tile.
	int width;
	int height;

	Tile * tileData;
	size_t tileDataSize;
} TileMap;

TileId * getTile(const TileMap * tileMap, Vector2 position);
void drawTile(const TileMap * tileMap, Vector2 position);

// Draw tiles in camera view.
void drawTiles(const TileMap * tileMap, Camera2D camera);

TileMap * createTileMap(int width, int height, Tile * tileData, size_t tileDataSize);
void closeTileMap(TileMap * tileMap);

#endif
