#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <ctype.h>

void setupEntities();
void setupBackground();
void createGoblins();
void enemyCatalog();
void duelByCode();
void duelRandom();
void mainMenu();
void duel(int code);
void playerAttack(struct entity enemy);
void playerDefend(struct entity enemy);
void useSkill();
bool flee(struct entity enemy);

int last_entity_created = 1;

struct entity{
	char name[50];

	int entity_category;
	/*
	entity category:
	0 = player
	1 = hostile (beast)
	2 = neutral (beast)
	3 = friendly (beast)
	4 = familiar (beast)
	5 = NPC
	*/

	int entity_race;
	/*
	entity race:
	0 = human
	1 = orc
	2 = elf
	3 = goblin
	4 = kobold
	5 = wisp
	*/

	int entity_type;
	/*
	entity type:
	0 = flesh
	1 = wood
	2 = bone
	3 = stone
	4 = metal
	5 = cloth
	*/

	int entity_rarity;
	/*
	entity rarity:
	0 = quest
	1 = common
	2 = uncommon
	3 = rare
	4 = legendary
	5 = unique
	*/

	/*
	int max_health;
	int max_mana;
	int max_shield;
	
	float health;
	float health_regen;
	float mana;
	float mana_regen;
	float shield;
	
	float damage;
	int armor;
	*/
};
struct entity entities[101];

int rng(int min, int max){
	return (min+(rand()%(max-min)+1));
}

createRandomEntity(){
	char name[100];
	char pos1[20];
	char pos2[20];
	char pos3[20];
	char pos4[20];
	
	entities[last_entity_created].entity_rarity = rng(0,5);
	switch(entities[last_entity_created].entity_rarity){
		/*
		entity rarity:
		0 = quest
		1 = common
		2 = uncommon
		3 = rare
		4 = legendary
		5 = unique
		*/
		case 0: // quest
			strcpy(pos1, " Quest");
			break;
		case 1: // common
			strcpy(pos1, " Common");
			break;
		case 2: // uncommon
			strcpy(pos1, " Uncommon");
			break;
		case 3: // rare
			strcpy(pos1, " Rare");
			break;
		case 4: // legendary
			strcpy(pos1, " Legendary");
			break;
		case 5: // unique
			strcpy(pos1, " Unique");
			break;
	}
	
	entities[last_entity_created].entity_type = rng(0,5);
	switch(entities[last_entity_created].entity_type){
		/*
		entity type:
		0 = flesh
		1 = wood
		2 = bone
		3 = stone
		4 = metal
		5 = cloth
		*/
		case 0: // flesh
			strcpy(pos2, " Flesh");
			break;
		case 1: // wood
			strcpy(pos2, " Wooden");
			break;
		case 2: // bone
			strcpy(pos2, " Skeleton");
			break;
		case 3: // stone
			strcpy(pos2, " Stone");
			break;
		case 4: // metal
			strcpy(pos2, " Metallic");
			break;
		case 5: // cloth
			strcpy(pos2, " Cloth");
			break;
	}
	
	entities[last_entity_created].entity_race = rng(0,5);
	switch(entities[last_entity_created].entity_race){
		/*
		entity race:
		0 = human
		1 = orc
		2 = elf
		3 = goblin
		4 = kobold
		5 = wisp
		*/
		case 0: // human
			strcpy(pos3, " Human");
			break;
		case 1: // orc
			strcpy(pos3, " Orc");
			break;
		case 2: // elf
			strcpy(pos3, " Elf");
			break;
		case 3: // goblin
			strcpy(pos3, " Goblin");
			break;
		case 4: // kobold
			strcpy(pos3, " Kobold");
			break;
		case 5: // wisp
			strcpy(pos3, " Wisp");
			break;
	}
	
	entities[last_entity_created].entity_category = rng(0,5);
	switch(entities[last_entity_created].entity_category){
		/*
		entity category:
		0 = player
		1 = hostile (beast)
		2 = neutral (beast)
		3 = friendly (beast)
		4 = familiar (beast)
		5 = NPC
		*/
		case 0: // player
			strcpy(pos4, " Player");
			break;
		case 1: // hostile (beast)
			strcpy(pos4, " Hostile");
			break;
		case 2: // neutral (beast)
			strcpy(pos4, " Neutral");
			break;
		case 3: // friendly (beast)
			strcpy(pos4, " Friendly");
			break;
		case 4: // familiar (beast)
			strcpy(pos4, " Familiar");
			break;
		case 5: // Shop
			strcpy(pos4, " ($hop)");
			break;
	}
	
	printf("\n=============");
	printf("\n=  entity_rarity ----%s", pos1);
	printf("\n=  entity_type ------%s", pos2);
	printf("\n=  entity_race ------%s", pos3);
	printf("\n=  entity_caregory --%s", pos4);
	printf("\n=== = = = = =");
	
	char posW[20];
	char posX[20];
	char posY[20];
	char posZ[20];
	if(strcmp(pos4, " Player")==0 && strcmp(pos2, " Skeleton")==0){
		strcpy(posW, pos1);
		strcpy(posX, pos4);
		strcpy(posY, pos2);
		strcpy(posZ, pos3);
		
		strcpy(pos1, posW); // UNCOMMON	1W -> UNCOMMON	1W
		strcpy(pos4, posZ); // PLAYER	4X -> ELF		4Z
		strcpy(pos2, posY); // SKELETON	2Y -> SKELETON	2Y
		strcpy(pos3, posX); // ELF		3Z -> PLAYER	3X
	} else {
		
		if(strcmp(pos4, " Familiar")==0 && strcmp(pos2, " Skeleton")==0){
		strcpy(posW, pos1);
		strcpy(posX, pos4);
		strcpy(posY, pos2);
		strcpy(posZ, pos3);
		
		strcpy(pos1, posW);
		strcpy(pos4, posZ);
		strcpy(pos2, posY);
		strcpy(pos3, posX);
		} else {
			if(strcmp(pos4, " Familiar")==0){
				strcpy(posX, pos4);
				strcpy(pos4, pos2);
				strcpy(pos2, pos3);
				strcpy(pos3, posX);
			}
			
			if(strcmp(pos2, " Skeleton")==0){
				strcpy(posX, pos2);
				strcpy(pos2, pos3);
				strcpy(pos3, posX);
				strcpy(pos3, posX);
			}
			
			if(strcmp(pos4, " Player")==0){
				strcpy(posX, pos4);
				strcpy(pos4, pos2);
				strcpy(pos2, pos3);
				strcpy(pos3, posX);
			}
		}
	}
	
	strcpy(name, strcat(pos1, strcat(pos4, strcat(pos2, pos3) ) ) );
	strcpy(entities[last_entity_created].name, name);
	printf("\n-  name:  %s", name);
	printf("\n=============");
	printf("\n");
}

main(){
	srand(time(NULL));
	for(int i=0; i<5; i++){
		createRandomEntity();
	}
}
