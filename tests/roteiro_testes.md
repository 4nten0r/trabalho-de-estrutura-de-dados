# Roteiro de Testes

Roteiro manual e reproduzível. Compile antes de testar:

```bash
gcc -std=c11 -Wall -Wextra -pedantic -Iinclude src/*.c -o sistema_bst
./sistema_bst
```

A coluna **Resultado Obtido** fica em branco para ser preenchida por quem executar os testes
(escreva "OK" ou descreva o que aconteceu de diferente).

## Carga base

Vários testes partem desta árvore. Use a opção `1` para cadastrar, nesta ordem, os IDs:
`50, 30, 70, 20, 40, 60, 80` (nome, categoria e bairro podem ser quaisquer textos válidos).

```
        50
      /    \
    30      70
   /  \    /  \
  20  40  60  80
```

Cada teste começa com o programa recém-aberto (BST e fila vazias), salvo quando disser "com a carga base".

## 1. BST: inserção, busca e listagem

| ID | Entrada | Passos | Resultado Esperado | Resultado Obtido |
|----|---------|--------|--------------------|------------------|
| T01 | ID `50`, nome `Praca Central`, categoria `Praca`, bairro `Centro` | Opção `1` e preencher os campos | "Registro cadastrado com sucesso." | |
| T02 | Carga base | Cadastrar os 7 IDs; opção `4` | Listagem em-ordem: 20, 30, 40, 50, 60, 70, 80 (ID crescente) | |
| T03 | ID `40` | Com a carga base, opção `2` e informar `40` | Exibe o registro de ID 40 com nome, categoria e bairro | |
| T04 | ID `999` | Com a carga base, opção `2` e informar `999` | "Registro com ID 999 nao encontrado." | |
| T05 | Opção `4` sem registros | Programa recém-aberto, opção `4` | "A BST esta vazia." | |

## 2. BST: remoção

| ID | Entrada | Passos | Resultado Esperado | Resultado Obtido |
|----|---------|--------|--------------------|------------------|
| T06 | Remover folha `20` | Carga base, opção `3` com `20`, depois opção `4` | "Registro 20 removido da BST."; lista: 30, 40, 50, 60, 70, 80 | |
| T07 | Remover nó com 1 filho `30` | Carga base, remover `20` (opção `3`); remover `30` (agora só tem o filho 40); opção `4` | Lista: 40, 50, 60, 70, 80; o 40 continua acessível pela opção `2` | |
| T08 | Remover nó com 2 filhos `50` (raiz) | Carga base, opção `3` com `50`, depois opção `4` | Lista: 20, 30, 40, 60, 70, 80; ID 50 não é mais encontrado na opção `2` | |
| T09 | Remover ID inexistente `999` | Carga base, opção `3` com `999` | "Registro com ID 999 nao encontrado."; árvore inalterada | |

## 3. Validação de IDs e opções

| ID | Entrada | Passos | Resultado Esperado | Resultado Obtido |
|----|---------|--------|--------------------|------------------|
| T10 | ID duplicado `50` | Carga base, opção `1` e informar `50` | "Erro: ja existe um registro com o ID 50."; nada é inserido | |
| T11 | ID negativo `-5` | Opção `1` e informar `-5` | "Entrada invalida..."; o programa pede o ID de novo | |
| T12 | ID zero `0` | Opção `1` e informar `0` | "Entrada invalida..."; o programa pede o ID de novo | |
| T13 | ID texto `abc` | Opção `1` e informar `abc` | "Entrada invalida..."; o programa pede o ID de novo | |
| T14 | ID com sufixo `12abc` | Opção `1` e informar `12abc` | "Entrada invalida..."; o programa pede o ID de novo | |
| T15 | ID vazio (só Enter) | Opção `1` e apertar Enter | "Entrada invalida..."; o programa pede o ID de novo | |
| T16 | Overflow `2147483648` (INT_MAX + 1) | Opção `1` e informar `2147483648` | "Entrada invalida..."; o programa pede o ID de novo | |
| T17 | Overflow `99999999999999999999` | Opção `1` e informar o número | "Entrada invalida..."; o programa pede o ID de novo | |
| T18 | Limite válido `2147483647` (INT_MAX) | Opção `1` e informar `2147483647`, preencher os textos | Aceito: "Registro cadastrado com sucesso." | |
| T19 | Opção de menu inválida `9` | Digitar `9` no menu | "Opcao invalida. Escolha de 0 a 7." e o menu volta | |
| T20 | Opção de menu `abc`, `-1`, vazia | Digitar cada uma no menu | "Entrada invalida..." e o menu volta | |

## 4. Validação de textos

| ID | Entrada | Passos | Resultado Esperado | Resultado Obtido |
|----|---------|--------|--------------------|------------------|
| T21 | Nome vazio | Opção `1`, ID `1`, apertar Enter no nome | "Texto invalido: nao pode ser vazio."; pede o nome de novo | |
| T22 | Nome só com espaços (`"     "`) | Opção `1`, ID `1`, digitar só espaços no nome | "Texto invalido: nao pode ser vazio."; pede o nome de novo | |
| T23 | Categoria e bairro vazios / só espaços | Repetir T21 e T22 nos campos categoria e bairro | Mesma rejeição e novo pedido em cada campo | |
| T24 | Texto com 80 caracteres | Nome com 80 letras `a` | "Texto muito longo (maximo 79 caracteres)."; pede o nome de novo | |
| T25 | Texto com 79 caracteres | Nome com 79 letras `b` | Aceito e exibido por inteiro na listagem | |
| T26 | Texto com espaços nas pontas | Nome `"   Praca Central   "` | Aceito; listado como `Praca Central` (sem espaços nas pontas) | |
| T27 | Texto muito longo (300 caracteres) | Colar 300 letras no nome | Rejeitado como longo; o excesso não vaza para o próximo campo | |

## 5. Fila

| ID | Entrada | Passos | Resultado Esperado | Resultado Obtido |
|----|---------|--------|--------------------|------------------|
| T28 | Inserir `7` e `3` | Opção `5` com `7`; opção `5` com `3`; opção `7` | "Inicio -> 7 -> 3 -> Fim" | |
| T29 | IDs repetidos | Opção `5` com `7` duas vezes; opção `7` | "Inicio -> 7 -> 7 -> Fim" (repetição aceita) | |
| T30 | ID que não existe na BST | Programa recém-aberto, opção `5` com `999`; opção `7` | `999` entra na fila normalmente | |
| T31 | Remoção FIFO | Inserir `10`, `20`, `30`; opção `6` três vezes | Removidos nesta ordem: 10, 20, 30 | |
| T32 | Sem inserção automática | Cadastrar um registro na BST (opção `1`); opção `7` | "A fila esta vazia." | |
| T33 | Fila independente da BST | Carga base; opção `5` com `40`; remover `40` da BST (opção `3`); opção `7` | O ID 40 continua na fila | |
| T34 | Fila volta a funcionar após esvaziar | Inserir `1`, remover, inserir `2`, opção `7` | "Inicio -> 2 -> Fim" | |

## 6. Estruturas vazias

| ID | Entrada | Passos | Resultado Esperado | Resultado Obtido |
|----|---------|--------|--------------------|------------------|
| T35 | Remover da BST vazia | Programa recém-aberto, opção `3` | "A BST esta vazia. Nada para remover."; o programa continua | |
| T36 | Remover da fila vazia | Programa recém-aberto, opção `6` | "A fila esta vazia. Nada para remover."; o programa continua | |
| T37 | Exibir fila vazia | Programa recém-aberto, opção `7` | "A fila esta vazia." | |

## 7. Memória e encerramento

| ID | Entrada | Passos | Resultado Esperado | Resultado Obtido |
|----|---------|--------|--------------------|------------------|
| T38 | Valgrind com BST e fila preenchidas | `valgrind --leak-check=full ./sistema_bst`; carga base, inserir 3 IDs na fila, remover 2 nós da BST, opção `0` | "All heap blocks were freed -- no leaks are possible" e "ERROR SUMMARY: 0 errors" | |
| T39 | Encerrar com a opção `0` | Opção `0` | "Encerrando..." e o programa termina | |
| T40 | Fim da entrada (Ctrl+D) | Com dados cadastrados, pressionar Ctrl+D no menu | O programa termina sem travar e sem vazamentos (confirmar no Valgrind) | |
