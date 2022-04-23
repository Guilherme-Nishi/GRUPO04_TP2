#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include "controle.c"
int main(){

    int opcao, valor;
    No *no = NULL;
    FILE *arquivo = NULL;

    do{
    	printf("\nDigite o numero referente a sua escolha deste menu abaixo:\n");
        printf("\n\t1 - Gera ABP");
        printf("\n\t2 - Calcula Fator de Balanceamento");
        printf("\n\t3 - Imprime ABP");
        printf("\n\t4 - Sair\n\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
        	printf("Digite o nome do arquivo a ser lido: obs:Siga o modelo:");
            printf("Siga o exemplo ./files/arquivo.csv\n\n");
            scanf("%s", Leitura); 

            arquivo = openFile(Leitura);

            if(arquivo == NULL) {
                printf("ABP não gerado, aquivo nulo.\n\n");
                break;
            }
            //raiz = inserir(raiz, valor);
            break;
        case 2:
            printf("\tDigite o valor a ser removido: ");
            if(no){
            	salvaFator(no);
            	printf("Fator de balanceamento gerado e salvo.\n\n");
        	}
        	else{
        		printf("Não foi possivel gerar o fator de balanceamento.\n\n");
			}        
            break;
        case 3:
            imprimir(no, 1);
            break;
        case 4:
            desaloca(no);
            printf("todos os nós foram desalocados!\n");
            break;
        default:
            printf("Digite um numero valido!\n");
        }

    }while(opcao != 4);

    return 0;
}
