#ifndef VALIDACAO_H
#define VALIDACAO_H

#include <stddef.h>

/* Resultado de uma tentativa de leitura. */
typedef enum {
    LEITURA_OK,       /* entrada valida */
    LEITURA_EOF,      /* fim da entrada (Ctrl+D / Ctrl+Z) */
    LEITURA_INVALIDA  /* entrada rejeitada (mensagem ja exibida) */
} StatusLeitura;

/* Remove espacos nas extremidades da string (modifica a propria string). */
void trim(char *s);

/*
 * Converte texto em inteiro com strtol.
 * Rejeita: vazio, nao numerico, sufixo invalido (ex: "12abc"),
 * valor menor que 'minimo' e valor fora do limite de int (INT_MAX).
 * Retorna 1 se valido (e grava em *valor) ou 0 se invalido.
 */
int parse_inteiro(const char *texto, int minimo, int *valor);

/* Le um inteiro >= minimo, uma unica tentativa. */
StatusLeitura ler_inteiro(const char *prompt, int minimo, int *valor);

/* Le um ID positivo (> 0), repetindo ate ser valido ou acabar a entrada. */
StatusLeitura ler_id(const char *prompt, int *valor);

/*
 * Le um texto, aplica trim e valida: nao vazio e com no maximo tam-1
 * caracteres. Repete ate ser valido ou acabar a entrada.
 */
StatusLeitura ler_texto(const char *prompt, char *destino, size_t tam);

#endif
