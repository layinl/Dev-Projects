#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rng(int lower, int upper){
	return ( lower + ( rand() % ( upper - lower ) + 1 ) );
}

main(){
	srand(time(NULL));
	for(int i=0; i<100; i++){
		printf("\n\t%d", rng(12, 29));
	}
}
