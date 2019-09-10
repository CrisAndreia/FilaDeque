#include <stdio.h>
#include <stdlib.h>
#include "FilaDeque.h"

/*
Deque 

			| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
			---------------------------------
			| 6 | 5 | 7 |   |   |   | 4 | 11|
			
	dados = vetor
	capacidade = 8
	inicio = 6
	fim=2
*/

int main(void) {
	
	Fila f;
	
	inicializa_fila (&f, 6);
	
	inserirDireita(&f, 1);
	inserirDireita(&f, 2);
	inserirDireita(&f, 3);
	
	inserirEsquerda(&f, 4);
	inserirEsquerda(&f, 5);
	inserirEsquerda(&f, 6);

	mostra_fila(f);
	desaloca_fila(&f);

}
