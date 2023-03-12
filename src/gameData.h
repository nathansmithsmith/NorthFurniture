// C headers.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <assert.h>
#include <errno.h>
#include <string.h>
#include <math.h>

// Raylib.
#include <raylib.h>
#include <raymath.h>

#ifndef GAME_DATA_H
#define GAME_DATA_H

typedef enum ErrorCodes {
	CSUCCESS = 0,
	CERROR = -1
} ErrorCodes;

typedef struct GameData GameData;

#endif
