#include <stdio.h>

int main() {

    /*
    ============================================================
                BATALHA NAVAL - NÍVEL NOVATO
    ============================================================

    Objetivo:
    - Criar um tabuleiro 10x10 utilizando uma matriz.
    - Inicializar todas as posições com 0 (água).
    - Criar dois navios de tamanho 3 utilizando vetores.
    - Posicionar um navio horizontalmente.
    - Posicionar outro navio verticalmente.
    - Representar os navios pelo número 3.
    - Garantir que os navios estejam dentro do tabuleiro.
    - Evitar sobreposição entre os navios.
    - Exibir o tabuleiro utilizando loops aninhados.

    Representação:
        0 = Água
        3 = Navio
    ============================================================
    */


    // ========================================================
    // CONSTANTES DO PROGRAMA
    // ========================================================

    // Tamanho fixo do tabuleiro: 10 linhas por 10 colunas.
    const int TAMANHO_TABULEIRO = 10;

    // Cada navio ocupará exatamente 3 posições.
    const int TAMANHO_NAVIO = 3;


    // ========================================================
    // DECLARAÇÃO DO TABULEIRO
    // ========================================================

    // Matriz bidimensional responsável por representar
    // todas as posições do tabuleiro.
    int tabuleiro[10][10];


    // ========================================================
    // DECLARAÇÃO DOS NAVIOS
    // ========================================================

    /*
    Cada navio é representado por um vetor de tamanho 3.

    O valor 3 representa uma parte do navio.
    */

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};


    // ========================================================
    // COORDENADAS DOS NAVIOS
    // ========================================================

    /*
    As coordenadas são definidas diretamente no código,
    conforme permitido pelo desafio.

    Navio horizontal:
        começa na linha 2 e coluna 2.

        Ele ocupará:
        [2][2]
        [2][3]
        [2][4]

    Navio vertical:
        começa na linha 5 e coluna 6.

        Ele ocupará:
        [5][6]
        [6][6]
        [7][6]

    Dessa forma os dois navios não se sobrepõem.
    */

    int linhaHorizontal = 2;
    int colunaHorizontal = 2;

    int linhaVertical = 5;
    int colunaVertical = 6;


    // ========================================================
    // VARIÁVEIS AUXILIARES
    // ========================================================

    int linha;
    int coluna;
    int i;

    /*
    Esta variável será utilizada para determinar se
    podemos ou não posicionar os navios.

    1 = posição válida
    0 = posição inválida
    */

    int posicaoValida = 1;


    // ========================================================
    // INICIALIZAÇÃO DO TABULEIRO
    // ========================================================

    /*
    Utilizamos dois loops aninhados.

    O primeiro percorre as linhas.
    O segundo percorre as colunas.

    Todas as posições recebem inicialmente o valor 0,
    representando água.
    */

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            tabuleiro[linha][coluna] = 0;
        }
    }


    // ========================================================
    // VALIDAÇÃO DO NAVIO HORIZONTAL
    // ========================================================

    /*
    Para o navio horizontal precisamos verificar:

    - se a linha está dentro do tabuleiro;
    - se a coluna inicial é válida;
    - se as três posições cabem horizontalmente.
    */

    if (linhaHorizontal < 0 ||
        linhaHorizontal >= TAMANHO_TABULEIRO ||
        colunaHorizontal < 0 ||
        colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {

        printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");

        posicaoValida = 0;
    }


    // ========================================================
    // POSICIONAMENTO DO NAVIO HORIZONTAL
    // ========================================================

    /*
    Se as coordenadas forem válidas, percorremos o vetor
    do navio e copiamos cada valor 3 para o tabuleiro.

    A linha permanece a mesma.

    Apenas a coluna aumenta:

        [linha][coluna]
        [linha][coluna + 1]
        [linha][coluna + 2]
    */

    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            tabuleiro[linhaHorizontal][colunaHorizontal + i]
                = navioHorizontal[i];
        }
    }


    // ========================================================
    // VALIDAÇÃO DO NAVIO VERTICAL
    // ========================================================

    /*
    Agora verificamos se o navio vertical cabe no tabuleiro.

    Nesse caso, a coluna permanece fixa e as linhas aumentam.
    */

    if (linhaVertical < 0 ||
        linhaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaVertical < 0 ||
        colunaVertical >= TAMANHO_TABULEIRO) {

        printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");

        posicaoValida = 0;
    }


    // ========================================================
    // VERIFICAÇÃO DE SOBREPOSIÇÃO
    // ========================================================

    /*
    Antes de posicionar o navio vertical, verificamos
    cada uma das posições que ele pretende ocupar.

    Se alguma dessas posições já possuir o valor 3,
    significa que existe outro navio naquele local.
    */

    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {

                printf("Erro: Os navios nao podem se sobrepor.\n");

                posicaoValida = 0;
            }
        }
    }


    // ========================================================
    // POSICIONAMENTO DO NAVIO VERTICAL
    // ========================================================

    /*
    Caso não exista nenhuma sobreposição, copiamos os
    valores do vetor navioVertical para a matriz.

    Agora a coluna permanece fixa e a linha aumenta.
    */

    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            tabuleiro[linhaVertical + i][colunaVertical]
                = navioVertical[i];
        }
    }


    // ========================================================
    // EXIBIÇÃO DO TABULEIRO
    // ========================================================

    printf("\n=======================================\n");
    printf("       BATALHA NAVAL - TABULEIRO\n");
    printf("=======================================\n\n");

    printf("Legenda: 0 = Agua | 3 = Navio\n\n");


    /*
    Novamente utilizamos loops aninhados.

    O primeiro percorre cada linha.
    O segundo percorre cada coluna.

    Cada número é exibido seguido de um espaço.
    */

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        // Ao terminar uma linha, pulamos para a próxima.
        printf("\n");
    }


    // ========================================================
    // FIM DO PROGRAMA
    // ========================================================

    return 0;
}