#include <stdio.h>
#include <stdlib.h>
#define tamf 10

typedef struct sLista{
    int valor[tamf];
    int n;
} LISTA;

void ler_elemento(int *elem){
    printf("\nIndique o valor desejado: ");
    scanf("%d", elem);
}

void inicializar_lista(LISTA *L){
    L -> n = -1;
}

int lista_cheia(LISTA *L){
    if(L -> n+1 == tamf)
        return 1;
    else
        return 0;
}

int lista_vazia(LISTA *L){
    if(L -> n    == -1)
        return 1;
    else
        return 0;
}

void lista_inserir_fim_valor(LISTA *L, int elem){
    L -> valor[L->n+1] = elem;
    L -> n = L->n+1; 
}

void lista_inserir_fim(LISTA *L){
    int elem;

    if (lista_cheia(L)){
        printf("\nErro - lista cheia\n");
        return;
    }

    ler_elemento(&elem);
    
    lista_inserir_fim_valor(L, elem);
}

void inverter_lista(LISTA *L1, LISTA *L2){
    int i;

    for (i = L1->n; i >= 0; i--)
        lista_inserir_fim_valor(L2, L1->valor[i]);
}

void lista_mostrar(LISTA *L){
    int i;
    
    for (i = 0; i < L->n+1; i++)
        printf(" %d", L->valor[i]);
    
    printf(". \n");
}

int menu(){
    int opt;

    printf("\n1 - Inserir um elemento no final da lista 1. ");
    printf("\n2 - Remover um elemneto do final da lista 1. ");
    printf("\n3 - Inverter lista 1 em lista 2. ");
    printf("\n4 - Exibir os elementos do vetor. ");
    printf("\n0 - Sair. ");

    printf("\n\nIndique a opcao desejada: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    LISTA L1;
    LISTA L2;
    int opt;

    inicializar_lista(&L1); 
    inicializar_lista(&L2);

    do{
        opt = menu();
    
        switch (opt) {
            case 0: 
                break;

            case 1:
                lista_inserir_fim(&L1);
                break;
            
            case 2:
                if (lista_vazia(&L1))
                    printf("Lista Vazia!\n");
                else
                    L1.n = L1.n - 1;
                break;
            
            case 3:
                inicializar_lista(&L2);
                inverter_lista(&L1, &L2);
                break;

            case 4:
                printf("\nLista 1:");
                lista_mostrar(&L1);
                printf("\nInvertida (Lista 2):");
                lista_mostrar(&L2);
                break;

            default:
                printf("\nErro - opcao fora dos limites \n");
                break;
        }

    } while(opt != 0);

    return 0;
}