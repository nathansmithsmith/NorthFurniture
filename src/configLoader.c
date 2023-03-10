#include "configLoader.h"
#include "util.h"

char * configErrorToString(ConfigErrors error) {
	switch (error) {
		case CONFIG_SUCCESS:
			return "success";
		case CONFIG_ERROR:
			return "error";
		case CONFIG_TAB_ERROR:
			return "tab error";
		case CONFIG_MISSING_VALUE:
			return "missing value";
		case CONFIG_WHITE_SPACE_ERROR:
			return "white space error";
		default:
			return "";
	}
}

void createConfigLine(char * line, const ConfigLine lineData) {
	int i;
	char valueBuf[CONFIG_LINE_MAX];

	memset(line, 0, CONFIG_LINE_MAX);
	memset(valueBuf, 0, CONFIG_LINE_MAX);

	if (lineData.value == NULL)
		return;

	// Format value.
	switch (lineData.type) {
		case VALUE_STRING:
			strncat(valueBuf, (const char*)lineData.value, CONFIG_LINE_MAX - 1);
			break;
		case VALUE_FLOAT:
			snprintf(valueBuf, CONFIG_LINE_MAX, "%f", *((float*)lineData.value));
			break;
		case VALUE_INT:
			snprintf(valueBuf, CONFIG_LINE_MAX, "%d", *((int*)lineData.value));
			break;
		case VALUE_BOOL:
			if (*((bool*)lineData.value))
				strcat(valueBuf, "true");
			else
				strcat(valueBuf, "false");

			break;
		default:
			return;
	}

	// Format line.
	snprintf(line, CONFIG_LINE_MAX, "%s = %s", lineData.option, valueBuf);
}

ConfigErrors getOptionAndValue(const char * lineBuf, char * optionBuf, char * valueBuf) {
	int i, j;
	bool gettingOption = true;

	memset(optionBuf, 0, CONFIG_LINE_MAX);
	memset(valueBuf, 0, CONFIG_LINE_MAX);

	for (i = 0; i < CONFIG_LINE_MAX; ++i) {
		if (lineBuf[i] == '\0') // End of string.
			break;
		if (lineBuf[i] == '\n') // New line.
			break;
		if (lineBuf[i] == '\r')
			break;
		if (lineBuf[i] == '\t')
			return CONFIG_TAB_ERROR;

		// Finished getting option.
		if (gettingOption && lineBuf[i] == '=') {
			j = 0;
			gettingOption = false;
			continue;
		}

		// Get option.
		if (gettingOption) {
			optionBuf[j] = lineBuf[i];
			++j;
		} else { // Get value.
			valueBuf[j] = lineBuf[i];
			++j;
		}
	}

	// Didnt get value.
	if (gettingOption)
		return CONFIG_MISSING_VALUE;
	else if (j == 0)
		return CONFIG_MISSING_VALUE;

	// Strip white space.
	stripWhiteSpace(optionBuf, CONFIG_LINE_MAX);
	stripWhiteSpace(valueBuf, CONFIG_LINE_MAX);

	// White space error.
	if (characterCount(optionBuf, CONFIG_LINE_MAX, ' ') != 0)
		return CONFIG_WHITE_SPACE_ERROR;

	return CONFIG_SUCCESS;
}

ConfigErrors dumpConfig(const char * filePath, const ConfigLine * configLines, size_t configLinesSize) {
	int i;
	ConfigErrors res = CONFIG_SUCCESS;
	FILE * fp = NULL;

	char lineBuf[CONFIG_LINE_MAX];

	// Open file.
	fp = fopen(filePath, "w");

	if (fp == NULL) {
		TraceLog(LOG_ERROR, "Error opening %s: %s ", filePath, strerror(errno));
		res = CONFIG_ERROR;
		goto cleanMem;
	}

	// Writing.
	for (i = 0; i < configLinesSize; ++i) {
		createConfigLine(lineBuf, configLines[i]);
		fputs(lineBuf, fp);
		fputc('\n', fp);
	}

cleanMem:
	if (fp != NULL)
		fclose(fp);

	return res;
}

ConfigErrors loadConfig(const char * filePath, ConfigLine * configLines, size_t configLinesSize) {
	int i;
	ConfigErrors res = CONFIG_SUCCESS;
	FILE * fp = NULL;

	char lineBuf[CONFIG_LINE_MAX];

	// Open file.
	fp = fopen(filePath, "r");

	if (fp == NULL) {
		TraceLog(LOG_ERROR, "Error opening %s: %s", filePath, strerror(errno));
		res = CONFIG_ERROR;
		goto cleanMem;
	}

	while (fgets(lineBuf, CONFIG_LINE_MAX, fp) != NULL) {
		printf("%s", lineBuf);
	}

cleanMem:
	if (fp != NULL)
		fclose(fp);

	return CONFIG_SUCCESS;
}
