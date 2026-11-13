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

