#include <stdio.h>
#include <stdlib.h>
#define TAMF 10

typedef struct sList {
    int itens[TAMF];
    int n;
} LIST;

void initialize(LIST *L){
    L->n = -1;
}

int getValue(){
    int value;
    printf("\nInsert an value: ");
    scanf( "%d", &value);
    return value;
}

int getPosition(){
    int pos;
    printf("\nInsert the position (0-%d): ", TAMF-1);
    scanf("%d",&pos);

    if(pos < 0 || pos > TAMF-1)
        return -1;

    return pos;
}

int empty(LIST *L){
    return (L->n == -1)  ? 1 : 0;
}

int full(LIST *L){
    return (L->n == TAMF - 1) ? 1 : 0;
}

void insertIten(LIST *L, int value, int k){
    L->n++;
    L->itens[k] = value;
}

void removeIten(LIST *L, int k) {
    int i;

    for (i = k; i < L->n; i++)
        L->itens[i] = L->itens[i+1];
    
    L->n--;
}

void display(LIST *L){
    int i;

    printf("Lista:");

    for (i = 0; i < L->n+1; i++) 
        printf(" %d", L->itens[i]);
    
    printf("\n");
}

int search(LIST *L, int value){
    int i;
    int pos = -1;

    for(i = 0; i < L->n; i++){
        if (L->itens[i] == value) {
            pos = i;
            i = L-> n;
        }
    }

    return pos;
}

int menu(){
    int opt;

    printf("1. Insert Element. \n");
    printf("2. Remove  Element. \n");
    printf("3. Print List. \n");
    printf("4. Search value. \n");
    printf("0. Exit Program.\n\n");

    printf("Your option: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    LIST L;
    int  opt, pos;

    initialize(&L);

    while (opt !=  0) {
        opt = menu();

        switch (opt) {
            case 0:
                break;
            
            case 1:
                if (full(&L))
                    printf("\nError! The list is full\n\n");
                else{
                    pos = getPosition();
                    if (pos == -1 ||  pos > L.n + 1)
                        printf("\nInvalid position!\n\n");
                    else
                        insertIten(&L, getValue(), pos);
                }
                break;

            case 2:
                if (empty(&L))
                    printf("\nError! The list is empty\n\n");
                else{
                    pos = getPosition();
                    if (pos == -1 || pos > L.n + 1)
                        printf("Invalid position!\n");
                    else
                        removeIten(&L, pos);
                }
                break;
            
            case  3:
                if (empty(&L))
                    printf("\nError! The list is empty\n\n");
                else
                    display(&L);
                break;
            
            case  4:
                if (empty(&L))
                    printf("\nError! The list is empty\n\n");
                else {
                    pos = search(&L, getValue());
                    
                    if (pos == -1)
                        printf("\nElement not found in the list.\n\n");
                    else
                        printf("\nThe element was found at position %d.\n", pos);
                }
                break;

            default:
                printf("\nError: invalid option! \n\n");
                break;
        }
    }
    

    return 0;
}