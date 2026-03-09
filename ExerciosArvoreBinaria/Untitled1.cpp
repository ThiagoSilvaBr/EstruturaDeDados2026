#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

setlocale(LC_ALL, "Portuguese");

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
/*
int main(void){
	Nodo *nodo5 = create(5);
	Nodo *nodo2 = create(2);
	Nodo *nodo1 = create(1);
	Nodo *nodo8 = create(8);
	Nodo *nodo4 = create(4);
	
	nodo5->esq = nodo2;
	nodo2->esq = nodo1;
	nodo5->dir = nodo8;
	nodo2->dir = nodo4;
	
	return 0;
}*/

/*1.	Adicione ao main um novo nó com o valor 10 e conecte-o como filho à direita do nodo8.
2.	Escreva um printf que imprima o valor do nodo4 acessando-o a partir do nodo5 (ex: nodo5->esq->dir->valor).
3.	Crie uma função void imprimir(Nodo *n) que receba um nó e imprima seu valor. Use-a no main para imprimir o nodo5.
4.	Escreva um if que verifique se o nodo8 possui um filho à esquerda e imprima "Vazio" caso seja NULL.
5. Mude o valor do nodo1 para 7 sem criar um novo nó, apenas acessando o ponteiro existente.*/


//Exercicio 1

/*int main(){
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
	
}*/

//Exercicio 2

/*int main(){
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
	
	printf("O valor do Nodo4 é:%d", nodo5->esq->dir->valor);
}
*/

//Exercicio 3
/*
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
	
	imprimir(nodo8);
}*/

//Exercicio 4

/*
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
*/

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


