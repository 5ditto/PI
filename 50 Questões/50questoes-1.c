#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Exercício 1
void um (){
	int n, maior;
	printf("Introduza o primeiro nº da sequência:\n");
	scanf("%d", &n);
	maior = n;

	while(n!= 0){
		printf("Introduza o próximo nº da sequência:\n");
		scanf("%d", &n);
		printf("\n");
		if(n > maior)
			maior = n;
	}
	 printf("O maior elemento é %d.\n", maior);
}

//EXERCÍCIO 2
void dois (){
	int n, soma = 0, conta = 1;
	float media = 0;
	printf("Introduza o primeiro nº da sequência:\n");
	scanf("%d", &n);
	soma = n;

	while(n!= 0){
		printf("Introduza o próximo nº da sequência:\n");
		scanf("%d", &n);
		printf("\n");
		soma += n;
		conta++;
		printf("conta : %d soma : %d\n", conta, soma);
	}
	media = soma/conta;
	 printf("A média é %f .\n", media);
}

//Exercício 3
void tres (){
	int n, maior1, maior2;
	printf("Introduza o primeiro nº da sequência:\n");
	scanf("%d", &n);
	maior1 = n;
	maior2 = n;

	while(n!= 0){
		printf("Introduza o próximo nº da sequência:\n");
		scanf("%d", &n);
		if(n > maior1){
			maior2 = maior1;
			maior1 = n;
		}
		else if (n > maior2){
			maior2 = n;
		}		
	}
	 printf("O segundo maior elemento é %d.\n", maior2);
}

//Exercício 4
int bitsUm (unsigned int n){
	int conta = 0;
	while(n > 0){
		if(n%2 != 0)	
			conta++;
		n = n/2;
	}
	return conta;
}


//Exercício 5
int trailingZ(unsigned int n){
	int conta = 0;
	if(n == 0)
		return 32;
	while(n > 0){
		if(n%2 == 0)	
			conta++;
		n = n/2;
	}
	return conta;
}

//Exercício 6
int qDig (unsigned int n){
	int conta;
	for(conta = 0; n < 10; conta++, n=n/10);
	return conta;
}

//Exercício 7
char *mystrcat(char s1[], char s2[]){
	int i = strlen (s1), j;
	for(j=0;s2[j] != '\0'; j++)
		s1[i+j] = s2[j];
	s1[i+j] ='\0';
	return s1;
}

//Exercício 8 MAL
char *mystrcpy(char *dest, char source[]){
	int i, l = strlen(source);
	for(i = 0; source[i]!='\0';i++){
		dest = source[i];
		dest++;
	}
	return *dest;
}

//Exercício 9
int max (int n, int m){
    return(n>m ? n : m);
}

int mystrcmp (char s1[], char s2[]){
	int  l1 = strlen(s1), l2 = strlen(s2), i;

	for(i = 0; i < max(l1,l2); i++){
		if(s1[i] == s2[i]);
		else{
			if(s1[i]<s2[i])
				return (-1);
			else
				return 1;
		}

	}

	return 0;
}

//Exercício 10
char *mystrstr (char s1[], char s2[]) {
    int i,  l1 = strlen(s1), l2 = strlen(s2) - 1, j = 0;
    if(l2 + 1 >l1)
		return NULL;
	if(s2[0] == '\0')
		return s1;
	for(i = 0; s1[i] != '\0'; i++){
		if(s1[i] == s2[j])
				j++;
		if(s2[j] == '\0')
			return(s1 + i -l2);
	}

	return NULL;
}

//Exercício 11
void strrev(char s[]){
	int i, j;
	char tmp;
	for(i=0, j = strlen(s)-1;i < strlen(s)/2; i++, j--){
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
	s[strlen(s)] = '\0'; 
}

//Exercício 12
int isVogal (char s){
	if(s == 'a' || s == 'e' || s == 'i' || s == 'o' ||  s == 'u' || 
	   s == 'A' || s == 'E' || s == 'I' || s == 'O' ||  s == 'U' )

		return 1;
	else
		return 0;
}

//v1
void strnoV (char s[]){
	int i, j; 
	char aux[strlen(s)];
	for(i = 0, j = 0; s[i] != '\0'; i++){
		if(isVogal(s[i])  != 1){
		    aux[j] = s[i];
		    j++;
		} 
	}
	for(i = 0; i < strlen(s); i++)
	    s[i] = aux[i];
	 s[i] = '\0';

}


//v2
void strnoV (char s[]){
	int i = 0, j, t = strlen(s); 
	while(s[i]!='\0'){
		if(isVogal(s[i])  == 1){
		    t--;
		    for(j = i+1; s[j] != '\0';j++){
		        s[j-1] = s[j];
		    }
		    s[t] = '\0';
		} 
		else
		    i++;
	}


}

//Exercício 13
void truncW (char t[], int n){
    int i, j = 0, c = n ;
    for(i = 0; t[i] != '\0'; i++){
        if(t[i] == ' '){
            c = n;
            t[j]=t[i];
            j++;
        }
        else{
           if( c == 0){
               t[j] = t[i];
           }
            else{
                c--;
                t[j]=t[i];
                j++;
            }
        }
            
    }
    t[j] = '\0';
}

//Exercício 14

char charMaisfreq (char s[]) {
    int i, j, maior = 0, conta;
    char freq = s[0];
    for(i=0; s[i] != '\0'; i++){
        for(j= i + 1, conta = 0; s[j] != '\0'; j++){
            if(s[j] == s[i])
                conta++;
        }
        if (conta > maior ){
            maior = conta;
            freq = s[i];
        }
        
    }
    ;
    return freq;
}

//Exercício 15
int iguaisConsecutivos (char s[]) {
    int i, conta = 1, maior = 0;
    for(i = 0; s[i]!='\0'; i++){
        if(s[i] == s[i + 1])
            conta++;
        else
            conta = 1;
        if(conta > maior)
            maior = conta;
    }
    return maior;
}


//Exercício 16
int pertence(char s[],int i, int j){
    for(; i < j; i++){
        if(s[j] == s[i])
            return 1;
    }
    return 0;
}

int difConsecutivos(char s[]){
    int i, j, maior = 0, conta = 0;
    for(i = 0; s[i] != '\0'; i++){
         conta = 0;
        for(j = i; s[j] != '\0' && pertence(s, i, j) == 0; j++){
            conta ++;
        }
        if(conta > maior){
            maior = conta;
        }
    }
    return maior;   
}


//Exercício 17
int maiorPrefixo (char s1 [], char s2 []) {
    int i = 0, conta = 0;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] == s2[i])
            conta++;
        else
            return conta;
        i++;
    }
    return conta;
}

//Exercício 18
int maiorSufixo (char s1 [], char s2 []) {
    int i = strlen(s1)-1, j = strlen(s2)-1, conta = 0;
    for(; i >= 0 && j >= 0 && s1[i] == s2[j]; i--, j--, conta++);
    return conta;
}

//Exercício 19
int sufPref (char s1[], char s2[]) {
    int i = 0, j = 0, conta = 0;
    while(s1[i] != '\0' && s2[j] != '\0'){
        if(s1[i] != s2[j])
            i++;
        else{
            while(s1[i] == s2[j] && s1[i]!='\0'){
                i++;
                j++;
                conta++;
            }
            if(s1[i] != '\0'){
                conta = 0;
                j = 0;
            }
        }
    }
    return conta;
}

//Exercício 20
int contaPal (char s[]) {
    int i = 0, conta=0;
    for(;s[i]!='\0'; i++){
        if(s[i] != ' ' && s[i] != '\n'){
            if(s[i+1] != ' ' && s[i+1] != '\0');
            else{
                conta++;
            }
        } 
    }
    return conta;
}

//Exercício 21
int isVogal (char s){
	if(s == 'a' || s == 'e' || s == 'i' || s == 'o' ||  s == 'u' || 
	   s == 'A' || s == 'E' || s == 'I' || s == 'O' ||  s == 'U' )

		return 1;
	else
		return 0;
}

int contaVogais (char s[]) {
    int i, conta = 0;
    for(i = 0; s[i] != '\0'; i++){
        if(isVogal(s[i]))
            conta++;
    }
        
    return conta;
}

//Exercício 22
int pertence(char s[],char c){
    int i;
    for(i = 0; s[i] != '\0'; i++){
        if(c == s[i])
            return 1;
    }
    return 0;
}

int contida (char a[], char b[]) {
    int i;
    for(i = 0; a[i] != '\0'; i++){
        if(pertence(b, a[i]) == 0)
            return 0;
    } 
    return 1;
}

//Exercício 23
int palindroma (char s[]) {
    int i, j = strlen(s) - 1;
    for(i = 0; i < j; i++, j--){
        if( s[i] != s[j])
            return 0;
    }
    return 1;
}

//Exercício 24
int remRep (char t[]) {
    int r = 0, i;
    for(i = 0; t[i] != '\0'; i++){
        if (t[i] != t[i+1]){
            t[r] = t[i];
            r++;
        }
    }
    t[r] = '\0';
    return r;
}

//Exercício 25
int limpaEspacos (char t[]) {
    int i,r=0;
    for(i = 0; t[i] != '\0'; i++){
        if(t[i] == ' ' && t[i+1] ==  ' ');
        else{
            t[r] = t[i];
            r++;
        }
        
    }
    t[r] = '\0';
    return r;
}
//Exercício 26
   void insere (int v[], int N, int x){
       int i, j = 0;
       for(i = 0;  i < N && v[i] < x; i++);
       for(j = N; j != i; j--)
            v[j] = v[j-1];
        v[i] = x;
   }

//Exercício 27
void merge (int r [], int a[], int b[], int na, int nb){
    int i, x = 0, y = 0;
    for( i = 0; x < na && y < nb; i++){
        if(a[x] > b[y]){
            r[i] = b[y];
            y++;
        }
        else{
            r[i] = a[x];
            x++;
        }
    }
    if(x < na ){
        while(x < na){
            r[i] = a[x];
            x++;
            i++;
        }
    }
    else{
        while(y < nb){
            r[i] = b[y];
            y++;
            i++;
        }
    }
  
}

//Exercício 28
int crescente (int a[], int i, int j){
    while(i < j){
        if(a[i] > a[i+1])
            return 0;
        else{
            i++;
        }
        
    }
   return 1;
}

//Exercício 29
int isNeg( int i){
    if ( i < 0)
        return 1;
    else
        return 0;
}
int retiraNeg (int v[], int N){
    int i, j = 0;
    for(i = 0; i < N; i++){
        if(isNeg(v[i]));
        else{
            v[j] = v[i];
            j++;
        }
    }
    return j;
}

//Exercício 30
int menosFreq (int v[], int N){
    int i, j, mfreq = v[0], conta = 0, menos = N;
    for(i = 0; i < N; i++){
        
        if (v[i] == v[i+1]){
            conta++;
        }
        else{
            if(conta < menos){
                menos = conta;
                mfreq = v[i];
            }
            conta = 0;
        }
    }
    return mfreq;
}

//Exercício 31
