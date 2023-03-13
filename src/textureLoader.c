#include "textureLoader.h"
#include "util.h"
#include <raylib.h>

void initTextureData(GameTextureData * textureData) {
	textureData->textures = NULL;
	textureData->texturesSize = 0;

	TraceLog(LOG_INFO, "Game texture data initialization");
}

void closeTextureData(GameTextureData * textureData) {
	int i;

	if (textureData->textures == NULL) {
		textureData->texturesSize = 0;
		return;
	}

	// Unload textures.
	for (i = 0; i < textureData->texturesSize; ++i)
		UnloadTexture(textureData->textures[i]);

	// Free.
	textureData->texturesSize = 0;
	free(textureData->textures);
	textureData->textures = NULL;

	TraceLog(LOG_INFO, "Game texture data closed");
}

// Add Textures to new texture data.
ErrorCodes createAndAddTextures(GameTextureData * textureData, const Texture2D * textures, size_t texturesSize) {
	textureData->texturesSize = texturesSize;

	// Allocate textures.
	textureData->textures = (Texture2D*)calloc(textureData->texturesSize, sizeof(Texture2D));

	if (textureData->textures == NULL) {
		allocationError("textureData->textures");
		return CERROR;
	}

	// Copy textures.
	memcpy(textureData->textures, textures, texturesSize * sizeof(Texture2D));

	return CSUCCESS;
}

ErrorCodes addTextures(GameTextureData * textureData, const Texture2D * textures, size_t texturesSize) {
	int i, j;
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
		allocationError("textureData->textures");
		return CERROR;
	}

	// Copy new textures.
	j = 0;
	
	for (i = oldTexturesSize; i < textureData->texturesSize; ++i)
		textureData->textures[i] = textures[j++];

	return CSUCCESS;
}

Texture2D getTexture(GameTextureData textureData, int id) {
	if (textureData.textures == NULL || id < 0 || id >= textureData.texturesSize)
		return (Texture2D){0};

	return textureData.textures[id];
}

ErrorCodes loadTexturesFromFiles(GameTextureData * textureData, const char ** files, size_t filesSize) {
	int i;
	Texture2D textures[filesSize];

	// Load testures.
	for (i = 0; i < filesSize; ++i)
		textures[i] = LoadTexture(files[i]);

	// Add textures.
	return addTextures(textureData, textures, filesSize);
}
