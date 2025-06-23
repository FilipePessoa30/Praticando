// Crie duas pilhas P1 e P2, empilhe 5 números em cada, depois crie
// uma terceira pilha P3 que intercale os elementos das duas (um de cada por vez).
// Exemplo:
// P1: 1 3 5 7 9
// P2: 2 4 6 8 10
// P3: 1 2 3 4 5 6 7 8 9 10

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10

struct Pilha
{
	int topo;
	int dados[MAX];
};

void criar_pilha(struct Pilha *p)
{
	p->topo = -1;
}

int cheia(struct Pilha *p)
{
	return p->topo == MAX - 1;
}

int vazia(struct Pilha *p)
{
	return p->topo == -1;
}

void push(struct Pilha *p, int valor)
{
	if (cheia(p))
	{
		printf("Pilha Cheia! \n");
		return;
	}
	p->topo++;
	p->dados[p->topo] = valor;
}

int pop(struct Pilha *p)
{
	if (vazia(p))
	{
		printf("Pilha Vazia! \n");
		return -1;
	}
	int valor = p->dados[p->topo];
	p->topo--;
	return valor;
}

void inverter_pilha(struct Pilha *p)
{
	struct Pilha aux;
	criar_pilha(&aux);

	while (!vazia(p))
	{
		int valor = pop(p);
		push(&aux, valor);
	}

	while (!vazia(&aux))
	{
		int valor = pop(&aux);
		push(p, valor);
	}
}

int main()
{

	srand(time(NULL));
	struct Pilha minha_pilha1;
	struct Pilha minha_pilha2;
	struct Pilha minha_pilha3;
	criar_pilha(&minha_pilha1);
	criar_pilha(&minha_pilha2);
	criar_pilha(&minha_pilha3);

	printf("Adicionando elementos na P1\n");
	for (int i = 0; i < 5; i++)
	{
		int valor = rand() % 100;
		printf("Adicionado, %d, na posição %d \n", valor, i);
		push(&minha_pilha1, valor);
	}

	printf("Adicionando elementos na P2\n");
	for (int i = 0; i < 5; i++)
	{
		int valor = rand() % 100;
		printf("Adicionado, %d, na posição %d \n", valor, i);
		push(&minha_pilha2, valor);
	}

	printf("Invertendo as pilhas\n");
	inverter_pilha(&minha_pilha1);
	inverter_pilha(&minha_pilha2);

	printf("Intercalando os elementos em P3\n");
	int contador = 0;
	while (!vazia(&minha_pilha1) || !vazia(&minha_pilha2))
	{ // Mudança: continua enquanto ALGUMA pilha tem elementos
		if (contador == 0)
		{
			if (!vazia(&minha_pilha2))
			{ // Mudança: verificar se não está vazia
				int valor = pop(&minha_pilha2);
				push(&minha_pilha3, valor);
				printf("De P2: %d foi adicionado\n", valor);
			}
			contador++;
		}
		else if (contador == 1)
		{
			if (!vazia(&minha_pilha1))
			{ // Mudança: verificar se não está vazia
				int valor = pop(&minha_pilha1);
				push(&minha_pilha3, valor);
				printf("De P1: %d foi adicionado\n", valor);
			}
			contador--;
		}
	}

	// Mostrar resultado
	printf("Resultado intercalado em P3:\n");
	while (!vazia(&minha_pilha3))
	{
		int valor = pop(&minha_pilha3);
		printf("%d ", valor);
	}
	printf("\n");

	return 0;
}