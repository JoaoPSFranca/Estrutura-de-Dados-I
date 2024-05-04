#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

typedef struct sCell {
    char channel[TAM];
    struct sCell *next;
    struct sCell *prev;
} CELL;

void init(CELL **head) { *head = NULL; }

int isEmpty(CELL *head) { return (head == NULL); }

CELL *getNode(){ return (CELL*) malloc(sizeof(CELL)); }

void getChannelName(char channel[]) {
    printf("Enter the name of the channel: ");
    scanf("%s", channel);
}

void addInit(CELL **head, char chan[]){
    CELL *newCell = getNode();

    if (newCell != NULL) {
        if (!isEmpty(*head)) {
            strcpy(newCell->channel, chan);
            
            newCell->prev = NULL;
            newCell->next = *head;

            (*head)->prev = newCell;
            *head = newCell;
        } else {
            strcpy(newCell->channel, chan);
            newCell->next = NULL;
            newCell->prev = NULL;
            *head = newCell;
        }
    } else 
        printf("Error: Could not alocate memory for the new cell.\n");
}

void addEnd(CELL **head, char chan[]){
    CELL *newCell = getNode();
    CELL *aux = *head;

    if(newCell != NULL){
        if (!isEmpty(*head)){
            while (aux->next != NULL) 
                aux = aux->next;

            strcpy(newCell->channel, chan);
            aux->next = newCell;
            newCell->prev = aux;
            newCell->next = NULL;
        } else  
            addInit(head, chan);
    } else
        printf("Error: Could not alocate memory for the new cell.\n");
}

void printCell(CELL  *cell) {
    printf("\n\tPrevious channel: %s\n", cell->prev->channel);
    printf("\tCurrent channel: %s\n", cell->channel);
    printf("\tNext channel: %s\n", cell->next->channel);
}

CELL *getNext(CELL **head, CELL **curr) {
    if ((*curr)->next == NULL){
        *curr = *head;
        return *curr;
    }
    else{
        *curr = (*curr)->next;
        return *curr;
    }
}

CELL *getPrev(CELL **curr){
    if((*curr)->prev == NULL){
        CELL *aux = *curr;

        while (aux->next != NULL) 
            aux = aux->next;

        *curr = aux;
        return *curr;
    } else{
        *curr = (*curr)->prev;
        return *curr;
    }
}

int menu(){
    int opt;

    printf("\n\n\tMenu:\n");
    printf("1. Add channel to the beginning of the list\n");
    printf("2. Add channel to the end of the list\n");
    printf("3. Go to next channel\n");
    printf("4. Go to previous channel\n");
    printf("0. Exit\n");

    printf("\nChoose an option: ");
    scanf("%d", &opt);

    return opt;
}

int main() {
    CELL *head = NULL;
    CELL *current = NULL;
    char channel[TAM];
    int opt;

    do {
        if (current != NULL)
            printCell(current); 
        opt = menu();

        switch (opt) {
            case 0:
                printf("Goodbye!\n");
                break;
            case 1:
                getChannelName(channel);
                addInit(&head, channel);
                if (current == NULL)
                    current = head; 
                break;
            case 2:
                getChannelName(channel);
                addEnd(&head, channel);
                if (current == NULL)
                    current = head; 
                break;
            case 3:
                current = getNext(&head, &current);
                break;
            case 4:
                current = getPrev(&current);
                break;
            default:
                printf("Invalid option, try again.\n");
        }
    } while (opt != 0);

    return 0;
}