#include <stdio.h>

void insereValor(int picles[], int n) {
    int posicao, valor;
    printf("Digita a posição aí pra inserir o número, zé\n");
    scanf("%i", &posicao);
    printf("Digita o numero q tu quer bota zé\n");
    scanf("%i", &valor);
    n++;
    for (int i = n; i >= posicao; --i) {
        picles[i] = picles[i - 1];
    }
    picles[posicao] = valor;
    printf("Teu array ta assim agora zé:\n");
    for (int i = 0; i < n; ++i) {
        printf("%i ", picles[i]);
    }
}

void removeValor(int picles[], int n) {
    int posicao;
    printf("Insere a posição pra deletar, zé\n");
    scanf("%i", &posicao);

    for (int i = posicao; i < n; ++i) {
        picles[i] = picles [i + 1];
    }

    n--;

    printf("Teu array ta assim agora zé:\n");
    for (int i = 0; i < n; ++i) {
        printf("%i ", picles[i]);
    }
}

void atualizaValor(int picles[], int n) {
    int posicao, valor;
    printf("Insere a posicao q vc quer atualizar, zé\n");
    scanf("%i", &posicao);
    printf("Insere o novo numero ai, zé\n");
    scanf("%i", &valor);
    picles[posicao] = valor;
    printf("Teu array ta assim agora zé:\n");
    for (int i = 0; i < n; ++i) {
        printf("%i ", picles[i]);
    }
}

void trocaValoresDePosicaoZe(int picles[], int n) {
    int posicao1, posicao2, aux;
    printf("Insere a posicao1, zé\n");
    scanf("%i", &posicao1);
    printf("Insere a posicao2, zé\n");
    scanf("%i", &posicao2);

    aux = picles[posicao1];
    picles[posicao1] = picles[posicao2];
    picles[posicao2] = aux;

    printf("Teu array ta assim agora zé:\n");
    for (int i = 0; i < n; ++i) {
        printf("%i ", picles[i]);
    }

}

int main( )
{
    int cebola[10];
    int tamanho = 5;
    printf("Digita 5 número aí pro array, zé\n");
    for (int i = 0; i < tamanho; ++i) {
        scanf("%i", &cebola[i]);
    }
    printf("Teu array ta assim, zé:\n");
    for (int i = 0; i < tamanho; ++i) {
        printf("%i ", cebola[i]);
    }
    int opcao;
    printf("\nQuer inserir(1), remover(2), atualizar(3) ou trocar valores de posições(4), zé?\n");
    scanf("%i", &opcao);
    if (opcao == 1) {
        insereValor(cebola, tamanho);
    } else if (opcao == 2) {
        removeValor(cebola, tamanho);
    } else if (opcao == 3) {
        atualizaValor(cebola, tamanho);
    } else if (opcao == 4) {
        trocaValoresDePosicaoZe(cebola, tamanho);
    } else {
        printf("Quer fazer nada então, ok zé, tenha um bom dia =D\n");
    }
    return 0;

}