#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

//1
void libertaLista(Palavras l){
    while(l ){
        Palavras aux = l;
        l = l->prox;
        free(aux);
    }
}

//2
int quantasP(Palavras l){
    int conta = 0;
    while(l){
        conta++;
        l = l->prox;
    }
    return conta;
}

//3
void listaPal(Palavras l){
    while (l){
        printf("Palavra: %s , Número de ocorrências: %d\n", l->palavra ,l->ocorr);
        l = l->prox;    
    }
}

//4
char * ultima(Palavras l){
    if(l == NULL)
        return NULL;
    while(l->prox){
        l = l->prox;
    }
    return (l->palavra);
}

//5
Palavras acrescentaInicio(Palavras l, char *p){
    Palavras nova = malloc(sizeof (Palavras));
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = l;
    return nova;
}

//6
Palavras acrescentaFim(Palavras l, char *p){
    Palavras nova = malloc(sizeof (Palavras));
    Palavras aux = l;
    nova->palavra = p;
    nova->ocorr = 1;
    nova->prox = NULL;
    if(!l)
        return nova;
    while(aux->prox){
        aux = aux->prox;
    }
    return l;
}

//7
Palavras acrescenta(Palavras l, char *p){
    if(l == NULL){
        Palavras novo = malloc(sizeof(Palavras));
        novo->palavra = p;
        novo->ocorr = 1;
        novo->prox = NULL;
        return novo;
    }
    Palavras aux = l;
    while(!aux && !strcmp(aux->palavra,p)){
        aux = aux->prox;
    }
    if(aux != NULL){
        aux->ocorr++;
        return l;
    }
    else
        acrescentaInicio(l, p);   
}

//8
struct celula * maisFreq (Palavras l){
    Palavras mf = l;
    if(l == NULL)
        return NULL;
    while(l){
        if(l->ocorr > mf->ocorr){
            mf = l;
        }
        l = l->prox;
    }
    return mf;
}