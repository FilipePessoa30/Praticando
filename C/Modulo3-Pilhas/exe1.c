// Implemente uma pilha com struct como acima. Crie as funções:
// inicializarPilha
// push
// pop
// topo
// isEmpty
// Use no main() para empilhar 5 valores e depois desempilhar tudo.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Pilha
{
    int topo;
    int dados[MAX];
};

void inicializarPilha(struct Pilha *p)
{
    p->topo = -1;
}

int isEmpty(struct Pilha *p)
{
    return p->topo == -1;
}

int full(struct Pilha *p)
{
    return p->topo == MAX - 1;
}

void push(struct Pilha *p, int valor)
{
    if (full(p))
    {
        printf("Pilha Cheia! \n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor;
}

int pop(struct Pilha *p)
{
    if (isEmpty(p))
    {
        printf("Pilha Vazia! \n");
        return -1;
    }
    int item = p->dados[p->topo];
    p->topo--;
    return item;
}

int topo(struct Pilha *p)
{
    if (isEmpty(p))
    {
        return -1;
    }
    return p->dados[p->topo];
}



int main()
{

    struct Pilha *minha_pilha = (struct Pilha *)malloc(sizeof(struct Pilha));
    inicializarPilha(minha_pilha);

    printf("Empilhando valores:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Push: %d\n", i);
        push(minha_pilha, i);
    }

    printf("\nDesempilhando valores:\n");
    for (int i = 0; i < 5; i++)
    {
        int valor = pop(minha_pilha);
        if (valor != -1) {
            printf("Pop: %d\n", valor);
        }
    }

    free(minha_pilha);
    return 0;
}