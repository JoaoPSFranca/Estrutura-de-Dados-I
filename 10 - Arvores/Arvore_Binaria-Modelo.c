#include <stdio.h>
#include <stdlib.h>

typedef struct sNode{
    int info;
    struct sNode *esq;
    struct sNode *dir;
} Node;

typedef struct searchTree{
    Node *root;
} Tree;

void init(Node **root) {
    *root = NULL;
}

int isEmpty(Node *root) {
    return root == NULL;
}

void insertNode(Node **root, int value){
    if(*root == NULL)
        *root = (Node *) malloc(sizeof(Node));
    
    Node *aux = *root;
    
    if (value <= aux->info) {
        while(aux != NULL){
            if (aux->info > value) {
                /* code */
            }
            else
                aux = aux->esq;
        }
    }
    
    while(aux != NULL){
        if(value < aux->info){
            if(aux->esq == NULL){
                aux->esq = (Node *) malloc(sizeof(Node));
                aux = aux->esq;
                aux->info = value;
                aux->esq = NULL;
                aux->dir = NULL;
                break;
            }
            else
                aux = aux->esq;
        }
    }
}

int countNode(Node *root){
    if(root != NULL){
        int esquerda = countNode(root->esq);
        int direita = countNode(root->dir);
        return (1 + esquerda + direita);
    }
    else
        return 0;
}

int countLeaf(Node *root){
    if(root != NULL){
        int esquerda = countLeaf(root->esq);
        int direita = countLeaf(root->dir);

        if(root->esq == NULL && root->dir == NULL)
            return (1 + esquerda + direita);
        else
            return (esquerda + direita);
    }
    else
        return 0;
}

int countHeight(Node *root){
    if(root != NULL){
        int maior = 0;
        int esquerda = countHeight(root->esq);
        int direita = countHeight(root->dir);
        
        if (esquerda > direita)
            maior = esquerda;
        else
            maior = direita;

        return 1 + maior;
    }
    else
        return 0;
}

Node* search(Node *root, int info){
    Node* aux;
    aux = root;

    if(isEmpty(aux))
        return NULL;
    else if(info > aux->info)
        return search(aux->dir, info);
    else if(info < aux->info)
        return search(aux->esq, info);
    else
        return aux;
}

void visit(Node *root){
    printf("%d ", root->info);
}

void inOrder(Node *root){
    if(root != NULL){
        inOrder(root->esq);
        visit(root);
        inOrder(root->dir);
    }
}

void preOrder(Node *root){
    if(root != NULL){
        preOrder(root->esq);
        preOrder(root->dir);
        visit(root);
    }
}