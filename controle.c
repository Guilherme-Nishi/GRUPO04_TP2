#include "controle.h"

//aloca novo nó
No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->Chave = x;
        novo->pEsq = NULL;
        novo->pDir = NULL;
        novo->FatBal = 0;
    }
    else
        printf("\nNão foi possivel alocar um novo No!\n");
    return novo;
}

//  Retorna a altura de um nó ou -1 caso ele seja nulo
int altura(No *no){
    if(no == NULL){
        return -1;
    }
    else{
        int esq = altura( no->pEsq );
        int dir = altura( no->pDir );
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

//   Calcula e retorna o fator de balanceamento de um nó
void fatorDeBalanceamento(No *no){	
    
    int esq = altura(no->pEsq);
    int dir = altura(no->pDir);
    if(dir == -1){
    	dir = 0;
	}
	if(esq == -1){
		esq = 0;
	}
    no->FatBal = (esq - dir);
    
}

//passa por cada no para ser impressa
void imprimir(No *no, int nivel){
    int i;
    if(no){
        imprimir(no->pEsq, nivel + 1);
        printf("\n\n");
        printf("Chave: %d FB: %d", no->Chave, no->FatBal);
        imprimir(no->pDir, nivel + 1);
    }
}

//passa por cada nó para ser desalocado
void salvaFator(No *no){
    if(no){
        salvaFator(no->pDir);
        fatorDeBalanceamento(no);
        salvaFator(no->pEsq);
    }
}

//desalocar cada um dos nos
void desaloca(No *no){
    if(no){
        desaloca(no->pDir);
        desaloca(no->pEsq);
        free(no);
    }
}

//função cria a arvore e retorna
No* criaArvore(No *no, int x){
    if(no == NULL) 
        return novoNo(x);
    else{ 
        if(x < no->Chave)
            no->pEsq = criaArvore(no->pEsq, x);
        else if(x > no->Chave)
            no->pDir = criaArvore(no->pDir, x);
        else
            printf("\nElemento %d ingnorado pois já existe.\n", x);
    }
    return no;
}


