// Escreva um programa que leia 5 números inteiros em um vetor e imprima a soma dos valores.

#include <stdio.h>
#define TAMANHO 5

int main()
{
    int numeros[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Digite o número %d º:  ", i + 1);
        scanf("%d", &numeros[i]);
        printf("\n");
    }

    int soma = 0;

    for (int i = 0; i < TAMANHO; i++)
    {
        soma = soma + numeros[i];
    }

    printf("A soma de todos os numeros é: %d \n", soma);

    return 0;
}
