#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Logical Functions


// Game Objects
struct entity {
	float health;
	float max_health;
	float damage;
	float experience;
	float next_level_xp;
	int level;
	float armor;
};
struct entity player;
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
main() {
	printf("\nWelcome to The Way");
	printf("\nChoose your Race:");
	printf("\nChoose your Job:");
	printf("\nChoose your Mindset:");
	printf("\nChoose your Name");
}
