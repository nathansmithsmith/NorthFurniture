#include "playerCamera.h"

void initPlayerCamera(Camera2D * camera) {
	camera->target = (Vector2){0.0, 0.0};
	camera->offset = (Vector2){GetRenderWidth() / 2.0, GetRenderHeight() / 2.0};
	camera->rotation = 0.0;
	camera->zoom = 1.0;
}

void updatePlayerCamera(GameData * gameData, Camera2D * camera) {
	camera->offset = (Vector2){GetRenderWidth() / 2.0, GetRenderHeight() / 2.0};

	camera->zoom += ((float)GetMouseWheelMove()*0.05f);

	if (camera->zoom > 3.0f)
		camera->zoom = 3.0f;
	else if (camera->zoom < 0.1f)
		camera->zoom = 0.1f;
}
