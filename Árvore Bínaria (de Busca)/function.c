#include "function.h"

int max(int a, int b){
	if( a > b ){
		return a;
	}
	return b;
}

int altura(PONT no){
	if( no == NULL ){ 
		// Mesma coisa que usar if(!no)
		return 0;
		}
	return 1 + max( altura(no->esq), altura(no->dir) ); // Percorre a arvore pela esquerda e pela direita para ver qual tem altura maior
}

PONT buscaBinaria(TIPOCHAVE ch, PONT raiz){
	if( !raiz ){
		return NULL;
		}
	if( raiz->chave == ch ){
		return raiz;
		}
	if( raiz->chave < ch ){
		buscaBinaria(ch, raiz->dir);
		}
	else{
		buscaBinaria(ch, raiz->esq);
		}
}

PONT criaNo(TIPOCHAVE ch){
	PONT no = (PONT) malloc( sizeof(NO) );
	no->esq = NULL;
	no->dir = NULL;
	no->chave = ch;
	return no;
}

int inserir(TIPOCHAVE ch, PONT atual){
	PONT ant;
	// Percorre a arvore para a direita ou esquerda até encontrar uma posição NULL (vazia)
	while(atual != NULL){
		ant = atual;
		if( atual->chave < ch )
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	atual = criaNo(ch); // Utiliza a váriavel atual, pois estava 'sobrando'
	if( ant->chave < ch )
		ant->dir = atual;
	else
		ant->esq = atual;
	return 1;
}

PONT buscaNoPai(TIPOCHAVE ch, PONT atual){
	PONT noPai = atual;
	while( atual != NULL ){
		if( atual->chave == ch )
			return noPai;
		noPai = atual;
		if( atual->chave < ch )
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return noPai;
}

void emordem(PONT no){ // E - R - D
	if( !no ){ 
		return 0;
	}
	
	emordem(no->esq);
	printf("%d, ", no->chave);
	emordem(no->dir);
}