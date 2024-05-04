#include <stdio.h>
#include <stdlib.h>

typedef struct sNode {
    int data;
    struct sNode *next;
} Node;

Node *getNode(){
    return (Node *)malloc(sizeof(Node));
}

void freeNode(Node *head){
    free(head);
}

int isEmpty(Node *head){
    if(head == NULL)
        return 1;
    return 0;
}

int getData(){
    int data;
    
    printf("Enter data: ");
    scanf("%d", &data);
    
    return data;
}

int getPosition(){
    int position;

    printf("Enter position: ");
    scanf("%d", &position);

    return position;
}

Node *insertInit(Node *head, int data){
    Node *newNode = getNode();

    newNode->data = data;
    newNode->next = head;

    return newNode;
}

Node *insertEnd(Node *head, int data){
    if (!isEmpty(head)){
        Node *newNode = getNode();
        newNode->data = data;
        newNode->next = NULL;
    
        Node *aux = head;

        while(!isEmpty(aux->next))
            aux = aux->next;
        
        aux->next = newNode;
    } else { head = insertInit(head, data); }
    
    return head;
}

Node *insertPosition(Node *head, int data, int pos){
    if(pos-1 == 0)
        head = insertInit(head, data);
    else{
        int cont = 0;
        Node *aux = head;

        while(!isEmpty(aux) && pos != cont){
            if(pos-2 == cont){
                Node *newNode = getNode();
                newNode->data = data;
                newNode->next = aux->next;
                aux->next = newNode;
            } else {
                aux = aux->next;
                cont++;
            }
        }

        if(pos != cont)
            printf("Error: Position out of range. ");
    }

    return head;
}

Node *deleteInit(Node *head){
    if(!isEmpty(head)){
        Node *aux = head;
        head = head->next;
        freeNode(aux);
    } else
        printf("Error: Empty List. ");

    return head;
}

Node *deleteEnd(Node *head){
    if(!isEmpty(head)){
        if (head->next == NULL)
            head = deleteInit(head);
        else{
            Node *aux = head;
            Node *aux2 = head->next;
            while(!isEmpty(aux2->next)){
                aux = aux2;
                aux2 = aux2->next;
            }
            aux->next = NULL;
            freeNode(aux2);
        }
    } else 
        printf("Error: Empty List. ");

    return head;
}

Node *deleteData(Node *head, int data){
    if(!isEmpty(head)){
        if(head->data == data)
            head = deleteInit(head);
        else{
            Node *aux = head;
            Node *aux2 = head->next;

            while(!isEmpty(aux2) && aux2->data != data){
                aux = aux2;
                aux2 = aux2->next;
            }

            if(aux2->data == data){
                aux->next = aux2->next;
                freeNode(aux2);
            }
            else
                printf("Error: Data not found. ");
        }
    } else
        printf("Error: Empty List. ");
    
    return head;
}

Node *deletePosition(Node *head, int pos){
    if(pos-1 == 0)
        head = deleteInit(head);
    else{
        int cont = 0;
        Node *aux = head;
        Node *aux2 = head->next;

        while(!isEmpty(aux2) && pos != cont){
            if(pos-2 == cont){
                aux->next = aux2->next;
                freeNode(aux2);
                pos = cont;
            } else {
                aux = aux2;
                aux2 = aux2->next;
                cont++;
            }
        }
        if(pos != cont)
            printf("Error: Position out of range. ");
    }

    return head;
}

void printList(Node *head){
    Node *aux = head;
    
    printf("%d ", aux->data);
    aux = aux->next;
    
    while (!isEmpty(aux)) {
        printf("-> %d ", aux->data);
        aux = aux->next;
    }

    printf("\n");
}

int menu() {
    int option;

    printf("\nSelect an option: \n");
    printf("1. Insert data at the beginning. \n");
    printf("2. Insert data at the end. \n");
    printf("3. Insert data at a specific position. \n");
    printf("4. Delete data at the beginning. \n");
    printf("5. Delete data at the end. \n");
    printf("6. Delete data at a specific position. \n");
    printf("7. Delete a specific data. \n");
    printf("8. Print list. \n");
    printf("0. Exit. \n");
    printf("> ");
    scanf("%d", &option);

    return option;
}

int main() {
    Node *head = NULL;
    int data, position, option;

    do {
        option = menu();

        switch (option) {
            case 1:
                data = getData();
                head = insertInit(head, data);
                break;
            case 2:
                data = getData();
                head = insertEnd(head, data);
                break;
            case 3:
                data = getData();
                position = getPosition();
                head = insertPosition(head, data, position);
                break;
            case 4:
                head = deleteInit(head);
                break;
            case 5:
                head = deleteEnd(head);
                break;
            case 6:
                position = getPosition();
                head = deletePosition(head, position);
                break;
            case 7:
                data = getData();
                head = deleteData(head, data);
                break;
            case 8:
                printList(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 0);

    return 0;
}