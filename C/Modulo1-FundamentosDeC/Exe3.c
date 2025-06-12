// Crie um programa que use malloc para alocar
// dinamicamente um vetor de 10 números inteiros, peça os valores ao usuário e imprima os pares.

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

int main()
{

    int *vetor;

    vetor = (int *)malloc(sizeof(int) * TAMANHO);

    // Verificar se malloc funcionou
    if (vetor == NULL)
    {
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Digite o %d ° do vetor: ", i + 1);
        scanf("%d", &vetor[i]);
        printf("\n");
    }
    printf("Nesse vetor temos os seguintes pares: \n");
    for (int i = 0; i < TAMANHO; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            printf(" %d ", vetor[i]);
        }
    }

    printf("\n");

    free(vetor);

    return 0;
}