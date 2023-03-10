#include "gameData.h"
#include "configLoader.h"

#ifndef SETTINGS_H
#define SETTINGS_H

// All the settings in the game.
typedef struct Settings {

	// Screen.
	int windowWidth;
	int windowHeight;
	bool fullScreen;

	char name[20];
	float testNumber;

} Settings;

extern Settings defaultSettings;

ConfigErrors dumpSettings(const char * filePath, Settings * settings);
ConfigErrors loadSettings(const char * filePath, Settings * settings);

#endif
