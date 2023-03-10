#include "settings.h"
#include "game.h"
#include <stdbool.h>

Settings defaultSettings = {
	.windowWidth = 800,
	.windowHeight = 480,
	.fullScreen = false,
	.name = "nathan",
	.testNumber = 2.5
};

ConfigErrors dumpSettings(const char * filePath, Settings * settings) {
	ConfigLine configLines[] = {
		{"windowWidth", &settings->windowWidth, VALUE_INT},
		{"windowHeight", &settings->windowHeight, VALUE_INT},
		{"fullScreen", &settings->fullScreen, VALUE_BOOL},
		{"name", settings->name, VALUE_STRING},
		{"testNumber", &settings->testNumber, VALUE_FLOAT}
	};

	return dumpConfig(
		filePath, 
		configLines, 
		sizeof(configLines) / sizeof(ConfigLine)
	);
}

ConfigErrors loadSettings(const char * filePath, Settings * settings) {
	ConfigLine configLines[] = {
		{"windowWidth", &settings->windowWidth, VALUE_INT},
		{"windowHeight", &settings->windowHeight, VALUE_INT},
		{"fullScreen", &settings->fullScreen, VALUE_BOOL},
		{"name", settings->name, VALUE_STRING},
		{"testNumber", &settings->testNumber, VALUE_FLOAT}
	};

	return loadConfig(
		filePath, 
		configLines, 
		sizeof(configLines) / sizeof(ConfigLine)
	);
}
