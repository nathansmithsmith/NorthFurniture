#include "gameData.h"
#include "textureLoader.h"

#ifndef TILES_H
#define TILES_H

#define TILE_SIZE 16

typedef enum TileTypes {
	TILE_NONE = 0,
	TILE_NONWALKABLE = 0x1
} TileTypes;

typedef struct Tile {
	uint16_t id;
	uint64_t type;
} Tile;

void drawTile(GameTextureData textureData, Tile tile, Vector2 position);

typedef struct TileMap {
	Tile * tiles;
	int width;
	int height;
} TileMap;

TileMap * createTileMap(int width, int height);

#endif
