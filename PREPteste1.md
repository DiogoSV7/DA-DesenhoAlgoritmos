# Brute-Force Approach ( DESCRIÇÃO DO TESTE )


You will need to reason about the use of the Brute-Force approach in the development of an algorithm, in particular, derive a simple pseudo-code implementation and determine its asymptotic complexity for a selected choice of a data structure.



## Razões para utilizar uma approach Brute-Force


1. O algorítmo é simples e a sua correção é trivialmente establecida

2. Como o seu domínio é explorado, a sua otimalidade é geralmente garantida



- Não há inteligência na implementação.
- Utiliza computer power e não inteligência.

  

## Temos de criar um pseudo-code para um algorítmo de Brute-Force


* Podemos complementar o nosso pseudo-code com texto escrito, mas deve ser detalhado e facilmente traduzível para código
* Para além disto, devemos dizer a complexidade temporal para uma determinada estrutura de dados


## Nota de complexidade assintótica


* Provavelmente, iremos obter um algoritmo exponencial, logo, este tipo de algoritmo apenas se torna viável para problemas pequenos.


* Devemos pensar hibridamente:
    - Pequenos problemas : Utilizar Brute-Force
    - Grandes problemas : Polinomial ou até melhor
 

<img width="318" alt="Captura de ecrã 2024-03-06, às 16 55 45" src="https://github.com/DiogoSV7/Resumos-Desenho-de-Algoritmos/assets/145665382/ab6e2c18-9c41-445c-bc55-378f5c6d26c9">

## Utilização do Brute-Force em criação de Minimum Spanning Trees

  1. O algoritmo de brute-force trata de primeiro gerar todas as spanning trees possíveis.

  2. Para cada uma destas spanning trees calcular o seu custo

  3. Selecionar a que tem o menor custo

!!! Não é uma boa approach, uma vez que o número de árvores pode ser muito grande


# Greedy Algorithms 

## 2 Propriedades de uma Optimal Greedy Choice e uma Solução Ótima para um subproblema

**Propriedade 1:**  Existe sempre uma solução ótima que inicie com a atividade 1.

**PROVA:**

  - Assumir que **A** é uma solução ótima que inicia com uma atividade nº **k**
  - Podemos definir **B** = **A** - {**k**} U {1}
  - Uma vez que ***f1** <= **fk** e **f1** <= **sj**, para qualquer **j**!=**k**
  - Assim a atividade 1 é compatível com outras atividades que não **k**
  - Como **B** e **A** são mutualmente disjuntas, ou seja podemos trocar **k** por **1**
  - **B** também é solução ótima

**Propriedade 2:**  Depois da primeira escolha ser feita, o problema resume-se a encontrar atividades compatíveis com a atividade 1.

**PROVA:**

  - Assumir que **A** é uma solução ótima que começa com a atividade 1
  - Então tem existir uma solução ótima para **S**, na qual **si** >=**f1**;


* Não temos de saber como provar, porém, temos de conseguir demonstrar que estas propriedades existem em algoritmos pre-determinado ou um sample algorithm fornecido no teste

## Prova de Correção do Greedy Algorithm 

**1 -PODE-SE CHEGAR A UMA SOLUÇÃO ÓTIMA GLOBAL, INDO PELAS SOLUÇÕES ÓTIMAS LOCAIS**

**2 - SOLUÇÃO ÓTIMA PARA O PROBLEMA CONTEM SOLUÇÃO ÓTIMA PARA OS SUB-PROBLEMS**

## Fractional Knapsack e Como este determina uma solução ótima

**IMPORTANTE** - Greedy algorithm **NÃO FORNECE** uma solução ótima para o **INTEGER KNAPSACK**. Este algoritmo é feito através de dynamic programming.

**PORQUÊ**:
  - Basicamente, como é necessário que a knapsack fique completamente cheia, e no integer knapsack, a bolsa apenas pode ter itens inteiros. **NÃOO** podemos garantir que exista um subconjunto de itens que complete completamente a saca


**IMPORTANTE** - Greedy Algorithm **FORNECE** uma solução ótima para **FRACTIONAL KNAPSACK**

**PORQUÊ**:
  - Ao sermos capazes de inserir porções de itens, ao contrário de termos necessariamente de inserir um item inteiro, podemos garantir que o item com o maior ratio de valor/peso será inserido no espaço que sobra, que não é capaz de suportar um item inteiro. Deste modo, a solução ótima estará sempre garantida

**IMPORTANTE** - No teste temos de ser capazes de receber um exercício de Fractional Knapsack e ser capazes de determinar o outcome do algorítmo na sequência de itens selecionados

## Greedy Approach a construir uma MST

  1. Manter um subset da árvore **A** do grafo **G**
  2. Identificar a **edge(u,v)** que adicionada  a **A** ainda seja:
       - A união de **A** com a edge ainda seja um subset de **A**
       - Não crie nenhum cíclo, ou seja, seja uma **safe edge**


## Minimum-Cost Spanning Tree Algos ( PRIM E KRUSKAL )

**O QUE TEMOS DE SABER :**

 - A complexidade temporal das suas implementações (PRIM E KRUSKAL)
 - Exemplos dos seus usos em grafos restritos

**Complexidade do PRIM :** O(E log V) 
  - Para cada aresta O(E) existe um "pior caso" um update com o custo O(log V)

<img width="554" alt="Captura de ecrã 2024-03-02, às 13 00 07" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/c07a8a87-95d9-4b08-bba4-a0d1fa9c30fc">

**Complexidade do KRUSKAL :** O(E log E)

<img width="470" alt="Captura de ecrã 2024-03-02, às 12 53 33" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/282c4994-8cf8-4360-a01b-f4b031efcc48">

 * **KRUSKAL´S Algorithm** - baseado em clusters e unir 2 cluters diferentes através da aresta mais leve
     - Utiliza listas para representar os sets : O(E V)
     - A sua complexidade temporal também depende muito da implementação de disjoint sets, que é a melhor estrutura de dados para um melhor desempenho do algorítmo, os disjoint sets permitem facilmente juntar 2 nós e formar um componente novo.

 * **PRIM´S Algorithm** - algoritmo começa com um nó "root", expande a árvore uma aresta de cada vez, a cada iteração escolhe a aresta mais leve
     - Utiliza um priority queue;
     - key[v] - aresta mais leve a conectar v a um nó na árvore
     - pred[v] - predecedor de v na árvore
  
## Usos importantes destes 2 Algorítmos em restricted graphs

* Planeamento de Rotas

* Gerenciamento da Network na presença de Falhas 

## Princípios da Construção de MST

* MST´s devem verificar 2 propriedades muito úteis:

  1. *Cycle Property* : A aresta mais pesada de um cíclo nunca é utilizada.

  2. *Cut Property* : Num corte entre 2 sets, a aresta que os irá ligar é a mais leve.

* Se adicionarmos **uma** edge a uma árvore e criarmos, exatamente, um cíclo, podemos remover qualquer uma daquelas arestas e eliminarmos uma árvore.
 
* Estas duas propriedades formam a base para todos os greedy algorithms de criação de MST´s.

<img width="499" alt="Captura de ecrã 2024-03-02, às 12 39 46" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/8c460c18-0c95-4bb8-982c-4a9d5ce496f9">

## Prova de Otimilidade de MST

*PRESSUPOSTO*
- G é um undirected e connected graph com uma função de peso das arestas w;

*PROVA*

1. Dado que (u,v) atravessa o (S, V-S) a sua adição a A não cria um cíclo, uma vez que tanto u ou v não estão ambos em S ou V-S e o corte contem A.

2. O resultado de adicionar (u,v) a A seria o com menor custo:

3. Se existisse uma aresta (x,y) com menor custo, e essa aresta também atrevessasse o corte

4. Deste modo, a àrvore que escolhemos não seria ótima porque existiria uma aresta com menor custo


**QUESTÃO EXISTENCIAL** - É necessário utilizar uma priority queue se todas as arestas tiverem o mesmo peso?


# Djikstra´s Algorithm 

<img width="650" alt="Captura de ecrã 2024-03-09, às 18 28 06" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/2759cc6d-d27a-4dd0-85da-9680fa1e92ed">

**PROBLEMA** - Djikstra´s pode não funcionar se a árvore tiver pesos negativos.

**PORQUE É QUE O DJIKSTRA PRODUZ SEMPRE UMA SOLUÇÃO ÓTIMA PARA O SHORTEST PATH?** - 

* Através de uma greedy approach, apenas selecionando o nó mais próximo da fonte atual, asseguramos que a cada iteração do algorítmo conseguimos extender o caminho mais curto encontrado até agora.

* Para além disto, através da relaxação constante de arestas, podemos ter a certeza que estamos a tomar o caminho mais curto, podendo alterá-lo se encontrarmos uma nova opção através da relaxação de arestas

## Aplicação do Dijkstra´s em DAG´s ou grafos com peso de arestas restrito

**USO EM DAGS** - Assegurando que não existem cíclos, existe uma maior facilidade em desenvolver algorítmos para encontrar o caminho mais curto. Por exemplo, numa topological source, é preferível utilizar este método do que o djikstra, podendo também o grafo ser muito denso.

**ARESTAS COM PESO RESTRITO** - Em grafos em que possam existir restrições quanto ao peso das arestas, é perferível utilizar, por exemplo, um BFS, como todas as arestas têm o mesmo peso, BFS assegura que encontramos o caminho mais curto, de uma maneira mais eficiente. Logo, este caso especial, de certa forma, torna o dijkstra inútil.

# Bellman-Ford Algorithm

* Também é baseado na relaxação de arestas

* Mantem distância associada com cada nó

<img width="637" alt="Captura de ecrã 2024-03-09, às 18 47 32" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/62d312ce-5d54-4e6d-9847-7968f62d0ec9">


## Aplicabilidade no contexto de grafos com arestas que têm peso negativo

* Basicamente, para todas as arestas, vamos fazer uma relaxação. Depois dessa relaxação se, conseguirmos encontrar um caminho mais curto, significa que estamos na presença de arestas negativas

**SE EXISTIREM CÍCLOS NEGATIVOS** - Se o algorítmo encontrar um cíclo negativo retorna falso, dizendo que não existe um shortest path

* Consegue detetar a presença de cíclos negativos, porém, não consegue produzir o caminho mais curto se estes estiverem presentes

# All-Pairs Shortest Path. Utilizando Bellman-Ford e Dijkstra

 * Johnson´s algorithm baseia-se em reescrever as arestas

 * Ou seja, se todas as arestas tiverem tiverem pesos positivos, usamos Dijkstra

## Simple Edge Weight Reassignment

Não podemos apenas adicionar o complemento para cada aresta, pois, se o fizessemos, os caminhos mais longos que seriam curtos, seriam multiplamente penalizados, podendo deixar de se considerar os mais curtos

**!! Utilizamos a Edge Reweighting do Johnson´s**

## Edge Reweighting

<img width="649" alt="Captura de ecrã 2024-03-10, às 09 46 18" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/365256f6-0e2c-4987-aa62-09a69a35e047">

* O peso da aresta passa a ser : **w** (PESO ORIGINAL) + **h(u)** (shortest path ao ponto de origem da aresta) - **h(v)** (shortest path até ao ponto destino da aresta utilizando w)


**!! É importanto saber que a shorter path w, será um shortest path com w´(caminho com edge reweighting)**

**Existe um cíclo com peso negativo em w, se e só se existir também um cíclo com peso negativo em w´**

<img width="640" alt="Captura de ecrã 2024-03-10, às 09 57 07" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/606a992a-383f-4550-a934-290df2f9f83c">

## Complexidade : 

* Bellman-Ford-Moore : O(V E)

* Dijkstra para ca nó : O( V (V+E) log V)

* TOTAL : O(V(V+E) log V)

# Max-Flow Algorithms

* Para estes algorítmos temos de ignorar self-loops e arestas múltiplas

## Multiple Sources e Sinks

* Para este tipo de redes, temos de definir uma **SUPER-SOURCE** e um **SUPER SINK**

* Entre estas super-sources e os sinks ou sorces, estes podem fornecer uma quantidade ilimitada.

## Maximum Flows Definições

* Um **flow network** é um grafo direcionado com arestas com pesos positivos

<img width="617" alt="Captura de ecrã 2024-03-10, às 10 04 17" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/80146347-ec0d-466d-b531-57d79d4ef620">


## Cálculo do minimum cut capacity

* Fazemos cortes nas arestas. Se arestas forem para o lado do sink são adicionadas ao valor do cut, se forem para o lado da source não acontece nada, ou seja, não subtrai ao valor do cut

* **MINIMUM CUT  = MAX FLOW**

## Ford-Fulkerson Max Flow Algorithm

<img width="639" alt="Captura de ecrã 2024-03-10, às 10 09 05" src="https://github.com/DiogoSV7/DA---DesenhoAlgoritmos/assets/145665382/eb95c7df-2f4e-4a4b-902d-8047928a5157">

* Este algorítmo vai sempre encontrando caminhos até chegar ao sink, até deixarem de existir paths que levem até ao sink (augmenting paths)

## Análise da Complexidade para valores racionais de Capacidades das arestas

* Convertemos as capacidades para inteiros através de scalling

* Nº de augmenting paths é : | f* | (valor limitado pelo max flow)

* **COMPLEXIDADE** : O(E |f*|)

## Análise de Complexidade para valores iracionais de Capacidades de arestas

* Para valores irracionais o algorítmo pode nunca terminar

* Aliás, pode terminar e levar-nos a um valor errado

## Edmonds-Karp

**COMPLEXIDADE DESTE ALGORITMO : O(V E^2)**

* Este algorítmo utiliza uma BFS para identificar o caminho mais curto, uma vez que cada aresta tem distância 1

* Uma edge (u,v) num gráfico residual, é **crítica** se a capacidade residual de p for o mesmo que a capacidade da aresta

* No máximo dos máximos, uma aresta pode ser crítica O(V) vezes

# Maximal Bipartite Matching

**BIPARTITE MATCHING** - Num grafo bipartido, os vértices podem ser divididos em 2 sets disjuntos, nos quais não existem arestas que unam 2 vértices dentro do mesmo set. Uma bipartite matching é um subset de arestas, nas quais nenhuma delas partilham um vértice em comum.

**MAXIMAL BIPARTITE MATCHING** - é uma bipartite matching só que não pode ser mais expandida

* Para encontrar o maximal bipartite matching podemos utilizar o algorítmo do max-flow

* Ao utilizar o Ford-Fulkerson algorítmo leva a uma complexidade de O(E |f*|)

* Ou seja, criar uma super-source e um super-sink com distâncias 1

* Depois apenas conectar apenas os do meio, desde que nenhum destes vértices esteja ligado a um do outro set

# Divide and Conquer 

<img width="814" alt="Captura de ecrã 2024-03-10, às 15 11 49" src="https://github.com/DiogoSV7/DA-DesenhoAlgoritmos/assets/145665382/5f152e20-4d5c-4160-b040-2b77cc75d4d5">

## Recurrence de MergeSort

* A invocação do MergeSort cria uma árvore com **log n** níveis

* A cada nível temos de chamar o merge que cresce linearmente a cada nível

* A **recurrence T(n) = 2 T(n/2) + c n**

* **SOLUÇÃO É: T(n) = k(n log n)**

## Recurrence das Hanoi Towers

* **Hanoi(n,A,B,C)** - Mover n discord de A para B utilizando C como temporário

* Definição recursiva das Torres de Hanoi :

  - **Hanoi(n,A,B,C) = Hanoi(n-1,A,C,B) + Hanoi(1,A,B,C) + Hanoi(n-1,C,B,A)**

<img width="626" alt="Captura de ecrã 2024-03-10, às 15 22 52" src="https://github.com/DiogoSV7/DA-DesenhoAlgoritmos/assets/145665382/77ecde77-8fef-436f-99f3-4198b50f4ad6">

 
<img width="636" alt="Captura de ecrã 2024-03-10, às 15 21 59" src="https://github.com/DiogoSV7/DA-DesenhoAlgoritmos/assets/145665382/07a58d5e-01ff-454e-aaf6-d619d18eea99">

## Recurrence 

* Recurrence é uma relação que define uma sequência baseada numa regra que dá o próximo termo baseando-se no termo passado.

* Funciona como recursão basicamente

* Temos de ter um caso base

* E a chamada da recursão deve reduzir o problema até que ele acabe por alcançar o caso base

<img width="631" alt="Captura de ecrã 2024-03-10, às 15 26 38" src="https://github.com/DiogoSV7/DA-DesenhoAlgoritmos/assets/145665382/00e5d355-a077-46d2-9cba-82b7499e56bc">

<img width="646" alt="Captura de ecrã 2024-03-10, às 15 28 27" src="https://github.com/DiogoSV7/DA-DesenhoAlgoritmos/assets/145665382/bcdb2bd1-dea3-4269-9716-4f79f35133bf">


* STILL INCOMPLETE...




