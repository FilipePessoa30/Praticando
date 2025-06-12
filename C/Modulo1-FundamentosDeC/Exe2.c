//Escreva uma função float media(float v[], int n) que calcule a média dos elementos de um vetor de float.

#include <stdio.h>

float media(float v[], int n){
	float soma = 0;
	for(int i = 0; i< n ; i++){
		soma = soma + v[i];
	}

	return (soma/n);
}

int main(){

	float notas[] = {7.5, 2.7, 7.3, 7.5};
	int quantidade = 4;

	float resultado = media(notas, quantidade);

	printf("A média das notas é: %.2f \n",resultado );

	return 0;
}