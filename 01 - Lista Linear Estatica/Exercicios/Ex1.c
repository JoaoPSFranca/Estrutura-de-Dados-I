#include <stdio.h>
#include <stdlib.h>
#define tamf 10

typedef struct sLista{
    int valor[tamf];
    int n;
} LISTA;

void ler_posicao(int *posicao){
    printf("Indique a posicao desejada: ");
    scanf("%d", posicao);
}

void ler_elemento(int *elem){
    printf("Indique o valor desejado: ");
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

void lista_inserir_posicao(LISTA *L){ 
    int k, elem;
    int i;

    ler_posicao(&k);

    if (lista_cheia(L)){
        printf("\nErro - lista cheia\n");
        return;
    }
    else{
        if(k < 0 || k > L->n+1){
            printf("\nErro - elemento fora dos limites\n");
        }
    }

    ler_elemento(&elem);

    for (i = (L->n+1); i > k; i--) {
        L->valor[i] = L->valor[i-1];
    }

    L->valor[k] = elem;
    L->n = L->n+1;
}

void lista_remover_posicao (LISTA *L) {
    int i; 
    int k;

    ler_posicao(&k);
    
    if (k < 0 || k > L->n) {
        printf("\nErro - elemento fora dos limites\n");
    }

    for (i = k; i < (L->n); i++) {
        L->valor[i] = L->valor [i+1];
    }
    
    L->n = L->n-1;
}

void lista_acessar_posicao(LISTA *L){
    int k;
    ler_posicao(&k);

    if (k < 0 || k > L->n)
        printf("\nErro - elemento fora dos limites\n");
    else
        printf("\nO olemento da posicao %d possui valor %d. \n", k, L->valor[k]);
}

void lista_buscar (LISTA *L){
    int elem = -1;
    int i = 0;
    int val;

    ler_elemento(&val);
    
    for (i = 0; i < L -> n+1; i++) {
        if (val == L -> valor[i]) {
            elem = i;
            break;
        }
    }

    printf("\nO olemento de valor %d esta na posicao %d. \n", val, elem);
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

    printf("\n1 - Inserir um elemento em uma posicao especifica. ");
    printf("\n2 - Remover um elemento de uma posicao especifica. ");
    printf("\n3 - Acessar um elemento de uma posicao especifica ");  
    printf("\n4 - Procurar um determinado elemento. ");
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
                lista_inserir_posicao(&lista);
                break;
            
            case 2: 
                lista_remover_posicao(&lista);
                break;

            case 3:
                lista_acessar_posicao(&lista);
                break;

            case 4:
                lista_buscar(&lista);
                break;

            case 5:
                lista_mostrar(&lista);
                break;

            default:
                printf("\nErro - opcao fora dos limites\n");
                break;
        }

    } while(opt != 0);

    return 0;
}