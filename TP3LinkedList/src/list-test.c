#include "list-test.h"

void testPrintNode(){
    struct Node* node1 = malloc(sizeof(struct Node));
    node1->next = NULL;
    node1->prev = NULL;

    char *nodeValue1 = malloc(2*sizeof(char));
    nodeValue1[0] = 'a';
    nodeValue1[1] = '\0';
    node1->value = nodeValue1;

    printf("==============================================\n");
    printf("test: printNode()\n");
    printf("function output: ");
    printNode(node1);
    printf("\n");
    printf("expected result: -(%d)-\n", *(node1->value));
    printf("==============================================\n");
}

void testPrintList() {
    struct List* list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    struct List *list2 = malloc(sizeof(struct List));
    struct Node *node1 = malloc(sizeof(struct Node));
    struct Node *node2 = malloc(sizeof(struct Node));
    list2->size = 0;

    node1->prev = NULL;
    node1->next = node2;
    char *node1Val = malloc(2*sizeof(char));
    node1Val[0] = 'a';
    node1Val[1] = '\0'; 
    node1->value = node1Val;

    node2->prev = node1;
    node2->next = NULL;
    char *node2Val = malloc(2*sizeof(char));
    node2Val[0] = 'z';
    node2Val[1] = '\0';
    node2->value = node2Val;

    list2->head = node1;
    list->size++;
    list2->tail = node2;
    list->size++;

    printf("==============================================\n");
    printf("test List_print()\n");
    printf("function output: ");
    List_print(list);
    printf("expected result: -(NULL)--(NULL)-\n");
    printf("----------------------------------------------\n");
    printf("test List_print()\n");
    printf("function output: ");
    List_print(list2);
    printf("expected result: -(97)--(122)-\n");
    printf("==============================================\n");
}

void testListClear() {
    struct List *list = malloc(sizeof(struct List));
    struct Node *node1 = malloc(sizeof(struct Node));
    struct Node *node2 = malloc(sizeof(struct Node));

    list->size = 0;

    node1->prev = NULL;
    node1->next = node2;
    char *node1Val = malloc(2*sizeof(char));
    node1Val[0] = 'a';
    node1Val[1] = '\0'; 
    node1->value = node1Val;

    node2->prev = node1;
    node2->next = NULL;
    char *node2Val = malloc(2*sizeof(char));
    node2Val[0] = 'z';
    node2Val[1] = '\0';
    node2->value = node2Val;

    list->head = node1;
    list->size++;
    list->tail = node2;
    list->size++;

    printf("==============================================\n");
    printf("test List_Clear()\n");
    printf("Before clear\n");
    printf("function output: ");
    List_print(list);
    printf("expected result: -(97)--(122)-\n");
    printf("----------------------------------------------\n");
    List_clear(list);
    printf("test List_Clear()\n");
    printf("After Clear\n");
    printf("function output: ");
    List_print(list);
    printf("expected result: -(NULL)--(NULL)-\n");
    printf("==============================================\n");

}

// void testCreateNode() {
//     struct node
// }