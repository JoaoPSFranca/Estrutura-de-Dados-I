#include <stdio.h>
#include <stdlib.h>

typedef struct sNode{
    int info;
    struct sNode *esq;
    struct sNode *dir;
} Node;

int countNode(Node *raiz){
    if(raiz != NULL){
        int esquerda = countNode(raiz->esq);
        int direita = countNode(raiz->dir);
        return (1 + esquerda + direita);
    }
    else
        return 0;
}

int countLeaf(Node *raiz){
    if(raiz != NULL){
        int esquerda = countLeaf(raiz->esq);
        int direita = countLeaf(raiz->dir);

        if(raiz->esq == NULL && raiz->dir == NULL)
            return (1 + esquerda + direita);
        else
            return (esquerda + direita);
    }
    else
        return 0;
}

int countHeight(Node *raiz){
    if(raiz != NULL){
        int maior = 0;
        int esquerda = countHeight(raiz->esq);
        int direita = countHeight(raiz->dir);
        
        if (esquerda > direita)
            maior = esquerda;
        else
            maior = direita;

        return 1 + maior;
    }
    else
        return 0;
}