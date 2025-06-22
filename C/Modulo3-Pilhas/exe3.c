// Modifique a pilha para armazenar uma struct Livro com titulo e ano. Empilhe 3 livros e imprima do último para o primeiro.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct Livro
{
    char titulo[50];
    int ano;
};

struct Pilha
{
    int topo;
    struct Livro dados[MAX];
};

void inicializarPilha(struct Pilha *p)
{
    p->topo = -1;
}

int cheio(struct Pilha *p)
{
    return p->topo == MAX - 1;
}

int vazio(struct Pilha *p)
{
    return p->topo == -1;
}

void push(struct Pilha *p, struct Livro livro)
{
    if (cheio(p))
    {
        printf("Pilha Cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = livro;
}

struct Livro pop(struct Pilha *p)
{
    struct Livro livroVazio = {"", 0};
    if (vazio(p))
    {
        printf("Pilha vazia!\n");
        return livroVazio;
    }
    struct Livro livro = p->dados[p->topo];
    p->topo--;
    return livro;
}

int main()
{

    struct Pilha minha_pilha;
    inicializarPilha(&minha_pilha);

    // Criar 3 livros
    struct Livro livro1 = {"Dom Casmurro", 1899};
    struct Livro livro2 = {"O Cortiço", 1890};
    struct Livro livro3 = {"Iracema", 1865};

    // Empilhar 3 livros
    push(&minha_pilha, livro1);
    push(&minha_pilha, livro2);
    push(&minha_pilha, livro3);

    // Imprimir do último para o primeiro
    printf("Livros do último para o primeiro:\n");
    for (int i = 0; i < 3; i++)
    {
        struct Livro livro = pop(&minha_pilha);
        printf("%s (%d)\n", livro.titulo, livro.ano);
    }

    return 0;
}