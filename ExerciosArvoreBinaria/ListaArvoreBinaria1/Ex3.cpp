#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct nodo{
	int valor;
	struct nodo *esq;
	struct nodo *dir;
};

typedef struct nodo Nodo;

Nodo* create(int valor){
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

//3.	Crie uma função void imprimir(Nodo *n) que receba um nó e imprima seu valor. Use-a no main para imprimir o nodo5.


//Exercicio 3

void imprimir(Nodo *n){
	printf("O valor do nodo%d:%d", n->valor,n->valor);
}

int main(){
		Nodo *nodo5 = create(5);
	Nodo *nodo2 = create(2);
	Nodo *nodo1 = create(1);
	Nodo *nodo8 = create(8);
	Nodo *nodo4 = create(4);
	Nodo *nodo10 = create(10);
	
	nodo5->esq = nodo2;
	nodo2->esq = nodo1;
	nodo8->dir = nodo5;
	nodo2->dir = nodo4;
	nodo8->dir = nodo10;
	
	imprimir(nodo5);
}


