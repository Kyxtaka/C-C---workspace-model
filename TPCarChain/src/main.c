#include <stdio.h>
#include "char_func.h"

int main() {
    printf("Hello World");
    printf("\n");
    printf("======================================\n");
    // test with "Toto" should return 4
    const char *testString = "Toto";
    printf("Length of '%s' is %zu", testString, stringLength(testString));

    printf("\n");
    printf("======================================\n");

    // compare Two char string in lexicographical order
    const char *str1 = "Hellp";
    const char *str2 = "Hello";
    int result = stringCompare(str1, str2);
    printf("Comparison of '%s' and '%s' is %d", str1, str2, result);
    return 0;
}