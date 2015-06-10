#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "globalvars.h"
#include "graphicinterface.h"
#include "ranking.h"

extern int** mgame;
extern int* pone;
extern int* ptwo;
extern struct possibilities *vectorp;
extern char* playerone;
extern char* playertwo;
int turn, cOne = 0, cTwo = 0;



void fillGame(int input) {
  switch(input) {
    case 55: // 7
      if (mgame[0][0] == 0) {
        if (turn == 1) {
          //caso jogador um, preenche seu vetor com a posicao da jogada
          pone[cOne] = 55;
          //preenche matriz do jogo com a vez da jogada
          mgame[0][0] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 55;
          mgame[0][0] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
        printf("Jogada ja realizada!!\n");
      }
      break;
    case 56: // 8
      if (mgame[0][1] == 0) {
        if (turn == 1) {
          pone[cOne] = 56;
          mgame[0][1] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 56;
          mgame[0][1] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
       printf("Jogada ja realizada!!\n");
      }
      break;
    case 57: // 9
      if (mgame[0][2] == 0) {
        if (turn == 1) {
          pone[cOne] = 57;
          mgame[0][2] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 57;
          mgame[0][2] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
       printf("Jogada ja realizada!!\n");
      }
      break;
    case 52: // 4
      if (mgame[1][0] == 0) {
        if (turn == 1) {
          pone[cOne] = 52;
          mgame[1][0] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 52;
          mgame[1][0] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
       printf("Jogada ja realizada!!\n");
      }
      break;
    case 53: // 5
      if (mgame[1][1] == 0) {
        if (turn == 1) {
          pone[cOne] = 53;
          mgame[1][1] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 53;
          mgame[1][1] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
       printf("Jogada ja realizada!!\n");
      }
      break;
    case 54: // 6
      if (mgame[1][2] == 0) {
        if (turn == 1) {
          pone[cOne] = 54;
          mgame[1][2] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 54;
          mgame[1][2] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
       printf("Jogada ja realizada!!\n");
      }
      break;
    case 49: // 1
      if (mgame[2][0] == 0) {
        if (turn == 1) {
          pone[cOne] = 49;
          mgame[2][0] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 49;
          mgame[2][0] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
       printf("Jogada ja realizada!!\n");
      }
      break;
    case 50: // 2
      if (mgame[2][1] == 0) {
        if (turn == 1) {
          pone[cOne] = 50;
          mgame[2][1] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 50;
          mgame[2][1] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
       printf("Jogada ja realizada!!\n");
      }
      break;
    case 51: // 3
      if (mgame[2][2] == 0) {
        if (turn == 1) {
          pone[cOne] = 51;
          mgame[2][2] = 1;
          cOne++;
          turn = 2;
        } else {
          ptwo[cTwo] = 51;
          mgame[2][2] = 2;
          cTwo++;
          turn = 1;
        }
      } else {
       printf("Jogada ja realizada!!\n");
      }
      break;
  }
}



int verifyWinner() {
  int i, j, win, win2;
  struct multiplayerResult result;
  for (i = 0; i <= 7; i++) { //passa pelas possibilidades
    win = 0;
    for (j = 0; j <= 5; j++) { //passa pelas jogadas do player1
      if (vectorp[i].v1 == pone[j] || vectorp[i].v2 == pone[j] || vectorp[i].v3 == pone[j]) {
        win++;
      }
    }
    if (win == 3) {
      result.winner = playerone;
      result.looser = playertwo;
      addMultiplayerRanking(result);
      printf("\nVitoria do jogador %s!!! \n", playerone);
      return 1;
    }
  }
  for (i = 0; i <= 7; i++) { //passa pelas possibilidades
    win2 = 0;
    for (j = 0; j <= 5; j++) { //passa pelas jogadas do player2
      if (vectorp[i].v1 == ptwo[j] || vectorp[i].v2 == ptwo[j] || vectorp[i].v3 == ptwo[j]) {
        win2++;
      }
    }
    if (win2 == 3) {
      result.winner = playertwo;
      result.looser = playerone;
      addMultiplayerRanking(result);
      printf("\nVitoria do jogador %s!!! \n", playertwo);
      return 1;
    }
  }
  return 0;
}



void startMultiplayer() {
  buildVars();
  // contador de jogadas do jogador um e dois
  int finished = 0;
  int input;

  printf("\nPlayer 1 - nickname: ");
  gets(playerone);
  printf("\nPlayer 2 - nickname: ");
  gets(playertwo);

  printGame();

  while(finished == 0) {
    input = getch();
    // verifica de quem é a vez de jogar
    if (turn == 1){
      fillGame(input);
    } else if (turn == 2) {
      fillGame(input);
    }
    printGame();
    if (cOne >= 3 || cTwo >= 3) {
        finished = verifyWinner();
        if (cOne == 5 && finished == 0) {
          printf("\nO jogo terminou em empate :(\n");
          finished = 1;
        }
    }
  }
}
