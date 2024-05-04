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

void lista_inserir_inicio(LISTA *L){
    int elem;
    int i;

    if (lista_cheia(L)){
        printf("\nErro - lista cheia\n");
        return;
    }
    
    ler_elemento(&elem);
    
    for (i = (L->n+1); i > 0; i--) {
        L->valor[i] = L->valor[i-1];
    }

    L->valor[0] = elem;
    L->n = L->n+1;
}

void lista_inserir_fim(LISTA *L){
    int elem;

    if (lista_cheia(L)){
        printf("\nErro - lista cheia\n");
        return;
    }
    
    ler_elemento(&elem);
    
    L -> valor[L->n+1] = elem;
    L -> n = L->n+1; 
}

void lista_remover_inicio (LISTA *L) {
    int i; 

    for (i = 0; i < (L->n); i++) {
        L->valor[i] = L->valor [i+1];
    }
    
    L->n = L->n-1;
}

void lista_mostrar(LISTA *L){
    int i;

    for (i = 0; i < L->n+1; i++) {
        printf("\n----------------");
        printf("\n  Posicao:.%d", i);
        printf("\n  Valor:...%d", L->valor[i]);
    }
    
    printf("\n----------------\n");
}

int menu(){
    int opt;

    printf("\n1 - Inserir um elemento no inicio da lista. ");
    printf("\n2 - Inserir um elemento no final da lista. ");
    printf("\n3 - Remover um elemento do inicio da lista. ");  
    printf("\n4 - Remover um elemento do final da lista. ");
    printf("\n5 - Exibir os elementos do vetor. ");
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
                lista_inserir_inicio(&lista);
                break;
            
            case 2:
                lista_inserir_fim(&lista);
                break;

            case 3:
                lista_remover_inicio(&lista);
                break;
                
            case 4:
                if (lista_vazia(&lista))
                    printf("Lista Vazia!\n");
                else
                    lista.n = lista.n - 1;
                break;

            case 5:
                lista_mostrar(&lista);
                break;

            default:
                printf("\nErro - opcao fora dos limites");
                break;
        }

    } while(opt != 0);

    return 0;
}