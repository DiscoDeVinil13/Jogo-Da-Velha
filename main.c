
#include <stdio.h>
#include <stdlib.h>

// Inicialização das váriaveis globais.
int posicao = 10;
int validade = 0;
int vitoria = 0;
int Velha[9];

// ----------------------------------------------
// Exibição do mapa das casas, armazenados em um vetor para ficar mais fácil, também limpa dito
// vetor ali em baixo para evitar lixo na memória.

int MAPA(void) {
    for (int i = 0; i < 9; i++) {
        Velha[i] = 0;
    }
    printf("Jogo da Velha!\n");
    printf("-------------\n");
    printf("| 1 | 2 | 3 |\n");
    printf("-------------\n");
    printf("| 4 | 5 | 6 |\n");
    printf("-------------\n");
    printf("| 7 | 8 | 9 |\n");
    printf("-------------\n");
    printf("Escolha suas jogadas (ao iniciar a partida) baseadas no mapa das casas!\n");

    return 0;
}

// -----------------------------------------------
// Função que exibe o estado atual do tabuleiro, convertendo as váriaveis
// em X e O que deixa mais característico de jogo da velha

int exibir_tabuleiro(void) {
    char simbolo[3] = {' ', 'X', 'O'};

    printf("\n-------------\n");
    printf("| %c | %c | %c |\n",
           simbolo[Velha[0]], simbolo[Velha[1]], simbolo[Velha[2]]);

    printf("-------------\n");
    printf("| %c | %c | %c |\n",
           simbolo[Velha[3]], simbolo[Velha[4]], simbolo[Velha[5]]);

    printf("-------------\n");
    printf("| %c | %c | %c |\n",
           simbolo[Velha[6]], simbolo[Velha[7]], simbolo[Velha[8]]);
    printf("-------------\n");

    return 0;
}

// ------------------------------------------------
// Verifica duas coisas, que a posição em primeiro lugar exista dentro do
// mapa das casas (1 até 9) e depois o vetor já não armazena outro valor na
// casa especificada, retornando validade = 0 para falso e validade = 1 para
// verdadeiro

int VerificarJogada(void) {
    validade = 0;

    if (posicao >= 1 && posicao <= 9) {
        if (Velha[posicao - 1] == 0) {
            validade = 1;
        }
    }

    return 0;
}

// ---------------------------------------
// Função que roda quando jogador for jogar. Puxa da função "VerificarJogada"
// para dar validade e funciona em loop até a posição escolhida ser viável.

int Jogada(void) {
    do {
        printf("\nQual posicao queres jogar? (1 ate 9): ");

        if (scanf("%d", &posicao) != 1) {
            while (getchar() != '\n');
            validade = 0;
            printf("Entrada invalida! Digite um numero.\n");
            continue;
        }

        VerificarJogada();

        if (validade == 0) {
            printf("Posicao invalida! Tente novamente.\n");
        }

    } while (validade == 0);

    Velha[posicao - 1] = 1;

    return 0;
}

// ---------------------------------------
// Função que checa toda rodada se as posições do mapa estão alinhadas
// e declara vitória se sim.

int VerificarVitoria(void) {

    // Vitória nas horizontais
    if (Velha[0] == Velha[1] && Velha[1] == Velha[2] && Velha[0] != 0)
        return Velha[0];

    if (Velha[3] == Velha[4] && Velha[4] == Velha[5] && Velha[3] != 0)
        return Velha[3];

    if (Velha[6] == Velha[7] && Velha[7] == Velha[8] && Velha[6] != 0)
        return Velha[6];

    // Vitória nas Verticais
    if (Velha[0] == Velha[3] && Velha[3] == Velha[6] && Velha[0] != 0)
        return Velha[0];

    if (Velha[1] == Velha[4] && Velha[4] == Velha[7] && Velha[1] != 0)
        return Velha[1];

    if (Velha[2] == Velha[5] && Velha[5] == Velha[8] && Velha[2] != 0)
        return Velha[2];

    // Vitórias nas Diagonais
    if (Velha[0] == Velha[4] && Velha[4] == Velha[8] && Velha[0] != 0)
        return Velha[0];

    if (Velha[2] == Velha[4] && Velha[4] == Velha[6] && Velha[2] != 0)
        return Velha[2];

    return 0;
}


// --------------------------------------------------
// Algoritmo Minimax: analisa as possibilidades futuras
// e retorna a melhor pontuacao para o computador.

int Minimax(int vez, int profundidade) {

    int resultado = VerificarVitoria();

    // Verifica se alguem venceu.
    if (resultado == 2) {
        return 10 - profundidade;
    }

    if (resultado == 1) {
        return profundidade - 10;
    }

    int melhorPontuacao;
    int temJogada = 0;

    // O computador tenta maximizar a pontuacao.
    if (vez == 2) {
        melhorPontuacao = -1000;
    }
    // O jogador tenta minimizar a pontuacao.
    else {
        melhorPontuacao = 1000;
    }

    for (int i = 0; i < 9; i++) {

        if (Velha[i] == 0) {

            temJogada = 1;

            // Simula uma jogada.
            Velha[i] = vez;

            int pontuacao;

            if (vez == 2) {
                pontuacao = Minimax(1, profundidade + 1);
            }
            else {
                pontuacao = Minimax(2, profundidade + 1);
            }

            // Desfaz a jogada simulada.
            Velha[i] = 0;

            // Escolhe a melhor pontuacao.
            if (vez == 2) {
                if (pontuacao > melhorPontuacao) {
                    melhorPontuacao = pontuacao;
                }
            }
            else {
                if (pontuacao < melhorPontuacao) {
                    melhorPontuacao = pontuacao;
                }
            }
        }
    }

    // Se nao houver casas livres, terminou em empate.
    if (temJogada == 0) {
        return 0;
    }

    return melhorPontuacao;
}


// --------------------------------------------------
// Funcao que escolhe a melhor jogada para o computador, utilizando Min Max.

int JogadaComputador(void) {

    int melhorPontuacao = -1000;
    int escolha = -1;

    for (int i = 0; i < 9; i++) {

        if (Velha[i] == 0) {

            // Simula a jogada do computador.
            Velha[i] = 2;

            // Analisa as possibilidades a partir dela.
            int pontuacao = Minimax(1, 1);

            // Desfaz a simulacao.
            Velha[i] = 0;

            // Guarda a jogada com melhor resultado.
            if (pontuacao > melhorPontuacao) {
                melhorPontuacao = pontuacao;
                escolha = i;
            }
        }
    }

    // Executa a melhor jogada encontrada.
    if (escolha != -1) {
        Velha[escolha] = 2;
    }

    return 0;
}



// --------------------------------------------------
// Programa princial, que roda o jogo da velha: puxa o mapa das casas, pergunta quem começa e
// alterna as jogadas entre computador e player até alguém ganhar.;

int main(void) {

    int vez;
    int jogadas = 0;

    MAPA();

    printf("\nQuem comeca?\n");
    printf("1 - Jogador (X)\n");
    printf("2 - Computador (O)\n");
    printf("Escolha: ");

    while (scanf("%d", &vez) != 1 || (vez != 1 && vez != 2)) {
        while (getchar() != '\n');
        printf("Opcao invalida. Escolha 1 ou 2: ");
    }

    while (jogadas < 9 && vitoria == 0) {

        if (vez == 1) {
            printf("\nSua vez! (X)\n");
            Jogada();
            jogadas++;

            exibir_tabuleiro();

            vitoria = VerificarVitoria();

            if (vitoria != 0) {
                break;
            }

            vez = 2;
        }
        else {
            printf("\nVez do computador! (O)\n");
            JogadaComputador();
            jogadas++;

            exibir_tabuleiro();

            vitoria = VerificarVitoria();

            if (vitoria != 0) {
                break;
            }

            vez = 1;
        }
    }

    // Resultado final
    if (vitoria == 1) {
        printf("\nParabens! Voce venceu!\n");
    }
    else if (vitoria == 2) {
        printf("\nO computador venceu!\n");
    }
    else {
        printf("\nEmpate!\n");
    }

    return 0;
}
