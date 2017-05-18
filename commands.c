#include "commands.h"

/**
 * Note this file is to contain console output,
 * meaning printf's are expected to be seen in this file.
 */

AddressBookList * commandLoad(char * fileName)
{
    /**
     * Loads the given file and returns a new AddressBookList.
     * 
     * If the file doesn't exist or corruption is found in the file
     * then NULL is returned.
     */
    AddressBookList * list;
    AddressBookNode * node;
    char ** buffer = NULL;
    char ** tokens = NULL;
    char line[MAX_LINE_LENGTH];
    FILE * fp;
    int lineCount = 0;
    int i = 0;
    int x;
    long id;
    char *ptr;
/*    char* name;*/

    list = createAddressBookList();

    printf("opening file: %s\n", fileName);
    fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        printf("file does not exist or cannot be read, aborting load.\n");
        return NULL;
    }
    printf("loading the file...\n");
    while (fgets(line, sizeof(line), fp)) 
    {
        if(validateLine(line))
        {
            if(line[0] != '#')
            {
                buffer = realloc(buffer, (i+1) * sizeof(char *));
                buffer[i] = malloc(MAX_LINE_LENGTH);
                strcpy(buffer[i], line);
                i++;
                lineCount++;
            }
        }
        else
        {
            for(x = 0; x < lineCount; x++)
            {
                free(buffer[i]);
            } 
            free(buffer);
            free(list);
            printf("corrupt data, read discarded\n");
            return NULL;
        }
    }
    fclose(fp);

    for(i = 0; i < lineCount; i++)
    {
        tokens = tokenize(buffer[i]);
/*        printf("%s\n", tokens[0]);*/
        if(tokens[0] == NULL || tokens[1] == NULL)
        {
            freeAddressBookList(list);
            printf("corrupt data, read discarded 2\n");
            return NULL;
        }
        /*id = convertInputToInt(tokens[0]);*/
/*        name = tokens[1];*/

        /*printf("%s\n%s\n%s\n", tokens[0], tokens[1], tokens[2]);*/
        id = strtol(tokens[0], &ptr, 10);
        node = createAddressBookNode(id, tokens[1]);
        insertNode(list, node);
        if(tokens[2] != NULL) 
        {
            addTelephone(node->array, tokens[2]);
        }
        free(tokens);
        free(buffer[i]);
    }
    free(buffer);
    printf("%d phone book entries have been loaded from the file\n", lineCount);
    return list;
}

Boolean validateLine(char * line)
{
    if(strlen(line) > MAX_LINE_LENGTH)
        return FALSE;
    return TRUE;
}

Boolean validateTokens(char ** tokens)
{
/*    int id;
    char* name;*/
/*    printf("%s\n%s\n%s\n%s\n", tokens[0], tokens[1], tokens[2], tokens[3]);*/
    if(tokens[0] || tokens[1] == NULL)
    {
        return FALSE;
    }
    return TRUE;
}

void commandUnload(AddressBookList * list)
{ 
    if(list != NULL)
    {
/*    printf("%p\n", &list);*/
/*    printf("list size: %d\n",list->size);*/
        if(list->size == 0)
        {
            printf("\nNo list to unload.");
            freeAddressBookList(list);
        }
        else
        {
            freeAddressBookList(list);
        printf("\nThe list is unloaded.");
        }
/*    printf("%p\n", &list);*/
    }
    else
    {
        printf("\nNo list to unload.");
    }
}

int getLongestName(AddressBookList * list) {
    AddressBookNode * node = list->head;
    int length = 0;

    while(node != NULL) 
    {
        if(strlen(node->name) > length)
        {
        length = strlen(node->name);
        }
        node = node->nextNode;
    }
    return length;
}

#define POSLEN 3
#define SERIALLEN 6
#define TELEPHONELEN 10
#define SPACINGLEN 16
#define IDLEN 4

void printCharLine(char c, int n) {
    char* line = charLine(c, n);
    printf("%s\n", line);
    free(line);
}

char* charLine(char c, int n) {
    char* line;
    line = malloc(sizeof(c) * (n+1));
    memset(line, (int)c, sizeof(char) * (n+1));
    line[n] = '\0';
    return line;
}

void commandDisplay(AddressBookList * list)
{ 
    int serial = 0;
    /*int i;*/
    int nameLen;
    int headerLen;
    char * phones = NULL;
    char * posStr = "";
    AddressBookNode * node;
    if(list == NULL)
    {
        printf("no list to print");
        return;
    }
    if(list->size == 0)
    {
        printf("no list to print");
        return;
    }
    node = list->head;
    nameLen = getLongestName(list);
    headerLen = nameLen+POSLEN+SERIALLEN+IDLEN+TELEPHONELEN+SPACINGLEN;
    printCharLine('-', headerLen);
    printf("| Pos | Serial | ID   | %-*s | Telephone  |\n", nameLen, "Name");
    printCharLine('-', headerLen);

    if(node == NULL) {
        /* print empty line */
        printf("| %*s |\n", headerLen - 4, "");
    } 
    else 
    {
        while(node != NULL) 
        {
            serial++;
            if(node == list->current)
                posStr = "CUR";
            else
                posStr = "";
/*            i=0;
            while(node->array->telephones[i] != NULL)
            {
                phones = realloc(phones, (sizeof(char*) * (i + 1)));
                strcat(phones, node->array->telephones[i]);
                i++;
            }*/
            printf("| %-*s | %-*d | %-*d | %-*s | %s\n",
                    POSLEN, posStr,
                    SERIALLEN, serial,
                    IDLEN, node->id,
                    nameLen, node->name,
                    phones);
/*            free(phones);*/
            node = node->nextNode;
        }
    }
}

void commandForward(AddressBookList * list, int moves)
{ }

void commandBackward(AddressBookList * list, int moves)
{ }

void commandInsert(AddressBookList * list, int id, char * name, char * telephone)
{ }

void commandAdd(AddressBookList * list, char * telephone)
{ }

void commandFind(AddressBookList * list, char * name)
{ }

void commandDelete(AddressBookList * list)
{ }

void commandRemove(AddressBookList * list, char * telephone)
{ }

void commandSort(
    AddressBookList * list,
    int sort(const void * node, const void * otherNode))
{
    /* Sort the nodes within list in ascending order using the
     * provided sort function to compare nodes.
     */
}

int compareName(const void * node, const void * otherNode)
{
    /* Compare node name with otherNode name.
     * 
     * return < 0 when node name is smaller than otherNode name.
     * return 0 when the names are equal.
     * return > 0 when node name is bigger than otherNode name.
     */
    return 0;
}

int compareID(const void * node, const void * otherNode)
{
    /* Compare node id with otherNode id.
     * 
     * return < 0 when node id is smaller than otherNode id.
     * return 0 when the ids are equal.
     * return > 0 when node id is bigger than otherNode id.
     */
    return 0;
}

void commandSave(AddressBookList * list, char * fileName)
{ }
