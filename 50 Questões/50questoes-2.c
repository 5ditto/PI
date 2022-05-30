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
    int alt;
    if(a == NULL)
        return 0;
    
    int direita = altura(a->dir);
    int esquerda = altura(a->esq);
    if(direita > esquerda)
        alt = 1+ direita;
    else 
        alt = 1 + esquerda;
    
    return alt;
}

//29
ABin cloneAB(ABin a){
    ABin c;
    if(!a)
        return NULL;
    c = newABin(a->valor,cloneAB(a->esq), cloneAB(a->dir));
    return c;
}

// codeBoard é gay por isso
ABin cloneAB2(ABin a){
    
    if(!a)
        return NULL;
    //c = newABin(a->valor,cloneAB(a->esq), cloneAB(a->dir));
    ABin c = malloc(sizeof(struct nodo));
    c->valor = a->valor;
    c->esq = cloneAB2(a->esq);
    c->dir = cloneAB2(a->dir);
    return c;
}

//30
void mirror(ABin *a){
    
    if(!(*a))
        return;
    ABin aux = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = aux;
    mirror(&((*a)->esq));
    mirror(&((*a)->dir));

}

//31
void insere(int a, LInt *l){
    LInt atual = *l;
    LInt nodo = newLInt(a, NULL);
    
    if(!*l){
        *l = nodo;
        return;
    }
    while(atual->prox){
        atual = atual->prox;
    }
    atual->prox = nodo;
    nodo->prox = NULL;
    
}

void inorder(ABin a, LInt *l){
    if(!a)
        return;
    inorder(a->esq, l);
    insere(a->valor, l);
    inorder(a->dir, l);
   
}

//32
void preorderaux(ABin a,LInt *l){
    if(!a)
        return;
    LInt atual = *l;
    while(atual->prox){
        atual = atual->prox;
    }
    atual->prox = newLInt(a->valor, NULL);
    preorderaux(a->esq, l);
    preorderaux(a->dir, l);
}


void preorder(ABin a, LInt *l){
    *l = newLInt(0, NULL);
    preorderaux(a, l);
    *l = (*l)->prox;
    
}

//33
void posteraux(ABin a,LInt *l){
    if(!a)
        return;
    LInt atual = *l;
    posteraux(a->esq, l);
    posteraux(a->dir, l);
    while(atual->prox){
        atual = atual->prox;
    }
    atual->prox = newLInt(a->valor, NULL);
    
}

void posorder(ABin a, LInt *l){
    *l = newLInt(0, NULL);
    posteraux(a, l);
    *l = (*l)->prox;
    
}  

//34
int depth(ABin a, int x){
    if(!a)
        return -1;
    
    if(a->valor == x)
        return 1;
    
    if(depth(a->esq, x) == -1 && depth(a->dir,x) == -1)
        return -1;
    
    if(depth(a->esq,x) == -1)
        return (depth(a->dir,x) + 1);
    
    if(depth(a->dir,x) == -1)
        return (depth(a->esq,x) + 1);

    if(depth(a->esq,x) < depth(a->dir,x))
        return (depth(a->esq,x) + 1);
    else    
        return(depth(a->dir,x) + 1); 
}

//35
int freeAB(ABin a){
    
    if(!a)
        return 0;
    int conta = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return conta;    
}

//36
int pruneAB(ABin *a, int l){
    if(*a == NULL)
        return 0;
    if(l > 0){
        return (pruneAB(&((*a)->esq),l-1) + pruneAB(&((*a)->dir),l-1));
        
    }
    else{
       int res = 1 + pruneAB(&((*a)->esq), 0) + pruneAB(&((*a)->dir), 0);
        free(*a);
        *a=NULL;
        return res;
    }
}

//37
int iguaisAB(ABin a, ABin b){
    if(!a && !b)
        return 1;
    if(a == NULL)
        return 0;
    if(b == NULL)
        return 0;
    if(a->valor != b->valor)
        return 0;
    
    int igualdireita = iguaisAB(a->dir,b->dir);
    int igualesquerda = iguaisAB(a->esq,b->esq);

    return igualdireita*igualesquerda;
}

//38
void insere2(LInt *l, ABin a, int n){
    if(!a)
        return;
    if(n == 1){
        LInt atual = *l;
        while(atual->prox){
            atual = atual->prox;
        }
        LInt nodo = newLInt(a->valor, NULL);
        atual->prox = nodo;
        nodo->prox = NULL;
    
    }
    else{
        insere2(l, a->esq, n-1);
        insere2(l, a->dir, n-1);
    }
}

LInt nivelL(ABin a, int n){
    LInt l = newLInt(0,NULL);

    insere2(&l, a, n);

    l = l->prox;
    return l;
    
}

//39
int insereA(ABin a, int v[], int n,int i){
    if(a == NULL)
        return i;
    if(n == 1){
        v[i] = a->valor;
        i++;
    }
    else{
        i = insereA(a->esq,v,n-1,i);
        i = insereA(a->dir,v,n-1,i);
    }
    return i;
}

int nivelV(ABin a, int n, int v[]){
    return insereA(a,v,n,0);
}

//40
int acrescenta(ABin a, int v[], int *N, int *i){
    if(a == NULL)
        return 0;
    int x = 0;
    x += acrescenta(a->esq,v,N,i);
    if(*N > 0){
        v[*i] = a->valor;
        (*i)++;
        (*N)--;
        x++;
    }
    x += acrescenta(a->dir,v,N,i);
    return x;
}
int dumpAbin(ABin a, int v[], int N){
    int x, i = 0;
    x = acrescenta(a,v,&N,&i);
    return x;
}

//41
ABin somasAcA(ABin a){
    int acesq, acdir;
    if(a == NULL)
        return NULL;
    
    ABin nodo = malloc(sizeof(struct nodo));
    ABin newl = somasAcA(a->esq);
    ABin newr = somasAca(a->dir);
    nodo->esq = newl;
    nodo->dir = newr;

    if(newl == NULL){
        acesq = 0;
    }
    else{
        acesq = newl->valor;
    }

    if(newr == NULL){
        acdir = 0;
    }
    else{
        acdir = newr->valor;
    }

    nodo->valor = acdir + acesq + a->valor;

    return nodo;
}

//42
int contaFolhas(ABin a){
    if(a == NULL)
        return 0;
    if(a->esq == NULL && a->dir == NULL)
        return 1;
    int conta = contaFolhas(a->esq) + contaFolhas(a->dir);
    return conta;
}

//43
ABin cloneMirror(ABin a){
    if(a == NULL)
        return NULL;
    ABin c = malloc(sizeof(struct nodo));
    c->valor = a->valor;
    c->esq = cloneMirror(a->dir);
    c->dir = cloneMirror(a->esq);
    return c;
}

//44
int addOrd (ABin *a, int x) {
    ABin nodox = malloc(sizeof(struct nodo));
    nodox->valor = x;
    nodox->esq = NULL;
    nodox->dir = NULL;


    if(*a == NULL){
        (*a) = nodox;
        return 0;
    }
    ABin atual = *a, ant;

    while(atual){
        if(x == atual->valor)
            return 1;
        
        ant = atual;

        if(x<atual->valor)
            atual = atual->esq;
        else    
            atual = atual->dir;
    }

    if(x < ant->valor){
        ant->esq = nodox;
    }
    else
        ant->dir = nodox;

    return 0;
}

//45
int lookupAB(ABin a, int x){
    if(a == NULL){
        return 0;
    }
    while(a){
        if(x == a->valor)
            return 1;
        if( x < a->valor)
            a = a->esq;
        else
            a = a->dir;
    }
    return 0;
}

//46
int depthOrd(ABin a, int x){
    if(a == NULL){
        return -1;
    }
    int nivel = 1; 
    while(a){
        if(x == a->valor)
            return nivel;
        if( x < a->valor){
            a = a->esq;
            nivel++;
        }
        else{
            a = a->dir;
            nivel++;
        }
    }
    return -1;
}

//47
int maiorAB(ABin a){
    if(a == NULL)
        return 0;
        
    while(a->dir){
        a = a->dir;
    }
    return a->valor;
}

//48
void removeMaiorA(ABin *a){
    if(a == NULL)
        return;
    if((*a)->dir == NULL){
        *a = (*a)->esq;
        return;
    }
    ABin ant, atual = *a;
    while(atual->dir){
        ant = atual;
        atual = atual->dir;
    }
    ant->dir = atual->esq;
    
}

//49
int quantosMaiores(ABin a, int x){
    if(a == NULL)
        return 0;
    int qmaiores = 0;
    if(a->valor > x)
        qmaiores = 1 + quantosMaiores(a->dir, x) + quantosMaiores(a->esq,x);
    else
        qmaiores = quantosMaiores(a->esq,x) + quantosMaiores(a->dir, x);


    return qmaiores;    
}

//50
int length (LInt l) {
	int x = 0;
	while (l != NULL) {
		l = l->prox;
		x++;
	}
	return x;
}

LInt parteAMeio (LInt *l){
	LInt atual = *l, ant = newLInt (0, atual);
	*l = ant;
	int x = length (atual) / 2;
	while (x > 1) {
		atual = atual->prox;
		ant = ant->prox;
		x--;
	}
	ant->prox = NULL;
	ant = *l;
	*l = ant->prox;
	free (ant);
	return atual;
}

void listToBTree (LInt l, ABin *a) {
	if (l == NULL) {
		*a = NULL;
		return;
	}
	LInt dir = parteAMeio (&l);
	*a = newABin (dir->valor, NULL, NULL);
	listToBTree (l, &(*a)->esq);
	listToBTree (dir->prox, &(*a)->dir);
	return;
}
//51 
int max(ABin a){
    if(a == NULL)
        return 0;
    
    while(a->dir){
        a = a->dir;
    }
    
    return(a->valor);
}

int min(ABin a){
    if(a == NULL){
        return 0;
    }
    while(a->esq){
        a = a->esq;
    }
    return(a->valor);
}
 
int deProcura(ABin a){
    if(a == NULL)
        return 1;
    
    if(a->dir != NULL && min(a->dir) < a->valor)
        return 0;
    else if(a->esq != NULL && max(a->esq) > a->valor)
        return 0;
    else if(deProcura(a->dir) == 0 || deProcura(a->esq) == 0)
        return 0;
    return 1; 
    
}