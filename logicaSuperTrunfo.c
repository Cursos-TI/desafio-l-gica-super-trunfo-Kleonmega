#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigoCarta[50];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

void cadastrarCarta(Carta *carta) {
    printf("\nCadastro de Carta:\n");
    printf("Digite o Estado: ");
    scanf(" %[^\n]", carta->estado);
    printf("Digite o Código da Carta: ");
    scanf(" %[^\n]", carta->codigoCarta);
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);
    printf("Digite a População: ");
    scanf("%d", &carta->populacao);
    printf("Digite a Área (em km²): ");
    scanf("%f", &carta->area);
    printf("Digite o PIB (em milhões): ");
    scanf("%f", &carta->pib);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

void exibirCarta(Carta carta) {
    printf("\n=== Dados da Carta ===\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigoCarta);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f pessoas/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f milhões/pessoa\n", carta.pibPerCapita);
}

void compararCartas(Carta carta1, Carta carta2) {
    
    float atributo1 = carta1.pibPerCapita;
    float atributo2 = carta2.pibPerCapita;

    printf("\nComparação de Cartas (Atributo: PIB per capita):\n");
    printf("Carta 1 - %s: %.2f\n", carta1.nomeCidade, atributo1);
    printf("Carta 2 - %s: %.2f\n", carta2.nomeCidade, atributo2);

    if (atributo1 > atributo2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (atributo1 < atributo2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {

    Carta carta1, carta2;

    
    printf("Insira os dados da primeira carta:");
    cadastrarCarta(&carta1);
    
    printf("\nInsira os dados da segunda carta:");
    cadastrarCarta(&carta2);


    exibirCarta(carta1);
    exibirCarta(carta2);

    compararCartas(carta1, carta2);

    return 0;
}