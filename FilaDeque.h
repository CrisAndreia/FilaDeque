# FilaDeque
Implementando Fila em C

#define ERRO_FILA_CHEIA -1
#define ERRO_FILA_VAZIA -2

typedef struct{
	int *dados;
	int capacidade;
	int inicio, fim, num_ele;
}Fila;

void inicializa_fila (Fila *p, int c);
int inserirDireita(Fila *p, int info);
int inserirEsquerda(Fila *p, int info);
int fila_vazia(Fila f);
int fila_cheia (Fila f);
int removerDireita(Fila *p, int *info);
int removerEsquerda(Fila *p, int *info);
void mostra_fila(Fila p);
void desaloca_fila(Fila *p);
