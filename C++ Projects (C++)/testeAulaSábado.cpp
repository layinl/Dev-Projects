#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stringsEFuncoes(){
	
	char nome1[20], nome2[20];
	printf("gets(nome1): ");
	gets(nome1);
	printf("nome1: %s\n", nome1);
	printf("\ngets(nome1): ");
	gets(nome2);
	printf("nome2: %s\n", nome2);
	
	printf("\nstrcmp(nome1, nome2): \n\t%d\n", strcmp(nome1, nome2));
	
	strcpy(nome1, nome2);
	
	printf("\nstrcpy(nome1, nome2): \n\tnome1: %s\n\tnome2: %s\n", nome1, nome2);
	
	printf("\nstrlen(nome1): \n\t%d\n", strlen(nome1));
	
	printf("\nstrcat(nome1, \"-concatenando-\"): \n\t%s\n", strcat(nome1, "-concatenando-"));
	
}

main() {
	
	stringsEFuncoes();
	
}
