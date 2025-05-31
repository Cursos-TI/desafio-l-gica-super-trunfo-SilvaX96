#include <stdio.h>
#include <string.h>

#include <stdio.h>
#include <string.h>

// Struct pra guardar os dados de cada cidade (a famosa carta do Super Trunfo)
typedef struct {
    char Estado[50];                  // Estado da cidade (tipo SP, RJ, etc.)
    char codigoCarta[50];            // Um código pra identificar a carta
    char nomeCidade[100];           // Nome da cidade (ex: São Paulo)
    unsigned long int populacao;    // População da cidade
    float area;                      // Área em km²
    float pib;                       // Produto Interno Bruto da cidade (em milhões)
    int NumeroPontosTuristicos;     // Quantidade de pontos turísticos
    float densidadePopulacional;    // Habitantes por km² (calculado depois)
    float pibPerCapita;             // PIB por pessoa (calculado também)
    float superPoder;               // Um valor final que representa a “força” da carta
} Carta;

// Função que calcula os valores derivados (coisas que dependem dos dados principais)
void calcularDerivados(Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
    float invDens = (c->densidadePopulacional > 0) ? (1.0 / c->densidadePopulacional) : 0.0;
    c->superPoder = c->populacao + c->area + c->pib + c->NumeroPontosTuristicos + c->pibPerCapita + invDens;
}

// Função pra preencher os dados de uma carta manualmente
void preencherCarta(Carta *carta, int numero) {
    printf("\n--- Preenchendo Carta %d ---\n", numero);

    printf("Digite o Estado: \n");
    scanf("%s", carta->Estado);

    printf("Digite o codigo da Carta: \n");
    scanf("%s", carta->codigoCarta);

    printf("Digite o nome da cidade: \n");
    scanf(" %[^\n]", carta->nomeCidade);
 // Lê até a próxima aspa

    printf("Digite a Populacao: \n");
    scanf("%lu", &carta->populacao);

    printf("Digite a Area (em km²): \n");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em milhões): \n");
    scanf("%f", &carta->pib);

    printf("Digite o numero de pontos turisticos: \n");
    scanf("%d", &carta->NumeroPontosTuristicos);

    calcularDerivados(carta); // Já manda calcular os derivados
}

// Função pra mostrar na tela os dados da carta bonitinha
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

// Função show pra comparar dois atributos escolhidos pelas cartas
void menuComparacaoAvancada(Carta c1, Carta c2) {
    int primeiroAtributo, segundoAtributo;

    // Escolha do primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo pra comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    printf("Opção: ");
    scanf("%d", &primeiroAtributo);

    // Escolha do segundo (não pode ser o mesmo do primeiro)
    printf("\nEscolha o SEGUNDO atributo pra comparar:\n");
    for (int i = 1; i <= 5; i++) {
        if (i != primeiroAtributo) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Populacional (menor vence)\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &segundoAtributo);

    // Coloca os valores numa array pra facilitar a vida
    float valoresC1[6] = {0, c1.populacao, c1.area, c1.pib, c1.NumeroPontosTuristicos, c1.densidadePopulacional};
    float valoresC2[6] = {0, c2.populacao, c2.area, c2.pib, c2.NumeroPontosTuristicos, c2.densidadePopulacional};

    float soma1 = 0, soma2 = 0;

    printf("\nComparando %s vs %s\n", c1.nomeCidade, c2.nomeCidade);

    // Loop pra comparar os dois atributos escolhidos
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? primeiroAtributo : segundoAtributo;
        float v1 = valoresC1[atributo];
        float v2 = valoresC2[atributo];

        const char *nome;
        switch (atributo) {
            case 1: nome = "População"; break;
            case 2: nome = "Área"; break;
            case 3: nome = "PIB"; break;
            case 4: nome = "Pontos Turísticos"; break;
            case 5: nome = "Densidade Populacional"; break;
            default: nome = "Desconhecido"; break;
        }

        printf("\nAtributo: %s\n", nome);
        printf("%s: %.2f | %s: %.2f\n", c1.nomeCidade, v1, c2.nomeCidade, v2);

        if (atributo == 5) {
            // Densidade populacional: quanto menor, melhor!
            if (v1 < v2) printf("%s venceu esse atributo!\n", c1.nomeCidade);
            else if (v2 < v1) printf("%s venceu esse atributo!\n", c2.nomeCidade);
            else printf("Empate nesse atributo!\n");
        } else {
            // Nos outros atributos, maior é melhor
            if (v1 > v2) printf("%s venceu esse atributo!\n", c1.nomeCidade);
            else if (v2 > v1) printf("%s venceu esse atributo!\n", c2.nomeCidade);
            else printf("Empate nesse atributo!\n");
        }

        soma1 += v1;
        soma2 += v2;
    }

    // Resultado final da comparação
    printf("\nSOMA DOS ATRIBUTOS:\n");
    printf("%s: %.2f\n", c1.nomeCidade, soma1);
    printf("%s: %.2f\n", c2.nomeCidade, soma2);

    if (soma1 > soma2)
        printf("\n%s venceu a rodada!\n", c1.nomeCidade);
    else if (soma2 > soma1)
        printf("\n%s venceu a rodada!\n", c2.nomeCidade);
    else
        printf("\nEmpate!\n");
}

// Função principal: a entrada do jogo!
int main() {
    Carta carta1, carta2;
    int escolha;

    printf("===== Super Trunfo das Cidades (Avançado) =====\n");
    printf("Escolha a opção:\n");
    printf("1 - Usar cartas já cadastradas\n");
    printf("2 - Cadastrar novas cartas\n");
    printf("Opção: ");
    scanf("%d", &escolha);

     if (escolha == 1) {
        // Cartas Prontas!!
        // Campo Grande (MS)
        strcpy(carta1.Estado, "MS");
        strcpy(carta1.codigoCarta, "MS001");
        strcpy(carta1.nomeCidade, "Campo Grande");
        carta1.populacao = 916001;
        carta1.area = 8096.0;
        carta1.pib = 26300.0;
        carta1.NumeroPontosTuristicos = 12;

        // Cuiabá (MT)
        strcpy(carta2.Estado, "MT");
        strcpy(carta2.codigoCarta, "MT001");
        strcpy(carta2.nomeCidade, "Cuiabá");
        carta2.populacao = 618124;
        carta2.area = 3538.0;
        carta2.pib = 21600.0;
        carta2.NumeroPontosTuristicos = 10;
    } else if (escolha == 2) {
        preencherCarta(&carta1, 1);
        preencherCarta(&carta2, 2);
    } else {
        // Deu ruim na escolha
        printf("Opção inválida!\n");
        return 0;
    }

    // Calcula os derivados das cartas
    calcularDerivados(&carta1);
    calcularDerivados(&carta2);

    // Mostra as cartas completas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Manda ver na comparação
    menuComparacaoAvancada(carta1, carta2);

    return 0;
}