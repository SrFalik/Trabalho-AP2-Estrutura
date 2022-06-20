#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct no {
    int valor;
    struct no *prox;
};
struct no *inicio = NULL;


void inserirNo() {
    struct no *temp = inicio;
    struct no *anterior = NULL;

    int pos, valor;
    printf("\nEscreva a posicao e o valor:\n");

    scanf("%d %d", &pos, &valor);

    struct no *novo = calloc(1, sizeof(struct no));
    novo->valor = valor;

    if (pos == 0) {
        novo->prox = inicio;
        inicio = novo;
    } else {
        // Inserir no meio da lista

        int inserido = 0;
        for (int i = 0; temp != NULL; i++) {
            if (i == pos) {
                if (anterior != NULL) {
                    anterior->prox = novo;
                }
                novo->prox = temp;
                inserido = 1;
                break;
            }
            anterior = temp;
            temp = temp->prox;
        }

        if (!inserido) { // Insere no final
            temp = inicio;

            for (int i = 0; temp != NULL; i++) {
                if (temp->prox == NULL) {
                    temp->prox = novo;
                    break;
                }
                temp = temp->prox;
            }
        }
    }
}

void deletarNo() {
    int pos;

    printf("Insira a posicao:\n");
    scanf("%d", &pos);

    if (pos == 0) {
        struct no *temp;
        temp = inicio;

        inicio = inicio->prox;
        free(temp);
    } else {
        struct no *atual = inicio;
        struct no *anterior;
        int apagou = 0;

        for (int i = 0; atual != NULL; i++) {
            if (i == pos) {
                if (anterior != NULL) {
                    anterior->prox = atual->prox;
                }
                free(atual);
                apagou = 1;
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }

        if (apagou) {
            printf("Item apagado.\n");
        }
    }
 }

void imprimirNos() {
    struct no *temp;
    temp = inicio;

    while (temp != NULL) {
        printf("Valor: %d\n", temp->valor);
        temp = temp->prox;
    }
}

void atualizarNo() {
    int pos;
    int valor;
    printf("Digite o numero da posicao:\n");
    scanf("%d", &pos);
    printf("Digite o valor para ser atualizado:\n");
    scanf("%d", &valor);

    struct no *temp;
    temp = inicio;

    int achou = 0;

    for (int i = 0; temp != NULL; i++) {
        if (i == pos) {
            achou = 1;
            temp->valor = valor;
            break;
        }
        temp = temp->prox;
    }

    if (achou) {
        printf("Valor da posicao %d foi atualizado para %d\n", pos, valor);
    } else {
        printf("Posicao nao encontrada\n");
    }
}

int main() {

    int n;
    printf("Insira o numero de nos:\n");
    scanf("%d", &n);

    if (n != 0) {
        int data;
        struct no *newnode;
        struct no *temp;
        newnode = calloc(1,sizeof(struct no));
        inicio = newnode;
        temp = inicio;
        printf("Insira o valor pra ser inserido\n");
        scanf("%d", &data);
        inicio->valor = data;

        for (int i = 2; i <= n; i++) {
            newnode = calloc(1,sizeof(struct no));
            temp->prox = newnode;
            printf("Insira o valor pra ser inserido\n");
            scanf("%d", &data);
            newnode->valor = data;
            temp = temp->prox;
        }
    }

    printf("\nLista criada\n");

    while (1) {
        printf("Inserir no (1), deletar no (2), atualizar no (3) e imprimir (4) qualquer outro numero fecha o programa\n");

        int opcao;

        scanf("%i", &opcao);
        if (opcao == 1) {
            inserirNo();
        } else if (opcao == 2) {
            deletarNo();
        } else if (opcao == 3) {
            atualizarNo();
        } else if (opcao == 4) {
            imprimirNos();
        } else {
            printf("Fechando...");
            break;
        }
    }
}

