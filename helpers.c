#include "helpers.h"

void readRestOfLine()
{
	int ch;
	while(ch = getc(stdin), ch != EOF && ch != '\n')
    { } /* Gobble each character. */

    /* Reset the error status of the stream. */
		clearerr(stdin);
}

Boolean readInput(char* inputPointerAddress, int size)
{
	int i;
	fgets(inputPointerAddress, size, stdin);
	for(i = 0; i < size; i++)
	{
		if(inputPointerAddress[i] == '\n')
		{
			break;
		}
	}
	if(inputPointerAddress[i] != '\n')
	{
		inputPointerAddress[0] = 0;
		readRestOfLine();
		return FALSE;
	}
	else if(inputPointerAddress[0] == '\n')
	{
		inputPointerAddress[0] = 0;
		return FALSE;
	}
	return TRUE;
}

int convertInputToInt(char* strInput)
{
	char* end;
	int userChoice;
	userChoice = strtol(strInput, &end, 10);
	return userChoice;
}

char** tokenize(char * strInput)
{
	char ** tokens;
	int tokIndex = 0;

	tokens = malloc(sizeof(*tokens));

	tokens[tokIndex] = strtok(strInput, DELIM);
/*	printf("token index %d:			string: %s\n", tokIndex, tokens[tokIndex]);*/
	while (tokens[tokIndex] != NULL)
	{
		tokIndex++;
		tokens = realloc(tokens, (tokIndex+1) * (sizeof(char*)));
    	tokens[tokIndex] = strtok(NULL, DELIM);
/*    	printf("token index %d:		string: %s\n", tokIndex, tokens[tokIndex]);*/
	}
	return tokens;
}

int tokenizeInput(char * strInput, int * tokCount, char * commands[])
{
	char* token;
	*tokCount = 0;
	token = strtok(strInput, DELIM);
/*	commands[*tokCount] = malloc(MAXINPUTLENGTH);
*/	commands[*tokCount] = token;

	while (token != NULL)
	{
		(*tokCount)++;
		token = strtok(NULL, DELIM);
		if(*tokCount < (MAX_INPUT_TOKENS))
		{
/*			commands[*tokCount] = malloc(MAXINPUTLENGTH);
*/			commands[*tokCount] = token;
		}
	}
	return EXIT_SUCCESS;
}

void lowerCaseStr(char * strInput)
{
	int i;
	for(i = 0; strInput[i]; i++)
	{
		if(isupper( strInput[i]) )
		{
			strInput[i] = tolower(strInput[i]);
		}
	}
}