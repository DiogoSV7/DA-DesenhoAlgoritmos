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
       - Cf(u,v) = C(u,v) - F(u,v);
  - Residual Network de um grafo G = cada edge(residual) do grafo apenas pode ter um flow positivo
    

### Cuts e Flows numa Flow Network

  $ Liquido Cut Flow - quantidade de flow que pode ser cortado.
  
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
    - Complexidade do algorítmo é O(E |f*|).

### Edmonds-Karp Algorithm

OBJETIVO : Encontrar augmenting paths utilizando o shortest path

### Análise do Edmonds-Karp Algorithm

Distância de s para u aumenta, no mínimo 2 unidades cada vez que edge(u,v) é critica. Uma edge é crítica se residual capacity de p for a mesma que a edge capacity.

- No limite, distancia entre *s* e *u* não pode ser maior do que |V|-2.
- No máximo, uma edge pode ser no máximo O(V) vezes.
- Existem O(E) pares de vértices.
- Complexidade de Edmonds-Karp é O(V E^2).

### Maximal Bipartite Matching

Undirected graph G = (V,E)

- Basicamente, é o problema das danças dos meninos e meninas que o professor usou
- Maximal Bipartite Matching em G é equivalente a encontrar o máx flow em G´
- Utilizar o método genérico do Ford-Fulkerson algorithm leva a uma complexidade de O(E |f*|)
- A complexidade de maximal bipartite matching é O(V E)

## Minimum Cost Spanning Trees

### Definição de Spanning Tree

* Um grafo undirected é cnectado se para cada par de vértices existe, no mín, um "path" a conectar os 2 vértices.

* Dado um grafo undirected e conectado, a spanning tree é um subset acíclico de edges que conecta todos os vértices no grafo

* Numa spanning tree, o seu custo é a soma de todos os custos associados a cada uma das suas edges

### Minimum Cost Spanning Tree (MST)

É uma spanning tree, cuja soma de todos os pesos das suas edges seja mínimo.

### Brute-Force Algoithm para implementar MST

1. O algoritmo de brute-force trata de primeiro gerar todas as spanning trees possíveis.
2. Para cada uma destas spanning trees calcular o seu custo
3. Selecionar a que tem o menor custo

!!! Não é uma boa approach, uma vez que o número de árvores pode ser muito grande

### Greedy Approach para construir uma MST

- Manter uma subset tree A do grafo G
- Cada aresta (u,v) adicionada a A tem de ser:
      - A U {(u,v)} tem de continuar a ser um subset tree A
      - Não pode criar cíclos, ou seja, é uma safe edge

*ALGORITMO*

  1. Criar um subset vazio;
  2. Enquanto este subset não é uma spanning tree:
       3. Identificar safe edge(u,v);
       4. Adicionar ao subset A
  5. Retornar spanning tree A;

<img width="499" alt="Captura de ecrã 2024-03-02, às 12 39 46" src="https://github.com/DiogoSV7/Resumos-Desenho-de-Algoritmos/assets/145665382/a30e72be-aa60-4bb1-8d4c-17407213bc0c">

### Definições MST

* CUT (S, V-S) - Um *CUT* de um undirected graph é uma partição dos vértices para sets disjuntos de nós

* Se uma aresta atravessar um corte, um dos seus nós tem de ficar em S e outro em V-S

* Um corte contem o set de vértices A, se nenhuma aresta atravessar o corte

* Uma aresta que atravesse o corte com o menor custo, é designada como "aresta leve"

* Uma aresta é "safe edge" se não criar nenhum cíclo

### MST Construction Properties

* MST´s devem verificar 2 propriedades muito úteis:

  1. *Cycle Property* : A aresta mais pesada de um cíclo nunca é utilizada

  2. *Cut Property* : Num corte entre 2 sets, a aresta que os irá ligar é a mais leve
 

### Prova de Otimilidade de MST

*PRESSUPOSTO*
- G é um undirected e connected graph com uma função de peso das arestas w;

*PROVA*

1. Dado que (u,v) atravessa o (S, V-S) a sua adição a A não cria um cíclo, uma vez que tanto u ou v não estão ambos em S ou V-S e o corte contem A.

2. O resultado de adicionar (u,v) a A seria o com menor custo:
3. Se existisse uma aresta (x,y) com menor custo, essa aresta também atrevessaria o corte
4. Deste modo, a àrvore que escolhemos não seria ótima porque existiria uma aresta com menor custo
  
### Kruskal´s Algorithm

*IDEIA PRINCIPAL* : 

1. Começar com cada nó isolado como o seu próprio cluster
2. Escolher a aresta mais leve que ligue 2 clusters
3. Continuar ate |V| -1 arestas são adicionadas

<img width="470" alt="Captura de ecrã 2024-03-02, às 12 53 33" src="https://github.com/DiogoSV7/Resumos-Desenho-de-Algoritmos/assets/145665382/2139801c-f2f6-4406-9971-f4856a40acbd">

### Complexidade Temporal do Kruskal´s Algorithm

* Inicialização : O(E log E) devido ao sort() das suas edges
* Construção : Utilizar listas para representar cada set O(E V)

### Prim´s Algorithm

*IDEIA PRINCIPAL*

* Construir uma MST a partir Root node:
  - Começa com um nó ROOT
  - Expande a árvore, uma aresta de cada vez
  - A cada iteração do algoritmo escolhe a LIGHTEST SAFE EDGE

* Utilizar uma priority queue
* key[v] -> lowest edge weight a conectar v a um nó da árvore
* pred[v] -> precedente de v na árvore

<img width="554" alt="Captura de ecrã 2024-03-02, às 13 00 07" src="https://github.com/DiogoSV7/Resumos-Desenho-de-Algoritmos/assets/145665382/f85f92f8-ac8b-427f-b233-456bacb8f55d">

### Complexidade do Prim´s Algorithm

* Complexidade do algoritmo é O(E log V)

* NÃO EXISTE GRANDE DIFERENÇA ENTRE UTILIZAR KRUSKAL´S OU PRIM´S ALGORITHM

## Shortest Paths

### Variedades de Shortest Path Problems

* SINGLE SOURCE SHORTEST PATH (SSSP):
    - Identificar caminho mais curto entre o nó source S e outro qualquer nó V
 
* SINGLE-DESTINATION SHORTEST PATH:
    - Identificar o caminho mais curto entre qualquer nó V e um nó sink T
 
* SINGLE-PAIR SHORTEST PATHS:
    - Identificar o caminho mais curto entre dois nós U e V
 
* ALL-PAIRS SHORTEST PATHS(APSP´s):
    - Identificar o caminho mais curto entre cada par de nós em V ( cojunto de vértices do grafo ).

### Relaxação de uma aresta

<img width="547" alt="Captura de ecrã 2024-03-02, às 13 07 28" src="https://github.com/DiogoSV7/Resumos-Desenho-de-Algoritmos/assets/145665382/1f2b3ca0-c057-4c8b-95e4-42348af2015f">

!!! A dist[w] não pode aumentar

### Outline do Djikstra´s Algorithm (Greedy Approach)

*IDEIA PRINCIPAL* 

  * Manter um set de nós explorados S, dos quais temos de calcular a shortest path distance de s até u.
  * Inicializar o set S com um ponto S.
  * Distância de (s) =0, a distância de todos os outros pontos é infinita
  * Repetidamente escolher nós unexplored que tenham uma distância mínima e adicioná-los ao set S.
  * Utilizar uma priority queue para refletir a relaxação da aresta mais recente

### Pseudo-Código do Dijkstra´s 

<img width="643" alt="Captura de ecrã 2024-03-03, às 16 59 55" src="https://github.com/DiogoSV7/Resumos-Desenho-de-Algoritmos/assets/145665382/9876c011-7b43-4541-ab9c-aa049db88f3a">

### Complexidade do Dijkstra´s

RESPOSTA : *O((V+E) log V)*

### Ciclos com Pesos Negativos

* Arestas podem apresentar pesos negativos
* Um cíclo pode chegar a uma soma de pontos que tenha um valor negativo
* Se os nós em um ciclo negativo forem alcançáveis através de S, temos de colocar a sua distância a -infinito

!!! Uma vez que o Djikstra´s não consegue lidar com arestas com peso negativo, temos de utilizar o Bellman-Ford-Moore algortihm, que tolera arestas negativas e reporta-as retornando um erro

## Bellman-Ford-Moore Algorithm

* Também é baseado em relaxação de arestas
* Mantém distância associada a cada nó
* COMPLEXIDADE TEMPORAL É MAIOR DO QUE A DE DJIKSTRA´S

### Bellman-Ford-Moore Algorithm Pseudo-Code

<img width="628" alt="Captura de ecrã 2024-03-03, às 17 05 46" src="https://github.com/DiogoSV7/Resumos-Desenho-de-Algoritmos/assets/145665382/082aa4c0-3369-443f-8c96-0a7d9ac83e58">

!!! INICIALIZE SINGLE SOURCE É UM BOCADO PARECIDO COM O OUTRO

<img width="622" alt="Captura de ecrã 2024-03-03, às 17 07 24" src="https://github.com/DiogoSV7/Resumos-Desenho-de-Algoritmos/assets/145665382/970668c7-bddd-4eeb-ade9-728da4c608a1">




