//Criado por Alexssandro de Souza freitas.

#include <stdio.h>
#include <string.h>

#define MAX_CIDADES 10

// Estrutura para representar uma cidade
typedef struct {
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
} Cidade;

int main() {
    Cidade cidades[MAX_CIDADES];
    int totalCidades = 0;
    int i;

    printf("=== Cadastro de Cidades Super Trunfo ===\n");

    // Cadastro das cidades
    printf("Quantas cidades deseja cadastrar (max %d)? ", MAX_CIDADES);
    scanf("%d", &totalCidades);

    if (totalCidades < 2 || totalCidades > MAX_CIDADES) {
        printf("Numero invalido de cidades. Deve ser entre 2 e %d.\n", MAX_CIDADES);
        return 1;
    }

    for (i = 0; i < totalCidades; i++) {
        printf("\nCidade %d:\n", i + 1);
        printf("Codigo: ");
        scanf(" %s", cidades[i].codigo);
        printf("Nome: ");
        scanf(" %[^\n]", cidades[i].nome);
        printf("Populacao: ");
        scanf("%d", &cidades[i].populacao);
        printf("Area (km²): ");
        scanf("%f", &cidades[i].area);
        printf("PIB (em bilhões): ");
        scanf("%f", &cidades[i].pib);
    }

    // Seleção de cartas
    int c1, c2;
    printf("\n=== Comparação ===\n");
    printf("Escolha duas cidades para comparar (índices de 1 a %d):\n", totalCidades);

    printf("Cidade 1 (número): ");
    scanf("%d", &c1);
    printf("Cidade 2 (número): ");
    scanf("%d", &c2);

    // Verificação de índices válidos
    if (c1 < 1 || c1 > totalCidades || c2 < 1 || c2 > totalCidades || c1 == c2) {
        printf("Cidades inválidas para comparação.\n");
        return 1;
    }

    c1--; c2--; // ajustar para índices de vetor

    // Escolha do atributo
    int atributo;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("Opcao: ");
    scanf("%d", &atributo);

    // Comparação
    printf("\n--- Resultado ---\n");

    switch (atributo) {
        case 1:
            printf("Populacao: %s (%d) vs %s (%d)\n", cidades[c1].nome, cidades[c1].populacao, cidades[c2].nome, cidades[c2].populacao);
            if (cidades[c1].populacao > cidades[c2].populacao)
                printf("Vencedora: %s\n", cidades[c1].nome);
            else if (cidades[c2].populacao > cidades[c1].populacao)
                printf("Vencedora: %s\n", cidades[c2].nome);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Area: %s (%.2f km²) vs %s (%.2f km²)\n", cidades[c1].nome, cidades[c1].area, cidades[c2].nome, cidades[c2].area);
            if (cidades[c1].area > cidades[c2].area)
                printf("Vencedora: %s\n", cidades[c1].nome);
            else if (cidades[c2].area > cidades[c1].area)
                printf("Vencedora: %s\n", cidades[c2].nome);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("PIB: %s (%.2f bilhões) vs %s (%.2f bilhões)\n", cidades[c1].nome, cidades[c1].pib, cidades[c2].nome, cidades[c2].pib);
            if (cidades[c1].pib > cidades[c2].pib)
                printf("Vencedora: %s\n", cidades[c1].nome);
            else if (cidades[c2].pib > cidades[c1].pib)
                printf("Vencedora: %s\n", cidades[c2].nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Atributo inválido.\n");
    }

    return 0;
}
