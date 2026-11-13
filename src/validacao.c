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

