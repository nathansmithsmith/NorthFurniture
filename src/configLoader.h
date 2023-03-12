#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

/*
 * A Custom config loader.
 *
 * format
 *
 * option = value
 * option = value
 * # Comments must not have white space before them.
 * ...
 *
 * No tabs in config file.
*/

#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#define CONFIG_LINE_MAX 255

typedef enum ConfigErrors {
	CONFIG_SUCCESS = 0,
	CONFIG_ERROR = -1,
	CONFIG_TAB_ERROR = -2,
	CONFIG_MISSING_VALUE = -3,
	CONFIG_WHITE_SPACE_ERROR = -4,
	CONFIG_INVALID_OPTION = -5,
	CONFIG_INVALID_VALUE = -6
} ConfigErrors;

#define CONFIG_ERROR_MAX 255

char * configErrorToString(ConfigErrors error);

// Types that the 'value' can be.
typedef enum ConfigValueTypes {
	VALUE_STRING,
	VALUE_FLOAT,
	VALUE_INT,
	VALUE_BOOL
} ConfigValueTypes;

// Data for each line.
typedef struct ConfigLine {
	char option[CONFIG_LINE_MAX];
	void * value;
	ConfigValueTypes type;
	size_t valueSize; // Used when type is 'VALUE_STRING'.
} ConfigLine;

// Used for sorting config lines and binary search.
static int compareConfigLines(const void * c1, const void * c2);

// Run after setting all the data in the config lines.
// It sorts the config lines to be faster for searching.
void initConfigLines(ConfigLine * configLines, size_t configLinesSize);

// CONFIG_LINE_MAX for 'line' len.
// Uses 'lineData' to create a nicely formatted config line.
void createConfigLine(char * line, const ConfigLine lineData);

// Gets and option and value from a config line.
// 'CONFIG_LINE_MAX' for buffers sizes.
ConfigErrors getOptionAndValue(const char * lineBuf, char * optionBuf, char * valueBuf);

// Returns config line with option as 'optionBuf' or null.
ConfigLine * findConfigLineWithOption(const char * optionBuf, const ConfigLine * configLines, size_t configLinesSize);

// Loads data from 'lineBuf' and writes it to 'configLines'.
ConfigErrors loadConfigLine(const char * lineBuf, ConfigLine * configLines, size_t configLinesSize);

ConfigErrors dumpConfig(const char * filePath, const ConfigLine * configLines, size_t configLinesSize);
ConfigErrors loadConfig(const char * filePath, ConfigLine * configLines, size_t configLinesSize);

#endif
