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

const LocalUrbano *bst_buscar(const NoBST *raiz, int id) {
    while (raiz != NULL) {
        if (id == raiz->dado.id) {
            return &raiz->dado;
        }
        raiz = (id < raiz->dado.id) ? raiz->esq : raiz->dir;
    }
    return NULL;
}

/* Retorna o no de menor ID da subarvore (o mais a esquerda). */
static const NoBST *menor_no(const NoBST *raiz) {
    while (raiz->esq != NULL) {
        raiz = raiz->esq;
    }
    return raiz;
}

int bst_remover(NoBST **raiz, int id) {
    NoBST *alvo;

    if (*raiz == NULL) {
        return 0;
    }

    if (id < (*raiz)->dado.id) {
        return bst_remover(&(*raiz)->esq, id);
    }
    if (id > (*raiz)->dado.id) {
        return bst_remover(&(*raiz)->dir, id);
    }

    alvo = *raiz;

    if (alvo->esq == NULL) {        /* 0 filhos ou so filho direito */
        *raiz = alvo->dir;
        free(alvo);
    } else if (alvo->dir == NULL) { /* so filho esquerdo */
        *raiz = alvo->esq;
        free(alvo);
    } else {                        /* 2 filhos: usa o sucessor em-ordem */
        const NoBST *sucessor = menor_no(alvo->dir);
        int id_sucessor = sucessor->dado.id;

        alvo->dado = sucessor->dado;
        bst_remover(&alvo->dir, id_sucessor);
    }
    return 1;
}

int bst_listar_em_ordem(const NoBST *raiz) {
    int total;

    if (raiz == NULL) {
        return 0;
    }

    total = bst_listar_em_ordem(raiz->esq);
    printf("ID: %d | Nome: %s | Categoria: %s | Bairro: %s\n",
           raiz->dado.id, raiz->dado.nome, raiz->dado.categoria,
           raiz->dado.bairro);
    total++;
    total += bst_listar_em_ordem(raiz->dir);
    return total;
}

