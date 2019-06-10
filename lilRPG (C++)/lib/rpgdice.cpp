#include <stdlib.h>
#include <time.h>

srand(time(NULL));

int rng(int min, int max){
	return (min+(rand()%((max-min)+1)));
}

