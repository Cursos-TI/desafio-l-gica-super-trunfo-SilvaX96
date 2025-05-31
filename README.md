# Super Trunfo das Cidades

## Sobre o Projeto
Este projeto é uma versão estilo "Super Trunfo" usando cidades brasileiras. Cada carta representa uma cidade com diversos atributos como população, área, PIB e pontos turísticos. A ideia é comparar duas cidades com base em dois atributos escolhidos pelo jogador e ver quem vence a rodada!

O jogo roda no terminal e foi feito para praticar conceitos de **structs**, **menus**, **switch**, **if-else**, **operador ternário** e mais.

## Requisitos Atendidos 

### Funcionais:
- Escolha de dois atributos diferentes para comparação.
- Comparação com múltiplos atributos (com exceção para densidade demográfica).
- Soma dos atributos comparados.
- Empates tratados corretamente.
- Menus dinâmicos que impedem repetição de atributos.
- Exibição clara do resultado da rodada.

### Não Funcionais:
- Interface simples e amigável (tudo no terminal com instruções).
- Código com boa performance (comparações rápidas).
- Estrutura organizada, com comentários explicativos.
- Tratamento de erros e entradas inválidas com `if` e `default` nos `switch`.

## Novidades e Melhorias 
- Comentários explicativos em linguagem descontraída e acessível.
- Cidades pré-carregadas: **Campo Grande (MS)** e **Cuiabá (MT)**.
- Simplificação de saídas com símbolos como `km2` e `milhões` em vez de `km²` e `milhões` com unicode (mais fácil pra quem tá começando).
- Lógica clara pra mostrar qual cidade venceu cada atributo.
- Tudo pronto para expandir o jogo com novos recursos!

1. Compile o código com `gcc` ou outra IDE C.
   ```bash
   gcc super_trunfo.c -o super_trunfo
   ./super_trunfo
   ```
2. Escolha se quer usar as cartas pré-cadastradas ou digitar novas.
3. Compare dois atributos e veja quem ganha!

## Possíveis Expansões 
- Várias rodadas com placar.
- Modo multiplayer.
- Salvar/ler cartas de arquivos.
- Interface gráfica futuramente.

## Fim