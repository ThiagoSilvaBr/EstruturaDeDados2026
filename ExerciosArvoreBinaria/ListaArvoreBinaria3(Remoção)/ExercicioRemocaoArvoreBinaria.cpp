/*
Exercício 1: Identificação de Caso (Folha)
Pergunta: Se chamarmos rem(raiz, 10) em uma árvore onde o nodo 10 não possui filhos, qual trecho do código será executado e qual será o estado do ponteiro do pai?
R: Será chamado o trecho de dentro do if(filho->esq==NULL && filho->dir==NULL), que removerá o lado esquerdo do ponteiro pai. Não possuirá mais filhos

Exercício 2: O Problema da Raiz
Pergunta: O que acontece se tentarmos remover o valor que está na raiz da árvore usando essa função rem?
R: Ocorrerá um erro de compilação, não sendo possivel nem rodar o programa.

Exercício 3: Nodo com Um Filho (Esquerda)
Pergunta: Desenhe uma subárvore onde o nodo 20 tem o filho 15 à esquerda e nenhum à direita. Se removermos o 20, quem ocupará o lugar dele na estrutura do pai?
R: Imagem na pasta.

Exercício 4: O Caso Ausente (Dois Filhos)
Pergunta: O que o código atual faz se tentarmos remover um nodo que possui tanto filho à esquerda quanto à direita?
R: Ele só vai remover um lado, pois o código não tem estrutura para remover dois filhos de um nodo.

Exercício 5: Valor Inexistente
Pergunta: Se percorrermos toda a árvore e o valor não for encontrado (filho == NULL), o que o código imprime?
R: Não acontece nada, pois não há um tratamento caso não exista o valor inserido na árvore

Exercício 6: Vazamento de Memória (Memory Leak)
Pergunta: O código desconecta o nodo da árvore, mas falta um comando essencial da linguagem C para liberar memória. Qual?
R: Falta o comando free();

Exercício 7: Lógica do do-while
Pergunta: No loop de busca, por que a condição é filho!=NULL && filho->valor != valor?
R: ele vai percorrer enquanto não chegar no ultimo elemento e o valor não ser igual o inserido, após as condições sairá do loop.

Exercício 8: Ponteiro do Pai (Lado Direito)
Pergunta: Se o nodo a ser removido tem apenas um filho à direita, e esse nodo era o filho da direita do seu pai, qual linha específica faz a conexão?
R: A linha que faz a conexão está dentro da lógica que se encontra no 118, mais especificamente na linha 122.

Exercício 9: Análise de Saída
Pergunta: Dada uma árvore com a sequência 15 -> 10 (esq) -> 5 (esq). Ao chamar rem(raiz, 10), qual mensagem aparecerá no console?
R: Será 5, 10 e 15.

Exercício 10: Erro de Atribuição Dupla
Pergunta: No bloco de "1 filho a esquerda", o código testa if(pai->esq == filho) e depois if(pai->dir == filho). É possível que ambos sejam verdadeiros?
R: Não, pois o sistema esta apenas estruturado para lidar com Nodo folha ou Nodo com filho unico.
*/


#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int valor;
	struct nodo *esq;
	struct nodo *dir;	
};

typedef struct nodo Nodo;

Nodo* create(int valor)
{
	Nodo *n = (Nodo*) malloc(sizeof(Nodo));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(Nodo *n)
{
	if(n==NULL){
		//printf("Aborta o loop \n" );
		return;		
	}	
	imprimir(n->esq);	
	printf("\n Valor: %d\n",n->valor);
	imprimir(n->dir);
}

void add(Nodo *n, int valor){
	if(valor < n->valor)	{
		if(n->esq == NULL)
			n->esq = create(valor);
		else
			add(n->esq,valor);
	}else {
		if(n->dir == NULL)
			n->dir = create(valor);
		else
			add(n->dir,valor);
	}
}

void remover(Nodo *n, int valor){	
	Nodo *filho = n;
	Nodo *pai;
	do{
		pai = filho;
		if(valor < filho->valor){
			filho = filho->esq;
		}else if(valor > filho->valor){
			filho = filho->dir;
		}
	}while( (filho!=NULL) && (filho->valor!=valor));
	
	if(filho!= NULL){
		//== no folha
		if(filho->esq==NULL && filho->dir==NULL){
			if(pai->esq==filho){
				pai->esq = NULL;
			}else if(pai->dir==filho){
				pai->dir = NULL;
			}
		}	
		//== o no tem um filho
		//== filho lado esquerdo
		if(filho->esq!=NULL && filho->dir==NULL){
			if(pai->esq==filho){
				pai->esq = filho->esq;
			}else if(pai->dir==filho){
				pai->dir = filho->esq;				
			}			
		}		
		//== filho lado direito	
		if(filho->esq==NULL && filho->dir!=NULL){
			if(pai->esq==filho){
				pai->esq = filho->dir;
			}else if(pai->dir==filho){
				pai->dir = filho->dir;
			}			
		}
	}
}

main(){
	Nodo *raiz = create(50);
	add(raiz,20);	
	add(raiz,10);
	add(raiz,80);
	add(raiz,40);
	add(raiz, 15);	
	add(raiz, 5);
	imprimir(raiz);
	remover(raiz,10);
	imprimir(raiz);
}

