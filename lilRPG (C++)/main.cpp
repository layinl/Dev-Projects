#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Logical Functions
int rng (int min, int max){
	return (min+(rand()%((max-min)+1)));
}

// Game Objects
struct entity {
	float health;
	float max_health;
	float damage;
	float experience;
	float next_level_xp;
	int level;
	float armor;
	int str;
	int agi;
	int dex;
	int inte;
	int vit;
	int luck;
};
struct entity player;
// Player Model:
/*
	str; // dano
	agi; // esquiva, velocidade
	dex; // critico, acerto
	inte; // mana, danoM, capacidade intelectual
	vit; // vida, regen
	luck; // loot
	max_health = 50 + str/2 + vit*3;
	health = max_health;
	float damage;
	float experience;
	float next_level_xp;
	int level;
	float armor;
*/
struct entity enemy;

struct item {
	char name[200];
	int code;
	int type;
	int count;
};
struct item itemDB[500];

struct container {
	char name[200];
	int size;
	struct item slots[];
};
struct container containers[200];

// Functions
	// Player
void py_chooseRace() {
	printf("\nChoose your Race:");
	printf("\n1) Human");
	printf("\n2) Orc");
	printf("\n3) Halfling");
	printf("\n4) Elf");
}


// Main Code
main() {
	printf("\nWelcome to The Way");
	printf("\nChoose your Job:");
	printf("\nChoose your Mindset:");
	printf("\nChoose your Name");
}
