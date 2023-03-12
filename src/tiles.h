#include "gameData.h"

#ifndef TILES_H
#define TILES_H

typedef enum TileTypes {
	TILE_NONE = 0,
	TILE_NONWALKABLE = 0x1
} TileTypes;

typedef struct Tile {
	int16_t id;
	uint64_t type;
	Vector2 pos;
} Tile;

#endif
