#ifndef SIMPLE_CHAINED_ARRAY_H
#define SIMPLE_CHAINED_ARRAY_H

typedef struct SimpleNode {
    int value;
    struct SimpleNode* next;
};

#endif