//Crie uma função que inverta um vetor de inteiros usando uma pilha.


#include <stdio.h>
#include <stdlib.h>

#define MAX 10


struct Pilha
{
	int topo;
	int dados[MAX];
};

void inicializarPilha (struct Pilha *p){
	p-> topo = -1;
}

int cheio(struct Pilha *p){
	return p->topo == MAX - 1;
}

int vazio(struct Pilha *p){
	return p->topo == -1;
}

void push (struct Pilha *p, int valor){
	if(cheio(p)){
		printf("Pilha Cheia!\n");
		return;
	}
	p->topo++;
	p->dados[p->topo] = valor;
}

int pop (struct Pilha *p){
	if (vazio(p)){
		printf("Pilha vazia!\n");
		return -1;
	}
	int valor = p->dados[p->topo];
	p->topo --;
	return valor;
}

int main(){

	struct Pilha *minha_pilha1 = (struct Pilha*)malloc(sizeof(struct Pilha));
	struct Pilha *minha_pilha2 = (struct Pilha*)malloc(sizeof(struct Pilha));
	inicializarPilha(minha_pilha1);
	inicializarPilha(minha_pilha2);


	printf("Empilhando na pilha 1\n");
	for(int i = 0; i<10; i++){
		printf("Empilhando: %d \n", i);
		push(minha_pilha1,i);
	}

	printf("Empilhando os números da pilha 1 na pilha 2\n");
	for (int i= 0; i<10; i++){
		int valor = pop(minha_pilha1);
		printf("Desempilhando o %d \n", valor);
		push(minha_pilha2,valor);
	}

	printf("A pilha invertida ficou\n");
	for(int i = 0; i<10 ; i++){
		int valor = pop(minha_pilha2);
		printf("Desempilhando os valores invertidos %d \n", valor);
	}


	return 0;
}