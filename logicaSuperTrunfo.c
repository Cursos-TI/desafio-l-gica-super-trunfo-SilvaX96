#include <stdio.h>
#include <string.h>

// Definição da struct Carta, que guarda os dados de uma cidade
typedef struct {
    char Estado[50];               // Estado da cidade
    char codigoCarta[50];          // Código único da carta
    char nomeCidade[100];          // Nome da cidade
    unsigned long int populacao;   // Quantidade de habitantes
    float area;                    // Área em km²
    float pib;                     // PIB em milhões
    int NumeroPontosTuristicos;    // Quantidade de pontos turísticos
    float densidadePopulacional;   // População / área, calculado depois
    float pibPerCapita;            // PIB / população, calculado depois
    float superPoder;              // Um valor "mágico" calculado com vários fatores
} Carta;

// Função para preencher os dados da carta com info do usuário
void preencherCarta(Carta *carta, int numero) {
    printf("\n--- Preenchendo Carta %d ---\n", numero);

    printf("Digite o Estado: \n");
    scanf("%s", carta->Estado);

    printf("Digite o codigo da Carta: \n");
    scanf("%s", carta->codigoCarta);

    // Aqui aceita nomes com espaços, lendo até a quebra de linha
    printf("Digite o nome da cidade: \n");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Digite a Populacao: \n");
    scanf("%lu", &carta->populacao);

    printf("Digite a Area (em km²): \n");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em milhões): \n");
    scanf("%f", &carta->pib);

    printf("Digite o numero de pontos turisticos: \n");
    scanf("%d", &carta->NumeroPontosTuristicos);

    // Calculando os atributos derivados
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;

    // Esse é  "super poder" add no nivel aventureio do primeido modulo, que junta vários números
    float inversoDensidade = (carta->densidadePopulacional > 0) ? (1.0 / carta->densidadePopulacional) : 0.0;

    carta->superPoder = carta->populacao + carta->area + carta->pib +
                        carta->NumeroPontosTuristicos + carta->pibPerCapita + inversoDensidade;
}

// Função pra mostrar os dados da carta na tela
void exibirCarta(Carta carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Estado: %s | Código: %s\n", carta.Estado, carta.codigoCarta);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.NumeroPontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função que mostra o menu pro usuário escolher o que comparar e faz a comparação
void menuComparacao(Carta c1, Carta c2) {
    int opcao;

    do {
        printf("\nEscolha o atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Populacional (menor vence)\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        printf("\nComparando %s x %s\n", c1.nomeCidade, c2.nomeCidade);

        switch (opcao) {
            case 1:
                printf("População: %lu x %lu\n", c1.populacao, c2.populacao);
                if (c1.populacao > c2.populacao)
                    printf("%s venceu!\n", c1.nomeCidade);
                else if (c2.populacao > c1.populacao)
                    printf("%s venceu!\n", c2.nomeCidade);
                else
                    printf("Empate!\n");
                break;

            case 2:
                printf("Área: %.2f x %.2f km²\n", c1.area, c2.area);
                if (c1.area > c2.area)
                    printf("%s venceu!\n", c1.nomeCidade);
                else if (c2.area > c1.area)
                    printf("%s venceu!\n", c2.nomeCidade);
                else
                    printf("Empate!\n");
                break;

            case 3:
                printf("PIB: %.2f x %.2f milhões\n", c1.pib, c2.pib);
                if (c1.pib > c2.pib)
                    printf("%s venceu!\n", c1.nomeCidade);
                else if (c2.pib > c1.pib)
                    printf("%s venceu!\n", c2.nomeCidade);
                else
                    printf("Empate!\n");
                break;

            case 4:
                printf("Pontos Turísticos: %d x %d\n", c1.NumeroPontosTuristicos, c2.NumeroPontosTuristicos);
                if (c1.NumeroPontosTuristicos > c2.NumeroPontosTuristicos)
                    printf("%s venceu!\n", c1.nomeCidade);
                else if (c2.NumeroPontosTuristicos > c1.NumeroPontosTuristicos)
                    printf("%s venceu!\n", c2.nomeCidade);
                else
                    printf("Empate!\n");
                break;

            case 5:
                // Aqui a regra é inverter, menor densidade vence
                printf("Densidade Populacional: %.2f x %.2f hab/km²\n", c1.densidadePopulacional, c2.densidadePopulacional);
                if (c1.densidadePopulacional < c2.densidadePopulacional)
                    printf("%s venceu!\n", c1.nomeCidade);
                else if (c2.densidadePopulacional < c1.densidadePopulacional)
                    printf("%s venceu!\n", c2.nomeCidade);
                else
                    printf("Empate!\n");
                break;

            case 0:
                printf("Encerrando comparação...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);
}

int main() {
    Carta carta1, carta2;
    int escolha;

    printf("===== Super Trunfo das Cidades =====\n");
    printf("Escolha a opção:\n");
    printf("1 - Usar cartas já cadastradas\n");
    printf("2 - Cadastrar novas cartas\n");
    printf("Opção: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        // Aqui  já deixei duas cartas cadastradas pra usar sem precisar digitar
        strcpy(carta1.Estado, "SP"); //strcpy é uma função da biblioteca padrão da linguagem C (vem da <string.h>) que copia uma string para outra.
        strcpy(carta1.codigoCarta, "SP001");
        strcpy(carta1.nomeCidade, "São Paulo");
        carta1.populacao = 12300000;
        carta1.area = 1521.11;
        carta1.pib = 750000.0;
        carta1.NumeroPontosTuristicos = 20;

        strcpy(carta2.Estado, "RJ");
        strcpy(carta2.codigoCarta, "RJ001");
        strcpy(carta2.nomeCidade, "Rio de Janeiro");
        carta2.populacao = 6700000;
        carta2.area = 1182.30;
        carta2.pib = 350000.0;
        carta2.NumeroPontosTuristicos = 15;

    } else if (escolha == 2) {
        // Aqui o usuário pode criar as cartas digitando tudo
        preencherCarta(&carta1, 1);
        preencherCarta(&carta2, 2);

    } else {
        printf("Opção inválida! Encerrando programa.\n");
        return 0;
    }

    // Depois de tudo, calculamos os atributos derivados (densidade, PIB per capita e super poder)
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta1.superPoder = carta1.populacao + carta1.area + carta1.pib +
                       carta1.NumeroPontosTuristicos + carta1.pibPerCapita +
                       ((carta1.densidadePopulacional > 0) ? (1.0 / carta1.densidadePopulacional) : 0);

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;
    carta2.superPoder = carta2.populacao + carta2.area + carta2.pib +
                       carta2.NumeroPontosTuristicos + carta2.pibPerCapita +
                       ((carta2.densidadePopulacional > 0) ? (1.0 / carta2.densidadePopulacional) : 0);

    // Mostramos as cartas na tela
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Chamamos o menu de comparação interativo
    menuComparacao(carta1, carta2);

    return 0;
}