#include <stdio.h>
#include <stdlib.h>
#define TAMF 10

typedef struct sPilha {
    int itens[TAMF];
    int top;
} PILHA;

void init(PILHA *P){
    P->top = -1;
}

int getValue(){
    int value;
    printf("Enter a value: ");
    scanf("%d", &value);
    return value;
}

int isEmpty(PILHA *P){
    return (P->top == -1) ? 1 : 0;
}

int isFull(PILHA *P){
    return (P->top == TAMF - 1) ? 1 : 0;
}

void insertPilha(PILHA *P, int value){
    P->top++;
    P->itens[P->top] = value;
}

int removePilha(PILHA *P){
    int aux;

    aux = P->itens[P->top]; 
    P->top--;

    return aux;
}

void displayPilha(PILHA P){
    PILHA V;
    init(&V);

    while (!isEmpty(&P))
        insertPilha(&V, removePilha(&P));

    printf("Values in the stack:");
    
    while (!isEmpty(&V))
        printf(" %d", removePilha(&V));
    
    printf("\n");
}

int menu(){
    int opt;

    printf("\nChoose an option:\n");
    printf("1. Insert element\n");
    printf("2. Remove element\n");
    printf("3. Display elements\n");
    printf("0. Exit\n\n");
    
    printf("Option: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    PILHA pilha;
    int opt;

    init(&pilha);

    while (opt != 0) {
        opt = menu();

        switch (opt){
            case 0:
                break;

            case 1:
                if (isFull(&pilha))
                    printf("Stack is full!\n");
                else
                    insertPilha(&pilha, getValue());
                break;

            case 2:
                if (isEmpty(&pilha))
                    printf("Stack is empty!\n");
                else
                    removePilha(&pilha);
                break;

            case 3:
                if (isEmpty(&pilha))
                    printf("The stack is empty.\n");
                else
                    displayPilha(pilha);
                break;
            
            default:
                printf("Invalid option! Try again.\n");
                break;
        }
    }
}