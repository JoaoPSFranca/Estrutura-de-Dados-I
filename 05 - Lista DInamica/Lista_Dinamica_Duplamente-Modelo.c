#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
    int data;
    struct sNode *next;
    struct sNode *prev;
} Node;

void init(Node **head){ *head = NULL; }

void freeNode(Node *head){ free(head); }

int isEmpty(Node *head) { return head == NULL; }

Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int getData() { 
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    return data;
}

void addInit(Node **head, int data){
    Node *newNode = createNode(data);
    if(isEmpty(*head)) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void addEnd(Node **head, int data){
    Node *newNode = createNode(data);

    if (isEmpty(*head)) {
        addInit(head, data);
    } else {
        Node *aux = *head;
        
        while (!isEmpty(aux->next)) {
            aux = aux->next;
        }

        aux->next = newNode;
        newNode->prev = aux;
    }
}

void deleteStart(Node **head){
    if (isEmpty(*head)) {
        printf("Error: Empty List. ");
    } else {
        Node *aux = *head;
        *head = aux->next;
        
        if (!isEmpty(*head))
            (*head)->prev = NULL;
        
        freeNode(aux);
    }
}

void deleteEnd(Node **head){
    if (isEmpty(*head)) {
        printf("Error: Empty List");
    } else {
        Node *aux = *head;

        while (!isEmpty(aux->next)) {
            aux = aux->next;
        }

        Node *aux2 = aux->prev;
        aux2->next = NULL;
        freeNode(aux);
    }
}

void printList(Node **head){
    if (isEmpty(*head)) {
        printf("Error: Empty List. ");
    } else {
        Node *aux = *head;

        printf("%d ", aux->data);
        aux = aux->next;

        while (!isEmpty(aux)) {
            printf("-> %d ", aux->data);
            aux = aux->next;
        }

        printf("\n");
    }
}

int menu() {
    int choice;

    printf("\n1. Add node at the beginning\n");
    printf("2. Add node at the end\n");
    printf("3. Delete node at the beginning\n");
    printf("4. Delete node at the end\n");
    printf("5. Print list\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    return choice;
}

int main() {
    Node *head;
    int data, choice;

    init(&head);

    do {
        choice = menu();

        switch (choice) {
            case 1:
                data = getData();
                addInit(&head, data);
                break;
            case 2:
                data = getData();
                addEnd(&head, data);
                break;
            case 3:
                deleteStart(&head);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
                printList(&head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 6);

    return 0;
}