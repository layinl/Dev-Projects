#include <stdio.h>

void func(int*a){
	printf("\nestou na func");
	(*a)++;
}

main(){
	int a=1;
	printf("\n%d", a);
	func(&a);
	printf("\n%d", a);
}
