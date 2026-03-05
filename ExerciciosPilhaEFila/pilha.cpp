//PILHA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct tp_aluno{
	int ra;
	char nome[100];
	struct tp_aluno *prox;
};

typedef struct tp_aluno Aluno;
int escolha;
bool sair;

//Ponteiros controlador
Aluno *topo = NULL;

//Inserir ultimo na Pilha
void inserir(){
	system("CLS");
	Aluno *alunos = (Aluno*)malloc(sizeof(Aluno));
	
	if(!alunos){
		printf("Não foi possivel alocar na memória.\n");
	}
	
	printf("Digite o RA do aluno:");
	scanf("%d", &alunos->ra);
	printf("\nDigite o nome do aluno:");
	fflush(stdin);
	fgets(alunos->nome, 100, stdin);
		
	if(!topo){
		alunos->prox = NULL;
	}else{
		alunos->prox = topo;
	}
	
	topo = alunos;
}

void listar(){
	system("CLS");
	Aluno *aux = topo;
	printf("\n====== Dados Dos Alunos ======\n");
	
	while(aux){
		printf("R.A:%d\n", aux->ra);
		printf("Nome:%s\n", aux->nome);
		
		if(!aux->prox){
			printf("Próximo:nulo\n");
		}else{
			printf("Próximo:%d\n", aux->prox->ra);
		}
		
	  printf("--------------------------\n");
	  aux = aux->prox;
	}
}

void remover(){
	system("CLS");
	if(!topo){
		printf("A pilha é vazia.\n");
	}
	
	Aluno *aux = topo;
	printf("O aluno %s foi removido.\n", aux->nome);
	topo = aux->prox;
	free(aux);
}

void sairDoSistema(){
	system("CLS");
	printf("\nSaindo do Sistema...\n");
	bool sair = true;
	system("pause");

	
}

void menu(){
	printf("-------------------- Selecione a opção que deseja ----------------------\n");
	printf("01- Cadastrar aluno na chamada\n");
	printf("02- Listar alunos na chamada\n");
	printf("03- Remover alunos na chamada\n");
	printf("04 - Sair\n");
	printf("------------------------------------------------------------------------\n");
	printf("Digite sua opção\n");
	scanf("%d", &escolha);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	while(!sair){
		menu();
		switch(escolha){
			case 1:
				inserir();
				break;
			case 2:
				listar();
				break;
			case 3:
				remover();
				break;
			case 4:
				sairDoSistema();
				break;
			default:
				printf("Digite um valor válido.");
				break;
		}
	}
}
