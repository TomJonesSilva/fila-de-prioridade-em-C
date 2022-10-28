#include <stdio.h>

// Representa uma fila de prioridades
// com espaço máximo para m itens.
struct pq_struct {
   int m; // Número máximo de itens
   int n; // Posição do último item presentemente armazenado
   int *v;
};

typedef struct pq_struct *pq;

// Constroi uma nova fila de prioridades
// com espaço disponível m.
pq buildpq (int m);

// Extrair o menor valor armazenado na
// fila de prioridades p, e devolve esse
// valor. Assume que a fila não está
// vazia
int extractmin (pq p);

// Insere x na fila de prioridades p.
// Assume que a fila não está cheia.
void insert (pq p, int x);

// Aumenta o valor na posição k da fila
// de prioridades p para um novo e maior
// valor x. Assume que k é uma posição
// válida.
void incq (pq p, int k, int x);

// Diminui o valor na posição k da fila
// de prioridades p para um novo e menor
// valor x. Assume que k é uma posição
// válida.
void decq (pq p, int k, int x);

// Imprime o conteúdo de uma fila de prioridades.
void dumppq (pq p);


// Lê uma sequência de inteiros de um arquivo
// de números inteiros chamado "dados.in",
// contendo na primeira a quantidade de inteiros,
// e na sequência um inteiro por linha.
// Devolve uma fila de prioridades contendo esses
// inteiros.
pq loadpq ();

// Grava o conteúdo do heap pq em um arquivo nomeado
// "heap.out", contendo na primeira linha a
// quantidade de elementos no heqp, e nas linhas
// seguintes o conteudo do heap, um número por linha,
// da posição 1 até a última.
void savepq (pq p);