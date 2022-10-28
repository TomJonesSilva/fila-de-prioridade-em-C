#include "pq.h"
#include "stdbool.h"
#include "stdlib.h"
#include <stdio.h>

void Corrige_Descendo(pq A, int n, int i) {
  int j;
  j = i;
  while (2 * j <= n) {
    int f = 2 * j;
    if (f < n && A->v[f] >= A->v[f + 1]) {
      f = f + 1;
    }
    if (A->v[j] <= A->v[f]) {
      j = n;
    } else {
      int troca = A->v[j];
      A->v[j] = A->v[f];
      A->v[f] = troca;
    }
    j = f;
  }
}

void Corrige_Subindo(pq A, int m) {
  int i = m;
  while (i >= 2 && A->v[i] < A->v[i / 2]) {
    int trocar;
    trocar = A->v[i / 2];
    A->v[i / 2] = A->v[i];
    A->v[i] = trocar;
    i = i / 2;
  }
}

pq buildpq(int m) {
  // criando uma nova struct
  struct pq_struct novastruct;
  novastruct.n = 0;
  novastruct.m = m + 1;
  novastruct.v = (int *)malloc(m * sizeof(int));
  pq novo = malloc(sizeof(novastruct));
  *novo = novastruct;

  return novo;
}

int extractmin(pq p) {
  // retorna aposicao 1 da fila
  return p->v[1];
}

void insert(pq p, int x) {
  // atribuindo x a posicao n+1do vetor
  p->v[p->n + 1] = x;

  // reorganizando a fila
  Corrige_Subindo(p, p->n + 1);
  // atualizando o valor de n
  p->n = p->n + 1;
}

void incq(pq p, int k, int x) {
  p->v[k] = x;
  Corrige_Subindo(p, k);
}

void decq(pq p, int k, int x) {
  p->v[k] = x;
  int valor = p->n;
  Corrige_Descendo(p, valor, k);
}

void dumppq(pq p) {
  for (int i = 1; i <= p->n; i++) {
    printf(" %i ", p->v[i]);
  }
}

pq loadpq() {

  FILE *entrada;
  entrada = fopen("dados.in", "r");

  // verificando se o arquivo existe!
  if (entrada == NULL) {
    printf("\narquivo não encontrado!\n");
    getchar();
    exit(0);
  }

  // pegar a primeira linha do arquivo
  int n;
  fscanf(entrada, "%i", &n);

  // criando a fila de prioridades
  pq novo = buildpq(n);

  // lendo o arquivo e adicionando na fila de prioridade
  for (int i = 0; i < n; i++) {
    int x;
    // lendo todas as linhas do arquivo;
    int k = fscanf(entrada, "%i", &x);

    insert(novo, x);
  }
  fclose(entrada);
  return novo;
}

void savepq(pq p) {
  // criando oarquivo de saida
  FILE *saida;
  saida = fopen("heap.out", "w");
  // verificando se o ponteiro não esta vazio
  if (saida == NULL) {
    printf("\n arquivo não encontrado!\n");
    getchar();
    exit(0);
  }
  // colocando a quantidade de inteiros na primeira linha
  fprintf(saida, "%i\n", p->n);
  // escrevendo a fila de prioridade no arquivo
  for (int i = 1; i <= p->n; i++) {
    fprintf(saida, "%i\n", p->v[i]);
  }
  fclose(saida);
}