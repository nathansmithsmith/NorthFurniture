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

// Adds 'texture' to 'textureData'.
ErrorCodes addTextures(GameTextureData * textureData, const Texture2D * textures, size_t texturesSize);

#endif
