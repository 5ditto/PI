#include <stdio.h>
#include <stdlib.h>
#include "ficha6.h"



// Static stacks 

//(*s). = s->

void SinitStack (SStack s){
	s->sp = 0;
}


int  SisEmpty (SStack s){
	return (s->sp == 0);
}

int  Spush (SStack s, int x){
	if(s->sp == Max)
        return 1;
    else{
        s->values[s->sp] = x;
        s->sp++;
        return 0;
    }
}

int  Spop (SStack s, int *x) {
	if(s->sp == 0)
        return 1;
    else{
        *x = s->values[s->sp-1];
        s->sp--;
	    return 0;
    }
}

int  Stop (SStack s, int *x) {//x -> endereço e (*x) -> conteudo guardado no endereço
    if(s->sp == Max){
        return 1;
    }
    else{
        *x = s->values[s->sp-1];
	    return 0;
    }
}

// Stacks with dynamic arrays

void DinitStack (DStack s) {
	s->sp = 0;
    s->size = 1;
    s->values = malloc(s->size * sizeof (int));
}

int  DisEmpty (DStack s) {
	return (s->sp == 0);
}

int  Dpush (DStack s, int x){
	int r=0;
	if(s->sp == s->size - 1){
        s->size++;
    }
	return r;
}

int  Dpop (DStack s, int *x){
	int r=0;
	
	return r;
}

int  Dtop (DStack s, int *x){
	int r=0;
	
	return r;
}

// Static queues 

void SinitQueue (SQueue q){
    q->length = 0; 
}

int  SisEmptyQ (SQueue q){
    return (q->length == 0);
}
//(front + length)%Max

int  Senqueue (SQueue q, int x){
	if(q->length == Max){
        return 1;
    }else{
        q->values[(q->length + q->front)%Max] = x;
        q->length++;
        return 0;
    }
}

int  Sdequeue (SQueue q, int *x) {
    if(q->length == 0)
        return 1;
	else{
        *x = q->values[q->front];
        q->front = (q->front + 1)%Max;
        q->length--;
        return 0;
    }
}

int  Sfront (SQueue q, int *x) {
	if(q->length == 0)
        return 1;
	else{
        *x = q->values[q->front];
        return 0;
    }
}


// Queues with dynamic arrays

int dupQueue (DQueue q) {
	// ...
	return (-1);
}

void DinitQueue (DQueue q) {
	// ...
}

int  DisEmptyQ (DQueue s) {
	return (-1);
}

int  Denqueue (DQueue q, int x){
	// ...
	return (-1);
}

int  Ddequeue (DQueue q, int *x){
	// ...
	return (-1);
}

int  Dfront (DQueue q, int *x){
	// ...
	return (-1);
}


void ShowDStack (DStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}


void ShowSStack (SStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}


int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}


void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}


void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}