#include "fila.h"

#include <stdio.h>
#include <stdlib.h>

void fila_iniciar(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int fila_vazia(const Fila *fila) {
    return fila->inicio == NULL;
}

int fila_enqueue(Fila *fila, int id) {
    NoFila *novo = malloc(sizeof(NoFila));

    if (novo == NULL) {
        return 0;
    }

    novo->id = id;
    novo->prox = NULL;

    if (fila->fim == NULL) { /* fila vazia */
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    fila->tamanho++;
    return 1;
}

