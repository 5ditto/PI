#include <stdlib.h>
#include <stdio.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));
    
    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

//1
int length(LInt l){
    int count = 0;
    while(l){
        count++;
        l = l->prox;
    }
    return count;
}

//2
void freeL(LInt l){
    LInt aux;
    if(!l)
        return;
    
    while (l->prox){
        aux = l;
        l = l->prox;
        free(aux);        
    }    
}

//3
void imprimeL(LInt l){
    while(l){
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

//4
LInt reverseL(LInt l){
    if(!l)
        return NULL;
    LInt ant = NULL, next;
    while(l){
        next = l->prox;
        l->prox = ant;
        ant = l;
        l = next;
    }
    
    return ant;
}

//5
void insertOrd(LInt *l, int x){
    LInt xl = newLInt(x, NULL);
    LInt aux = *l;

    while(aux && aux->valor <= x){
        aux = aux->prox;
    }
    xl->prox = *l;
    *l = xl;

}