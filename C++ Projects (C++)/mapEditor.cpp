#include <stdio.h>
#include <math.h>

int max_y = 4;
int max_x = 4;
int map[5][5]{
	{ 0,  0,  4,  0,  0},
	{ 0,  4,  4,  0,  0},
	{ 4,  4,  0,  0,  0},
	{ 0,  0,  0,  0,  2},
	{ 0,  0,  0,  2,  2}
};

// -2 = invalid, current is Out of Bounds
// -1 = invalid, test is OoB
//  0 = valid, test return is false
//  1 = valid, test return is true

int OoB(int y, int x){
	int value = 0;
	if( (y<0 || y>max_y) || (x<0 || x>max_x) ){
		value = 1;
	}
	return value;
}

/*
	NW   N   NE
	 W   C   E
	SW   S   SE
*/

/*
printResult(int value){
	switch (value){
		case -2:
			printf("\n\t(%d) Current Tile is Out of Bounds.", value);
			break;
		case -1:
			printf("\n\t(%d) Test Tile is Out of Bounds.", value);
			break;
		case  0:
			printf("\n\t( %d) Test Tile doesn't equals the tested tile_code.", value);
			break;
		case  1:
			printf("\n\t( %d) Test Tile equals tested tile_code.", value);
			break;
	}
}
*/
void WarnOoB(int y, int x, int test_y, int test_x, int value){
	switch (value){
		case -2:
			printf("\n\t(ERROR %d) CURRENT TILE (%d, %d) IS OUT OF BOUNDS.", value, y, x);
			break;
		case -1:
			printf("\n\t(ERROR %d) TEST TILE (%d, %d) - FOR CURRENT TILE (%d, %d) - IS OUT OF BOUNDS.", value, test_y, test_x, y, x);
			break;
	}
}
int checkNW(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(!OoB(y-1, x-1)){
			if(map[y-1][x-1] == tile_code){
				value = 1;
			} else {
				value = 0;
			}
		} else {
			value = (-1);
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y-1, x-1, value);
	return value;
}
int checkN(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(!OoB(y-1, x)){
			if(map[y-1][x] == tile_code){
				value = 1;
			} else {
				value = 0;
			}
		} else {
			value = (-1);
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y-1, x, value);
	return value;
}
int checkNE(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(!OoB(y-1, x+1)){
			if(map[y-1][x+1] == tile_code){
				value = 1;
			} else {
				value = 0;
			}
		} else {
			value = (-1);
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y-1, x+1, value);
	return value;
}
int checkW(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(!OoB(y, x-1)){
			if(map[y][x-1] == tile_code){
				value = 1;
			} else {
				value = 0;
			}
		} else {
			value = (-1);
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y, x-1, value);
	return value;
}
int checkC(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(map[y][x] == tile_code){
			value = 1;
		} else {
			value = 0;
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y, x, value);
	return value;
}
int checkE(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(!OoB(y, x+1)){
			if(map[y][x+1] == tile_code){
				value = 1;
			} else {
				value = 0;
			}
		} else {
			value = (-1);
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y, x-1, value);
	return value;
}
int checkSW(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(!OoB(y+1, x-1)){
			if(map[y+1][x-1] == tile_code){
				value = 1;
			} else {
				value = 0;
			}
		} else {
			value = (-1);
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y+1, x-1, value);
	return value;
}
int checkS(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(!OoB(y+1, x)){
			if(map[y+1][x] == tile_code){
				value = 1;
			} else {
				value = 0;
			}
		} else {
			value = (-1);
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y+1, x, value);
	return value;
}
int checkSE(int y, int x, int tile_code){
	int value = (-2);
	if(!OoB(y,x)){
		if(!OoB(y+1, x+1)){
			if(map[y+1][x+1] == tile_code){
				value = 1;
			} else {
				value = 0;
			}
		} else {
			value = (-1);
		}
	} else {
		value = (-2);
	}
	WarnOoB(y, x, y+1, x+1, value);
	return value;
}

int checkTop(int y, int x, int tile_code){
	int value = (-2);
	int NW = checkNW(y,x,tile_code);
	int N = checkN(y,x,tile_code);
	int NE = checkNE(y,x,tile_code);
	if(NW>=0 && N>=0 && NE>=0){
		// printf("\nNW: %d  N: %d  NE: %d", NW, N, NE);
		value = (NW*pow(2, 0))+(N*pow(2,1))+(NE*pow(2,2));
		// printf("\nvalue: %d", value);
	}
	return value;
}

int checkMiddle(int y, int x, int tile_code){
	int value = (-2);
	int W = checkW(y,x,tile_code);
	int C = checkC(y,x,tile_code);
	int E = checkE(y,x,tile_code);
	if(W>=0 && C>=0 && E>=0){
		// printf("\nW: %d  C: %d  E: %d", W, C, E);
		value = (W*pow(2,3))+(C*pow(2,4))+(E*pow(2,5));
		// printf("\nvalue: %d", value);
	}
	return value;
}

int checkBottom(int y, int x, int tile_code){
	int value = (-2);
	int SW = checkSW(y,x,tile_code);
	int S = checkS(y,x,tile_code);
	int SE = checkSE(y,x,tile_code);
	if(SW>=0 && S>=0 && SE>=0){
		// printf("\nSW: %d  S: %d  SE: %d", SW, S, SE);
		value = (SW*pow(2,6))+(S*pow(2,7))+(SE*pow(2,8));
		// printf("\nvalue: %d", value);
	}
	return value;
}

int checkAround(int y, int x, int tile_code){
	int top = checkTop(y,x,tile_code);
	int middle = checkMiddle(y, x, tile_code);
	int bottom = checkBottom(y, x, tile_code);
	int total = top + middle + bottom;
	return total;
}

int whichAround(int y, int x, int tile_code){
	int total = checkAround(y, x, tile_code);
	int m[9];
	for(int i=8; i>=0; i--){
		m[i] = 0;
		if(total/pow(2,i)!=0){
			m[i] = 1;
			total -= pow(2,i);
		}
	}
}

int countAround(int y, int x, int tile_code){
	int total = checkAround(y, x, tile_code);
	int counter = 0;
	for(int i=8; i>=0; i--){
		if(total/pow(2,i)!=0){
			counter++;
			total -= pow(2,i);
		}
	}
}

int ifAnyAround(){
	
}

int ifNAround(){
	
}

int ifAllAround(){
	
}

char translate(int tile_code){
	char ch;
	switch(tile_code){
		case (-99):
			ch = ' ';
			break;
		case 0: // ground
			ch = '.';
			break;
		case 1:
			ch = '_';
			break;
		case 2: // Sea Water
			ch = 'W';
			break;
		case 3: // Shallow Water
			ch = 'w';
			break;
		case 4: // River Water
			ch = '~';
			break;
		case 5: // Sand
			ch = ',';
			break;
		case 6: // Tree
			ch = 't';
			break;
		case 7: // Stone
			ch = 's';
			break;
		case 8: // Iron
			ch = 'i';
			break;
		default:
			ch = '?';
			break;
	}
	return ch;
}

int pNW(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y-1, x-1)){
			value = map[y-1][x-1];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

int pN(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y-1, x)){
			value = map[y-1][x];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

int pNE(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y-1, x+1)){
			value = map[y-1][x+1];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

int pW(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y, x-1)){
			value = map[y][x-1];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

int pC(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y, x)){
			value = map[y][x];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

int pE(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y, x+1)){
			value = map[y][x+1];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

int pSW(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y+1, x-1)){
			value = map[y+1][x-1];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

int pS(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y+1, x)){
			value = map[y+1][x];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

int pSE(int y, int x, int return_is_0__print_is_1){
	int value = (-99);
	if(!OoB(y,x)){
		if(!OoB(y+1, x+1)){
			value = map[y+1][x+1];
		} else {
			value = (-99);
		}
	} else {
		value = (-99);
	}
	if (return_is_0__print_is_1 == 1) {
		printf("%c", translate(value));
	}
	return value;
}

void pTilesAround(int y, int x){
	if((y-1<0 || y+1>max_y) || (x-1<0 || x+1>max_x)){
	} else {
		printf("\nPrinting tiles around map[%d][%d]", y, x);
		printf("\n");
		printf("\n\t%d, %d, %d", pNW(y, x, 0), pN(y, x, 0), pNE(y, x, 0));
		printf("\n\t%d, %d, %d",  pW(y, x, 0), pC(y, x, 0),  pE(y, x, 0));
		printf("\n\t%d, %d, %d", pSW(y, x, 0), pS(y, x, 0), pSE(y, x, 0));
	}
}

void printMap(){
	for(int y = 0; y <= max_y; y++) {
		printf("\n ");
		for(int x = 0; x <= max_x; x++){
			pC(y, x, 1);
			printf(" ");
		}
	}
}

void tweakMap(int *y, int *x){
	
}


int current_y = 0;
int current_x = 0;

main(){
	printMap();
}
