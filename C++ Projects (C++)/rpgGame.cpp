#include <stdio.h>
#include <string.h>

int max_x = 2;
int max_y = 2;

/*
int map[15][15] = {
						    //   x = 7   //
			{2, 2, 2, 2, 2, 2, 0,  0, 2, 2, 2, 2, 2, 0, 0},
			{2, 2, 2, 2, 0, 0, 0,  0, 2, 2, 2, 2, 0, 0, 0},
			{2, 2, 0, 0, 0, 0, 0,  0, 0, 2, 2, 2, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 2, 2, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 2, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0},   //   y = 7   //
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0}
};
*/

int map[3][3] = {
					{2, 2, 0},
					{0, 0, 0},
					{0, 0, 0}
};

			/*	base-func 
scrollMapLRUD() {     (Left-Right, Up-Down)

	int y = map_y, x = map_x;
	for(int i = 0; i <= y; i++) {
		for(int j = 0; j <= x; j++){
			
			// each column
		}
		
		// end of line
	}
	
}
			*/

bool checkCurrentFor(int current_tile_y, int current_tile_x, int tile_code){
	bool equals_tile_code = false;
	int y = current_tile_y, x = current_tile_x;
	if(isInsideMapLimits(y, x)){
		if(map[y][x] == tile_code){
			equals_tile_code = true;
		}
	}
	return equals_tile_code;
}

bool* checkTopFor(int current_tile_y, int current_tile_x, int tile_code){
	int y = current_tile_y, x = current_tile_x;
	bool NW_N_NE[3] = { checkNWFor(y, x, tile_code),   checkNorthFor(y, x, tile_code),   checkNEFor(y, x, tile_code) };
	return NW_N_NE;
}
			
bool* checkBottomFor(int current_tile_y, int current_tile_x, int tile_code){
	int y = current_tile_y, x = current_tile_x;
	bool SW = checkSWFor(y, x, tile_code);
	bool S = checkSouthFor(y, x, tile_code);
	bool SE = checkSWFor(y, x, tile_code);
	bool bottom[3] = {SW, S, SE};
	return bottom;
}
			
bool* checkRightFor(int current_tile_y, int current_tile_x, int tile_code){
	int y = current_tile_y, x = current_tile_x;
	bool NE = checkNEFor(y, x, tile_code);
	bool E = checkEastFor(y, x, tile_code);
	bool SE = checkSEFor(y, x, tile_code);
	bool right[3] = {NE, E, SE};
	return right;
}
			
bool* checkLeftFor(int current_tile_y, int current_tile_x, int tile_code){
	int y = current_tile_y, x = current_tile_x;
	bool NW = checkNWFor(y, x, tile_code);
	bool W = checkWestFor(y, x, tile_code);
	bool SW = checkSWFor(y, x, tile_code);
	bool left[3] = {NW, W, SW};
	return left;
}

bool checkAroundFor(int current_tile_y, int current_tile_x, int tile_code){
	int y = current_tile_y, x = current_tile_x;
	bool top[3] = {checkTopFor(y,x,tile_code)};
	bool west = checkWestFor(y,x,tile_code);
	bool east = checkEastFor(y,x,tile_code);
	bool bottom[3] = {checkBottomFor(y,x,tile_code)};
	bool around[8] = {
							top,
						west, east,
						   bottom
					 };
	return around;
}

void ifThisAndAny(int current_tile_y, int current_tile_x, int tile_code, int this_code){
	
}

void ifThisAndN(int current_tile_y, int current_tile_x, int tile_code, int this_code){
	
}

void ifThisAndAll(int current_tile_y, int current_tile_x, int tile_code, int this_code){
	
}

bool ifAnyAround(int current_tile_y, int current_tile_x, int tile_code){
	bool around[8] = {checkAroundFor(current_tile_y, current_tile_x, tile_code)};
	bool any = false;
	for(int i = 0; i < 8; i++){
		if (around[i]){
			printf("\n\t%d: true", i);
		} else {
			printf("\n\t%d: false", i);
		}
	}
	return any;
}

bool ifNAround(int current_tile_y, int current_tile_x, int tile_code, int n){
	bool around[8] = {checkAroundFor(current_tile_y, current_tile_x, tile_code)};
	int count = 0;
	bool reached_n = false;
	for(int i = 0; i < 8; i++){
		if (around[i]){
			count++;
		}
	}
	if(count>=n){
		reached_n = true;
	}
	return reached_n;
}

bool ifAllAround(int current_tile_y, int current_tile_x, int tile_code){
	bool around[8] = {checkAroundFor(current_tile_y, current_tile_x, tile_code)};
	int count = 0;
	bool all = false;
	for(int i = 0; i < 8; i++){
		if (around[i]){
			count++;
		}
	}
	if(count==8){
		all = true;
	}
	return all;
}

void changeThisIfAny(int current_tile_y, int current_tile_x, int tile_code, int this_tile){
	if(ifAnyAround(current_tile_y, current_tile_x, tile_code)){
		map[current_tile_y][current_tile_x] = this_tile;
	}
}

void makeShallowFromSea(int current_tile_y, int current_tile_x){
	changeThisIfAny(current_tile_y, current_tile_x, 2, 3);
}

void tweakMap(){
	int y = max_y, x = max_x;
	for(int i = 0; i <= y; i++) {
		for(int j = 0; j <= x; j++){
			makeShallowFromSea(i, j);
			// each column
		}
		// end of line
	}
}

char translate(int tile_code){
								// X is terrain           
									// 00 (or 0) is regular ground/grass
									// 01 (or 1) is sand
									// 02 (or 2) is sea water
									// 03 (or 3) is shallow water
									// 04 (or 4) is river
									// 05 (or 5) is a terrain that has a tree
									// 06 (or 6) is a terrain that has a stone
									// 07 (or 7) is a terrain that has iron ore
								// 1X is entity
									// 10 is the player
									// 11 is a Slime
									// 12 is a Boar
									// 13 is a Zombie
									// 14 is a Kobold Archer
									// 15 is an Orc Warrior
	char ascii;
	switch(tile_code){
		// Terrains
		case 0: // grass
			ascii = '_';
			break;
		case 1: // sand
			ascii = '.';
			break;
		case 2: // sea water
			ascii = 'W';
			break;
		case 3: // shallow water
			ascii = 'w';
			break;
		case 4: // river
			ascii = '~';
			break;
		case 5: // terrain that has a tree
			ascii = 'T';
			break;
		case 6: // terrain that has a stone
			ascii = 'S';
			break;
		case 7: // terrain that has iron ore
			ascii = 'I';
			break;
		// Entities
		case 10: // Player
			ascii = '@';
			break;
		case 11: // Slime
			ascii = 's';
			break;
		case 12: // Boar
			ascii = 'b';
			break;
		case 13: // Zombie
			ascii = 'z';
			break;
		case 14: // Kobold Archer
			ascii = 'â';
			break;
		case 15: // Orc Warrior
			ascii = 'õ';
			break;
	}
	return ascii;
}

void printMap(){
	printf("\n\t\tShowing Map:");
	printf("\n\t");
	int y = max_y, x = max_x;
	printf("\n\t    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14");
	for(int i = 0; i <= y; i++){
		if(i>(-10) && i<10){
			printf("\n\t%d:  ", i);
		} else {
			printf("\n\t%d: ", i);
		}
		for(int j = 0; j <= x; j++){
			printf("%c", translate(map[i][j]));
			
			if (j != x) {
				printf("  ");
			}
		}
	}
}

printAround(int current_tile_y, int current_tile_x, char IDENTIFIER_TEST_OR_ASCII[]){
	int y = current_tile_y, x = current_tile_x, tile_code;
	if (isInsideMapLimits(y,x) && (y!=max_y && y!=0) && (x!=max_x && x!=0)){
		if (strcmp(IDENTIFIER_TEST_OR_ASCII, "TEST")==0){
			printf("\n(!) Input the tile code to test (!)");
			scanf("%d", &tile_code);
			bool around[8] = {
				checkNWFor(y,x,tile_code), checkNorthFor(y,x,tile_code), checkNEFor(y,x,tile_code),
				checkWestFor(y,x,tile_code), checkEastFor(y,x,tile_code),
				checkSWFor(y,x,tile_code), checkSouthFor(y,x,tile_code), checkSEFor(y,x,tile_code)
				};
				printf("\n\t");
			for(int i = 0; i<8; i++){
				if(i==4){
					printf("----, ");
				}
				if(around[i]){
					printf("true");
				} else {
					printf("false");
				}
				if (i==2 || i==4 || i==7) {
					printf("\n\t");
				} else {
					printf(", ");
				}
			}
		} else if (strcmp(IDENTIFIER_TEST_OR_ASCII, "ASCII")==0) {
			printf("\nPrinting around for map[%d][%d]", y, x);
			printf("\n");
			printf("\n\t%d, %d, %d", map[y-1][x-1], map[y-1][x], map[y-1][x+1]);
			printf("\n\t%d, %d, %d", map[y][x-1], map[y][x], map[y][x+1]);
			printf("\n\t%d, %d, %d", map[y+1][x-1], map[y+1][x], map[y+1][x+1]);
		}
	} else {
		printf("\nThis tile is not inside the map and/or does not have all tiles around for testing or showing.");
	}
}

main(){
	printf("%d", checkNorthFor(0,1,0));
}
