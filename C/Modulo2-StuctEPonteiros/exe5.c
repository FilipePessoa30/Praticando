// Faça o mesmo do exercício anterior, mas usando alocação dinâmica com malloc, e leia os dados com fgets e scanf.

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

    struct Produto *produto = (struct Produto *)malloc(TAMANHO * sizeof(struct Produto));

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
    free(produto);

    return 0;
}