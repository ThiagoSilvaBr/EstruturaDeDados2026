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



//5. Mude o valor do nodo1 para 7 sem criar um novo nó, apenas acessando o ponteiro existente.*/


//Exercicio5
void alterarValor(Nodo *n){
		n->valor = 7;
	
	
	printf("O valor do nodo é:%d", n->valor);
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
	
	alterarValor(nodo1);
	
}


