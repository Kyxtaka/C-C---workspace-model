#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "list-test.h"

int main() {
    testPrintNode();
    testPrintList();
    testListClear();
    testNodeNew();
    testListNew();
    testDeleteList();
    testInsertNode();
    return EXIT_SUCCESS;
}