#include<stdlib.h>
#include<stdio.h>
#include<time.h>



void myMysteryNumber(void) {

    srand(time(NULL));

    int randNumber = (rand() %100) + 1;
    printf("debug randNumber :%d\n", randNumber);
    int userNumber = -1;

    printf("Find the mystery number, please enter a number between 0 and 100: ");
    scanf("%d", &userNumber);
    while (userNumber != randNumber) {
        if (userNumber < randNumber) {
            printf("The mystery number bigger my bro\n");
        }else {
            printf("The mystery nupmer is smaller mf\n");
        }
        printf("Enter another number between 0 and 100: ");
        scanf("%d", &userNumber);
    }
    printf("Congrats you find the mystery number :%d", randNumber);
}