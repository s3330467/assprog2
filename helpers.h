#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <assert.h>

typedef enum boolean
{
    FALSE = 0,
    TRUE
} Boolean;
#define MAX_INPUT_LENGTH 50
#define NEW_LINE_SPACE 1
#define NULL_SPACE 1

/**
 * This is used to compensate for the extra character spaces taken up by
 * the '\n' and '\0' when input is read through fgets().
 **/
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

#define EMPTY_STRING ""

#define DELIM ", \n\t\b"

/**
 * This defines the maximum number of tokens needed to type the longest command
 **/
#define MAX_INPUT_TOKENS 4

/**
 * Call this function whenever you detect buffer overflow.
 **/
void readRestOfLine();
char** tokenize(char *);
Boolean readInput(char*, int);
int convertInputToInt(char*);
int tokenizeInput(char *,int *, char **);
void lowerCaseStr(char *);
#endif
