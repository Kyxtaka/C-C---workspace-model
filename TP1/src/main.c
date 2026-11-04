#include<stdio.h>
#include<stdlib.h>
#include "exo1.h"
#include "nbmystere.h"

int main() {
    printf("Hello World");
    int test = addition(5, 9);
    printf("test compilation of binary with addition %d + %d: %d\n", 5, 9, test);
    printf("======================================\n");
    myMysteryNumber();
    return EXIT_SUCCESS;
}