#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pegaNum() {
	int x;
	printf("\n\tDigite um n�mero:  ");
	scanf("%d", &x);
	return x;
}

int mult2Num() {
	int x, y, conta;
	x = pegaNum();
	y = pegaNum();
	conta = x*y;
	printf("\n\tConta:  %d", conta);
	return conta;
}

int contaDigitos(float num){
	int digitos;
	for (digitos = 0; num>1; digitos++){
		num = num/10;
	}
	printf("\n\tDigitos:   %d", digitos);
	return digitos;
}

main() {
	// Nesse programa, vamos:
	// - pegar dois n�meros, fazer uma conta com eles;
	// - pegar duas contas e som�-las;
	// - pegar o resultado e contar os d�gitos.

	float soma;
	int digitos;
	
	soma = mult2Num() + mult2Num();
	printf("\n\tSoma:   %f", soma);
	
	contaDigitos(soma);
	
}
