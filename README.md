# Trabalho de Estrutura de Dados

Projeto acadêmico de terminal em C11 com duas estruturas de dados independentes:
uma **Árvore Binária de Busca (BST)** e uma **Fila dinâmica (FIFO)**.

## Tema

**Locais urbanos.** Cada registro (`LocalUrbano`) tem:

| Campo | Tipo | Regra |
|-------|------|-------|
| `id` | `int` | inteiro positivo único (> 0) |
| `nome` | `char[80]` | até 79 caracteres úteis |
| `categoria` | `char[80]` | até 79 caracteres úteis |
| `bairro` | `char[80]` | até 79 caracteres úteis |

- A **BST** guarda os registros completos, ordenados pelo `id` (sem IDs repetidos).
- A **Fila** guarda **somente IDs** inteiros positivos. Ela é totalmente independente da BST:
  aceita IDs repetidos, aceita IDs que não existem na BST e mantém os IDs mesmo depois de o
  registro ser removido da BST. Cadastrar na BST não insere nada na fila.

## Estrutura de pastas

```
.
├── include/
│   ├── bst.h          # LocalUrbano, NoBST e operacoes da BST
│   ├── fila.h         # Fila dinamica de IDs
│   └── validacao.h    # Leitura segura e validacao
├── src/
│   ├── bst.c
│   ├── fila.c
│   ├── validacao.c
│   └── main.c         # Menu principal
├── tests/
│   └── roteiro_testes.md
├── .gitignore
└── README.md
```

## Como compilar

```bash
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude src/*.c -o sistema_bst
```

## Como executar

```bash
./sistema_bst
```

Menu:

```
====
SISTEMA DE ESTRUTURA DE DADOS
1- Cadastrar registro na BST
2- Buscar registro por ID na BST
3- Remover registro da BST
4- Listar registros em-ordem
5- Inserir ID na estrutura linear
6- Remover da estrutura linear
7- Exibir estrutura linear
0- Encerrar
Escolha uma opcao:
```

A "estrutura linear" é a fila (opções 5, 6 e 7).

## Regras de entrada

- Toda leitura usa `fgets` (nunca `scanf`). Linhas longas demais são descartadas por inteiro, para
  não vazarem para a próxima pergunta.
- IDs: usam `strtol` e rejeitam `0`, negativos, vazio, texto, sufixos como `12abc` e valores acima de `INT_MAX`.
- Opções do menu: seguem a mesma validação, mas aqui o `0` é aceito, porque é a opção "Encerrar".
- Textos (`nome`, `categoria`, `bairro`): passam por `trim` e rejeitam vazio, só espaços e mais de 79 caracteres.
- Remover da BST ou da fila vazia só mostra uma mensagem e o programa continua.

## Como rodar os testes

Os testes são manuais e estão em [`tests/roteiro_testes.md`](tests/roteiro_testes.md), em uma tabela com
Entrada, Passos, Resultado Esperado e Resultado Obtido. Compile, execute o programa e siga os passos de
cada caso, preenchendo a última coluna.

### Valgrind (vazamentos de memória)

```bash
valgrind --leak-check=full ./sistema_bst
```

Use o programa normalmente (cadastre registros, insira IDs na fila) e encerre com a opção `0`.
O esperado é ver:

```
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

Também é possível usar uma entrada pronta: `valgrind --leak-check=full ./sistema_bst < entrada.txt`.

## Fluxo de trabalho no Git

Cada parte foi desenvolvida em uma branch própria, com um commit descritivo, e depois integrada à `main`:

| Branch | O que implementa |
|--------|------------------|
| `feature/validacao` | leitura segura, `trim`, `strtol` |
| `feature/bst` | árvore binária de busca |
| `feature/fila` | fila dinâmica FIFO |
| `feature/menu-principal` | `main.c` com o menu |
| `docs/readme` | este README |
| `docs/roteiro-testes` | roteiro de testes |

## Declaração de uso de IA

Este projeto foi gerado com apoio de IA (Claude, da Anthropic), a partir dos requisitos fornecidos pelo
autor. O código foi compilado e testado, e o autor deve revisá-lo e ser capaz de explicá-lo.
