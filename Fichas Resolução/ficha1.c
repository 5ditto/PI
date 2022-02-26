#include <stdio.h>
#include <stdlib.h>


void um (){
	printf("EXERCÍCIO 1\n");
	int i,j;
	for(i = 0; i <5;i++){
		for (j=0; j<5;j++)
			printf("#");
		printf("\n");
	}
	printf("\n\n");
}

void dois (){
	printf("EXERCÍCIO 2\n");
	int i,j;
	for(i = 0; i <5;i++){
		for (j=0; j<5;j++){
			if (i%2 == 0 && j%2 == 0 || i%2 == 1 && j%2 == 1)
				printf("#");
			else 
				printf("_");
		}
		printf("\n");
	}
	printf("\n\n");
}

void tres1(){
	printf("EXERCÍCIO 3 - VERTICAL\n");
	int i,j;
	for(i = 0; i < 5 ; i++){
		for( j = 0; j <= i ; j++){
			printf("#");
		}
		printf("\n");
	}
	for(i; i>0;i--){
		for(j = 0; j < i; j++){
			printf("#");
		}
		printf("\n");
	}
	printf("\n\n");
}

void tres2(){
	printf("EXERCÍCIO 3 - HORIZONTAL");
	int i, j;
	for(i = 0; i <= 5; i++){
		for(j = 0; j < 4+i; j++){
			if(j< 5 - i)
				printf (" ");
			else
				printf("#");
		}
		printf("\n");
	}
	printf("\n\n");
}


int quatro(int n){
	printf("EXERCÍCIO 4");
	int i, j, conta = 0;
	for(i = 0; i <= n; i++){
		for(j = 0; j < n+i; j++){
			if(j< n - i)
				printf (" ");
			else{
				printf("#");
				conta++;
			}
		}
		printf("\n");
	}
	for(i; i >= 0; i--){
		for(j = 0; j < n+i; j++){
			if( j = n)
				printf ("");
			else
				printf("#");
		}
		printf("\n");
	}

	printf("Foram utilizados %d caracteres '#'",conta);
	printf("\n\n");
}
int main(){
	int n;
	um();
	dois();
	tres1();
	tres2();
	printf("Introduza um inteiro(raio):");
	scanf("%d", &n);
	quatro(n);
	return 0;
}