#include <stdio.h>
#include <string.h>

insereDesdeX(char string1[20], char string2[20], int posicao){
	char resultado[100];
	for (int i=0; i!=posicao; i++){
		resultado[i] = string1[i];
	}
	for (int i=0; string2[i] != '\0'; i++) {
		resultado[posicao+i] = string2[i];
	}
	for (int i=0; string1[posicao+i]!='\0'; i++){
		resultado[posicao+strlen(string2)+i] = string1[posicao+i];
	}
	
	printf("\nResultado:  %s", resultado);
}

main() {
	char s1[20], s2[20];
	int pos;
	
	printf("\nInsira um texto:\n");
	gets(s1);
	
	printf("\nInsira outro texto:\n");
	gets(s2);
	
	printf("\nInserir a partir de qual casa do primeiro texto?\n");
	scanf("%d", &pos);
	
	insereDesdeX(s1, s2, pos);
}
