#include "list-test.h"

void testPrintNode(){
    struct Node* node1 = malloc(sizeof(struct Node));
    node1->next = NULL;
    node1->prev = NULL;

    char *nodeValue1 = "a";
    node1->value = nodeValue1;

    printf("==============================================\n");
    printf("test: printNode()\n");
    printf("function output: ");
    printNode(node1);
    printf("\n");
    printf("expected result: -(%s)-\n", (node1->value));
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
    char *node1Val = "a";
    node1->value = node1Val;

    node2->prev = node1;
    node2->next = NULL;
    char *node2Val = "z";
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
    printf("expected result: -(a)--(z)-\n");
    printf("==============================================\n");
}

void testListClear() {
    struct List *list = malloc(sizeof(struct List));
    struct Node *node1 = malloc(sizeof(struct Node));
    struct Node *node2 = malloc(sizeof(struct Node));

    list->size = 0;

    node1->prev = NULL;
    node1->next = node2;
    char *node1Val = "a";
    node1->value = node1Val;

    node2->prev = node1;
    node2->next = NULL;
    char *node2Val = "z";
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
    printf("expected result: -(a)--(z)-\n");
    printf("----------------------------------------------\n");
    List_clear(list);
    printf("test List_Clear()\n");
    printf("After Clear\n");
    printf("function output: ");
    List_print(list);
    printf("expected result: -(NULL)--(NULL)-\n");
    printf("==============================================\n");

}


void testNodeNew() {
    struct Node *node1 = Node_new("");
    struct Node *node2 = Node_new("");    
    printf("==============================================\n");
    printf("test Node_new()\n");
    printNode(node1);
    printf("\n");
    printNode(node2);
    printf("\n==============================================\n");
}

void testListNew() {
    printf("==============================================\n");
    printf("test List_new()\n");
    struct List *list = List_new();
    List_print(list);
    printf("\n==============================================\n");
}

// void testNewNodeVal() {
//     printf("==============================================\n");
//     printf("test NewNodeValue\n");
//     char *nodeVal1 = NewNodeValue("t");
//     char *nodeVal2 = NewNodeValue("1");
//     printf("%s\n", nodeVal1);
//     printf("%s\n", nodeVal2);
//     printf("==============================================\n");
// }

void testDeleteList() {
    struct List *list = List_new();
    struct Node *node1 = Node_new("a");
    struct Node *node2 = Node_new("b");
    struct Node *node3 = Node_new("c");
    struct Node *node4 = Node_new("d");
    struct Node *node5 = Node_new("e");
    struct Node *node6 = Node_new("f");
    struct Node *node7 = Node_new("g");
    struct Node *node8 = Node_new("h");
    list->head = node1;

    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;
    node5->prev = node4;
    node6->prev = node5;
    node7->prev = node6;
    node8->prev = node7;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;

    list->tail = node8;
    list->size = 8;
    printf("==============================================\n");
    printf("test testDeleteList()\n");
    printf("before delete\n");
    List_print(list);
    List_delete(list);
    printf("list deleted\n");
    List_print(list);
    printf("==============================================\n");
}

void testInsertNode() {
    printf("==============================================\n");
    printf("test insertNode()\n");
    printf("implementing insert node....\n");
    printf("==============================================\n");
}