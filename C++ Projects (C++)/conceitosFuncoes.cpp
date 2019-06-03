#include <stdio.h>
#include <stdlib.h>

int retornaIntSemParametro(){
	printf("\nEu retorno 3, mas nao tenho parametro.\n");
	return 3;
}

int retornaIntComParametro(int x){
	printf("\nTenho um parametro do tipo int:  %d\n E retorno meu parametro + 3.\n", x);
	x = x+3;
	return x;
}

naoRetornaSemParametro(){
	printf("\nNao retorno nada e nao tenho parametro!\n");
}

naoRetornaComParametro(int x){
	printf("\nNao retorno, mas tenho um parametro do tipo int:  %d\n", x);
}

main(){
	
	retornaIntSemParametro();
	
	retornaIntComParametro(7);
	
	naoRetornaSemParametro();
	
	naoRetornaComParametro(9);
	
}
