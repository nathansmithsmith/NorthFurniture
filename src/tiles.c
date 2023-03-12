#include "tiles.h"
#include "textureLoader.h"
#include "game.h"
#include "util.h"

void drawTile(GameTextureData textureData, Tile tile, Vector2 position) {
	Texture2D * texture = getTexture(textureData, tile.id);
	
	// Get null tile if texture is null.
	if (texture == NULL) {
		texture = getTexture(textureData, 0);

		// Return if still null.
		if (texture == NULL)
			return;
	}

	// Draw.
	DrawTexture(*texture, position.x * TILE_SIZE, position.y * TILE_SIZE, WHITE);
}

TileMap * createTileMap(int width, int height) {
	int i;
	TileMap * tileMap = NULL;

	// Allocate 'tileMap'.
	tileMap = (TileMap*)malloc(sizeof(TileMap));

	if (tileMap == NULL) {
		allocationError("tileMap");
		return NULL;
	}

	// Allocate 'tileMap->tiles'.
	tileMap->tiles = (Tile*)calloc(width * height, sizeof(Tile));

	if (tileMap->tiles == NULL) {
		allocationError("tileMap->tileMap");
		return NULL;
	}

	return tileMap;
}
