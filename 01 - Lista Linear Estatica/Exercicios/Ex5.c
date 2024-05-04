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

void lista_mostrar(LISTA *L){
    int i;
    
    for (i = 0; i < L->n+1; i++)
        printf(" %d", L->valor[i]);
    
    printf(". \n");
}

void intercalar_listas(LISTA *L1, LISTA *L2, LISTA *L3){
    int i;
    int  j = 0;
    int k = 0;

    for (i = 0; i < ((L2->n+1) + (L1->n+1)); i++){
        if (lista_cheia(L3)){
            printf("\nErro - lista cheia.\n");
            break;
        }

        if (i%2 == 0){
            if (L1->n >= j)
                lista_inserir_fim_valor(L3, L1 -> valor[j]);
            j++;
        } else {
            if (L2->n >= k)
                lista_inserir_fim_valor(L3, L2 -> valor[k]);
            k++;
        }
    }
}

int menu(){
    int opt;

    printf("\n1 - Inserir um elemento no final da lista 1. ");
    printf("\n2 - Remover um elemneto do final da lista 1. ");
    printf("\n3 - Inserir um elemento no final da lista 2. ");
    printf("\n4 - Remover um elemneto do final da lista 2. ");
    printf("\n5 - Intercalar listas 1 e 2 na lista 3. ");
    printf("\n6 - Exibir os elementos do vetor. ");
    printf("\n0 - Sair. ");

    printf("\n\nIndique a opcao desejada: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    LISTA L1;
    LISTA L2;
    LISTA L3;
    int opt;

    inicializar_lista(&L1); 
    inicializar_lista(&L2);
    inicializar_lista(&L3);

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
                lista_inserir_fim(&L2);
                break;
            
            case 4:
                if (lista_vazia(&L2))
                    printf("Lista Vazia!\n");
                else
                    L2.n = L2.n - 1;
                break;
            
            case 5:
                inicializar_lista(&L3);
                intercalar_listas(&L1, &L2, &L3);
                break;

            case 6:
                printf("\nLista 1:");
                lista_mostrar(&L1);
                printf("\nLista 2:");
                lista_mostrar(&L2);
                printf("\nIntercalada (Lista 3):");
                lista_mostrar(&L3);
                break;

            default:
                printf("\nErro - opcao fora dos limites \n");
                break;
        }

    } while(opt != 0);

    return 0;
}