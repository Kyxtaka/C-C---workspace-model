#include "vigenere.h"
#include "char_func.h"

// void initVigenereTable1(char vigenereTable[26][26]) {
//     // char vigenereTable[26][26];
//     for(int i = 0; i < 26; i++) {
//         char lettre = (char)("a"+i);
//         for (int j = 0; j < 26; j++) {
//             vigenereTable[i][j] = lettre;
//             ++lettre;
//             if (lettre > (char)"z") {
//                 lettre = (char)"a";
//             }
//         }
//     }
// }

// void initVigenereTable2(char (*vigenereTable)[26]) {
//     // char vigenereTable[26][26];
//     for(int i = 0; i < 26; i++) {
//         char lettre = (char)("a"+i);
//         for (int j = 0; j < 26; j++) {
//             vigenereTable[i][j] = lettre;
//             ++lettre;
//             if (lettre > "z") {
//                 lettre = "a";
//             }
//         }
//     }
// }

void initVigenereTable3(char vigenereTable[][26]) {
    for(int i = 0; i < 26; i++) {
        char lettre = (char)('a'+i);
        for (int j = 0; j < 26; j++) {
            vigenereTable[i][j] = lettre;
            ++lettre;
            if (lettre > 'z') {
                lettre = 'a';
            }
        }
    }
}

void printVigenereTable(char vigenereTable[][26]) {
    for (int i = 0; i<26; i++) {
        for (int j = 0; j<26; j++) {
            printf("%c ", vigenereTable[i][j]);
        }
        printf("\n");
    }
}


void encrypt(char message[], const char *key, char vigenereTable[][26]) {
    int index = 0;
    int keyIndex = 0;
    int keyLenght = stringLength(key);
    printf("encrypting: %s, with key: %s\n", message, key);
    printf("keyLenght: %d\n", keyLenght);
    while (message[index]) {
        if (message[index] >= 'a' && message[index] <= 'z') {
            message[index] = vigenereTable[key[keyIndex] - 'a'][message[index] - 'a'];
            index++;
            keyIndex++;
            if (keyIndex >= keyLenght) {
                keyIndex = 0;
            }
        }else {
            index++;
        }
    }
}