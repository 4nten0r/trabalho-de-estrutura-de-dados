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

int fila_dequeue(Fila *fila, int *id) {
    NoFila *removido;

    if (fila_vazia(fila)) {
        return 0;
    }

    removido = fila->inicio;
    *id = removido->id;
    fila->inicio = removido->prox;
    if (fila->inicio == NULL) { /* ficou vazia */
        fila->fim = NULL;
    }
    free(removido);
    fila->tamanho--;
    return 1;
}

void fila_exibir(const Fila *fila) {
    const NoFila *atual;

    printf("Inicio -> ");
    for (atual = fila->inicio; atual != NULL; atual = atual->prox) {
        printf("%d -> ", atual->id);
    }
    printf("Fim\n");
}

void fila_liberar(Fila *fila) {
    int descartado;

    while (fila_dequeue(fila, &descartado)) {
        /* cada dequeue libera um no */
    }
}
