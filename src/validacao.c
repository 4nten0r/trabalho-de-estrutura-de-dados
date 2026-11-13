#include "validacao.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BUFFER 256

/* Resultado interno da leitura de uma linha. */
typedef enum { LINHA_OK, LINHA_EOF, LINHA_LONGA } StatusLinha;

void trim(char *s) {
    char *inicio = s;
    size_t tamanho;

    while (*inicio != '\0' && isspace((unsigned char)*inicio)) {
        inicio++;
    }

    tamanho = strlen(inicio);
    while (tamanho > 0 && isspace((unsigned char)inicio[tamanho - 1])) {
        tamanho--;
    }

    memmove(s, inicio, tamanho);
    s[tamanho] = '\0';
}

/*
 * Le uma linha com fgets. Se a linha nao couber no buffer, descarta o
 * restante dela (para nao "vazar" para a proxima leitura) e informa
 * LINHA_LONGA.
 */
static StatusLinha ler_linha(char *buffer, size_t tam) {
    size_t tamanho;
    int c;

    if (fgets(buffer, (int)tam, stdin) == NULL) {
        return LINHA_EOF;
    }

    tamanho = strlen(buffer);
    if (tamanho > 0 && buffer[tamanho - 1] == '\n') {
        buffer[tamanho - 1] = '\0';
        return LINHA_OK;
    }

    if (feof(stdin)) { /* ultima linha sem '\n' */
        return LINHA_OK;
    }

    while ((c = getchar()) != '\n' && c != EOF) {
        /* descarta o resto da linha */
    }
    return LINHA_LONGA;
}

