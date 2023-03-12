#include "gameData.h"

#ifndef UTIL_H
#define UTIL_H

#define SET_BIT(b, n) (b | (0x1 << n))
#define CLEAR_BIT(b, n) (b & ~(0x1 << n))
#define IS_BIT_SET(b, n) ((b >> n) & 0x1)
#define TOGGLE_BIT(b, n) (b ^ (0x1 << n))

// Removes all white spaces on the left.
void stripLeftWhiteSpace(char * buf, size_t n);

// Removes all white spaces on the right.
void stripRightWhiteSpace(char * buf, size_t n);

// Removes white space on both sides.
void stripWhiteSpace(char * buf, size_t n);

// How many 'c' are in 'buf'.
int characterCount(const char * buf, size_t n, char c);

// String to int stuff.
ErrorCodes strToInt(const char * str, size_t n, int * intValue, bool forceHex);
int charToInt(char c); // -1 on error.
int hexCharToInt(char c);

#endif
