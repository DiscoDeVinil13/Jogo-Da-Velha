# Jogo-Da-Velha
Jogo da Velha em C


# Descrição Geral
Esse projeto é um jogo da velha desenvolvido em linguagem C, no qual o jogador enfrenta o computador. 
A ideia foi criar um jogo em que o computador não escolhesse suas jogadas aleatoriamente, mas sim analisasse as 
possibilidades antes de jogar, utilizando o algoritmo Minimax, e buscando impedir a vitória do player.

# Tabuleiro
O tabuleiro é representado por um vetor chamado Velha, que possui 9 posições, correspondentes às casas do jogo. 
Cada posição pode armazenar três valores: 0, quando a casa está vazia, 1, quando pertence ao jogador (X), e 2, 
quando pertence ao computador (O).

# Variáveis
As variáveis globais controlam algumas partes do funcionamento do jogo. A variável posicao armazena a casa 
escolhida pelo jogador, validade indica se a jogada pode ser realizada e vitoria guarda o resultado da partida. 
Já as variáveis vez e jogadas, utilizadas na função principal, controlam de quem é a vez de jogar e quantas jogadas 
já foram realizadas.

# Funções
O programa foi dividido em várias funções para facilitar a organização. A função MAPA() prepara o tabuleiro, deixando todas as casas vazias, e mostra a numeração das posições. A função exibir_tabuleiro() apresenta o estado atual do jogo, mostrando onde estão os X e os O.

# Função VerificarJogada
A função VerificarJogada() confere se a posição escolhida existe e se ainda está disponível. Já a função Jogada() recebe a escolha do jogador e continua solicitando uma posição enquanto a entrada for inválida.

# Função VerificarVitória
Para identificar quando alguém venceu, foi criada a função VerificarVitoria(), que verifica todas as combinações possíveis de vitória, considerando as linhas, colunas e diagonais do tabuleiro.

# Algoritimo MiniMax e Função JogadaComputador
A parte mais importante do projeto está nas funções Minimax() e JogadaComputador(). A função Minimax analisa as possíveis jogadas futuras, simulando tanto as decisões do computador quanto as do jogador. Ela utiliza recursividade para percorrer essas possibilidades e atribui pontuações de acordo com os resultados encontrados. O computador tenta alcançar a maior pontuação possível, enquanto considera que o jogador sempre tentará escolher a jogada que mais o prejudica.
A função JogadaComputador() utiliza essas pontuações para escolher a melhor posição disponível e realizar a jogada. Assim, o computador consegue antecipar possíveis situações do jogo e tomar decisões mais estratégicas.

# Função Main
Por fim, a função main() controla toda a partida. Ela inicializa o tabuleiro, pergunta quem começa e alterna as jogadas entre o jogador e o computador. Depois de cada jogada, verifica se alguém venceu e encerra a partida quando existe um vencedor ou quando todas as casas foram preenchidas, resultando em empate.
O desenvolvimento desse projeto foi uma forma de colocar em prática conceitos da linguagem C, principalmente o uso de vetores, funções, condições, laços de repetição e recursividade, além de entender melhor como funciona o algoritmo Minimax aplicado a um jogo.
