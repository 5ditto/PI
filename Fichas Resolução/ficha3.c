#include <stdio.h>

//Exercício 2
void swapM(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}


//Exercício 3
void swap (int v[], int i, int j){
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//Exercício 4
int soma (int v[], int N){
    int soma = 0, i;
    for( i = 0; i < N; i++){
        soma += v[i];
    }
    return soma;
}

//Exercício 5
void inverteArray(int v[], int N){
    int i = 0;
    for(i = 0; i < N/2; i++){
        swap(v,i,N-i-1);
    }
}


//Exercício 6
int maximum(int v[], int N, int *m){
    if(N <= 0)
        return -1;
    int max = 0, i;
    for(i = 0;i < N; i++){
        if(v[i] > max)
            max = v[i];
    }
    *m = max;
    return 0;
}

//Exercício 7
void quadrados(int q[], int N){
    int i;
    q[0] = 0;
    for(i = 1; i < N; i++){
        q[i] = q[i-1]+(2*(i-1)+1);
    }
}

// Exercício 8
void pascal(int v[], int N){
    int i, j;
    for(i = 0; i <= N; i++){
        v[i] = 1;
        //NÃO
    }
}

int main(){
    int x = 3, y = 5, m;
    int array[4] = {1, 2, 3, 6};
    swapM(&x,&y);
    //swap(array,0,2);
    printf("x = %d; y = %d\n", x, y);
    printf("v[0] = %d; v[2] = %d\n", array[0],array[2]);
    printf("soma = %d\n", soma(array,3));
    inverteArray(array,4);
    for(int i = 0; i < 4; i++){
        printf("%d ",array[i]);
    }
    maximum(array,4,&m);
    printf("\nO valor máximo do array é %d\n", m);
    int N = 5;
    int q[N];
    quadrados(q,N);
    for(int i = 0; i < N; i++){
        printf("%d ", q[i]);
    }
    printf("\n");
}