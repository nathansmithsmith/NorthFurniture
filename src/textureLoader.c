#include "textureLoader.h"
#include <raylib.h>

void initTextureData(GameTextureData * textureData) {
	textureData->textures = NULL;
	textureData->texturesSize = 0;
}

void closeTextureData(GameTextureData * textureData) {
	textureData->texturesSize = 0;

	// Free textures.
	if (textureData->textures != NULL)
		free(textureData->textures);
}

// Add Textures to new texture data.
ErrorCodes createAndAddTextures(GameTextureData * textureData, const Texture2D * textures, size_t texturesSize) {
	textureData->texturesSize = texturesSize;

	// Allocate textures.
	textureData->textures = (Texture2D*)calloc(textureData->texturesSize, sizeof(Texture2D));

	if (textureData->textures == NULL) {
		TraceLog(LOG_ERROR, "Error allocating memory for 'textureData->textures' %s", strerror(errno));
		return CERROR;
	}

	// Copy textures.
	memcpy(textureData->textures, textures, texturesSize * sizeof(Texture2D));

	return CSUCCESS;
}

ErrorCodes addTextures(GameTextureData * textureData, const Texture2D * textures, size_t texturesSize) {
	size_t oldTexturesSize;

	// Textures have not been created yet.
	if (textureData->textures == NULL)
		return createAndAddTextures(textureData, textures, texturesSize);

	oldTexturesSize = textureData->texturesSize;
	textureData->texturesSize += texturesSize;

	// Reallocate textures.
	textureData->textures = (Texture2D*)reallocarray(
		textureData->textures,
		textureData->texturesSize,
		sizeof(Texture2D)
	);

	if (textureData->textures == NULL) {
		TraceLog(LOG_ERROR, "Error reallocating memory for 'textureData->textures' %s", strerror(errno));
		return CERROR;
	}

	// Copy new textures.
	memcpy(
		textureData->textures + (oldTexturesSize * sizeof(Texture2D)),
		textures,
		texturesSize * sizeof(Texture2D)
	);

	return CSUCCESS;
}
