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

ErrorCodes initSettings(Settings * settings) {
	ConfigLine configLines[] = {
		{"windowWidth", &settings->windowWidth, VALUE_INT},
		{"windowHeight", &settings->windowHeight, VALUE_INT},
		{"fullScreen", &settings->fullScreen, VALUE_BOOL},
		{"name", settings->name, VALUE_STRING, 20},
		{"testNumber", &settings->testNumber, VALUE_FLOAT}
	};

	// Set to default.
	memcpy(settings, &defaultSettings, sizeof(Settings));

	// Set config lines size.
	settings->configLinesSize = sizeof(configLines) / sizeof(ConfigLine);

	// Allocate 'configLines'.
	settings->configLines = (ConfigLine*)calloc(settings->configLinesSize, sizeof(ConfigLine));

	if (settings->configLines == NULL) {
		TraceLog(LOG_ERROR, "Error allocating 'settings->configLines': %s", strerror(errno));
		return CERROR;
	}

	// Copy config line data.
	memcpy(settings->configLines, configLines, settings->configLinesSize * sizeof(ConfigLine));

	return CSUCCESS;
}

ErrorCodes closeSettings(Settings * settings) {
	if (settings->configLines != NULL)
		free(settings->configLines);

	return CSUCCESS;
}

ConfigErrors dumpSettings(const char * filePath, const Settings * settings) {
	return dumpConfig(
		filePath, 
		settings->configLines, 
		settings->configLinesSize
	);
}

ConfigErrors loadSettings(const char * filePath, Settings * settings) {
	return loadConfig(
		filePath, 
		settings->configLines, 
		settings->configLinesSize
	);
}
