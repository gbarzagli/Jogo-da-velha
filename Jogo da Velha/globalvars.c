/*
    Esse arquivo serve para guardar todas as variбveis usadas por mais de um arquivo C.
*/

#include <stdio.h>
#include <stdlib.h>
#include "globalvars.h"

// Matriz para exibir o jogo.
int** mgame;

// Vetor para guardar as jogadas do jogador 1
int* pone;

// Vetor para guardar as jogadas do jogador 2 ou do computador
int* ptwo;

// Variбvel para controlar de quem й a vez
int turn;

// Essa variбvel personalizada guardarб os valores para verificar quem ganhou.
struct possibilities* vectorp;

struct multiplayerResult mresult;

struct singleplayerResult sresult;

// Para guardar o nome do jogador um
char* playerone;

// Para guardar o nome do jogador dois
char* playertwo;


// Inicializa as variбveis
void buildVars() {
    // malloc armazena um tanto de memуria para a variбvel.
    mgame = malloc(3 * sizeof(int *));
    int i = 0;
    for(i = 0; i < 3; i++) {
        mgame[i] = malloc(3 * sizeof(int));
    }

    pone = (int *) malloc(5 * sizeof(int));
    ptwo = (int *) malloc(4 * sizeof(int));
    playerone = (char *) malloc(15 * sizeof(char));
    playertwo = (char *) malloc(15 * sizeof(char));
    vectorp = (struct possibilities *) malloc(8 * sizeof(struct possibilities));

    mgame[0][0] = 0;
    mgame[0][1] = 0;
    mgame[0][2] = 0;
    mgame[1][0] = 0;
    mgame[1][1] = 0;
    mgame[1][2] = 0;
    mgame[2][0] = 0;
    mgame[2][1] = 0;
    mgame[2][2] = 0;

    vectorp[0].v1 = 55; // 7
    vectorp[0].v2 = 56; // 8
    vectorp[0].v3 = 57; // 9
    vectorp[1].v1 = 52; // 4
    vectorp[1].v2 = 53; // 5
    vectorp[1].v3 = 54; // 6
    vectorp[2].v1 = 49; // 1
    vectorp[2].v2 = 50; // 2
    vectorp[2].v3 = 51; // 3
    vectorp[3].v1 = 55;
    vectorp[3].v2 = 52;
    vectorp[3].v3 = 49;
    vectorp[4].v1 = 56;
    vectorp[4].v2 = 53;
    vectorp[4].v3 = 50;
    vectorp[5].v1 = 57;
    vectorp[5].v2 = 54;
    vectorp[5].v3 = 51;
    vectorp[6].v1 = 55;
    vectorp[6].v2 = 53;
    vectorp[6].v3 = 51;
    vectorp[7].v1 = 57;
    vectorp[7].v2 = 53;
    vectorp[7].v3 = 49;

    turn = 1;
}
