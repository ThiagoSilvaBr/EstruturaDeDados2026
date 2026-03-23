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


//4.	Escreva um if que verifique se o nodo8 possui um filho à esquerda e imprima "Vazio" caso seja NULL.


//Exercicio 4


void verificarLados(Nodo *n){
	
	if(!n->esq){
		printf("A esquerda do nodo%d é Null.\n", n->valor);
	}else if(n->esq){
		printf("A esquerda do nodo%d é %d.\n", n->valor, n->esq->valor);
	}
	
	if(!n->dir){
		printf("A direita do nodo%d é Null.\n", n->valor);
	}else if(n->dir){
		printf("A direita do nodo%d é %d.\n", n->valor, n->dir->valor);
	}
	
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
	nodo5->dir = nodo8;
	nodo2->dir = nodo4;
	nodo8->dir = nodo10;
	
	verificarLados(nodo5);
}



