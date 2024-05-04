#include <stdio.h>
#include <stdlib.h>
#define TAMF 10

typedef struct sFila{
    int itens[TAMF];
    int start;
    int end;
} FILA;

void init(FILA *F){
    F->start = TAMF -1;
    F->end = TAMF - 1;
}

int getValue(){
    int value;

    printf("Enter a number: ");
    scanf("%d", &value);

    return value;
}

int isEmpty(FILA* F) { 
    return (F->start == F->end) ? 1 : 0; 
}

int isFull(FILA* F) { 
    return ((F->end - 1) == F->start) ? 1 : 0;  
}

void insertFila(FILA *F, int val){
    if(!isFull(F)) {
        F->itens[F->end] = val;

        if (F->end == 0)
            F->end = TAMF - 1;
        else
            (F->end)--;
    } else {
        printf("Error: Full Queue!\n");
    }
}

int removeFila(FILA *F){
    int aux;

    if (!isEmpty(F)){
        aux = F->itens[F->start];

        if(F->start == 0)
            F->start = TAMF - 1;
        else
            (F->start)--;
    } else {
        printf("\nError: Empty Queue!");
        aux = -1;
    }

    return aux;
}

void displayClassic(FILA F){
    printf("\nQueue:");

    while (!isEmpty(&F))
        printf(" %d", removeFila(&F));
    
    printf("\n");
}

void displayNonClassic(FILA *F){
    int i = F->start;
    
    printf("\nQueue:");

    while (i != F->end) {
        printf(" %d", F->itens[i]);
        
        i = (i == 0) ?  TAMF-1 : i-1;
    }
    
    printf("\n");
}

int menu(){
    int opt;

    printf("Menu:\n");
    printf("1 - Insert elements.\n");
    printf("2 - Remove elements.\n");
    printf("3 - Display classic mode.\n");
    printf("4 - Display non-classic mode.\n");
    printf("0 - Exit the program.\n");
    
    printf("\nEnter your option: ");
    scanf("%d", &opt);

    return opt;
}

int  main(){
    FILA F;
    init(&F);

    int opt;

    while(opt != 0){
        system("cls");
        opt = menu();
        system("cls");

        switch(opt){
            case 0:
                break;

            case 1: //Insert Element
                if(!isFull(&F)){
                    insertFila(&F, getValue());
                    printf("Element inserted successfully!\n");
                } else
                    printf("Error: Full Queue!\n");
                break;
            
            case 2: //Remove element
                if(!isEmpty(&F)){
                    removeFila(&F); 
                    printf("Element removed successfully!\n");
                } else {
                    printf("Error: Empty Queue!\n");
                }
                break;

            case 3: //Display Classic
                if(!isEmpty(&F))
                    displayClassic(F);
                else
                    printf("Error: Empty Queue!\n");
                break;

            case 4: //Display Non Classic
                if(!isEmpty(&F))
                    displayNonClassic(&F);
                else
                    printf("Error: Empty Queue!\n");
                break;
            
            default:
                printf("Invalid Option\n");
                break;
        }

        if (opt != 0) {
            printf("\n");
            system("\npause");
        }
    }
}
