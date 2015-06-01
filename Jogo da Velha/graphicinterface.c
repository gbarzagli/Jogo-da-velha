#include <stdio.h>
#include <stdlib.h>
#include "graphicinterface.h"
#include "globalvars.h"

extern int** mgame;
extern char* playerone;
extern char* playertwo;

char auxMgame[3][3];

void transformToChar() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            switch(mgame[i][j]) {
                case 1:
                    auxMgame[i][j] = 'X';
                break;
                case 2:
                    auxMgame[i][j] = 'O';
                break;
                default:
                    auxMgame[i][j] = ' ';
                break;
            }
        }
    }
}

void printGame() {
    system("cls");
    transformToChar();
    printf("\n\n\n\n\n");
    printf("                                %s vs %s ", playerone, playertwo);
    printf("\n\n\n\n\n");
    printf("                                %c | %c | %c \n", auxMgame[0][0], auxMgame[0][1], auxMgame[0][2]);
    printf("                               ---|---|---\n");
    printf("                                %c | %c | %c \n", auxMgame[1][0], auxMgame[1][1], auxMgame[1][2]);
    printf("                               ---|---|---\n");
    printf("                                %c | %c | %c \n", auxMgame[2][0], auxMgame[2][1], auxMgame[2][2]);
    printf("\n");
}
