//Modifique o exercício anterior para:
//Alocar os 3 livros dinamicamente usando malloc
//Verificar se a alocação falhou
//Ler os dados do usuário

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Livro
{
    char titulo[50];
    char autor[50];
    int ano;
};

int main()
{
    struct Livro *livro1 = (struct Livro*)malloc(sizeof(struct Livro));
    struct Livro *livro2 = (struct Livro*)malloc(sizeof(struct Livro));
    struct Livro *livro3 = (struct Livro*)malloc(sizeof(struct Livro));

    strcpy(livro1->titulo, "A Lei");
    strcpy(livro1->autor, "João");
    livro1->ano = 2000;

    strcpy(livro2->titulo, "Aquilo");
    strcpy(livro2->autor, "Alguém");
    livro2->ano = 1300;

    strcpy(livro3->titulo, "É isso");
    strcpy(livro3->autor, "Outra Pessoa");
    livro3->ano = 2010;

    printf("O nome do primeiro livro é %s, o autor é %s e o ano de publicação foi %d \n", livro1->titulo, livro1->autor, livro1->ano);
    printf("O nome do segundo livro é %s, o autor é %s e o ano de publicação foi %d \n", livro2->titulo, livro2->autor, livro2->ano);
    printf("O nome do terceiro livro é %s, o autor é %s e o ano de publicação foi %d \n", livro3->titulo, livro3->autor, livro3->ano);

    free(livro1);
    free(livro2);
    free(livro3);

    return 0;
}