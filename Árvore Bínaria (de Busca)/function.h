#ifndef LISTAENCADEADA_H_DEFINE
#define LISTAENCADEADA_H_DEFINE

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int TIPOCHAVE;

typedef struct AUX{
	TIPOCHAVE chave;
	struct AUX *esq, *dir;
}NO, *PONT; // NO é a estrutura e PONT é um ponteiro de NO

int max(int a, int b);
int altura(PONT no);
PONT buscaBinaria(TIPOCHAVE ch, PONT raiz);
int inserir(TIPOCHAVE ch, PONT atual);
PONT buscaNoPai(TIPOCHAVE ch, PONT atual);
void emordem(PONT no);
void emordem(PONT no);

#endif