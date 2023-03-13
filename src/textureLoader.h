#include "gameData.h"

#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

typedef struct GameTextureData {
	Texture2D * textures;
	size_t texturesSize;
} GameTextureData;

// Starts texture data with one allocated texture.
void initTextureData(GameTextureData * textureData);
void closeTextureData(GameTextureData * textureData);

ErrorCodes addTextures(GameTextureData * textureData, const Texture2D * textures, size_t texturesSize);

// Returns the texture at 'id' in 'textures'.
Texture2D getTexture(GameTextureData textureData, int id);

ErrorCodes loadTexturesFromFiles(GameTextureData * textureData, const char ** files, size_t filesSize);

#endif
