#include <stdio.h>
#include <stdlib.h>

typedef struct sCell{
    int value;
    int visited;
    struct sCell* next;
} CELL; 

int getValue() {
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    return value;
}

int getPosition() {
    int position;
    printf("Enter the position: ");
    scanf("%d", &position);
    return position;
}

CELL *getNode(){
    return (CELL*) malloc(sizeof(CELL));
}

void freeNode(CELL *q){
    free(q);
}

CELL *init(CELL *list){
    list = NULL;
    return list;
}

int isEmpty(CELL *list) {
    return list == NULL ? 1 : 0;
}

CELL *insertInit(CELL *list, int value) {
    CELL *newNode = getNode();

    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        return list;
    }

    newNode->value = value;
    newNode->next = list;
    newNode->visited = 0;

    return newNode;
}

CELL *insertEnd(CELL *list, int value) {
    CELL *newNode = getNode();

    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        return list;
    }

    newNode->value = value;
    newNode->next = NULL;
    newNode->visited = 0;

    if (isEmpty(list))
        return newNode;

    CELL *current = list;
    while (current->next != NULL)
        current = current->next;

    current->next = newNode;

    return list;
}

CELL *removeBeginning(CELL *list) {
    if (isEmpty(list)){
        printf("Error: The list is empty.\n");
        return list;
    }

    CELL *removed = list;
    list = list->next;
    free(removed);

    return list;
}

CELL *removeEnd(CELL *list) {
    if (isEmpty(list)){
        printf("Error: The list is empty.\n");
        return list;
    }
    
    if (list->next == NULL)
        return removeBeginning(list);

    CELL *current = list;
    CELL *post = list->next;

    while (post->next != NULL) {
        current = current->next;
        post = post->next;
    }
    
    CELL *removed = post;
    current->next = NULL;
    free(removed);

    return list;
}

CELL *removeVal(CELL *list, int value){
    CELL *current = list;
    CELL *previous = NULL;

    if (isEmpty(list)) {
        printf("Error: The list is empty.\n");
        return list;
    }

    if (current->value == value)
        return removeBeginning(current);

    while (current != NULL && current->value != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Value not found in the list.\n");
        return list;
    }

    previous->next = current->next;
    free(current);

    return list;
}

CELL *insertPosition(CELL *list, int value, int position){
    CELL *newNode = getNode();

    if (newNode == NULL) {
        printf("Error: Memory could not be allocated.\n");
        return list;
    }

    newNode->value = value;

    if (position == 0) {
        newNode->next = list;
        return newNode;
    }

    CELL *current = list;
    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) {
            printf("Error: Position out of bounds.\n");
            free(newNode);
            return list;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Error: Position out of bounds.\n");
        free(newNode);
        return list;
    }

    newNode->next = current->next;
    current->next = newNode;
    newNode->visited = 0;

    return list;
}

void displayList(CELL *list) {
    CELL *current = list;

    while (current != NULL) {
        printf("%d (%d) -> ", current->value, current->visited);
        current = current->next;
    }

    printf("NULL\n");
}

CELL *moveFoward(CELL *list, int value){
    CELL *current, *prev;
    int i = 1;

    if (!isEmpty(list)) {
        if (list->value == value){
            printf("Error: the value is already at the beginning. \n");
            return list;
        }

        current = list;

        while (current != NULL && i != 0) {
            if (current->value == value){
                prev->next = current->next;
                current->next = list;
                i = 0;
            } else {
                prev = current;
                current = current->next;
            }
        }
        
        if(i == 1)
            printf("Error: value not found. ");
        else
            return current;
    } else
        printf("Error: the list is empty. \n");

    return list;
}

CELL *transposition(CELL *list, int value){
    CELL *current, *prev, *post;
    int i = 1;

    if (!isEmpty(list)) {
        if (list->value == value){
            printf("Error: the value wanted need to stay in the position 1 or more. \n");
            return list;
        }
        
        post = list->next;
        current = list;
        prev = list;

        while (post != NULL && i != 0) {
            if (post->value == value){
                current->next = post->next;
                post->next = current;
                
                if (prev != current)
                    prev->next = post;
                else
                    list = post;
                
                i = 0;
            } else {
                prev = current;
                current = post;
                post = post->next;
            }
        }

        if(i == 1)
            printf("Error: value not found. ");
    } else
        printf("Error: the list is empty. \n");
    
    return list;
}

CELL *order(CELL *list){
    CELL *current, *prev, *post;
    int val = 1;

    while (val != 0) {
        post = list->next;
        current = list;
        prev = list;
        val = 0;

        while (post != NULL) {
            if (post->visited > current->visited){
                current->next = post->next;
                post->next = current;
                
                if (prev != current)
                    prev->next = post;
                else
                    list = post;
                
                CELL *aux = post;
                post = current;
                current = aux;

                val = 1;
            }

            prev = current;
            current = post;
            post = post->next;
        }
    }

    return list;
}

CELL *search(CELL *list, int value){
    CELL *current = list;
    CELL *wantedCell = list;
    int pos = 0;

    while (current != NULL) {
        if (current->value == value){
            wantedCell = current;
            break;
        }
        current = current->next;
        pos++;
    }

    if(wantedCell == list)
        printf("Error: Value not found in the list. \n");
    else
        printf("Value %d was found at position %d. \n", value, pos);

    (wantedCell->visited)++;

    return wantedCell;
}

int menu() {
    int choice;

    printf("\n\tList Menu:\n\n");
    printf(" 1. Insert at the beginning. \n");
    printf(" 2. Insert at the end. \n"); 
    printf(" 3. Insert at a specific position. \n");
    printf(" 4. Remove from the beginning. \n");
    printf(" 5. Remove from the end. \n");
    printf(" 6. Remove a specific value. \n");
    printf(" 7. Search for a value. \n");
    printf(" 8. Display the list. \n");
    printf(" 9. Move a value to the front. \n");
    printf("10. Perform a transposition. \n");
    printf("11. Order list by acess. \n");
    printf(" 0. Exit. \n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}

int main() {
    CELL *list = init(list);
    int choice, value, position;

    do {
        choice = menu();

        switch (choice) {
            case 0:
                printf("\nExiting...\n");
                break;
            case 1:
                value = getValue();
                list = insertInit(list, value);
                displayList(list);
                break;
            case 2:
                value = getValue();
                list = insertEnd(list, value);
                displayList(list);
                break;
            case 3:
                value = getValue();
                position = getPosition();
                list = insertPosition(list, value, position);
                displayList(list);
                break;
            case 4:
                list = removeBeginning(list);
                displayList(list);
                break;
            case 5:
                list = removeEnd(list);
                displayList(list);
                break;
            case 6:
                value = getValue();
                list = removeVal(list, value);
                displayList(list);
                break;
            case 7:
                value = getValue();
                displayList(list);
                search(list, value);
                break;
            case 8:
                displayList(list);
                break;
            case 9:
                value = getValue();
                list = moveFoward(list, value);
                displayList(list);
                break;
            case 10:
                value = getValue();
                list = transposition(list, value);
                displayList(list);
                break;
            case 11:
                printf("Pre-order List: ");
                displayList(list);
                list = order(list);
                printf("Ordered List: ");
                displayList(list);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
