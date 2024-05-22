# Preparação para o teste 2

## Dynamic Programming

### Princípio de Otimalidade de Dynamic Programming

**SE UMA SOLUÇÃO É ÓTIMA, QUALQUER PORÇÃO DA MESMA TAMBÉM DEVE SER ÓTIMA, COMPARANDO COM TODAS AS ESCOLHAS POSSÍVEIS PARA ESSA PORÇÃO**

*Corolário* - Se uma solução parcial é subótima, não precisa de ser mais explorada...

* Basicamente, podemos guardar soluções parciais numa **TABELA**, evitando recomputar tudo novamente.

 - A computação deste algorítmo é feito de forma reversa (fim para o início), quanto a recurrência é feita para a frente.

### Construção da tabela

* Começa sempre do fim para o início!!!

* Vai guardando a cada iteração o mínimo do caminho possível para daquele nó chegar ao final.

* Para determinar o caminho mais curto, temos de escolher o valor mais baixo da tabela quando chegamos ao nó inicial.

### Sequência de decisões

  * Se for impossível fazer escolhas ótimas baseadas apenas em escolhas locais - **GREEDY FALHA**
 
  * Se decisões forem interdependentes - **DIVIDE AND CONQUER FAILS**
 
  * Enumerar todas as alternativas possíveis - Evita recomputação, uma vez que guarda tudo numa tabela

**Princípio de ótimalidade aplica-se quando:**

  - Diferentes operações de enumeração partilham sub-problemas
  - Guardar soluções parciais para evitar recomputação
  - Formulação recursiva
  - Cálculo equivale ao preenchimento de uma tabela

### Equação de recurrência

* Primeiro, temos de derivar uma equação de recurrência para o problema.

**Como resolver essa equação:**
  - Identificar casos primitivos para soluções ótimas
  
  - Construir soluções iterativamente utilizando o princípio de otimalidade
  
  - Criar uma tabela e preenche-la usando a equação de recurrência e casos primitivos

### Complexidade Temporal 

* Se não guardassemos os resultados numa tabela, o pior caso, o de exploração de todos os caminhos e nós deria O(V^stages)

* Para o caso de guardarmos todos os resultados numa tabela, a complexidade passa a ser 0(V + E)

* O(V + E) vs O(V^stage)

## Knapsack Problem using Dynamic Programming

* Create a 2D DP table dp where dp[i][w] represents the maximum value that can be obtained using the first i items and with a knapsack capacity of w.

* Para cada item **i** de **1 a n**:

    - Para capacidade **w** de **1 a W**:

        - Se item i não for incluído : "dp[i][w] = dp[i-1][w]"
        - Se item i for incluído : "dp[i][w] = \max(dp[i-1][w], dp[i-1][w-w_i] + v_i)"
     
### Pseudo-polynomial Time Complexity - O(nW)

 * É polinomial em termos de números de items **n** e a capacidade do knapsack **W**

 * Se W for muito grande, o tempo de complexidade pode tornar-se infeasible, mesmo que apareça polinomial

## Longest Common Sub-Sequence (LCS)

<img width="565" alt="Captura de ecrã 2024-05-22, às 13 16 03" src="https://github.com/DiogoSV7/DA-DesenhoAlgoritmos/assets/145665382/f08eb84c-ccef-4991-9dd6-c6201e7e4252">













