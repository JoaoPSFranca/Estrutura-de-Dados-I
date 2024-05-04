#include <stdio.h>
#include <stdlib.h>

typedef struct sNode{
    int data;
    struct sNode *next;
    struct sNode *prev;
    int count;
} Node;

void init(Node **head){ *head = NULL; }

void freeNode(Node *head){ free(head); }

int isEmpty(Node *head){ return head == NULL; }

int getData(){
    int data;

    printf("Enter data: ");
    scanf("%d", &data);

    return data;
}

int getPosition(){
    int pos;

    printf("Enter position: ");
    scanf("%d", &pos);

    return pos;
}

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->count = 0;
    return newNode;
}

void insertInit(Node **head, int data){
    Node *newNode = createNode(data);
    
    if (!isEmpty(*head)){
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

void insertEnd(Node **head, int data){
    if (isEmpty(*head)) {
        insertInit(head, data);
    } else {
        Node *newNode = createNode(data);
        Node *aux = *head;
        
        while(!isEmpty(aux->next)){
            aux = aux->next;
        }

        aux->next = newNode;
        newNode->prev = aux;
    }
}

void deleteInit(Node **head){
    if(isEmpty(*head)){
        printf("Error: Empty List. \n");
    } else {
        Node *aux = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        freeNode(aux);
    }
}

void deleteEnd(Node **head){
    if(isEmpty(*head)){
        printf("Error: Empty List. \n");
    } else {
        Node *aux = *head;

        while (!isEmpty(aux->next)) {
            aux = aux->next;
        }

        Node *auxPrev = aux->prev;
        auxPrev->next = NULL;
        freeNode(aux);
    }
}

int searchPosition(Node **head, int data){
    int pos = 1;

    if (isEmpty(*head)) {
        printf("Error: Empty List. \n");
    } else {
        Node *aux = *head;

        while(!isEmpty(aux) && aux->data != data){
            pos++;
            aux = aux->next;
        }

        if (aux == NULL) {
            printf("Error: Data not Found. \n");
            pos = 0;
        } else { (aux->count)++; }
    }

    return pos;
}

int searchData(Node **head, int pos){
    int count = 1;
    int data = 0;

    if (isEmpty(*head)) {
        printf("Error: Empty List. \n");
    } else {
        Node *aux = *head;

        while(!isEmpty(aux) && pos != count){
            count++;
            aux = aux->next;
        }

        if (aux == NULL) {
            printf("Error: Position not Found. \n");
            data = -1000000;
        } else { data = aux->data; (aux->count)++; }
    }

    return data;
}

Node *searchNode(Node **head, int data){
    Node *search = NULL;

    if (isEmpty(*head)) {
        printf("Error: Empty List. \n");
    } else {
        Node *aux = *head;

        while(!isEmpty(aux) && aux->data != data){
            aux = aux->next;
        }

        if (aux == NULL) {
            printf("Error: Data not Found. \n");
        } else { 
            search = aux;
        }
    }

    return search;
}

void switchNodes(Node **head, Node **current){
    Node *previous = (*current)->prev;        

    previous->next = (*current)->next;
    (*current)->prev = previous->prev;

    if ((*current)->next != NULL) { (*current)->next->prev = previous; }
    previous->prev->next = (*current);
    
    (*current)->next = previous;
    previous->prev = (*current);

    if(*head == previous) { (*head) = (*current); }
}

void transpose(Node **head, int data){
    if (isEmpty(*head)) {
        printf("Error: Empty List. \n");
    } else {
        Node *current = searchNode(head, data);
        
        if (current == NULL) { return; }
        
        if (current->next == NULL && current->prev == NULL) {
            printf("Error: List have only one Node. \n");
            return;
        }

        if (current == *head) { printf("Error: Data is in the head of the list. \n"); }
        else { switchNodes(head, &current); }
    }
}

void moveToFront(Node **head, int data){
    if (isEmpty(*head)) {
        printf("Error: Empty List. \n");
    } else {
        Node *current = searchNode(head, data);

        if (current == NULL) { return; }

        if (current == *head) { printf("The data is already in the beginning. \n"); return; }
        
        Node *previous = current->prev;

        previous->next = current->next;
        (*head)->prev = current;
        
        if (current->next != NULL) { current->next->prev = previous; }

        current->next = *head;
        current->prev = NULL;

        *head = current;
    }
}

void order(Node **head){
    if (isEmpty(*head)){
        printf("Error: Empty List. ");
    } else {
        if ((*head)->next == NULL) { printf("List have only one node. "); return; }
        
        int verify = 1;

        while (verify) {
            Node *aux = (*head)->next;
            verify = 0;
            
            while (!isEmpty(aux)) {
                if (aux->count > aux->prev->count) {
                    switchNodes(head, &aux);
                    verify = 1;
                }
            }
        }
    }
}

void printList(Node **head){
    if (isEmpty(*head)) {
        printf("Error: Empty List. ");
    } else {
        Node *aux = *head;
        
        printf("%d (%d)", aux->data, aux->count);
        aux = aux->next;

        while(!isEmpty(aux)) {
            printf("-> %d (%d)", aux->data, aux->count);
            aux = aux->next;
        }   
    }   
}

void freeList(Node **head) {
    Node *current = *head;
    Node *next;

    while (current!= NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int menu() {
    int option;

    printf("\n\tMenu:\n");
    printf("1. Insert data at the beginning\n");
    printf("2. Insert data at the end\n");
    printf("3. Delete data at the beginning\n");
    printf("4. Delete data at the end\n");
    printf("5. Search data by position\n");
    printf("6. Search position by data\n");
    printf("7. Transpose data\n");
    printf("8. Move data to the front\n");
    printf("9. Order list by count\n");
    printf("10. Print list\n");
    printf("0. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &option);

    return option;
}

int main() {
    Node *head = NULL;
    int option, data, pos;

    init(&head);

    while (1) {
        option = menu();

        switch (option) {
            case 1:
                data = getData();
                insertInit(&head, data);
                break;
            case 2:
                data = getData();
                insertEnd(&head, data);
                break;
            case 3:
                deleteInit(&head);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
                pos = getPosition();
                data = searchData(&head, pos);
                printf("The position %d has the data %d. ", pos, data);
                break;
            case 6:
                data = getData();
                pos = searchPosition(&head, data);
                printf("The data %d is in the position %d. ", data, pos);
                break;
            case 7:
                data = getData();
                transpose(&head, data);
                printList(&head);
                break;
            case 8:
                data = getData();
                moveToFront(&head, data);
                printList(&head);
                break;
            case 9:
                order(&head);
                printList(&head);
                break;
            case 10:
                printList(&head);
                break;
            case 0:
                freeList(&head);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}