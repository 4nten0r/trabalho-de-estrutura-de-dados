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
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida. Escolha de 0 a 7.\n"); break;
        }
    }

    bst_liberar(&raiz);
    fila_liberar(&fila);
    return 0;
}
