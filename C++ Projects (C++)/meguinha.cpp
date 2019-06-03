#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

char r[35];
char num[5];
char d1[3], d2[3], d3[3], d4[3], d5[3], d6[3], d[3];
char data[11];
char input[3];
int count = 0;

int rng(int min, int max){
	return (min+(rand()%((max-min)+1)));
}

int geraDezena(){
	return rng(1, 60);
}

int stringIgual(char str[], char str1[]){
	if (strcmp(str, str1)==0)
		return 1;
	else
		return 0;
}

/**
 * só o número:				n
 * número e data:			p
 * número, data e dezenas:	t
 */
void printSorteio(char conteudo) {
	switch(conteudo){
		case 'n':
			printf("\nNumero: %s", num);
			break;
		case 'p':
			printf("\nNumero: %s", num);
			printf("\nData: %s", data);
			break;
		case 't':
			printf("\nNumero: %s", num);
			printf("\nDezena #1: %s", d1);
			printf("\nDezena #2: %s", d2);
			printf("\nDezena #3: %s", d3);
			printf("\nDezena #4: %s", d4);
			printf("\nDezena #5: %s", d5);
			printf("\nDezena #6: %s", d6);
			printf("\nData: %s", data);
			break;
	}
}

void consultarDezena() {
	count = 0;
	printf("\nInsira uma dezena (de 01, 60): ");
fflush(stdin);
	gets(input);
	
	FILE *mega;
	mega = fopen("mega.txt", "r");
	while (!feof(mega)){
		fgets(r, 35, mega);
		
		num[0] = r[0];
		num[1] = r[1];
		num[2] = r[2];
		num[3] = r[3];
		num[4] = '\0';
		d1[0] = r[5];
		d1[1] = r[6];
		d1[2] = '\0';
		d2[0] = r[8];
		d2[1] = r[9];
		d2[2] = '\0';
		d3[0] = r[11];
		d3[1] = r[12];
		d3[2] = '\0';
		d4[0] = r[14];
		d4[1] = r[15];
		d4[2] = '\0';
		d5[0] = r[17];
		d5[1] = r[18];
		d5[2] = '\0';
		d6[0] = r[20];
		d6[1] = r[21];
		d6[2] = '\0';
		data[0] = r[23];
		data[1] = r[24];
		data[2] = r[25];
		data[3] = r[26];
		data[4] = r[27];
		data[5] = r[28];
		data[6] = r[29];
		data[7] = r[30];
		data[8] = r[31];
		data[9] = r[32];
		
		if(strcmp(input, d1)==0) {
			count++;
		} else if(strcmp(input, d2)==0) {
			count++;
		} else if(strcmp(input, d3)==0) {
			count++;
		} else if(strcmp(input, d4)==0) {
			count++;
		} else if(strcmp(input, d5)==0) {
			count++;
		} else if(strcmp(input, d6)==0) {
			count++;
		}
	}
	printf("\n\nA dezena ocorre %d vezes dentre os sorteios analisados.", count);
	fclose(mega);
}

void consultarPalpite() {
	char dz1[3], dz2[3], dz3[3], dz4[3], dz5[3], dz6[3];
	printf("\nInsira seis dezenas (de 01, 60): ");
fflush(stdin);
	gets(dz1);
	gets(dz2);
	gets(dz3);
	gets(dz4);
	gets(dz5);
	gets(dz6);
	
	printf("\nPalpite: |%s|%s|%s|%s|%s|%s|", dz1, dz2, dz3, dz4, dz5, dz6);
	
	
	FILE *mega;
	mega = fopen("mega.txt", "r");
	while (!feof(mega)){
		count = 0;
		fgets(r, 35, mega);
		
		num[0] = r[0];
		num[1] = r[1];
		num[2] = r[2];
		num[3] = r[3];
		num[4] = '\0';
		d1[0] = r[5];
		d1[1] = r[6];
		d1[2] = '\0';
		d2[0] = r[8];
		d2[1] = r[9];
		d2[2] = '\0';
		d3[0] = r[11];
		d3[1] = r[12];
		d3[2] = '\0';
		d4[0] = r[14];
		d4[1] = r[15];
		d4[2] = '\0';
		d5[0] = r[17];
		d5[1] = r[18];
		d5[2] = '\0';
		d6[0] = r[20];
		d6[1] = r[21];
		d6[2] = '\0';
		data[0] = r[23];
		data[1] = r[24];
		data[2] = r[25];
		data[3] = r[26];
		data[4] = r[27];
		data[5] = r[28];
		data[6] = r[29];
		data[7] = r[30];
		data[8] = r[31];
		data[9] = r[32];
		
		if(stringIgual(dz1, d1) || stringIgual(dz1, d2) || stringIgual(dz1, d3) || stringIgual(dz1, d4) || stringIgual(dz1, d5) || stringIgual(dz1, d6))
			count++;
		if(stringIgual(dz2, d1) || stringIgual(dz2, d2) || stringIgual(dz2, d3) || stringIgual(dz2, d4) || stringIgual(dz2, d5) || stringIgual(dz2, d6))
			count++;
		if(stringIgual(dz3, d1) || stringIgual(dz3, d2) || stringIgual(dz3, d3) || stringIgual(dz3, d4) || stringIgual(dz3, d5) || stringIgual(dz3, d6))
			count++;
		if(stringIgual(dz4, d1) || stringIgual(dz4, d2) || stringIgual(dz4, d3) || stringIgual(dz4, d4) || stringIgual(dz4, d5) || stringIgual(dz4, d6))
			count++;
		if(stringIgual(dz5, d1) || stringIgual(dz5, d2) || stringIgual(dz5, d3) || stringIgual(dz5, d4) || stringIgual(dz5, d5) || stringIgual(dz5, d6))
			count++;
		if(stringIgual(dz6, d1) || stringIgual(dz6, d2) || stringIgual(dz6, d3) || stringIgual(dz6, d4) || stringIgual(dz6, d5) || stringIgual(dz6, d6))
			count++;
		
		switch(count){
			case 4:
				printf("\n Esse palpite resultou em uma Quadra! Informacoes do Sorteio:");
				printSorteio('t');
				break;
			case 5:
				printf("\n Esse palpite resultou em uma Quina! Informacoes do Sorteio:");
				printSorteio('t');
				break;
			case 6:
				printf("\n Esse palpite resultou em uma Sena! Informacoes do Sorteio:");
				printSorteio('t');
				break;
		}
	}
	fclose(mega);
}

void sortear(int n){
	int dezenas[n];
	for(int i = 0; i<n; i++){
		dezenas[i] = geraDezena();
		printf("\ndezena %d: %d", i+1, dezenas[i]);
	}
	
	int repetidos = 1;
	while(repetidos != 0){
		repetidos = 0;
	 	for(int i = 0; i<n; i++){
			for(int j = 0; j<n; j++){
				if (i!=j){
					if(dezenas[i]==dezenas[j]){
						repetidos ++;
						printf("\nDEZENA TROCADA! (%d): de %d", i+1, dezenas[i]);
						dezenas[i] = geraDezena();
						printf(" para %d.", dezenas[i]);
						
						printf("\n");
						for(int i = 0; i<n; i++){
							printf("\ndezena %d: %d", i+1, dezenas[i]);
						}
						getch();
					}
				}
			}
		}
	}
}

void menuSorteio() {
	int opcao = 9;
	while(opcao!=0){
		printf("\n1) Sortear 6 Numeros   (R$3,50)");
		printf("\n2) Sortear 7 Numeros   (R$24,50)");
		printf("\n3) Sortear 8 Numeros   (R$98,00)");
		printf("\n4) Sortear 9 Numeros   (R$294,00)");
		printf("\n5) Sortear 10 Numeros  (R$735,00)");
		printf("\n	Ou digite um numero ate 25 para gerar um jogo customizado. (R$1.000,00 por numero a mais do que 10 - Preco maximo 15.000,00)");
		printf("\n0) Voltar");
		printf("\n");
		scanf("%d", &opcao);
		if(opcao>0 && opcao <=25){
			sortear(opcao+5);
			printf("\n");
		}
		
	}
}

void menuPrincipal(){
	int opcao = 9;
	while (opcao !=0) {
		printf("\n1) Consultar dezena");
		printf("\n2) Consultar palpite (6 dezenas)");
		printf("\n3) Sortear dezenas");
		printf("\n0) Sair");
		printf("\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				consultarDezena();
				break;
			case 2:
				consultarPalpite();
				break;
			case 3:
				menuSorteio();
				break;
		}
	}
}

main() {
	srand(time(NULL));
	menuPrincipal();
}

