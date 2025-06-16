//Crie uma função:
//void reajustarPrecos(struct Produto *produtos, int n, float porcentagem);
//Ela deve percorrer o vetor e aumentar o preço de todos os produtos pela porcentagem informada.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO 5

struct Produto
{
    char nome[50];
    float preco;
};

void reajustarPrecos( struct Produto *produtos, int n, float porcentagem){
	for(int i = 0; i < n ; i++){
		produtos[i].preco = produtos[i].preco * (1 + porcentagem/100);
	}
}

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

    reajustarPrecos(produto, 5, 40);

        for (int i = 0; i < TAMANHO; i++)
    {
        	printf("O produto %s tem o preço igual R$ %.2f após o reajuste\n", produto[i].nome, produto[i].preco);
    }

    free(produto);

    return 0;
}