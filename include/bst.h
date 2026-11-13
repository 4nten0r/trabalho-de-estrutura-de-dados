#ifndef BST_H
#define BST_H

#define TAM_TEXTO 80 /* 79 caracteres uteis + '\0' */

/* Registro do tema: locais urbanos. */
typedef struct {
    int id; /* inteiro positivo unico (> 0) */
    char nome[TAM_TEXTO];
    char categoria[TAM_TEXTO];
    char bairro[TAM_TEXTO];
} LocalUrbano;

/* No da arvore binaria de busca (ordenada pelo id). */
typedef struct NoBST {
    LocalUrbano dado;
    struct NoBST *esq;
    struct NoBST *dir;
} NoBST;

/* Resultado da insercao. */
typedef enum {
    BST_OK,
    BST_DUPLICADO,
    BST_SEM_MEMORIA
} StatusBST;

/* Insere um registro; rejeita ID duplicado. */
StatusBST bst_inserir(NoBST **raiz, const LocalUrbano *local);

/* Busca por ID. Retorna o registro ou NULL se nao existir. */
const LocalUrbano *bst_buscar(const NoBST *raiz, int id);

/* Remove o no com o ID (0, 1 ou 2 filhos). Retorna 1 se removeu, 0 se nao achou. */
int bst_remover(NoBST **raiz, int id);

/* Imprime em-ordem (ID crescente). Retorna a quantidade de registros. */
int bst_listar_em_ordem(const NoBST *raiz);

/* Libera todos os nos e deixa *raiz = NULL. */
void bst_liberar(NoBST **raiz);

#endif
