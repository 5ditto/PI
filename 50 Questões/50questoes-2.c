#include <stdio.h>
#include <stdlib.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

//1
int length (LInt l){
    int comp;
    if(l == NULL) return 0;
    if(l->prox == NULL) return 1;
    for(comp=1; l->prox != NULL; comp++)
        l =  l->prox;
    return comp;
}

//2
void freeL(LInt l){
    LInt  l2;
    if(l == NULL)
        return;
    while (l->prox)
    {
        l2 = l;
        l = l->prox;
        free(l2);
    }
}

//3
void imprimeL(LInt l){
    if(l == NULL)
        return;
    while(l->prox){
        printf("%d\n",l->valor);
        l->prox;
    }
}

//4
LInt reverse(LInt l){
    if(!l) return NULL;
    LInt ant = NULL;
    while (l){
        LInt x = l->prox;
        l->prox = ant;
        ant = l;
        l = x;
    }
    return ant;   
}

//5
void insertOrd (LInt *l, int x){
    LInt novo = newLInt(x, NULL);
    
    while((*l)!= NULL && (*l)->valor <= x){
        l = &((*l)->prox);
    }
    novo->prox = *l;
    *l = novo;   
}