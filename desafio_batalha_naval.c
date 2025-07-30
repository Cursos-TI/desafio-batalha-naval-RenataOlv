#include <stdio.h> // Para funções de entrada/saída (printf)

// --- Constantes do Tabuleiro e Navios ---
#define TAMANHO_TABULEIRO 10 // O tabuleiro será 10x10
#define AGUA              0  // Representa uma posição sem navio
#define NAVIO             3  // Representa uma posição com navio
#define TAMANHO_NAVIO_PADRAO 3 // Tamanho fixo para os navios (3 posições)

// --- Função para Inicializar o Tabuleiro ---
// Preenche todas as posições do tabuleiro com AGUA (0).
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// --- Função para Posicionar um Navio Horizontalmente ---
// Recebe o tabuleiro, coordenadas iniciais (linha, coluna) e o tamanho do navio.
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho) {
    // Garante que o navio não saia dos limites do tabuleiro.
    if (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && (coluna + tamanho) <= TAMANHO_TABULEIRO) {
        for (int j = 0; j < tamanho; j++) {
            tabuleiro[linha][coluna + j] = NAVIO;
        }
    } else {
        printf("Aviso: Nao foi possivel posicionar navio horizontalmente em (%d,%d). Fora dos limites.\n", linha, coluna);
    }
}

// --- Função para Posicionar um Navio Verticalmente ---
// Recebe o tabuleiro, coordenadas iniciais (linha, coluna) e o tamanho do navio.
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho) {
    // Garante que o navio não saia dos limites do tabuleiro.
    if (linha >= 0 && (linha + tamanho) <= TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else {
        printf("Aviso: Nao foi possivel posicionar navio verticalmente em (%d,%d). Fora dos limites.\n", linha, coluna);
    }
}

// --- Função para Posicionar um Navio na Diagonal (Descendente: para baixo e para a direita) ---
// Ex: (0,0) -> (1,1) -> (2,2)
void posicionarNavioDiagonalDescendente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho) {
    // Garante que o navio não saia dos limites do tabuleiro na diagonal.
    if (linha >= 0 && (linha + tamanho) <= TAMANHO_TABULEIRO &&
        coluna >= 0 && (coluna + tamanho) <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else {
        printf("Aviso: Nao foi possivel posicionar navio diagonalmente descendente em (%d,%d). Fora dos limites.\n", linha, coluna);
    }
}

// --- Função para Posicionar um Navio na Diagonal (Ascendente: para cima e para a direita) ---
// Ex: (2,0) -> (1,1) -> (0,2)
void posicionarNavioDiagonalAscendente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho) {
    // Garante que o navio não saia dos limites do tabuleiro na diagonal.
    // A linha inicial deve ser alta o suficiente para descer 'tamanho' casas.
    if (linha >= (tamanho - 1) && linha < TAMANHO_TABULEIRO && // Linha não pode ser muito baixa para subir
        coluna >= 0 && (coluna + tamanho) <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha - i][coluna + i] = NAVIO;
        }
    } else {
        printf("Aviso: Nao foi possivel posicionar navio diagonalmente ascendente em (%d,%d). Fora dos limites.\n", linha, coluna);
    }
}

// --- Função para Exibir o Tabuleiro Completo ---
// Imprime a matriz no console, mostrando 0s e 3s.
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  "); // Espaço para alinhar com as colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Números das colunas
    }
    printf("\n"); // Nova linha após os números das colunas

    printf("  "); // Espaço para alinhar
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("--"); // Linha separadora
    }
    printf("-\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d|", i); // Número da linha e separador
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime o conteúdo da célula
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }
}

// --- Função Principal do Programa ---
int main() {
    // Declaração do tabuleiro (matriz 10x10)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    printf("--- Batalha Naval - Nivel Aventureiro ---\n");

    // 1. Inicializar o tabuleiro com água
    inicializarTabuleiro(tabuleiro);
    printf("Tabuleiro inicializado (todos os '0's sao agua):\n");
    exibirTabuleiro(tabuleiro);
    printf("\n");

    // 2. Posicionar quatro navios (2 retos, 2 diagonais)
    printf("Posicionando 4 navios de tamanho %d...\n", TAMANHO_NAVIO_PADRAO);

    // Navio 1: Horizontal (começa em linha 0, coluna 0)
    posicionarNavioHorizontal(tabuleiro, 0, 0, TAMANHO_NAVIO_PADRAO);

    // Navio 2: Vertical (começa em linha 2, coluna 5)
    posicionarNavioVertical(tabuleiro, 2, 5, TAMANHO_NAVIO_PADRAO);

    // Navio 3: Diagonal Descendente (começa em linha 3, coluna 3)
    posicionarNavioDiagonalDescendente(tabuleiro, 3, 3, TAMANHO_NAVIO_PADRAO);

    // Navio 4: Diagonal Ascendente (começa em linha 7, coluna 1)
    // A linha inicial (7) é escolhida para permitir que o navio suba 'tamanho' casas (7 -> 6 -> 5)
    posicionarNavioDiagonalAscendente(tabuleiro, 7, 1, TAMANHO_NAVIO_PADRAO);


    // 3. Exibir o tabuleiro completo com os navios posicionados
    printf("\n--- Tabuleiro com Navios Posicionados ('3's sao navios) ---\n");
    exibirTabuleiro(tabuleiro);
    printf("\nFim da demonstracao da Batalha Naval Nivel Aventureiro.\n");

    return 0; // Indica que o programa foi executado com sucesso
}