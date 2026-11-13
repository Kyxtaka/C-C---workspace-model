#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "list-test.h"

int main() {
    // printf("Hello World\n");
    // struct List* list = List_new();
    // struct Node* node1 = malloc(sizeof(struct Node));
    // struct Node* node2 = malloc(sizeof(struct Node));
    // node1->next = node2;
    // node1->prev = NULL;

    // char *nodeValue1 = malloc(sizeof(char));
    // *nodeValue1 = 'a';
    // node1->value = nodeValue1;
    // printf("test print node1: %d \n", *(node1->value));

    // node2->next=NULL;
    // node2->prev=node1;

    // char *nodeValue2 = malloc(sizeof(char));
    // *nodeValue2 = 'F';
    // node2->value = nodeValue2;
    // printf("test print node2: %d \n", *(node2->value));


    // list->head=node1;
    // list->tail=node2;
    // list->size=2;
    // printf("print node1: ");
    // printNode(node1);
    // printf("\nprint node2: ");
    // printNode(node2);
    // printf("\nprintList: ");
    // List_print(list);
    // printf("\n");
    testPrintNode();
    testPrintList();
    testListClear();
    return EXIT_SUCCESS;
}