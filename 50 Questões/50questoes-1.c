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
	for(j=0;s2[j] 1= '\0'; j++)
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
	return *des;
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

int main(){
	int x;
	//printf("EXERCÍCIO 1\n");
	//um();

	//printf("EXERCÍCIO 2\n");
	//dois();

	//printf("EXERCÍCIO 3\n");
	//tres();
	
	//prinft("EXERCÍCIO 4\n");
	//bitsUm(x);


	return 0;
}