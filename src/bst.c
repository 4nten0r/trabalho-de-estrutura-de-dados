#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

StatusBST bst_inserir(NoBST **raiz, const LocalUrbano *local) {
    NoBST *novo;

    /* Desce ate achar a posicao livre (ou o ID repetido). */
    while (*raiz != NULL) {
        if (local->id == (*raiz)->dado.id) {
            return BST_DUPLICADO;
        }
        raiz = (local->id < (*raiz)->dado.id) ? &(*raiz)->esq : &(*raiz)->dir;
    }

    novo = malloc(sizeof(NoBST));
    if (novo == NULL) {
        return BST_SEM_MEMORIA;
    }

    novo->dado = *local;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;
    return BST_OK;
}

