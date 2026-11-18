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

struct Node *Node_new(char *value) {
    struct Node *node = malloc(sizeof(struct Node));
    if (node) {
        node->next = NULL;
        node->prev = NULL;
        node->value = NULL;
    }
    if (*(value) != (char) *"") {
        // char *nodeVal = NewNodeValue(value);
        char *nodeVal = strdup(value);
        node->value = nodeVal;
    }
    return node;
}

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
        printf("null pointer can't delete list\n");
        return;
    }
    printf("deleting list \n");
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
        printf("-[NULL PTR]-");
        return;
    }
    if (node->value != NULL) {
        printf("-(%s)-", (node->value));
    }else {
        printf("-(Empty Value)-");
    }
    return;
}

void List_print(struct List* list) {
    if (!list) {
        printf("NULL PTR\n");
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


int List_insert(struct List *list, struct Node *pos, const char *value) {
    
}