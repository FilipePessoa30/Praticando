// Crie um vetor estático de 5 produtos com:
// nome (string)
// preco (float)
// Imprima apenas os produtos com preço maior que R$ 100.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO 5

struct Produto
{
    char nome[50];
    float preco;
};

int main()
{

    struct Produto produto[TAMANHO];

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Qual nome do produto %d°:", i + 1);
        fgets(produto[i].nome, sizeof(produto[i].nome), stdin);

        produto[i].nome[strcspn(produto[i].nome, "\n")] = '\0';

        printf("Qual o preço do %s :", produto[i].nome);
        scanf("%f", &produto[i].preco);

        while (getchar() != '\n')
            ;
    }

    for (int i = 0; i < TAMANHO; i++)
    {
        if (produto[i].preco > 100)
        {
            printf("O produto %s tem o preço igual R$ %.2f, logo é maior que R$ 100,00\n", produto[i].nome, produto[i].preco);
        }
    }

    return 0;
}