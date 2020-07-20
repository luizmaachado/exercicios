#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila{
	int num;
	struct fila *ptr;
}fila;

void getDiv(fila *esquerda, fila *direita, int x, int i, int valor){

	while (x/10 != 0){

		esquerda->num = x/10;
		esquerda->ptr = malloc(sizeof(fila));
		esquerda = esquerda->ptr;
		esquerda->ptr = NULL;

		direita->num = valor%(10*i);
		direita->ptr = malloc(sizeof(fila));
		direita = direita->ptr;
		direita->ptr = NULL;

		x = x/10;

		i = i*10;
		getDiv(esquerda, direita, x, i,valor);
	}
}

int checkSelfDiv(fila *esquerda, fila *direita,int x){
	int i = 0;
	while(esquerda->ptr != NULL){
		if(direita->num == 0){
			direita = direita->ptr;
			esquerda = esquerda->ptr;
			i++;
		}
		else if(x%direita->num == esquerda->num){
			return i;
		}
		else{
			direita = direita->ptr;
			esquerda = esquerda->ptr;
			i++;
		}
	}
	return 731345678;
}

char* zero(int x, int left,char *pala){
	int i = 0;
	while(left/10!=0){
		left = left/10;
		i++;
	}
	i++;
	return (pala+i);
}

int divHub(int x){
	int i = 1;
	int valor = x;
	char test[332345];
	sprintf(test,"%d",x);
	char *pala = test;

	fila *esquerda = malloc(sizeof(fila));
	esquerda->ptr = NULL;
	fila *direita = malloc(sizeof(fila));
	direita->ptr = NULL;
	getDiv(esquerda,direita,x,i,valor);


	int resultado = checkSelfDiv(esquerda, direita,x);
	int print = 0;
	if (resultado != 731345678){
		while (print!=resultado){
			print++;
			direita = direita->ptr;
			esquerda = esquerda->ptr;
		}
		pala = zero(x,esquerda->num,pala);
		printf("%d : Left =%d | Right =%s\n", x, esquerda->num, pala);
		free(esquerda);
		free(direita);
		return 1;
	}
	else{
		return 0;
	}
}

int main(int argc, char **argv){
	int var1 = atoi(argv[1]);
	int var2 = atoi(argv[2]);
	int stop = 0;
	int ok = 0;

	if(var1>var2){
		printf("Nothing\n");
	}
	else{
		for(int i = var1;i<=var2;i++){
			stop = divHub(i);
			if (stop == 1){
				ok = 1;
			}
		}
			if (ok == 0){
				printf("Nothing\n");
			}
	}
	return 0;
}