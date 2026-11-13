#include "list.h"

struct List *List_new() {
    struct List* list = malloc(sizeof(struct List));
    if (list) {
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
    return list;
};

void freeNode(struct Node* node) {
    if (!node) {
        return;
    }
    node->prev = NULL;
    node->next = NULL;
    char *value = node->value;
    if (value != NULL) {
        node->value = NULL;
        free(value);
    }
    free(node);
}

void List_clear(struct List* list) {
    if (!list) {
        return;
    }
    struct Node* currentNode = list->head;
    struct Node* nodeToDelete = NULL;
    while (currentNode->next != list->tail) {
        nodeToDelete = currentNode->next;
        struct Node* newNextNode = nodeToDelete->next;
        if (nodeToDelete) {
            currentNode->next = newNextNode;
            newNextNode->prev = currentNode;
            freeNode(nodeToDelete);
        }
        currentNode = currentNode->next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void List_delete(struct List* list) {
    if (!list) {
        return;
    }
    List_clear(list);
    struct Node* head = list->head;
    struct Node* tail = list->tail;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    freeNode(head);
    freeNode(tail);
    free(list);
}


void printNode(struct Node* node) {
    if (!node) {
        return;
    }
    printf("-(%d)-", *(node->value));
}

void List_print(struct List* list) {
    if (!list) {
        return;
    }
    struct Node* currentNode = list->head; 
    if (list->head == NULL) {
        printf("-(NULL)-");
    }
    while(currentNode) {
        printNode(currentNode);
        currentNode = currentNode->next;
    }
    if(list->tail == NULL) {
        printf("-(NULL)-");
    }
    printf(" | size: %llu", list->size);
    printf("\n");    
}
