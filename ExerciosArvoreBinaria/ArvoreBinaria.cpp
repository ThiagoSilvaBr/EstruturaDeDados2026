/*
1.	Rastreio de Saída: Se adicionarmos os valores 7, 3, 9 após o 4 no main, qual será a ordem exata dos números impressos na tela pela função imprimir?
2.	Identificação de Ordem: A função imprimir utiliza o percurso In-order (esquerda-raiz-direita). O que aconteceria com a saída se você movesse o printf para antes da chamada imprimir(n->esq)?
R - A ordem de esquera-raíz-direita passaria a ser raíz-esquerda-direita
3.	Desenho de Árvore: Com base nas chamadas add do exemplo (5, 2, 1, 8, 4), desenhe a estrutura da árvore indicando quem é filho à esquerda e quem é à direita.
4.	Comportamento de Duplicados: O que acontece no código atual se você executar add(root, 5)? O novo valor será inserido à esquerda ou à direita?
5.	Análise de Condição: Na função add, por que é necessário verificar if(n->esq == NULL) antes de chamar a recursão? O que aconteceria se chamássemos add(n->esq, valor) diretamente?
Exercícios de Modificação de Código
6.	Inversão de Ordem: Modifique a função imprimir para que ela exiba os números em ordem decrescente.
7.	Busca de Valor: Crie uma função int existe(Nodo *n, int valor) que retorne 1 se o valor estiver na árvore e 0 se não estiver, seguindo a mesma lógica de navegação da função add.
8.	Contagem de Elementos: Crie uma função que retorne a quantidade total de nodos inseridos na árvore.
9.	Maior Valor: Implemente uma função que navegue pela árvore e retorne o maior valor nela contido (Dica: onde costumam ficar os maiores valores em uma árvore binária de busca?).
10.	Soma dos Nodos: Crie uma função int soma(Nodo *n) que utilize a recursão para retornar a soma de todos os valores armazenados na árvore.
*/	
#include <stdio.h>
#include <stdlib.h>

struct nodo
{
	int valor;
	struct nodo *esq;
	struct nodo *dir;
};

typedef struct nodo Nodo;

Nodo* create(int valor)
{
	Nodo *n = (Nodo*)malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(Nodo *n)
{
	if(n==NULL){
		printf("Aborta o loop \n" );
		return;		
	}		
	printf("Chamou o loop  da esquerda com o no: %i\n", n->valor);
	if(n->esq==NULL){
	    printf(" a proxima esquerda e nula, Vai abortar, imprimir o valor e chamar o loop da direita\n ");
	}
	imprimir(n->esq);
	
	
	printf("\n Valor: %d\n",n->valor);
	printf("Chamou o loop  da direita com o no: %i\n", n->valor);
	if(n->dir==NULL){
	    printf(" a proxima direita e nula, Vai abortar e acabou a função, volta pra quem esta esperando ou encerra tudo\n ");
	}
	imprimir(n->dir);
}

void add(Nodo *n, int valor)
{
	if(valor < n->valor)
	{
		if(n->esq == NULL)
			n->esq = create(valor);
		else
			add(n->esq,valor);
	}
	else
	{
		if(n->dir == NULL)
			n->dir = create(valor);
		else
			add(n->dir,valor);
	}
}

int main(void) {  	
	Nodo *raiz = create(5);
	
	add(raiz,2);
	add(raiz,1);
	add(raiz,8);
	add(raiz,4);	
	imprimir(raiz);
  	return 0;
}
