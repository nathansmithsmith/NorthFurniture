#include "util.h"
#include <string.h>

void stripLeftWhiteSpace(char * buf, size_t n) {
	int i, j;
	char bufCopy[n];
	bool gotToCharacter = false;

	memcpy(bufCopy, buf, n);
	memset(buf, 0, n);

	j = 0;

	for (i = 0; i < n; ++i) {
		if (bufCopy[i] == '\0') // End of string.
			break;

		// Check if past the white space.
		if (!gotToCharacter)
			gotToCharacter = bufCopy[i] != ' ';

		if (gotToCharacter) {
			buf[j] = bufCopy[i];
			++j;
		}
	}
}

void stripRightWhiteSpace(char * buf, size_t n) {
	int i;
	bool gotToCharacter = false;

	for (i = n - 1; i >= 0; --i) {
		if (buf[i] == '\0')
			continue;

		// Check if past the white space.
		if (!gotToCharacter)
			gotToCharacter = buf[i] != ' ';

		if (!gotToCharacter)
			buf[i] = '\0';
	}
}

void stripWhiteSpace(char * buf, size_t n) {
	stripLeftWhiteSpace(buf, n);
	stripRightWhiteSpace(buf, n);
}

int characterCount(const char * buf, size_t n, char c) {
	int i;
	int count = 0;

	for (i = 0; i < n; ++i) {
		if (buf[i] == '\0')
			break;
		if (buf[i] == c)
			++count;
	}

	return count;
}

ErrorCodes strToInt(const char * str, size_t n, int * intValue, bool forceHex) {
	int i;
	int cvalue;
	int valueMuliplier = 1;
	int mulpileBy = 10; // 10 for decimal and 16 for hex.
	int resValue = 0;
	int neg = 1; // -1 for negative and 1 for whole.
	size_t strLen; // String length.
	int endAt = 0; // Where loop should end.
	bool looksLikeHex = false;
	
	bool hexMode = false;

	if (str == NULL || intValue == NULL || n <= 0)
		return CERROR;

	// Get string length
	strLen = strnlen(str, n);

	if (strLen <= 0)
		return CERROR;

	// Is negative.
	if (str[0] == '-') {
		neg = -1;
		endAt = 1; // If negative 0 item in 'str' is skipped.
	}

	// Hex mode.
	if (n >= 2)
		if (str[0] == '0' && str[1] == 'x')
			looksLikeHex = true;

	if (looksLikeHex || forceHex) {
		hexMode = true;
		neg = 1;
		endAt = 0;
		mulpileBy = 16;
	}

	// Do the math stuff hehehe.
	for (i = strLen - 1; i >= endAt; i--) {
		cvalue = hexMode ? hexCharToInt(str[i]) : charToInt(str[i]);

		// 0x in hex string.
		if (hexMode && str[i] == 'x')
			break;

		// Character not a number.
		if (cvalue == -1)
			return CERROR;

		// Do the same math that is down below.
		resValue += cvalue * valueMuliplier;
		valueMuliplier *= mulpileBy;
	}

	/*
	 * "436"
	 * resValue = (6 * 1) + (3 * 10) + (4 * 100)
	*/

	*intValue = (resValue * neg);
	return CSUCCESS;
}

int charToInt(char c) {
	int cvalue = (int)c;

	// Not a number.
	// 48 to 57 is 0 to 9 in ascii.
	if (cvalue < 48 || cvalue > 57)
		return -1;

	return cvalue - 48; // 48 is the value of zero in ascii.
}

int hexCharToInt(char c) {
	int cvalue;
	cvalue = charToInt(c); // Between 0 and 9

	if (cvalue != -1)
		return cvalue;

	cvalue = tolower(c);

	// Not a hex number.
	// 97 to 102 is 'a' to 'f' in ascii.
	if (cvalue < 97 || cvalue > 102)
		return -1;

	return cvalue - 87; // Weird magic number made for your pain.
}
