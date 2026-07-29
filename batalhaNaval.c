#include <stdio.h>

#define TAM 10
#define TAM_HABILIDADE 5
#define TAM_NAVIO 3

int main() {

    // ============================================================
    // DECLARAÇÃO DO TABULEIRO
    // ============================================================
    // O tabuleiro possui 10 linhas e 10 colunas.
    //
    // Valores utilizados:
    // 0 = Água
    // 3 = Navio
    // 5 = Área afetada por habilidade
    // ============================================================

    int tabuleiro[TAM][TAM];


    // ============================================================
    // MATRIZES DAS HABILIDADES
    // ============================================================
    // Cada habilidade utiliza uma matriz 5x5.
    //
    // 0 = posição não afetada
    // 1 = posição afetada
    // ============================================================

    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];


    // ============================================================
    // VARIÁVEIS AUXILIARES
    // ============================================================

    int linha;
    int coluna;
    int i;


    // ============================================================
    // INICIALIZAÇÃO DO TABULEIRO
    // ============================================================
    // Percorremos todas as posições da matriz utilizando dois
    // loops aninhados e colocamos o valor 0, representando água.
    // ============================================================

    for (linha = 0; linha < TAM; linha++) {

        for (coluna = 0; coluna < TAM; coluna++) {

            tabuleiro[linha][coluna] = 0;
        }
    }


    // ============================================================
    // POSICIONAMENTO DOS NAVIOS
    // ============================================================
    // Mantemos quatro navios do nível aventureiro:
    //
    // 1 - Horizontal
    // 2 - Vertical
    // 3 - Diagonal principal
    // 4 - Diagonal secundária
    //
    // Cada navio ocupa três posições.
    // ============================================================


    // ------------------------------------------------------------
    // NAVIO 1 - HORIZONTAL
    // ------------------------------------------------------------
    // Começa na linha 1 e coluna 0.
    // A linha permanece fixa e a coluna aumenta.
    // ------------------------------------------------------------

    int linhaHorizontal = 1;
    int colunaHorizontal = 0;

    for (i = 0; i < TAM_NAVIO; i++) {

        tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
    }


    // ------------------------------------------------------------
    // NAVIO 2 - VERTICAL
    // ------------------------------------------------------------
    // Começa na linha 3 e coluna 2.
    // A coluna permanece fixa e a linha aumenta.
    // ------------------------------------------------------------

    int linhaVertical = 3;
    int colunaVertical = 2;

    for (i = 0; i < TAM_NAVIO; i++) {

        tabuleiro[linhaVertical + i][colunaVertical] = 3;
    }


    // ------------------------------------------------------------
    // NAVIO 3 - DIAGONAL PRINCIPAL
    // ------------------------------------------------------------
    // Linha e coluna aumentam simultaneamente.
    // ------------------------------------------------------------

    int linhaDiagonal1 = 4;
    int colunaDiagonal1 = 3;

    for (i = 0; i < TAM_NAVIO; i++) {

        tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i] = 3;
    }


    // ------------------------------------------------------------
    // NAVIO 4 - DIAGONAL SECUNDÁRIA
    // ------------------------------------------------------------
    // A linha aumenta enquanto a coluna diminui.
    // ------------------------------------------------------------

    int linhaDiagonal2 = 4;
    int colunaDiagonal2 = 7;

    for (i = 0; i < TAM_NAVIO; i++) {

        tabuleiro[linhaDiagonal2 + i][colunaDiagonal2 - i] = 3;
    }


    // ============================================================
    // CRIAÇÃO DA MATRIZ DA HABILIDADE CONE
    // ============================================================
    //
    // O cone começa estreito na parte superior e vai aumentando
    // em direção à parte inferior.
    //
    // Exemplo aproximado:
    //
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    // 0 0 0 0 0
    // 0 0 0 0 0
    //
    // A construção é realizada dinamicamente utilizando
    // condicionais dentro de loops aninhados.
    // ============================================================

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (
                (linha == 0 && coluna == 2) ||
                (linha == 1 && coluna >= 1 && coluna <= 3) ||
                (linha == 2)
            ) {
                cone[linha][coluna] = 1;
            }
            else {
                cone[linha][coluna] = 0;
            }
        }
    }


    // ============================================================
    // CRIAÇÃO DA MATRIZ DA HABILIDADE CRUZ
    // ============================================================
    //
    // A cruz possui uma linha horizontal e uma linha vertical
    // passando pelo centro da matriz.
    //
    // Exemplo:
    //
    // 0 0 1 0 0
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    // 0 0 1 0 0
    //
    // O centro da matriz 5x5 é a posição [2][2].
    // ============================================================

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (linha == 2 || coluna == 2) {

                cruz[linha][coluna] = 1;
            }
            else {

                cruz[linha][coluna] = 0;
            }
        }
    }


    // ============================================================
    // CRIAÇÃO DA MATRIZ DA HABILIDADE OCTAEDRO
    // ============================================================
    //
    // Visto de frente, o octaedro possui formato semelhante
    // a um losango.
    //
    // Exemplo:
    //
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    // 0 1 1 1 0
    // 0 0 1 0 0
    //
    // Utilizamos a distância da posição atual até o centro
    // da matriz para determinar se ela pertence ao losango.
    // ============================================================

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            int distanciaLinha = linha - 2;
            int distanciaColuna = coluna - 2;

            // Transformamos valores negativos em positivos.
            if (distanciaLinha < 0) {
                distanciaLinha = -distanciaLinha;
            }

            if (distanciaColuna < 0) {
                distanciaColuna = -distanciaColuna;
            }

            // Se a soma das distâncias for menor ou igual a 2,
            // a posição faz parte do losango.
            if (distanciaLinha + distanciaColuna <= 2) {

                octaedro[linha][coluna] = 1;
            }
            else {

                octaedro[linha][coluna] = 0;
            }
        }
    }


    // ============================================================
    // POSIÇÕES DAS HABILIDADES NO TABULEIRO
    // ============================================================
    //
    // Cada habilidade possui uma posição de origem.
    // Essas posições são definidas diretamente no código,
    // conforme permitido pelo desafio.
    // ============================================================

    int origemConeLinha = 0;
    int origemConeColuna = 7;

    int origemCruzLinha = 7;
    int origemCruzColuna = 2;

    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 7;


    // ============================================================
    // SOBREPOSIÇÃO DA HABILIDADE CONE
    // ============================================================
    //
    // Percorremos a matriz do cone.
    //
    // Quando encontramos valor 1, calculamos sua posição
    // correspondente dentro do tabuleiro.
    //
    // Antes de alterar o tabuleiro, verificamos seus limites.
    // ============================================================

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (cone[linha][coluna] == 1) {

                int linhaTabuleiro = origemConeLinha + linha;
                int colunaTabuleiro =
                    origemConeColuna + coluna - 2;

                // Verifica se a posição está dentro do tabuleiro.
                if (
                    linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAM &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAM
                ) {

                    // Não substituímos posições ocupadas por navios.
                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }


    // ============================================================
    // SOBREPOSIÇÃO DA HABILIDADE CRUZ
    // ============================================================

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (cruz[linha][coluna] == 1) {

                int linhaTabuleiro =
                    origemCruzLinha + linha - 2;

                int colunaTabuleiro =
                    origemCruzColuna + coluna - 2;

                // Verifica os limites do tabuleiro.
                if (
                    linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAM &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAM
                ) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }


    // ============================================================
    // SOBREPOSIÇÃO DA HABILIDADE OCTAEDRO
    // ============================================================

    for (linha = 0; linha < TAM_HABILIDADE; linha++) {

        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {

            if (octaedro[linha][coluna] == 1) {

                int linhaTabuleiro =
                    origemOctaedroLinha + linha - 2;

                int colunaTabuleiro =
                    origemOctaedroColuna + coluna - 2;

                // Verifica os limites antes de acessar a matriz.
                if (
                    linhaTabuleiro >= 0 &&
                    linhaTabuleiro < TAM &&
                    colunaTabuleiro >= 0 &&
                    colunaTabuleiro < TAM
                ) {

                    if (tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {

                        tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                    }
                }
            }
        }
    }


    // ============================================================
    // EXIBIÇÃO DO TABULEIRO
    // ============================================================

    printf("\n========================================\n");
    printf("       BATALHA NAVAL - NIVEL MESTRE\n");
    printf("========================================\n\n");

    printf("Legenda:\n");
    printf("0 = Agua\n");
    printf("3 = Navio\n");
    printf("5 = Area afetada pela habilidade\n\n");


    // ------------------------------------------------------------
    // Cabeçalho das colunas
    // ------------------------------------------------------------

    printf("   ");

    for (coluna = 0; coluna < TAM; coluna++) {

        printf("%d ", coluna);
    }

    printf("\n");


    // ------------------------------------------------------------
    // Exibição das linhas do tabuleiro
    // ------------------------------------------------------------

    for (linha = 0; linha < TAM; linha++) {

        // Número da linha
        printf("%d  ", linha);

        for (coluna = 0; coluna < TAM; coluna++) {

            printf("%d ", tabuleiro[linha][coluna]);
        }

        printf("\n");
    }


    // ============================================================
    // FINALIZAÇÃO DO PROGRAMA
    // ============================================================

    return 0;
}