#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//controle
int i=0, j=0, k=0;

//inputs e outputs
char hexadecimal_1[7], hexadecimal_2[7], hexaConverter[7], hexaConvertida[7];
int decimal_1[6], decimal_2[6], decimalConverter[6], decimalConvertida[6];
	
//reservadas
int numeros[16];
char hexes[17];
char hexDaCor[7];

setupReserved(){
	for (i=0;i<16;i++){ numeros[i] = i; }
	
	hexes[0] = '0'; hexes[1] = '1'; hexes[2] = '2'; hexes[3] = '3';
	hexes[4] = '4'; hexes[5] = '5'; hexes[6] = '6'; hexes[7] = '7';
	hexes[8] = '8'; hexes[9] = '9';	hexes[10] = 'a'; hexes[11] = 'b';
	hexes[12] = 'c'; hexes[13] = 'd'; hexes[14] = 'e'; hexes[15] = 'f';
	hexes[16] = '\0';
}

hexToDec(char hexadecimal_X[7], int decimal_X[6]){
	
	for (i=0; i<6; i++){
		switch (hexadecimal_X[i]){
			case 'a':
				decimal_X[i] = numeros[10];
				break;
			case 'b':
				decimal_X[i] = numeros[11];
				break;
			case 'c':
				decimal_X[i] = numeros[12];
				break;
			case 'd':
				decimal_X[i] = numeros[13];
				break;
			case 'e':
				decimal_X[i] = numeros[14];
				break;
			case 'f':
				decimal_X[i] = numeros[15];
				break;
			default:
				decimal_X[i] = (int) hexadecimal_X[i]-48;
		}
	}
}

decToHex(int decimal_X[6], char hexadecimal_X[7]){
	for (i=0;i<6;i++){
		hexadecimal_X[i] = hexes[decimal_X[i]];
	}
	hexadecimal_X[7] = '\0';
}

conversor(char hexaConverter[7]){
	int fatorDeConversao[6];
	
	hexToDec(hexadecimal_1, decimal_1);
	hexToDec(hexadecimal_2, decimal_2);
	hexToDec(hexaConverter, decimalConverter);
	
	for (i=0;i<6;i++){
		fatorDeConversao[i] = decimal_1[i] - decimal_2[i];
		decimalConvertida[i] = decimalConverter[i] - fatorDeConversao[i];
	}
	printf("\nFator de conversao: ");
	for(i=0;i<6;i++){ printf("-(%d)", fatorDeConversao[i]); if(i!=5){ printf(", "); }}
	decToHex(decimalConvertida, hexaConvertida);
	printf("\n\tA cor desejada e: %s", hexaConvertida);
	
}

main (){
	setupReserved();
	
	fputs("\n\tDigite o hexadecimal da cor:\n\t", stdout);
fflush(stdin);
	gets(hexadecimal_1);
	fputs("\n\tDigite o hexadecimal do tom desejado:\n\t", stdout);
fflush(stdin);
	gets(hexadecimal_2);
	
	hexToDec(hexadecimal_1, decimal_1);
	hexToDec(hexadecimal_2, decimal_2);
	
	fputs("\n\n\t\tDigite o hexadecimal da cor a ser convertida:\n\t\t", stdout);
fflush(stdin);
	gets(hexaConverter);
	
	conversor(hexaConverter);
	
}
