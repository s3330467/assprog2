#include "addressbook_array.h"

/**
* Note this file is NOT to contain console output,
* meaning printf's are NOT to be present in this file.
*/

AddressBookArray * createAddressBookArray()
{
    /**
     * Allocates and initialises a new AddressBookArray.
     * malloc or calloc are expected to be used to create the
     * AddressBookArray memory.
     * 
     * If memory cannot be allocated for the array NULL is returned.
     * 
     * Note telephones should be initialised to NULL.
     */
    AddressBookArray * array = malloc(sizeof(*array));
    if(array != NULL)
    {
        array->size = 0;
        array->telephones = NULL;
        return array;
    }
    return NULL;
}

void freeAddressBookArray(AddressBookArray * array)
{
    /**
     * Free's all telephones within the array and the AddressBookArray itself.
     */
    /*int i;
    int size = array->size;
    printf("array size: %d\n", array->size);
    for(i = 0; i < size; i++)
    {
        printf("freeing telephone #: %s",array->telephones[i]);
        free(array->telephones[i]);
    }
    free(array);
    return;*/
    int i;

    for(i = 0; i < array->size; i++) {
        free(array->telephones[i]);
    }
    free(array->telephones);
    free(array);
}

Boolean addTelephone(AddressBookArray * array, char * telephone)
{
    /**
     * Adds the provided telephone to the telephones array and returns TRUE.
     * 
     * If the telephone already exists or memory cannot be allocated
     * then FALSE is returned.
     * 
     * malloc or calloc are expected to be used to create memory for
     * the new telephone - do not forget to copy the provided telephone over.
     * Here is some sample code:
     * 
     * char * newTelephone = malloc(TELEPHONE_LENGTH);
     * strcpy(newTelephone, telephone);
     * 
     * After this it is expected you use *realloc* to make the telephones
     * array grow by 1. Here is some sample code:
     * 
     * array->telephones = realloc(array->telephones,
     *                     sizeof(*array->telephones) * (array->size + 1));
     * 
     * Once the array has grown by 1 you can store the new telephone in it
     * at the end. Here is some sample code:
     * 
     * array->telephones[array->size] = newTelephone;
     * array->size++;
     */
    char * newTelephone = malloc(TELEPHONE_LENGTH);
/*    if(findTelephone(array, telephone) != NULL)
    {
    	return FALSE;
    }*/

    strcpy(newTelephone, telephone);

    array->telephones = realloc(array->telephones,
        sizeof(*array->telephones) * (array->size + 1));

    array->size++;
    array->telephones[array->size -1] = newTelephone;

    return FALSE;
}

Boolean removeTelephone(AddressBookArray * array, char * telephone)
{
   /**
    * Removes the provided telephone from the telephones array and
    * returns TRUE.
    * 
    * If the telephone does not exist or memory cannot be reallocated
    * then FALSE is returned.
    * 
    * It is expected you use *realloc* to shrink the telephones
    * array by 1. Here is some sample code:
    * 
    * array->telephones = realloc(array->telephones,
    *                     sizeof(*array->telephones) * (array->size - 1));
    * array->size--;
    * 
    * Note for this to work you will first have to ensure the telephone
    * to remove is at the end of the array.
    * 
    * Also note you will need to free(...) the removed telephone as well.
    * 
    * If you are removing the LAST telephone in the array then you will need to
    * free telephones itself and set it to NULL. Here is some sample code:
    * 
    * free(array->telephones);
    * array->telephones = NULL;
    */

    return FALSE;
}

char * findTelephone(AddressBookArray * array, char * telephone)
{
    /**
     * Returns the telephone that matches the telephone provided.
     * 
     * If no telephone exists then NULL is returned.
     */

    return NULL;
}
