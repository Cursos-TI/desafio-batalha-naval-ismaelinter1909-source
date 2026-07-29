#include <stdio.h>

int main() {

    /*
    ============================================================
             BATALHA NAVAL - NÍVEL AVENTUREIRO
    ============================================================

    Objetivo:
    - Criar um tabuleiro 10x10.
    - Inicializar todas as posições com 0 (água).
    - Posicionar quatro navios de tamanho 3.
    - Um navio horizontal.
    - Um navio vertical.
    - Dois navios diagonais.
    - Representar os navios pelo valor 3.
    - Validar os limites do tabuleiro.
    - Evitar sobreposição entre os navios.
    - Exibir o tabuleiro completo.

    Representação:
        0 = Água
        3 = Navio
    ============================================================
    */


    // ========================================================
    // CONSTANTES
    // ========================================================

    // O tabuleiro possui 10 linhas e 10 colunas.
    const int TAMANHO_TABULEIRO = 10;

    // Todos os navios possuem tamanho 3.
    const int TAMANHO_NAVIO = 3;


    // ========================================================
    // DECLARAÇÃO DO TABULEIRO
    // ========================================================

    // Matriz bidimensional utilizada para representar
    // o tabuleiro da Batalha Naval.
    int tabuleiro[10][10];


    // ========================================================
    // DECLARAÇÃO DOS NAVIOS
    // ========================================================

    /*
    Cada navio é representado por um vetor.

    Cada posição possui o valor 3, que será posteriormente
    copiado para a matriz do tabuleiro.
    */

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};


    // ========================================================
    // COORDENADAS DOS NAVIOS
    // ========================================================

    /*
    NAVIO HORIZONTAL

    Começa em:
        linha 1
        coluna 1

    Ocupa:
        [1][1]
        [1][2]
        [1][3]
    */

    int linhaHorizontal = 1;
    int colunaHorizontal = 1;


    /*
    NAVIO VERTICAL

    Começa em:
        linha 4
        coluna 8

    Ocupa:
        [4][8]
        [5][8]
        [6][8]
    */

    int linhaVertical = 4;
    int colunaVertical = 8;


    /*
    NAVIO DIAGONAL 1

    Linha e coluna aumentam simultaneamente.

    Começa em:
        linha 3
        coluna 2

    Ocupa:
        [3][2]
        [4][3]
        [5][4]
    */

    int linhaDiagonal1 = 3;
    int colunaDiagonal1 = 2;


    /*
    NAVIO DIAGONAL 2

    A linha aumenta enquanto a coluna diminui.

    Começa em:
        linha 6
        coluna 6

    Ocupa:
        [6][6]
        [7][5]
        [8][4]
    */

    int linhaDiagonal2 = 6;
    int colunaDiagonal2 = 6;


    // ========================================================
    // VARIÁVEIS AUXILIARES
    // ========================================================

    int linha;
    int coluna;
    int i;

    /*
    Esta variável será utilizada durante as validações.

    1 = posição válida
    0 = posição inválida
    */

    int posicaoValida;


    // ========================================================
    // INICIALIZAÇÃO DO TABULEIRO
    // ========================================================

    /*
    Dois loops aninhados percorrem toda a matriz.

    Todas as posições recebem inicialmente o valor 0,
    representando a água.
    */

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            tabuleiro[linha][coluna] = 0;
        }
    }


    // ========================================================
    // NAVIO HORIZONTAL
    // ========================================================

    posicaoValida = 1;

    /*
    Verifica se o navio horizontal ficará completamente
    dentro dos limites do tabuleiro.
    */

    if (linhaHorizontal < 0 ||
        linhaHorizontal >= TAMANHO_TABULEIRO ||
        colunaHorizontal < 0 ||
        colunaHorizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {

        printf("Erro: Navio horizontal fora do tabuleiro.\n");

        posicaoValida = 0;
    }


    /*
    Verifica se as posições que serão ocupadas estão livres.
    */

    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != 0) {

                printf("Erro: Sobreposicao no navio horizontal.\n");

                posicaoValida = 0;
            }
        }
    }


    /*
    Se tudo estiver correto, posicionamos o navio.
    */

    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            tabuleiro[linhaHorizontal][colunaHorizontal + i]
                = navioHorizontal[i];
        }
    }


    // ========================================================
    // NAVIO VERTICAL
    // ========================================================

    posicaoValida = 1;


    /*
    Para o navio vertical, a coluna permanece fixa enquanto
    a linha aumenta.
    */

    if (linhaVertical < 0 ||
        linhaVertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaVertical < 0 ||
        colunaVertical >= TAMANHO_TABULEIRO) {

        printf("Erro: Navio vertical fora do tabuleiro.\n");

        posicaoValida = 0;
    }


    // Verificação de sobreposição.
    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaVertical + i][colunaVertical] != 0) {

                printf("Erro: Sobreposicao no navio vertical.\n");

                posicaoValida = 0;
            }
        }
    }


    // Posicionamento do navio vertical.
    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            tabuleiro[linhaVertical + i][colunaVertical]
                = navioVertical[i];
        }
    }


    // ========================================================
    // PRIMEIRO NAVIO DIAGONAL
    // ========================================================

    posicaoValida = 1;


    /*
    Nesta diagonal, linha e coluna aumentam juntas.

    Exemplo:

        [3][2]
        [4][3]
        [5][4]

    Portanto utilizamos:

        linhaDiagonal1 + i
        colunaDiagonal1 + i
    */

    if (linhaDiagonal1 < 0 ||
        colunaDiagonal1 < 0 ||
        linhaDiagonal1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaDiagonal1 + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {

        printf("Erro: Navio diagonal 1 fora do tabuleiro.\n");

        posicaoValida = 0;
    }


    // Verificação de sobreposição.
    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] != 0) {

                printf("Erro: Sobreposicao no navio diagonal 1.\n");

                posicaoValida = 0;
            }
        }
    }


    // Posicionamento do primeiro navio diagonal.
    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i]
                = navioDiagonal1[i];
        }
    }


    // ========================================================
    // SEGUNDO NAVIO DIAGONAL
    // ========================================================

    posicaoValida = 1;


    /*
    Neste navio diagonal:

    - a linha aumenta;
    - a coluna diminui.

    Exemplo:

        [6][6]
        [7][5]
        [8][4]

    Portanto utilizamos:

        linhaDiagonal2 + i
        colunaDiagonal2 - i
    */

    if (linhaDiagonal2 < 0 ||
        linhaDiagonal2 + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaDiagonal2 >= TAMANHO_TABULEIRO ||
        colunaDiagonal2 - (TAMANHO_NAVIO - 1) < 0) {

        printf("Erro: Navio diagonal 2 fora do tabuleiro.\n");

        posicaoValida = 0;
    }


    // Verificação de sobreposição.
    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            if (tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] != 0) {

                printf("Erro: Sobreposicao no navio diagonal 2.\n");

                posicaoValida = 0;
            }
        }
    }


    // Posicionamento do segundo navio diagonal.
    if (posicaoValida == 1) {

        for (i = 0; i < TAMANHO_NAVIO; i++) {

            tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i]
                = navioDiagonal2[i];
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
    Os loops aninhados percorrem todas as posições da matriz
    para exibir o tabuleiro completo.
    */

    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {

        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }


    // ========================================================
    // FIM DO PROGRAMA
    // ========================================================

    return 0;
}