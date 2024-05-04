#include <stdio.h>
#include <stdlib.h>
#define TAMF 10

typedef struct sDeque{
    int itens[TAMF];
    int start;
    int end;
} DEQUE;

void init(DEQUE *D){
    D->start = TAMF - 1;
    D->end = TAMF - 1;
}

int getItem(){
    int item;

    printf("Enter a number: ");
    scanf("%d", &item);
    
    return item;
}

int isEmpty(DEQUE *D){
    return (D->start == D->end)? 1 : 0;
}

int isFull(DEQUE *D){
    return ((D->end - 1) == D->start) ? 1: 0;
}

void pushFront(DEQUE *D, int item){
    if(isFull(D))
        printf("Error! Deque is full.\n");
    else {
        D->start = (D->start + 1) % TAMF;
        D->itens[D->start] = item;
    }
}

int popFront(DEQUE *D){
    int item;

    if (isEmpty(D))
        printf("Error! Deque is empty.\n");
    else{
        item = D->itens[D->start];
        
        if (D->start == 0)
            D->start = TAMF - 1;
        else
            (D->start)--;
    }

   return item;
}

void pushBack(DEQUE *D, int item){
    if(isFull(D))
        printf("Error! Dequeu is full.\n");
    else {
        D->itens[D->end] = item;
        
        if (D->end == 0)
            D->end =  TAMF - 1;
        else
            (D->end)--;
    }
}

int popBack(DEQUE *D){
    int item;

    if(isEmpty(D))
        printf("Error! Dequeue is Empty!\n");
    else {
        D->end =  (D->end + 1) % TAMF ;
        item = D->itens[D->end];
    }

    return item;
}

void printClassic(DEQUE D){
    printf("Deque:");

    while (!isEmpty(&D))
        printf(" %d", popBack(&D));
    
    printf("\n");    
}

void printNonClassic(DEQUE *D){
    int i =  D->end + 1;

    printf("\nDequeue:");

    while (i != D->start + 1) {
        printf(" %d", D->itens[i]);
        i = (i + 1) % TAMF;
    }
    
    printf("\n");
}

int menu(){
    int opt;
    
    printf("Menu: \n");
    printf("1 - Insert at start. \n");
    printf("2 - Insert at end. \n");
    printf("3 - Remove from start. \n");
    printf("4 - Remove from end. \n");
    printf("5 - Print classic. \n");
    printf("6 - Print non-classic. \n");
    printf("0 - Exit.\n\n");

    printf("Your option: ");
    scanf("%d", &opt);

    return opt;
}

int main(){
    DEQUE D;
    init(&D);
    
    int opt;

    while (opt != 0) {
        opt = menu();
        
        switch(opt) {
            case 0:
                break;
            
            case 1: 
                if (!isFull(&D)) 
                    pushFront(&D, getItem());
                else
                    printf("Error! Deque is full.\n");
                break;
            
            case 2:
                if (!isFull(&D)) 
                    pushBack(&D, getItem());
                else
                    printf("Error! Deque is full.\n");
                break;

            case 3:
                if(!isEmpty(&D))
                    popFront(&D);
                else
                    printf("Error! Deque is empty.\n");
                break;
            
            case 4: 
                if(!isEmpty(&D))
                    popBack(&D);
                else
                    printf("Error! Deque is empty.\n");
                break;
            
            case 5:
                if(!isEmpty(&D))
                    printClassic(D);
                else
                    printf("Deque is empty.\n");
                break;
            
            case 6:
                if(!isEmpty(&D))
                    printNonClassic(&D);
                else
                    printf("Deque is empty.\n");
                break;
            
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    

    return 0;
}