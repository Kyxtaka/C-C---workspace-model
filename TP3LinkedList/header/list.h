# ifndef LIST_HEADER_GUARD
# define LIST_HEADER_GUARD
#include <stdlib.h>
#include <stdio.h>
// a node of a List
struct Node {
    // a pointer to the previous node in the list (*)
    struct Node * prev ;
    // a pointer to the next node in the list (*)
    struct Node * next ;
    // the ( dynamically allocated ) string stored in the node
    char * value ;
};
// a doubly linked list of strings
struct List {
    // the size of the list
    size_t size;
    // a pointer to the first element of the list (*)
    struct Node * head;
    // a pointer to the last element of the list (*)
    struct Node * tail;
};
// (*) NULL if no such node exists




/// @brief Allocate memory for a new linked list
struct List *List_new();

//==============================================

/// @brief Clear the list and free nodes memory
/// @param list List* 
void List_clear(struct List* list);

/// @brief Delete a list and free
/// @param list 
void List_delete(struct List* list);


/// @brief Delete node and free memory
/// @param node 
void freeNode(struct Node* node);

/// @brief print node value
/// @param node 
void printNode(struct Node* node);

/// @brief print the whole list
/// @param list 
void List_print(struct List* list);


void List_insert(struct List *list, struct Node *pos, const char* value);
# endif