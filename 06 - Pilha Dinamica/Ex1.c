#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
    float value;
    struct sCell* next;
} CELL;

float getValue() {
    float value;

    printf("Enter a value: ");
    scanf("%f", &value);

    return value;
}

void init(CELL **head){
    *head = NULL;
}

CELL *getNode(){
    return (CELL*) malloc(sizeof(CELL));
}

void freeNode(CELL *n){
    free(n);
}

int isEmpty(CELL *head){
    if(head == NULL)  
        return 1;
    else  
        return 0;
}

void stack(CELL **head, float val){
    CELL* newNode = getNode();
    newNode->value = val;
    newNode->next = (*head);
    (*head) = newNode;
}

float unStack(CELL **head){
    float res = 0;
    
    if(!isEmpty(*head)){
        res = (*head)->value;
        (*head) = (*head)->next;
    } else
        printf("Error: empty stack!\n");

    return res;
}

void printStack(CELL *head) {
    while (!isEmpty(head))
        printf("%.2f ", unStack(&head));
    
    printf("\n");
}

int menu() {
    int option;

    printf("\n\tStack Menu:\n");
    printf("1. Push a value\n");
    printf("2. Pop a value\n");
    printf("3. Display the stack\n");
    printf("0. Exit\n");
    printf("\nEnter your option: ");
    scanf("%d", &option);

    return option;
}

int main() {
    int option;
    CELL *top = NULL;

    do {
        option = menu();

        switch(option) {
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                stack(&top, getValue());
                break;
            case 2:
                unStack(&top);
                break;
            case 3:
                if(!isEmpty(top))
                    printStack(top);
                else
                    printf("Error: empty stack!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

    } while(option != 0);

    return 0;
}
