#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct tp_aluno{
	int ra;
	char nome[100];
	struct tp_aluno *prox;
};

typedef struct tp_aluno Aluno;

Aluno *inicio = NULL;
Aluno *fim = NULL;
bool sair = false;
int op;
int escolha;

void menu(){
	printf("-------------------- Selecione a opção que deseja ----------------------\n");
	printf("01- Cadastrar aluno na chamada\n");
	printf("02- Listar alunos na chamada\n");
	printf("03- Remover alunos na chamada\n");
	printf("04 - Sair\n");
	printf("------------------------------------------------------------------------\n");
	printf("Digite sua opção\n");
}

void cadastrar(){
	Aluno *alunos = (Aluno*)malloc(sizeof(Aluno));
	printf("Digite o Ra do aluno:\n");
	scanf("%d", &alunos->ra);
	printf("Digite o nome do aluno:\n");
	fflush(stdin);
	fgets(alunos->nome, 100, stdin);
	alunos->prox = NULL;
	
	if(inicio == NULL){
		inicio = alunos;
		fim = alunos;
	}else{
		fim->prox = alunos;
		fim = alunos;
	}
	
	printf("Aluno adicionado\n");
	system("pause");
}

void listar(){
	Aluno *aux = inicio;
	printf("\n====== Dados Dos Alunos ======\n");
	while(aux){
		printf("R.A do aluno: %d\n", aux->ra);
		printf("Nome do aluno: %s\n", aux->nome);
		if(aux->prox == NULL){
			printf("Prox == NULL\n");
			printf("===========================\n");
		}else{
			printf("Prox == %d\n", aux->prox);
			printf("===========================\n");
		}
		aux = aux->prox;
	}
	system("pause");
}

void remover(){
	if(inicio == NULL){
		printf("Fila vazia.\n");
	}else{
		Aluno *aux = inicio;
		printf("O Aluno %s foi removido da chamada\n", aux->nome);
		inicio = inicio->prox;
		if(inicio == NULL){
			fim = NULL;
		}
		free(aux);
	}
	system("pause");
}

/*void remover(){
	if(inicio==NULL){
		printf("Fila vazia!\n");
	}else{
		Aluno *aux = inicio;
		printf("Removendo primeiro da fila: %s\n", aux->nome);
		inicio = inicio->prox;
		if(inicio==NULL){
			fim = NULL;
		}
		free(aux);
	}
	system("pause");	
}*/

void sairDoSistema(){
	printf("Saindo do sistema...\n");
	sair = true;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	while(!sair){
		system("CLS");
		menu();
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				cadastrar();
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
				printf("Digite uma opção válida\n");
				system("pause");

		}
	}	
}


