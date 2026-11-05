#ifndef _SIMPLE_CHAINED_ARRAY_H
#define _SIMPLE_CHAINED_ARRAY_H

typedef struct SimpleNode {
    int value;
    struct SimpleNode* next;
} SimpleNode;

void addSimpleNode(SimpleNode** head, int value);
void printSimpleChainArray(SimpleNode* head);
void freeSimpleChainArray(SimpleNode* head);



#endif