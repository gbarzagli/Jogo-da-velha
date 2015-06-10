#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include "globalvars.h"

extern struct multiplayerResult mresult;
extern struct singleplayerResult sresult;
FILE *franking;
char* result;
char c;

// Mostra quem venceu de quem no multiplayer
void showMultiplayerRanking() {
    franking = fopen("Multiplayer.txt","r");
    if(franking == NULL) {
        printf("Houve um erro ao abrir o arquivo.\n");
    } else {
        while(true) {
            fscanf(franking,"%c", &c);
            if(feof(franking)) {
                break;
            }
            printf("%c", c);
        }
        printf("\n");
        fclose(franking);
    }
    system("pause");
}

//  Exibe quem ganhou de qual bot em qual dificuldade.
void showSingleplayerRanking() {
    franking = fopen("Singleplayer.txt","r");
    if(franking == NULL) {
        printf("Houve um erro ao abrir o arquivo.\n");
    } else {
        while(true) {
            fscanf(franking,"%c", &c);
            if(feof(franking)) {
                break;
            }
            printf("%c\a", c);
        }
        printf("\n");
        fclose(franking);
    }
    system("pause");
}


void addMultiplayerRanking(struct multiplayerResult result) {
    franking = fopen("Multiplayer.txt","a");
    char str[111]="\n";
    char* winner = result.winner;
    char* looser = result.looser;
    strcat(str, winner);
    strcat(str, " venceu de ");
    strcat(str, looser);
    fprintf(franking, "%s", str);
    fclose(franking);
}

void addSingleplayerRanking(struct singleplayerResult result) {
    franking = fopen("Singleplayer.txt","a");
    char str[111]="\n";
    char* player = result.player;
    switch(result.result) {
        case 0:
            strcat(str, " perdeu do bot ");
        break;
        case 1:
            strcat(str, " venceu do bot ");
        break;
        default:
            strcat(str, " empatou com o bot ");
    }
    if(result.difficult) {
        strcat(str, " impossivel");
    } else {
        strcat(str, " possivel");
    }
    fprintf(franking, "%s", str);
    fclose(franking);
}
