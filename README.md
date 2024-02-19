# Resumos-Desenho-de-Algoritmos

## Brute Force Algorithms

  - Aprroach direta à resolução de problemas.
  - Não há inteligência na implementação.
  - Utiliza computer power e não inteligência.

### Traveling Salesman Problem (TSP)

  1. Encontrar o caminho mais curto através de um set de n cidades que visita.
     todas as cidades, exatamente uma vez, antes de regressar a casa.
  2. Pode ser modelado com weighted graphs, vertices são as cidades e edge weights sao distâncias.
  3. O mesmo que encontrar um Circuito Hamiltoniano, ou seja, encontrar um ciclo que passe por todos os vértices 1 vez.

### Exhausive Search: TSP

  Hamiltonian circuit : sequência de n+1 vértices adjacentes.
  Solução : Derivar todas as tours geradas pelas (n-1) permutações e encontrar o caminho mais curto.

### Knapsack Problem

  1. Dados n itens com weights w1, w2, ..., wn
  2. Com valores v1, v2, ..., vn
  3. E um saco com capacidade W
  4. Encontrar o subset de itens mais importantes que cabem no saco e não excedam a sua capacidade

  Solução : Gerar todos os subsets dos n itens, verificar os seus pesos e encontrar o subset com o maior valor
  Eficiência : 2^n

### Knapsack Problem (Alternative Algorithmic Strategy)

  1. Pegar em itens em ordem decrescente de value/weight.
  2. Tentar inserir no espaço restante do saco.
  3. Sortear todos os itens e depois pegar neles linearmente até caberem no saco.

  Eficiência : n log n

  SLIDES: TÊM IMAGENS COM EXEMPLOS DESTES PROBLEMAS

### Exhaustive Search at Large

  - Traveling Salesman and Knapsack problem:
      Exaustive search leva a tempo exponencial de complexidade.
  - São problemas NP-hard ( no known polynomial-time algorithms)

### Nota sobre Complexidade no Brute Force

  - Pensar "híbrido"
      Small problems -> Brute-Force
      Large problems -> Polynomial (ou melhor)

## Greedy Algorithms

    - Minimização de tarefas do sistema
    - Knapsack e Huffman codes examples

### Técnicas de Sintetizar Algoritmos

  1. Divide and Conquer -> divir em sub-problems mais pequenos
  2. Dynamic programming -> combinação entre DaC e uso de tabelas para evitar recomputação de sub-problemas
  3. Greedy Algorithms -> A cada iteração do algoritmo, escolher a opção local melhor para encontrar a solução ótima

### Exemplo de Seleção de Atividades

  S = {1,2,...,n} set de atividades que partilham um recurso comum

  - Atividade "i" é caracterizada por:
    1. Start time : Si
    2. Finish time : Fi
    3. Intervalo de execução da atividade:[Si, Fi[

  Objetivo : Encontrar o set Máximo de atividades que são mutuamente compatíveis

SLIDES : TÊM IMAGENS A MOSTRAR ESTE ALGORITMO

### Seleção de Atividades com Greedy Choice

  Objetivo : Selecionar atividade com menor finish time Fk (maximizar tempo para as restantes atividades)

  Pseudo-Code:
      *function* selectActivitiesGreedy( set S, set F)
        n = size[s];
        A = {1};
        j = 1;
        for i=2 to n do:
          if (Si >= Fj):
            A = A U {i};
            j= i;
        return A;











