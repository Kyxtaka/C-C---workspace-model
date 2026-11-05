#ifndef _SIMPLE_LINKED_ARRAY_H
#define _SIMPLE_LINKED_ARRAY_H
#include <stdio.h>
#include <stdlib.h>

typedef struct SimpleNode {
    int value;
    struct SimpleNode* next;
} SimpleNode;

// Core function, create, insert, remove
SimpleNode* createSimpleNode(int value);
void createSimpleLinkedArray(SimpleNode* head, SimpleNode* end);

/// @brief print the value of a simple node
/// @param node SimpleNode* node the node to print
void printSimpleNodeValue(SimpleNode* node);

/// @brief print the values of all nodes in the linked list
/// @param head SimpleNode* head the head of the linked list
void printSimpleLinkedArray(SimpleNode* head);

/// @brief insert a new node at the beginning of the linked list
/// @param head SimpleNode* head the head of the linked list
/// @param newNode SimpleNode* newNode the new node to insert
void insertAfterHead(SimpleNode* head, SimpleNode* newNode);

/// @brief insert a new node at the end of the linked list
/// @param head SimpleNode* head the head of the linked list
/// @param end SimpleNode* end the end of the linked list
/// @param newNode SimpleNode* newNode the new node to insert
void insertBeforeEnd(SimpleNode* head, SimpleNode* end, SimpleNode* newNode);

/// @brief remove a node from the linked list, if the node is the head or the end, it will note be removed, if the node is not in the linked list, it will not be removed
/// @param head SimpleNode* head the head of the linked list
/// @param end SimpleNode* end the end of the linked list
/// @param node SimpleNode* node the node to remove
void removeSimpleLinkedNode(SimpleNode* head, SimpleNode* end, SimpleNode* node);

// print function
/// @brief print the value of a simple node
/// @param node SimpleNode* node the node to print
void printSimpleNodeValue(SimpleNode* node);

// variant of core function
// void insertBeginningValue(SimpleNode** head, int value);


#endif