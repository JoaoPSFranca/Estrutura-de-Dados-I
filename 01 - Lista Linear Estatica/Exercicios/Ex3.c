#include <stdio.h>
#include <stdlib.h>
#define tamf 10

typedef struct sLista{
    float valor[tamf];
    int n;
} LISTA;

void ler_elemento(float *elem){
    printf("\nIndique o valor desejado: ");
    scanf("%f", elem);
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

int lista_buscar (LISTA *L){
    int k = -1;
    int i = 0;
    float elem;

    ler_elemento(&elem);
    
    for (i = 0; i < L -> n+1; i++) {
        if (elem == L -> valor[i]) {
            k = i;
            break;
        }
    }

    return k;
}

void lista_remover_posicao (LISTA *L) {
    int i; 
    int k = lista_buscar(L);

    if (k == -1){
        printf("\nElemento nao encontrado. \n");
        return;
    }

    for (i = k; i < (L->n); i++) {
        L->valor[i] = L->valor [i+1];
    }
    
    L->n = L->n-1;
}

void lista_inserir_posicao(LISTA *L, int k, float elem){ 
    int i;

    for (i = (L->n+1); i > k; i--) {
        L->valor[i] = L->valor[i-1];
    }

    L->valor[k] = elem;
    L->n = L->n+1;
}

void lista_adicionar_crescente(LISTA *L){
    float elem; 
    int i, k = -1;
    
    ler_elemento(&elem);

    if (lista_cheia(L)) {
        printf("\nLista cheia.\n");
        return;
    }
    
    if (lista_vazia(L)) {
        lista_inserir_posicao(L, 0, elem);
        return;
    }
    
    for (i = 0; i < L -> n+1; i++) {
        if (elem < L -> valor[i]) {
            k = i;
            break;
        }
    }

    if (k == -1) {
        L -> valor[L->n+1] = elem;
        L -> n = L->n+1; 
        return;
    }
    
    lista_inserir_posicao(L, k, elem);
    
}

void lista_mostrar(LISTA *L){
    int i;

    printf("\nLista ordenada:");
    
    for (i = 0; i < L->n+1; i++)
        printf(" %.2f", L->valor[i]);
    
    printf(". \n");
}

int menu(){
    int opt;

    printf("\n1 - Inserir um elemento na lista. ");
    printf("\n2 - Remover um elemneto da lista. ");
    printf("\n3 - Exibir os elementos do vetor. ");
    printf("\n0 - Sair. ");

    printf("\n\nIndique a opcao desejada: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    LISTA lista;
    int opt;

    inicializar_lista(&lista); 

    do{
        opt = menu();
    
        switch (opt) {
            case 0: 
                break;

            case 1:
                lista_adicionar_crescente(&lista);
                break;
            
            case 2:
                lista_remover_posicao(&lista);
                break;

            case 3:
                lista_mostrar(&lista);
                break;

            default:
                printf("\nErro - opcao fora dos limites");
                break;
        }

    } while(opt != 0);

    return 0;
}