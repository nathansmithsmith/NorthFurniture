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

	for (i = n - 1; i > 0; --i) {
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
