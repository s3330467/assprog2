#include "addressbook_list.h"

/**
* Note this file is *NOT* to contain console output,
* meaning printf's are *NOT* to be present in this file.
*/

AddressBookList * createAddressBookList()
{
    /**
    * Allocates and initialises a new AddressBookList.
    * malloc or calloc are expected to be used to create the
    * AddressBookList memory.
    * 
    * If memory cannot be allocated for the list NULL is returned.
    * 
    * Note head, tail and current should all be initialised to NULL.
    */
    AddressBookList * list = malloc(sizeof(*list));
    if(list != NULL)
    {
    	list->size = 0;
    	list->head = list->tail = list->current = NULL;
    }
    return list;
}

void freeAddressBookList(AddressBookList * list)
{
    AddressBookNode * node;
    int i;
    int size = list->size;
    if(list == NULL)
    {
        return;
    }
    if(size == 0)
    {
        free(list);
        return;
    }
    list->current = list->head;
    for(i = 0; i <= size; i++)
    {
        node = list->current;
        list->current = node->nextNode;
        freeAddressBookNode(node);
    }
    free(list);
    return;
}

AddressBookNode * createAddressBookNode(int id, char * name)
{
    /**
    * Allocates and initialises a new AddressBookNode.
    * malloc or calloc are expected to be used to create the
    * AddressBookNode memory.
    * 
    * Note the array of the node should also be created and initialised,
    * which should be done with the createAddressBookArray(...) function.
    * 
    * If memory cannot be allocated for the node or array NULL is returned.
    * 
    * Note previousNode and nextNode should both be initialised to NULL.
	    */
    AddressBookNode * node = malloc(sizeof(*node));
    if(node != NULL)
    {
    	node->array = createAddressBookArray();
    	if(node->array == NULL)
    	{
    		freeAddressBookNode(node);
    		return NULL;
    	}
		node->id = id;
    	strcpy(node->name,name);
    	node->previousNode = NULL;
    	node->nextNode = NULL;
    	return node;
    }
    return NULL;
}

void freeAddressBookNode(AddressBookNode * node)
{
    /**
    * Free's the array within the node and the AddressBookNode itself.
    * 
    * Note the freeAddressBookArray(...) function is used to free the array.
    */
/*    printf("node being freed: %d\n",node->id);*/
    freeAddressBookArray(node->array);
    free(node);
    return;
}

Boolean insertNode(AddressBookList * list, AddressBookNode * node)
{
    /**
     * Inserts the node into the list and returns TRUE.
     * 
     * If the list already contains a node with the same id
     * then FALSE is returned and the node is not inserted.
     */
   	if(list->head == NULL)
   	{
   		list->head = list->tail = list->current = node;
   		list->size = 0;
   		return TRUE;
   	}
   	else
   	{
   		list->tail->nextNode = node;
   		node->previousNode = list->tail;
   		list->tail = node;
   		list->size++;
   		return TRUE;
   	}
    return FALSE;
}

Boolean deleteCurrentNode(AddressBookList * list)
{
    /**
     * Delete's and free's the current node in the list and returns TRUE.
     * 
     * Note the freeAddressBookNode(...) function is used to free a node.
     * 
     * If the list has no nodes (i.e., there is no current node)
     * then FALSE is returned.
     */
    AddressBookNode * currentNode = list->current;
    if(list->head == NULL)
    {
        return FALSE;
    }
    list->current->nextNode->previousNode = list->current->previousNode;
    list->current->previousNode->nextNode = list->current->nextNode;
    list->current = currentNode->previousNode;
    free(list->current);
    return TRUE;
}

Boolean forward(AddressBookList * list, int forward)
{
    /**
     * Moves the current node forward in the list by the number provided
     * and returns TRUE.
     * 
     * If the current node cannot be moved forward by that many positions
     * then FALSE is returned and current remains unchanged.
     */
    return FALSE;
}

Boolean backward(AddressBookList * list, int backward)
{
    /**
    * Moves the current node backward in the list by the number provided
    * and returns TRUE.
    * 
    * If the current node cannot be moved backward by that many positions
    * then FALSE is returned and current remains unchanged.
    */

    return FALSE;
}

AddressBookNode * findByID(AddressBookList * list, int id)
{
    /**
     * Returns the node that matches the id provided.
     * 
     * If no node with a matching id exists then NULL is returned.
     */

    return NULL;
}

AddressBookNode * findByName(AddressBookList * list, char * name)
{
    /**
    * Sets current to the first node that matches the name provided
    * and returns this node.
    * 
    * If no node with a matching name exists then NULL is returned
    * and current remains unchanged.
    */

    return NULL;
}
