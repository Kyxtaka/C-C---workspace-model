#ifndef _VIGENERE_H_
#define _VIGENERE_H_
#include <stdlib.h>
#include <stdio.h>

// alocation automatique
// void initVigenereTable1(char vigenereTable[26][26]);
// void initVigenereTable2(char (*vigenereTable)[26]);
void initVigenereTable3(char vigenereTable[][26]);
void printVigenereTable(char vigenereTable[][26]);

void encrypt(char message[],const char* key, char vigenereTable[][26]);

#endif