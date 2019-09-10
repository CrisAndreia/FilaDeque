# FilaDeque
Implementando Fila em C

#include <stdio.h>
#include <stdlib.h>
#include "FilaDeque.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void inicializa_fila (Fila *p, int c){	//Recebe ponteiro de fila e a capacidade da fila
	p->dados=malloc(sizeof(int)*c);
	p->capacidade = c;
	p->inicio = 1; 
	p->fim=p->num_ele=0;	
}

int fila_vazia(Fila f){
	return f.num_ele==0;
}

int fila_cheia (Fila f){	//Recebe fila
	return f.num_ele==f.capacidade;
}

int inserirDireita(Fila *p, int info){		//Recebe ponteiro de fila e o valor a ser inserido
	if(fila_cheia(*p))
		return ERRO_FILA_CHEIA;
	p->num_ele++;
	if(p->fim == p->capacidade-1){
		p->fim=0;
	}
	else{
		p->fim++;
	}
	p->dados[p->fim]=info;
  return 1;
}

int inserirEsquerda(Fila *p, int info){		//Recebe ponteiro de fila e o valor a ser inserido
	if(fila_cheia(*p))
		return ERRO_FILA_CHEIA;
	p->num_ele++;
	if(p->inicio == 0){
		p->inicio=p->capacidade-1;
	}
	else{
		p->inicio--;
	}
	p->dados[p->inicio-1]=info;
  return 1;
}

int removerEsquerda(Fila *p, int *info){	// Recebe o ponteiro de fila e o valor a ser removido;
	if(fila_vazia(*p))
		return ERRO_FILA_VAZIA;
	p->num_ele--;
	*info = p->dados[p->inicio];
	if(p->inicio == p->capacidade-1)
		p->inicio = 0;
	else
		p->inicio++;
	return 1;
}

int removerDireita(Fila *p, int *info){	// Recebe o ponteiro de fila e o valor a ser removido;
	if(fila_vazia(*p))
		return ERRO_FILA_VAZIA;
	p->num_ele--;
	*info = p->dados[p->fim];
	if(p->fim == 0)
		p->fim = p->capacidade-1;
	else
		p->fim--;
	return 1;
}

void mostra_fila(Fila p){
	int i;
	if(fila_vazia(p))
	printf("Fila vazia!\n");
	else{
		printf("Dados da fila:\n");
		if(p.inicio<p.fim){
			for(i=p.inicio; i<=p.fim; i++){
				printf("%d\n", p.dados[i]);
			}
		}
		else{
			for(i=p.inicio;i<p.capacidade;i++){
				printf("%d\n", p.dados[i]);
			}
		    for(i=0;i<=p.fim;i++){
			    printf("%d\n",p.dados[i]);
		   }
		}
	}
}

void desaloca_fila(Fila *p){
	free(p->dados);
}

