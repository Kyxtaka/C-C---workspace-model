#include <stdio.h>
#include <stdlib.h>
#include "SimpleLinkedArray.h"
// int argc, char **argv
int main() {
    SimpleNode* head = createSimpleNode(0);
    SimpleNode* end = createSimpleNode(1);
    printSimpleNodeValue(head);
    printSimpleNodeValue(end);
    createSimpleLinkedArray(head, end);
    printSimpleNodeValue(head->next);
    printSimpleLinkedArray(head);
    // test fuite memoire
    SimpleNode* newNode = createSimpleNode(2);
    while (1) {
        newNode = createSimpleNode(2);
    }
    return EXIT_SUCCESS;
}