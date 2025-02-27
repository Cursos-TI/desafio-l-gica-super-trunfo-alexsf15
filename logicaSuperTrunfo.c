#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um país
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int pib;
} Pais;

// Função para criar as cartas dos países
void criarBaralho(Pais baralho[]) {
    strcpy(baralho[0].nome, "Brasil");
    baralho[0].populacao = 214000000;
    baralho[0].area = 8516000;
    baralho[0].pib = 1900000;

    strcpy(baralho[1].nome, "Estados Unidos");
    baralho[1].populacao = 331000000;
    baralho[1].area = 9834000;
    baralho[1].pib = 23000000;

    strcpy(baralho[2].nome, "China");
    baralho[2].populacao = 1400000000;
    baralho[2].area = 9597000;
    baralho[2].pib = 17700000;

    strcpy(baralho[3].nome, "Rússia");
    baralho[3].populacao = 144000000;
    baralho[3].area = 17098000;
    baralho[3].pib = 1775000;
}

// Função para comparar as cartas
int compararCartas(Pais carta1, Pais carta2, int atributo) {
    switch (atributo) {
        case 1: // População
            return carta1.populacao - carta2.populacao;
        case 2: // Área
            return carta1.area - carta2.area;
        case 3: // PIB
            return carta1.pib - carta2.pib;
        default:
            return 0;
    }
}

int main() {
    Pais baralho[4];
    criarBaralho(baralho);

    // Exemplo de jogada
    Pais cartaJogador = baralho[0];
    Pais cartaComputador = baralho[1];

    printf("Sua carta: %s\n", cartaJogador.nome);
    printf("Carta do computador: %s\n", cartaComputador.nome);

    int atributo;
    printf("Escolha o atributo (1: População, 2: Área, 3: PIB): ");
    scanf("%d", &atributo);

    int resultado = compararCartas(cartaJogador, cartaComputador, atributo);

    if (resultado > 0) {
        printf("Você venceu a rodada!\n");
    } else if (resultado < 0) {
        printf("O computador venceu a rodada!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
