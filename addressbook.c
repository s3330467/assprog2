#include "addressbook.h"

/**
* This file is to contain the main menu loop and thus it will have console
* output, meaning printf's are expected to be seen in this file.
* 
* After the user enters a command, then the corresponding function is to be
* called from commands.c, e.g., "forward" corresponds to "commandForward(...)".
*/

void menu()
{
	AddressBookList * list = NULL;
	int tokCount;
	char userInput[MAX_INPUT_LENGTH];
	char * commands[MAX_INPUT_TOKENS];
	showStudentInformation();
	for(;;)
	{
		printf("\nEnter your command: ");
		if(readInput(userInput, MAX_INPUT_LENGTH) == TRUE)
		{
			lowerCaseStr(userInput);
			tokenizeInput(userInput, &tokCount, commands);

			if(strcmp(COMMAND_LOAD,commands[0]) == 0)
			{	
				if(commands[1] != NULL)
				{
					if(list != NULL)
					{
						commandUnload(list);
					}
					list = commandLoad(commands[1]);
				}
			}
			else if(strcmp(COMMAND_DISPLAY, commands[0]) == 0)
			{

/*				printf("list is: %p\n", &list);*/
				commandDisplay(list);

			}
			else if(strcmp(COMMAND_UNLOAD, commands[0]) == 0)
			{
				commandUnload(list);
				list = createAddressBookList();
			}
			else if(strcmp(COMMAND_QUIT, commands[0]) == 0)
			{
				if(list != NULL)
				{
/*					printf("attempting quit unload\n");*/
					commandUnload(list);
				}
				return;
			}
			else
			{
				printf("invalid input\n");
			}
		}
	}
	return;
}

int checkCommands(char * commands[], AddressBookList * list)
{	
	if(strcmp(COMMAND_LOAD,commands[0]) == 0)
	{	
		if(commands[1] != NULL)
		{
			list = commandLoad(commands[1]);
			return TRUE;
		}
	}
	else if(strcmp(COMMAND_DISPLAY, commands[0]) == 0)
	{
		commandDisplay(list);
		return TRUE;
	}
	else if(strcmp(COMMAND_UNLOAD, commands[0]) == 0)
	{
		commandUnload(list);
		return TRUE;
	}
	else if(strcmp(COMMAND_QUIT, commands[0]) == 0)
	{
		return 3;
	}
	printf("invalid input\n");
	return FALSE;
}

void showStudentInformation()
{
	printf("\n---------------------------------------\n");
	printf("Name: %s\n", STUDENT_NAME);
	printf("No: %s\n", STUDENT_ID);
	printf("Email: %s\n", STUDENT_EMAIL);
	printf("---------------------------------------\n");
}

int main(int argc, char ** argv)
{
	menu();
	printf("\nGoodbye.\n");
	return EXIT_SUCCESS;
}
