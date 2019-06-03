#include <stdio.h>
void consulta();
void relatorio();

void menuPrincipal() {
	relatorio();
	consulta();
}

void relatorio() {
	printf("\n menu relatorio");
}

void consulta() {
	printf("\n menu consulta");
}

main(){
	menuPrincipal();
}
