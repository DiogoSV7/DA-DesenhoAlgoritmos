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
      - *function* selectActivitiesGreedy( set S, set F)
        - n = size[s];
        - A = {1};
        - j = 1;
        - for i=2 to n do:
          - if (Si >= Fj):
            - A = A U {i};
            - j= i;
        - return A;

### Correctness of Greedy Algorithm

  *Propriedade 1:* Existe sempre uma solução ótima que inicie com a atividade 1.
  *Propriedade 2:* Depois da primeira escolha ser feita, o problema resume-se a encontrar atividades compatíveis com a atividade 1.

  *Conclusão* Greedy Algorithm irá sempre computar uma solução ótima.

### Features de Greedy Approach

  1. Global optimal choice pode ser feita através de escolhas ótimas locais.
  2. Tem subdivisão do problema inicial.
  3. Escolhas podem ser feitas baseadas no critério local sem explorar muitas soluções locais.

### Knapsack Problem Algorithm

  1. Soma de todos os objetos não pode exceder o peso limite "W".
  2. Solução ótima tem de encher o saco inteiro "soma XiWi = W".

  -function fillUpKnapsackGreedy(v,w,W):
  - weight=0;
  - while weight < W do:
      - select element i with max(Vi/Wi)
      - if (Wi + weight <= W) :
          - Xi = 1;
          - weight+=Wi;
      - else:
          - Xi = (W -weight)/Wi; FRACTION OF THE LAST OBJECT TO FIT INTO THE KNAPSACK
          - weight = W;

### Prova por contradição do Knapsack greedy optimality

  1. Vamos deixar o item i ser um item com o valute to weight ratio (v/w). Queremos demonstrar que a solução ótima inclui o máximo de itens i possíveis.
  2. Provamos que esta frase é verdade por contradição. Logo, assumimos que existe uma solução ótima que não tem o máximo de itens i possíveis e também assumimos que o knapsack está cheio.
  3. Como o item i tem o maior (value to weight ratio), tem de existir um item j na nossa knapsack que Vj/Wj < Vi/Wi.
  4. Podemos retirar o item j com peso x da knapsack e inserir o item i com peso x na nossa knapsack.
  5. A troca x será maior que 0, uma vez que Vj/Wj < Vi/Wi.
  6. Deste modo, chegamos a uma contradição, uma vez que partimos do princípio que poderiamos melhorar a nossa solução returando item j e adicionando mais i. Logo, a solução não seria ótima.


### Optimal subproblem Prova por contradição

  1. Assumir que X é a solução ótima para o problema S com value V e knapsack capacity W.
  2. Então, X´ = X -Xj é uma solução ótima para o subproblema S´= S - {j} e knapsack capacity W´= W - Wj.

*Prova*
    - Assumir que X´não é ótima e que existe outra solução para S´.
    - Então, X´´U {Xj} é uma solução para S com valor V´´+ Vj > V´+ Vj = V
    - Logo é uma contradição, uma vez que V é assumido como ótimo.

### Problema: Minimizar o tempo de processamento do sistema

  *Dado um servidor com n clientes, cada um com service time (Ti), minimizar o tempo total para assistir todos os clientes.*

  Greedy Algorithm encontra solução ótima porque vai permutando e encontrando a melhor solução, por exemplo, para o tempo de espera dos hospitais.

### Huffman Codes

Variable length encoding -> menos bits para letras com maior frequência

Àrvore de prefix-free Codes -> permite chegar aos bits de uma letra.
IMPORTANTE : length do código do caracter = profundidade do caracter na àrvore.

### Huffman Codes Algorithm

  - *function* Huffman(C)
  - n = | C |;
  - Q = C; (Construir uma priority queue)
  - for i=1 to n-1 do:
      - z = AllocateNode();
      - x =left[z] = ExtractMin(Q);
      - y = right[z] = ExtractMin(Q);
      - f[z] = f[x] + f[y];
      - insert(Q,z);
   
  *Execution time:* O(n log n)

### Huffman Greedy Prova por Contradição da Otimalidade

  *Teorema:* Existe um prefix-free code para C que os códigos x e y, com menos frequências, têm a mesma length e diferem apenas no último bit.
  
  *Prova por contradição:*
  
      1. Assumir que T é ótimo, mas x e y não têm a mesma code length, ou seja, a sua profundidade na àrvore é diferente.
      2. Então, T teria dois simbolos b e c na sua máxima profundidade
      3. Assumir que f[b] <= f[c] e que f[x]<=f[y]. Como x e y têm frequências menores, podemos afirmar que f[x]<=f[b] e f[y]<=f[c].
      4. Como b e c se encontram na profundidade máxima, dT(b) >= dT(x) e dT(c)>= dT(y). Para além disso, f[b] - f[x] >=0 e dT(b) - dT(x) >=0. (dT é depth of tree)
      5. Deste modo, podemos criar uma árvore T´ trocando as posições x e b na T e outra T´´nas quais trocamos as posições c e y.
      6. Nestas novas àrvores B(T)>= B(T´) e B(T´)>=B(T´´) é uma contradição, uma vez que a árvore T é ótima.

    IMPORTANTE : Esta prova aplica-se apenas a um par de nós, os que têm menor frequências. Para fazermos para o resto dos nós teriamos de utilizar indução.
    
## Maximum Flow Algorithms

### Maximum Flow - Definitions

  - Flow Networks = Directed graph em que cada edge(u,v) tem capacidade c(u,v)>0
  
  - 2 nós especiais = Source *s* e Sink *t*
  
  - Todos os nós pertencem a um caminho de *s* para *t*
  
  - Flow Value = Somatório de f(s,v)

  - Max Flow Prob = Computar o max flow entre *s* e *t*

### Ford-Fulkerson Method

  *Ford-Fulkerson-Method(graph G, node s, node t){*
    - inicializar flow f a 0;
    - while (existir augmenting path P) do:
        - aumentar o flow ao longo de P;
        - atualizar a residual network;
    -return f;

NOTAS: 
  - augmenting path são caminhos que "vão para a frente"
  - residual network é o conceito do path que nós estamos a seguir

### Residual Network

  - Residual capacity = o flow adicional que é possível enviar entre u e v:
       $ Cf(u,v) = C(u,v) - F(u,v);
  - Residual Network de um grafo G = cada edge(residual) do grafo apenas pode ter um flow positivo

### Cuts e Flows numa Flow Network

  $ Liquido Cut Flow - quantidade de flow que pode ser cortado
  $ Cut capacity - Apenas inclui valores positivos de capacity edges

TRUQUE: Desenhando a linha do corte, se a linha apontar para dentro (t) é positivo, se apontar para fora da linha, é negativo

IMPORTANTE: Qualquer valor de flow é upper bounded pela capacidade de qualquer cut em G

### Ford-Fulkerson Basic Algorithm

*Ford-Fulkerson(Graph G, node s, node t){*
  - foreach(u,v) que pertence a G, do:
        - f[u,v] =0;
        - f[v,u]=0;
  - while exists augmen path P numa residual network G do:
        -computar Cf(p):
        -foreach(u,v) que pertence a P do:
            - f[u,v] = f[u,v] + Cf(p)   (aumentar flow value)
            - f[u,v] = f[v,u] - Cf(p)   (aumentar o reverse flow)

### Análise do Basic Algorithm

  Para valores irracionais, cujos computadores não são capazes de utilizar:
    - O algoritmo pode nunca terminar ou pode converger para um valor incorreto.

### Edmonds-Karp Algorithm

OBJETIVO : Encontrar augmenting paths utilizando o shortest path
    
