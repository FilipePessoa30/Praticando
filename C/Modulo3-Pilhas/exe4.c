// Crie duas pilhas P1 e P2, empilhe 5 números em cada, depois crie
// uma terceira pilha P3 que intercale os elementos das duas (um de cada por vez).
// Exemplo:
// P1: 1 3 5 7 9
// P2: 2 4 6 8 10
// P3: 1 2 3 4 5 6 7 8 9 10

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct Pilha
{
	int topo;
	int dados[MAX];
};