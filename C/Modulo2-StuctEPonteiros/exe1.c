// Crie uma struct chamada Livro com os campos:
// titulo (string)
// autor (string)
// ano (int)
// No main, crie 3 livros (estáticos, sem malloc) e imprima seus dados.

#include <stdio.h>
#include <string.h>

struct Livro
{
    char titulo[50];
    char autor[50];
    int ano;
};

int main()
{
    struct Livro livro1;
    struct Livro livro2;
    struct Livro livro3;

    strcpy(livro1.titulo, "A Lei");
    strcpy(livro1.autor, "João");
    livro1.ano = 2000;

    strcpy(livro2.titulo, "Aquilo");
    strcpy(livro2.autor, "Alguém");
    livro2.ano = 1300;

    strcpy(livro3.titulo, "É isso");
    strcpy(livro3.autor, "Outra Pessoa");
    livro3.ano = 2010;

    printf("O nome do primeiro livro é %s, o autor é %s e o ano de publicação foi %d \n", livro1.titulo, livro1.autor, livro1.ano);
    printf("O nome do segundo livro é %s, o autor é %s e o ano de publicação foi %d \n", livro2.titulo, livro2.autor, livro2.ano);
    printf("O nome do terceiro livro é %s, o autor é %s e o ano de publicação foi %d \n", livro3.titulo, livro3.autor, livro3.ano);

    return 0;
}