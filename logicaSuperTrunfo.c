#include <stdio.h>
#include <string.h>

// Definição da struct
typedef struct {
    char Estado[50]; // Nome do estado
    char codigoCarta[50]; // Código único da carta
    char nomeCidade[100]; // Nome da cidade
    unsigned long int populacao; // População da cidade
    float area; // Área da cidade em km²
    float pib; // PIB da cidade em milhões
    int NumeroPontosTuristicos; // Número de pontos turísticos
    float densidadePopulacional; // Pessoas por km² (calculado)
    float pibPerCapita; // PIB dividido pela população (calculado)
    float superPoder; // Valor calculado com base em vários atributos
} Carta;

// Função que preenche os dados da carta com informações digitadas pelo usuário
void preencherCarta(Carta *carta, int numero) {
    printf("\n--- Preenchendo Carta %d ---\n", numero);

    // Pegando as infos da cidade
    printf("Digite o Estado: \n");
    scanf("%s", carta->Estado);

    printf("Digite o codigo da Carta: \n");
    scanf("%s", carta->codigoCarta);

    printf("Digite o nome da cidade: \n");
    scanf(" %[^\n]", carta->nomeCidade); // lê até o final da linha, aceita espaços

    printf("Digite a Populacao: \n");
    scanf("%lu", &carta->populacao);

    printf("Digite a Area (em km²): \n");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em milhões): \n");
    scanf("%f", &carta->pib);

    printf("Digite o numero de pontos turisticos: \n");
    scanf("%d", &carta->NumeroPontosTuristicos);

    // Calculando alguns valores com base nos dados digitados
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;

    // Evita dividir por zero, caso a densidade seja 0
    float inversoDensidade = (carta->densidadePopulacional > 0) ? (1.0 / carta->densidadePopulacional) : 0.0;

    // Soma de vários fatores pra gerar um "poder total" da cidade
    carta->superPoder = carta->populacao
                      + carta->area
                      + carta->pib
                      + carta->NumeroPontosTuristicos
                      + carta->pibPerCapita
                      + inversoDensidade;
}

// Função que mostra os dados da carta na tela
void exibirCarta(Carta carta, int numero) {
    printf("\n--- Dados da Carta %d ---\n", numero);
    printf("Estado: %s - Codigo da carta: %s\n", carta.Estado, carta.codigoCarta);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Area: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.NumeroPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f \n", carta.superPoder);

    // Se a cidade for muito densa, exibe um alerta
    const char *alerta = (carta.densidadePopulacional > 1000) ? "Atenção: Alta densidade populacional!\n" : "";
    printf("%s", alerta);
}
// **** Nova função: comparação por atributo único***
// Função que compara duas cartas com base em um atributo (no momento, só população)
void compararPorAtributo(Carta c1, Carta c2, const char *atributo) {
    printf("\n=== Comparação por Atributo: %s ===\n", atributo);

    // Comparando pela população
    if (strcmp(atributo, "populacao") == 0) {
        printf("Carta 1: %lu habitantes\n", c1.populacao);
        printf("Carta 2: %lu habitantes\n", c2.populacao);
        if (c1.populacao > c2.populacao)
            printf("Resultado: Carta 1 venceu na população!\n");
        else if (c2.populacao > c1.populacao)
            printf("Resultado: Carta 2 venceu na população!\n");
        else
            printf("Resultado: Empate na população!\n");
    }

    // Dá pra adicionar mais comparações aqui (tipo por PIB, área, etc.)
}
// Função que poderia comparar todos os atributos e dar pontos pra cada carta

void compararCartas(Carta c1, Carta c2) {
    int pontos1 = 0;
    int pontos2 = 0;

    printf("\n========================\n");
    printf("COMPARAÇÃO ENTRE AS CARTAS\n");

    // Aqui daria pra comparar vários atributos (população, área, PIB, etc.)
    // E ir somando pontos pra cada carta
    

    // Resultado final com base nos pontos (que ainda são 0)
    printf("\nResultado final:\n");
    printf("Carta 1: %d ponto(s)\n", pontos1);
    printf("Carta 2: %d ponto(s)\n", pontos2);

    const char *resultadoFinal = (pontos1 > pontos2) ? " Carta 1 é a campeã!\n" :
                                 (pontos2 > pontos1) ? " Carta 2 é a campeã!\n" :
                                 " Empate geral!\n";
    printf("%s", resultadoFinal);
}

// Função principal do programa
int main() {
    Carta carta1, carta2;

    // Preenche os dados das duas cartas
    preencherCarta(&carta1, 1);
    preencherCarta(&carta2, 2);

    // Mostra os dados das duas cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Compara só a população entre as duas cartas
    compararPorAtributo(carta1, carta2, "populacao");

    return 0;
}
