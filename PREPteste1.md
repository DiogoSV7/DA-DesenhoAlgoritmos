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


# Djikstra´s
