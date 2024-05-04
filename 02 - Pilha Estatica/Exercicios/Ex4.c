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

void passar_para_pilha(PILHA *P, char palavra[]){
    int i = 0;
    int tamanho = strlen(palavra) - 1;

    for (i = 0; i < tamanho; i++)
        push(P, palavra[i]);
}

int comparar_palindromo(PILHA *P, char palavra[]){
    int i = 0;
    int aux = 1;
    int tamanho = strlen(palavra) - 1;

    for (i = 0; i < tamanho; i++) {
        char letra =  pop(P);

        if (palavra[i] != letra)
            aux = 0;
    }

    return aux;
}

int main() {
    PILHA pilha;
    char palavra[TAMF];

    inicializar(&pilha);

    printf("Digite a palavra: ");
    fgets(palavra, sizeof(palavra), stdin);

    passar_para_pilha(&pilha, palavra);
    
    if (comparar_palindromo(&pilha,  palavra))
        printf("\nA palavra eh um palindromo.\n");
    else
        printf("\nA palavra nao eh um palindromo.\n");

    return 0;
}