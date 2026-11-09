#include <stdio.h>
#include <stdlib.h>
#include "vigenere.h"

// int main() {
//     printf("Hello World");
//     printf("\n");
//     printf("======================================\n");
//     // test with "Toto" should return 4
//     const char *testString = "Toto";
//     printf("Length of '%s' is %zu", testString, stringLength(testString));

//     printf("\n");
//     printf("======================================\n");

//     // compare Two char string in lexicographical order
//     const char *str1 = "Hellp";
//     const char *str2 = "Hello";
//     int result = stringCompare(str1, str2);
//     printf("Comparison of '%s' and '%s' is %d", str1, str2, result);
//     return 0;
// }

// ’
int main () {
    char message[] = "l\'escargot se promene avec sa maison";
    const char *key = "perdu";

    char vigenereTable1[26][26];
    initVigenereTable3(vigenereTable1);
    printVigenereTable(vigenereTable1);

    encrypt(message, key, vigenereTable1);
    printf("obtained msg: %s \n", message);
    printf("should obtain: A\'IJFUGKFW MT TIRGTRV DPTG JD GPMJRH \n");
    // decrypt_1 (message, key, vigenereTable1);
    // printf("d!ecrypt1: %s \n", message);
    return EXIT_SUCCESS;
}