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

	// Data used for reading and writing settings to a config file.
	size_t configLinesSize;
	ConfigLine * configLines;

} Settings;

extern Settings defaultSettings;

ErrorCodes initSettings(Settings * settings);
ErrorCodes closeSettings(Settings * settings);

// Use these to read and write settings to config file.
ConfigErrors dumpSettings(const char * filePath, const Settings * settings);
ConfigErrors loadSettings(const char * filePath, Settings * settings);

#endif
