#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMF 20

typedef struct sPilha{
    char letra[TAMF];
    int topo;
} PILHA;

void inicializar(PILHA *P){
    P->topo = -1;
}

int vazia(PILHA *P){
    if (P->topo == -1){
        printf("\nERRO - Pilha vazia! \n");
        return 1;
    }

    return 0;
}

int cheia(PILHA *P){
    if (P->topo+1 == TAMF){
        printf("\nERRO - Pilha Cheia! \n");
        return 1;
    }

    return 0;
}

void push(PILHA *P, char item) {
    if (!cheia(P)) {
        P->topo = P->topo+1;
        P->letra[P->topo] = item;
    } 
}

char pop(PILHA *P) {
    if(!vazia(P)){
        char elem = P->letra[P->topo];
        P->topo = P->topo-1;
        return elem;
    }

    return '\0';  
}

void inverter_pilha(PILHA *P){
    char Aux[TAMF];
    int i=0;

    while (!vazia(P)) {
        Aux[i] = pop(P);        
        i++;
    }
    
    for (i=0; i < strlen(Aux); i++) {
        push(P,Aux[i]);
    }
}

int main(){
    

    return 0;
}