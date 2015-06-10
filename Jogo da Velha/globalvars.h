// Criaзгo de um novo tipo de variável personalizada
struct possibilities {
    int v1; // codigo ascii
    int v2;
    int v3;
};

// Variбvel para escrever no ranking o resultado do multiplayer.
struct multiplayerResult {
    char* winner;
    char* looser;
};

// Variбvel para escrever no ranking o resultado do singleplayer.
struct singleplayerResult {
    char* player;
    int difficult;
    int result;
};

// Classe header para ser importada quando um código necessitar usar o globalvars.c
void buildVars();
