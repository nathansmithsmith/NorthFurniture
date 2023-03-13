#include "playerCamera.h"
#include "game.h"
#include "tiles.h"

void initPlayerCamera(Camera2D * camera) {
	camera->target = (Vector2){0.0, 0.0};
	camera->offset = (Vector2){0.0, 0.0};
	camera->rotation = 0.0;
	camera->zoom = 1.0;
}

void updatePlayerCamera(GameData * gameData, Camera2D * camera) {
	camera->zoom += ((float)GetMouseWheelMove()*0.05f);

	if (camera->zoom > 3.0f)
		camera->zoom = 3.0f;
	else if (camera->zoom < 0.1f)
		camera->zoom = 0.1f;

	if (IsKeyDown(KEY_RIGHT))
		camera->target.x += 10;
	if (IsKeyDown(KEY_LEFT))
		camera->target.x -= 10;
	if (IsKeyDown(KEY_UP))
		camera->target.y -= 10;
	if (IsKeyDown(KEY_DOWN))
		camera->target.y += 10;
}
