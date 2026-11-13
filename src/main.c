#include <stdio.h>
#include <string.h>

#include "bst.h"
#include "fila.h"
#include "validacao.h"

static void exibir_menu(void) {
    printf("====\n");
    printf("SISTEMA DE ESTRUTURA DE DADOS\n");
    printf("1- Cadastrar registro na BST\n");
    printf("2- Buscar registro por ID na BST\n");
    printf("3- Remover registro da BST\n");
    printf("4- Listar registros em-ordem\n");
    printf("5- Inserir ID na estrutura linear\n");
    printf("6- Remover da estrutura linear\n");
    printf("7- Exibir estrutura linear\n");
    printf("0- Encerrar\n");
}

static void imprimir_local(const LocalUrbano *local) {
    printf("ID: %d | Nome: %s | Categoria: %s | Bairro: %s\n",
           local->id, local->nome, local->categoria, local->bairro);
}

static void cadastrar_na_bst(NoBST **raiz) {
    LocalUrbano local;
    int id;

    memset(&local, 0, sizeof(local));

    if (ler_id("Informe o ID: ", &id) != LEITURA_OK) {
        return;
    }
    if (bst_buscar(*raiz, id) != NULL) {
        printf("Erro: ja existe um registro com o ID %d.\n", id);
        return;
    }
    local.id = id;

    if (ler_texto("Nome: ", local.nome, TAM_TEXTO) != LEITURA_OK ||
        ler_texto("Categoria: ", local.categoria, TAM_TEXTO) != LEITURA_OK ||
        ler_texto("Bairro: ", local.bairro, TAM_TEXTO) != LEITURA_OK) {
        return;
    }

    switch (bst_inserir(raiz, &local)) {
        case BST_OK:
            printf("Registro cadastrado com sucesso.\n");
            break;
        case BST_DUPLICADO:
            printf("Erro: ja existe um registro com o ID %d.\n", id);
            break;
        case BST_SEM_MEMORIA:
            printf("Erro: memoria insuficiente.\n");
            break;
    }
}

static void buscar_na_bst(const NoBST *raiz) {
    const LocalUrbano *local;
    int id;

    if (ler_id("Informe o ID a buscar: ", &id) != LEITURA_OK) {
        return;
    }

    local = bst_buscar(raiz, id);
    if (local == NULL) {
        printf("Registro com ID %d nao encontrado.\n", id);
    } else {
        imprimir_local(local);
    }
}

int main(void) {
    NoBST *raiz = NULL;
    Fila fila;
    int opcao = -1;

    fila_iniciar(&fila);

    while (opcao != 0) {
        StatusLeitura status;

        exibir_menu();
        status = ler_inteiro("Escolha uma opcao: ", 0, &opcao);
        if (status == LEITURA_EOF) {
            break;
        }
        if (status == LEITURA_INVALIDA) {
            opcao = -1;
            continue;
        }

        switch (opcao) {
            case 1: cadastrar_na_bst(&raiz); break;
            case 2: buscar_na_bst(raiz); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida. Escolha de 0 a 7.\n"); break;
        }
    }

    bst_liberar(&raiz);
    fila_liberar(&fila);
    return 0;
}
