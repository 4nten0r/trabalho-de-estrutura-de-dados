#ifndef FILA_H
#define FILA_H

#include <stddef.h>

/*
 * Fila dinamica (FIFO) que guarda APENAS IDs inteiros positivos.
 * E independente da BST: aceita IDs repetidos e IDs inexistentes na BST.
 */
typedef struct NoFila {
    int id;
    struct NoFila *prox;
} NoFila;

typedef struct {
    NoFila *inicio;
    NoFila *fim;
    size_t tamanho;
} Fila;

void fila_iniciar(Fila *fila);

int fila_vazia(const Fila *fila);

/* Insere no fim. Retorna 1 se ok, 0 se faltou memoria. */
int fila_enqueue(Fila *fila, int id);

/* Remove do inicio e grava em *id. Retorna 1 se removeu, 0 se a fila estava vazia. */
int fila_dequeue(Fila *fila, int *id);

/* Exibe do inicio ao fim. */
void fila_exibir(const Fila *fila);

/* Libera todos os nos. */
void fila_liberar(Fila *fila);

#endif
