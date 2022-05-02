#include <stdio.h>

//Exercício 1
int isVogal (char s){
    if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u' ||
       s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U')
       return 1;
    else
        return 0;
}
int contaVogais(char *s){
    int vogal = 0, i = 0;
    while(s[i] != '\0'){
        if(isVogal(s[i])){
            vogal++;
        }
        i++;
    }
    return vogal;
}


int retiraVogaisRep (char *s){
    int i, j, n = strlen(s);
    for(i = 0; s[i ] != '\0'; i++){
        if(isVogal(s[i]) && s[i] == s[i+1]){
            for(j = i; s[j] != '\0'; j++)   
                s[j] = s[j+1];
        
            s[j] = '\0';
            i--;
        }
    }
    return (n - streln(s));

}

//não funfa
int duplicaVogais(char *s){
    int i,j = 0, conta = 0;
    for(i = 0; s[i] != '\0'; i++){
        if (isVogal(s[i])){
            s[j] = s[i];
            s[j+1] = s[i];
            j += 2;
            conta++;
        }
        else{
            s[j] = s[i];
            j++;
        }
    }
    
    return conta;
}

int ordenado(int v[], int N){
    int i;
    for(i = 1; i < N; i++){
        if( v[i - 1] > v[i] )
            return 0;
    }
    return 1;
}

void merge(int a[], int na, int b[], int nb, int r[]){
    int i, ia = 0, ib = 0;
    for(i = 0; ia < na && ib < nb; i++){
        if(a[ia] > b[ib]){
            r[i] = b[ib];
            ib++;
        }
        else{
            r[i] = a[ia];
            ia++;
        }
    }

    if(ia < na){
        while(ia<na){
            r[i] = a[ia];
            i++;
            ia++;
        }
    }
    else{
         while(ib<nb){
            r[i] = b[ib];
            i++;
            ib++;
        }
    }
}

int partition(int v[], int N, int x){
    int i, j, r = 0;
    for(i = 0;i < N; i++){
        for(j = i; j < N; j++){
            if(v[j] <= x && v[j] < v[i]){
                v[]
            }
        }
    }
}

int main(){

    return 0;
}