#include<stdio.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a){
    int i, notaf= 0 , soma_minit = 0;
    for(i = 0; i < 6; i++)
        soma_minit += a.miniT[i]*10;
    notaf = 0.75 * a.teste + 0.25 *(soma_minit/6);
    if(notaf < 10)
        notaf = 0; 
    return notaf;
}

int procuraNum (int num, Aluno t[], int N){
    int i ;
    for(i = 0; i < N; i++){
        if(t[i].numero == num)
            return i;
        else if(t[i].numero > num)
            return -1;
    }
    return -1;
}

void swap(Aluno *a,Aluno *b){
    Aluno aux = *a;
    *a = *b;
    *b = aux;
}

void ordenaPorNum (Aluno t [], int N){
    int i,j;
    for(i = 0; i < N - 1 ; i++){
        for(j = 0; j < N - i -1; j++){
            if(t[i].numero > t[j].numero){
                //int aux = t[i].numero;
                //t[i].numero = t[j].numero;
                //t[j].numero = aux;
                swap(t+i, t+j);
            }
                
        }
    }
    
}