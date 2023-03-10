#include "gameData.h"
#include "game.h"

int main(int argc, char ** argv) {
	GameData gameData;
	runGame(&gameData, argc, argv);
	return 0;
}
