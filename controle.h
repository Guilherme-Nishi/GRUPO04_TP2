#ifndef __CONTROLE__H
#define __CONTROLE__H

typedef struct No{
	int Chave;
	struct No *pEsq, *pDir;
	int FatBal;
}No;

No* novoNo(int x);

int altura(No *no);

void fatorDeBalanceamento(No *no);

void imprimir(No *no, int nivel);

void salvaFator(No *no);

void desaloca(No *no);

No* criaArvore(No *no, int x);	

#endif

