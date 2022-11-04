#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "function.c"

int main(){
	PONT noArvore = criaNo(6);

	inserir(2, noArvore);
	inserir(1, noArvore);
	inserir(4, noArvore);
	inserir(7, noArvore);
	inserir(8, noArvore);
	inserir(3, noArvore);
	inserir(5, noArvore);

	int valorBuscado = 7;
	if( buscaBinaria(valorBuscado, noArvore) ){
		printf("Busca : %d\n", buscaBinaria(valorBuscado, noArvore)->chave );
		}

	else{
		printf("Não encontrou\n");
		}

	printf("Em-ordem: ");
	emordem(noArvore);

	printf("\nAltura: %d\n", altura(noArvore) );
	return 0;
}