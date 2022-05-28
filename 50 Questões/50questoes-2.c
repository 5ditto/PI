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
    LInt ant = NULL;
    while((*l) && (*l)->valor <= x){
        ant = *l;
        l = &((*l)->prox);
    }
    if(ant){
        xl->prox = *l;
        ant->prox = xl;
    }
    else{
        xl->prox = (*l);
        *l = xl;
    }
}


// ou

void insertOrd2(LInt *l, int x){
    LInt xl = newLInt(x, NULL);

    while(*l && (*l)->valor <= x){
        l = &((*l)->prox);
    }
    xl->prox = *l;
    *l = xl;

}

//6
int removeOneOrd(LInt *l, int x){
    LInt atual = *l, ant;
    if(! atual)
        return 1;
    if(atual->prox == NULL && atual->valor == x)
        free(*l);
        *l = NULL;
        return 0;
    while (atual && atual->valor < x){
        ant = atual;
        atual = atual->prox;
    }
    if(atual && atual ->valor == x){
        ant->prox = atual->prox;
        free(atual);
        return 0;
    }
    return 1;
}

// ou 

int removeOneOrd(LInt *l, int x){
    LInt aux;
    while((*l) != NULL && (*l)->valor < x){
        l = &((*l)->prox);
    }
    if((*l)!= NULL){
        aux = *l;
        (*l) = (*l)->prox;
        free(aux);
        return 0;
    }
    return 1;
}

//7
void merge(LInt *r, LInt l1, LInt l2){
    LInt atual = newLInt(0,NULL);
    *r = atual;
    while(l1 != NULL && l2 != NULL){
        if(l1->valor >= l2->valor){
            atual->prox = l2;
            l2 = l2->prox;
        }
        else{
            atual->prox = l1;
            l1 = l1->prox;
        }
        atual = atual->prox;   
    }

    if(l1 == NULL){
        atual->prox = l2;
    }
    else{
        atual->prox = l1;
    }

    atual = *r;
    *r = (*r)->prox;
    free(atual);
}


//8
void splitQS(LInt l, int x, LInt *mx, LInt *Mx){
    *mx = newLInt(0,NULL);
    *Mx = newLInt(0, NULL);
    LInt aux, auxmx = *mx, auxMx = *Mx;

    while(l){
        if(l->valor < x){
            auxmx->prox = l;
            l = l->prox;
            auxmx = auxmx->prox;
            auxmx->prox = NULL;
        }
        else{
            auxMx->prox = l;
            l = l->prox;
            auxMx = auxMx->prox;
            auxMx->prox = NULL;
        }
    }

    auxmx = *mx;
    *mx = (*mx)->prox;
    free(auxmx);

    auxMx = *Mx;
    *Mx = (*Mx)->prox;
    free(auxMx);
}

//9

LInt parteAmeio(LInt *l){
    LInt y, atual = *l, ant;
    int count, i;

    // ver tamanho da lista
    for(count = 0;atual;count++, atual = atual->prox);
    
    count /= 2; // ver metade da lista
    atual = *l; // colocar o atual no inicio-  par aonde o *l está a apontar
    ant = NULL;
    
    // avançar no atual e guardar o último elem do y
    for(i = 0; i< count; i++){
        ant = atual;
        atual = atual->prox;
    }
    
    // lista vazia return null
    if(ant == NULL)
        return NULL;
        
    
    ant->prox = NULL;
    
    y = *l; // colocar o y no inicio que termina no ant
    *l = atual; // colocar o *l a apontar para o atual -> elem a seguir ao y 
    return y;
}

//10
int removeAll(LInt *l, int x){
    LInt atual = *l, ant = newLInt(0,*l);
    *l = ant;
    int count = 0;
    while(atual){
        if(atual->valor == x){
            ant->prox = (atual->prox);
            free(atual);
            atual = ant->prox;
            count++;
        }
        else{
            ant = ant->prox;
            atual = atual->prox;
        }
    }
    atual = *l;
    *l = atual->prox;
    free(atual);
    return count;
}


//11
int removeDups(LInt *l){
    LInt atual = *l;
    int count = 0;
    if(!atual && !(atual->prox))
        return count;
    while(atual){
        count += removeAll(&(atual->prox),atual->valor);
        atual = atual->prox;
    }
    return count;
        
}

//12
int removeMaiorL(LInt *l){
    LInt atual = *l;
    int maior = 0, maiorind, i;
    // ver o maior elemento
    for(i = 0; atual; i++){
        if(atual->valor > maior){
            maior = atual->valor;
            maiorind = i;
        }
        atual = atual->prox;
    }

    atual = *l;
    while(maiorind > 1){
        atual = atual->prox;
        maiorind--;
    }
    atual->prox = (atual->prox)->prox;
    
    return maior;
}

//13
void init(LInt *l){
    LInt aux;
    if(!(*l))
        return;
    if(!((*l)->prox)){
        free(*l);
        *l = NULL;
        return;
    }
    while((*l)->prox){
        l = &((*l)->prox);
    }
    aux = *l;
    (*l) = NULL;
    free(aux);

}

//14
void appendL(LInt *l, int x){
    LInt nodo = newLInt(x, NULL);
    if(!(*l)){
        *l = nodo;
        return;
    }
    while((*l)->prox){
        l = &((*l)->prox);
    }
    (*l)->prox = nodo;
        
}

//15
void concatL (LInt *a,LInt b){
    if(!(*a)){
        (*a) = b;
        return;
    }
    while((*a)->prox){
        a = &((*a)->prox);
    }
    (*a)->prox = b;
}

//16
LInt cloneL(LInt l){
    if(!l)
        return NULL;
    LInt tail = cloneL(l->prox);
    return newLInt(l->valor,tail);
}

//17
LInt cloneRev(LInt l){
    LInt novo = NULL;
    while(l){
        novo = newLInt(l->valor, novo);
        l  = l->prox;
    }
    return novo;
}

//18
int maximo(LInt l){
    int maior = 0;
    while(l){
        if(l->valor > maior){
            maior = l->valor;
        }
        l = l->prox;
    }
    return maior;
}

//19
int tamanho(LInt l){
    int i;
    for(i = 0; l; i++, l = l->prox);
    return i;
}
int take(int n, LInt *l){
    LInt aux, atual= *l;
    if(tamanho(atual)<= n)
        return tamanho(atual);
    while(n > 1){
        atual = atual->prox;
        n--;
    }
    aux = atual->prox;
    atual->prox = NULL;
    free(aux);
    atual = *l;
    return(tamanho(*l));

}

//20
int drop(int n, LInt *l){
    LInt atual = *l, aux;
    int i = 0;
    while(atual && n > 0){
        aux = atual;
        atual = atual->prox;
        free(aux);
        n--;
        i++;
    }
   
    *l = atual;
    return i;
}

//21
LInt NForward(LInt l, int N){
    if(!l){
        return NULL; 
    }
    while(N > 0){
        l = l->prox;
        N--;
    }
    return l;
}


//22
int listToArray(LInt l, int v[], int N){
    int i;
    for(i = 0; i < N && l; i++, l = l->prox){
        v[i] = l->valor ;
    }
    
    return i;
}

//23
LInt arrayToList(int v[],int N){
    LInt l = newLInt(v[0], NULL), atual  = l;
    int i ;
    if(N == 0){
        return NULL;
    }
    for(i = 1; i < N; i++){
        atual->prox = newLInt(v[i], NULL);
        atual = atual->prox;
    }
    
    return l;
}

//24
LInt somasAcL(LInt l){
    if(!l)
        return NULL;
    LInt new = newLInt(l->valor, NULL), atual = new;
    int somatorio = l->valor;
    l = l->prox;
    while(l){
        somatorio += l->valor;
        LInt nodo = newLInt(somatorio, NULL);
        atual->prox = nodo;
        atual = atual->prox;
        l = l->prox;
    }

    return new; 
}

//25
void remreps(LInt l){
    if(!l)
        return ;
    if(!(l->prox))
        return;

    LInt ant = l, atual = l->prox;
    
    while(atual){
       if(ant->valor == atual->valor){
           ant->prox = atual->prox;
           free(atual);
           atual = ant->prox;
       }
       else{
           ant = ant->prox;
           atual = atual->prox;
       }
    }
}

//26
LInt rotateL(LInt l){
    if(!l)
        return NULL;
    if(!(l->prox))
        return l;
    
    LInt first = l;
    l = l->prox;
    LInt atual = l;

    first->prox = NULL;
    while(atual->prox){
        atual = atual->prox;
    }
    atual->prox = first;
    first->prox = NULL;

    return l;
}

//27

LInt parte(LInt l){
    if(!l)
        return NULL;
    LInt atual = l->prox, ant = l, y = newLInt(0, NULL), auxy = y;
    int i;
    for(i = 2; atual; i++){
        if(i%2 == 0){
            auxy->prox = atual;
            auxy = auxy->prox;
            ant->prox = atual->prox;
            atual = atual->prox;
            auxy->prox = NULL;
        }
        else{
            ant = ant->prox;
            atual = atual->prox;
        }
    }
    auxy = y;
    y = y->prox;
    free(auxy);
    return y;

}

/*
-------------------- ÁRVORES BINÁRIAS --------------------
*/
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

ABin newABin (int r, ABin e, ABin d){
	ABin new = (ABin) malloc (sizeof (struct nodo));

	if (new!=NULL){
		new->valor = r;
		new->esq   = e;
		new->dir   = d;
	}
	return new;
}

//28
int altura(ABin a){
    int count;
    if(a == NULL)
        return 0;
    if(altura (a->esq) > altura(a->dir))
        count = 1 + altura(a->esq);

    else 
        count = 1 + altura(a->dir);
    return count;
}

// 29
ABin cloneAB(ABin a){
    ABin novo;
    if(a == NULL)
        novo = NULL;
    else
        novo = newABin(a->valor, cloneAB(a->esq),cloneAB(a->dir));

    return novo;
}