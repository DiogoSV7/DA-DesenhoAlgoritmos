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


## Fractional Knapsack e Como este determina uma solução ótima

**IMPORTANTE** - Greedy algorithm **NÃO FORNECE** uma solução ótima para o **INTEGER KNAPSACK**. Este algoritmo é feito através de dynamic programming.

**PORQUÊ**:
  - Basicamente, como é necessário que a knapsack fique completamente cheia, e no integer knapsack, a bolsa apenas pode ter itens inteiros. **NÃOO** podemos garantir que exista um subconjunto de itens que complete completamente a saca


**IMPORTANTE** - Greedy Algorithm **FORNECE** uma solução ótima para **FRACTIONAL KNAPSACK**

**PORQUÊ**:
  - Ao sermos capazes de inserir porções de itens, ao contrário de termos necessariamente de inserir um item inteiro, podemos garantir que o item com o maior ratio de valor/peso será inserido no espaço que sobra, que não é capaz de suportar um item inteiro. Deste modo, a solução ótima estará sempre garantida

**IMPORTANTE** - No teste temos de ser capazes de receber um exercício de Fractional Knapsack e ser capazes de determinar o outcome do algorítmo na sequência de itens selecionados

## Minimum-Cost Spanning Tree Algos ( PRIM E KRUSKAL )

**O QUE TEMOS DE SABER :**

 - A complexidade temporal das suas implementações
 - Exemplos dos seus usos em grafos restritos

   
