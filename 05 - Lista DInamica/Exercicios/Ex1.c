#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
    char value;
    struct sCell* next;
} CELL;

void init(CELL **head){
    *head = NULL;
}

CELL *getNode(){
    return (CELL*) malloc(sizeof(CELL));
}

CELL *freeNode(CELL *n){
    free(n);
}

int isEmpty(CELL *head){
    if(head == NULL)  
        return 1;
    else  
        return 0;
}

void insertAtHead(CELL **head, char val){
    CELL* newNode = getNode();
    newNode->value = val;
    newNode->next = (*head);
    (*head) = newNode;
}

char deleteFromHead(CELL **head){
    char res = '\0';
    
    if(!isEmpty(*head)){
        res = ((*head)->value);
        (*head) = (*head)->next;
    } else
        printf("Error: empty list!\n");

    return res;
}

void insertAtEnd(CELL **head, char val){
    CELL* newNode = getNode();
    CELL* temp = *head;
    newNode->value = val;
    newNode->next=NULL;

    if((*head)==NULL){
        (*head)=newNode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

char deleteFromEnd(CELL **head){
    char res = '\0';
    CELL *prev, *current;

    if(isEmpty(*head)) {
        printf("The list is empty.\n");
        return res;  
    } 

    current = *head;
    prev = NULL;

    while (current != NULL) {
        prev = current;
        current = current->next;
    }

    if(prev == NULL)
        *head = NULL;
    else
        prev->next = NULL;
    
    res = current->value;
    free(current);
    return res;
}

void deleteValue(CELL** head, char value){
    CELL* current = *head;
    CELL* previous = NULL;

    if(current != NULL && current->value == value){
        *head = current->next;
        freeNode(current);
        return;
    }

    while(current != NULL && current->value != value){
        previous = current;
        current = current->next;
    }

    if(current != NULL){
        previous->next = current->next;
        freeNode(current);
    }
}

void printList(CELL *head) {
    while (!isEmpty(head)) {
        printf("%c ", head->value);
        head = head->next;
    }
    printf("\n");
}

int menu() {
    int choice;

    printf("\n\tMenu:\n\n");

    printf("1. Insert at Head. \n");
    printf("2. Delete from Head. \n");
    printf("3. Insert at End. \n");
    printf("4. Delete from End. \n");
    printf("5. Print List. \n");
    printf("0. Exit. \n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    CELL *head = NULL;
    char val;
    int choice = -1;

    while (choice != 0) {
        choice = menu();

        switch (choice) {
            case 0:
                break;
            case 1:
                printf("Enter a value: ");
                scanf("%c", &val);
                insertAtHead(&head, val);
                break;
            case 2:
                val = deleteFromHead(&head);
                if (val!= '\0')
                    printf("Deleted value: %c\n", val);
                break;
            case 3:
                printf("Enter a value: ");
                scanf("%c", &val);
                insertAtEnd(&head, val);
                break;
            case 4: //******************************************
                val = removeFromEnd(&head);
                if (val!= '\0')
                    printf("Removed value: %c\n", val);
                break;
            case 5:
                printList(head);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
