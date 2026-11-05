#include "SimpleLinkedArray.h"

// should return SimpleNode**
SimpleNode* createSimpleNode(int value) {
    SimpleNode* node = malloc(sizeof(SimpleNode));
    if (node == NULL) {
        return NULL; // Handle memory allocation failure
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void createSimpleLinkedArray(SimpleNode* head, SimpleNode* end) {
    head->next = end;
}

void printSimpleNodeValue(SimpleNode* node) {
    if (node == NULL) {
        printf("Node is NULL\n");
        return;
    }
    printf("Node value: %d\n", node->value);
}

void printSimpleLinkedArray(SimpleNode* head) {
    SimpleNode* current = head;
    char* separator = " -> ";
    char* endMarker = " -> NULL\n";
    char* startMarker = "Linked List: ";
    while (current != NULL) {
        if (current == head) {
            printf("%s", startMarker);
        }
        printf("%d", current->value);
        if (current->next != NULL) {
            printf("%s", separator);
        } else {
            printf("%s", endMarker);
        }
        current = current->next;
    }
}

void insertAfterHead(SimpleNode* head, SimpleNode* newNode) {
    if (newNode == NULL) {
        return; // Handle null newNode
    }
    if (newNode == head) {
        return; // Handle case where newNode is the same as head
    }    
    head->next = newNode;
}


void insertBeforeEnd(SimpleNode* head, SimpleNode* end, SimpleNode* newNode) {
    if (newNode == NULL || head == NULL || end == NULL) {
        return;
    }
    while (head->next != end) {
        head = head->next;
    }
    head->next = newNode;
    newNode->next = end;
}

void removeSimpleLinkedNode(SimpleNode* head, SimpleNode* end, SimpleNode* node) {
    if (node == NULL || head == NULL || end == NULL) {
        return; // Handle null node or empty list
    }
    if (head == node || end == node) {
        return; // Handle case where node is the head or end
    }
    SimpleNode* current = head;
    while (current != NULL && current->next != node) {
        current = current->next;
    }
    if (current != NULL) {
        current->next = node->next;
        free(node);
    }
}


