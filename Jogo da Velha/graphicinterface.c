#include <stdio.h>
#include <stdlib.h>
#include "graphicinterface.h"
#include "globalvars.h"

extern int** mgame;
extern char* playerone;
extern char* playertwo;

void printGame() {
    system("cls");
    printf("\n\n\n\n\n");
    printf("                                %s vs %s ", playerone, playertwo);
    printf("\n\n\n\n\n");
    printf("                                %d | %d | %d \n", mgame[0][0], mgame[0][1], mgame[0][2]);
    printf("                               ---|---|---\n");
    printf("                                %d | %d | %d \n", mgame[1][0], mgame[1][1], mgame[1][2]);
    printf("                               ---|---|---\n");
    printf("                                %d | %d | %d \n", mgame[2][0], mgame[2][1], mgame[2][2]);
    printf("\n");
}
