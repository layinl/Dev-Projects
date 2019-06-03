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

struct item{
	char name[100];
	char description[500];
	
	/*
	1 = resource
	2 = consumable
	3 = equipment
	4 = tool
	5 = quest
	*/
	int item_type;
	
	/*
	1 = common
	2 = uncommon
	3 = rare
	4 = legendaary
	5 = unique
	*/
	int item_rarity;
	
	int max_stack;
	
	int uses;
	
	float value;
	
	float weight;
	
};

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
struct entity player;

main(){
	setupBackground();
	setupEntities();
	player = entities[0];
	mainMenu();
}

void setupBackground(){
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
}

int rng(int min, int max){
	return (min+(rand()%(max-min)));
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
	
	
	entities[last_entity_created].max_health = m_hp;
	entities[last_entity_created].health = entities[last_entity_created].max_health;
	entities[last_entity_created].max_mana = m_mp;
	entities[last_entity_created].mana = entities[last_entity_created].max_mana;
	entities[last_entity_created].max_shield = m_shd;
	entities[last_entity_created].shield = entities[last_entity_created].max_shield;
	entities[last_entity_created].health_regen = rng(0, 10) + rng(0, 10)*entities[last_entity_created].entity_rarity;
	entities[last_entity_created].mana_regen = rng(0, 5) + rng(0, 5)*entities[last_entity_created].entity_rarity;
	entities[last_entity_created].damage = rng(2, 20) + rng(2, 20)*entities[last_entity_created].entity_rarity;
	entities[last_entity_created].armor = rng(0, 100) + rng(0, 100)*entities[last_entity_created].entity_rarity;
	
	strcpy(name, strcat(pos1, strcat(pos4, strcat(pos2, pos3) ) ) );
	strcpy(entities[last_entity_created].name, name);
	printf("%s", name);
}

createBasicEntity(char name[], int m_hp, int m_mp, int m_shd, float hp_reg, float mp_reg, float dmg, int armor){
	strcpy(entities[last_entity_created].name, name);
	entities[last_entity_created].max_health = m_hp;
	entities[last_entity_created].health = entities[last_entity_created].max_health;
	entities[last_entity_created].max_mana = m_mp;
	entities[last_entity_created].mana = entities[last_entity_created].max_mana;
	entities[last_entity_created].max_shield = m_shd;
	entities[last_entity_created].shield = entities[last_entity_created].max_shield;
	entities[last_entity_created].health_regen = hp_reg;
	entities[last_entity_created].mana_regen = mp_reg;
	entities[last_entity_created].damage = dmg;
	entities[last_entity_created].armor = armor;
	last_entity_created++;
}

createComplexEntity(char name[], int m_hp, int m_mp, int m_shd, float hp_reg, float mp_reg, float dmg, int armor, int res_f, int res_a, int res_w, int res_e){
	strcpy(entities[last_entity_created].name, name);
	entities[last_entity_created].max_health = m_hp;
	entities[last_entity_created].health = entities[last_entity_created].max_health;
	entities[last_entity_created].max_mana = m_mp;
	entities[last_entity_created].mana = entities[last_entity_created].max_mana;
	entities[last_entity_created].max_shield = m_shd;
	entities[last_entity_created].shield = entities[last_entity_created].max_shield;
	entities[last_entity_created].health_regen = hp_reg;
	entities[last_entity_created].mana_regen = mp_reg;
	entities[last_entity_created].damage = dmg;
	entities[last_entity_created].armor = armor;
	entities[last_entity_created].resist_fire = res_f;
	entities[last_entity_created].resist_air = res_a;
	entities[last_entity_created].resist_water = res_w;
	entities[last_entity_created].resist_earth = res_e;
	last_entity_created++;
}

void createPlayer(){
	printf("\n\tDê um nome ao seu personagem:  ");
	gets(entities[0].name);
	entities[0].max_health = 100;
	entities[0].health = entities[0].max_health;
	entities[0].max_mana = 0;
	entities[0].mana = entities[0].max_mana;
	entities[0].max_shield = 0;
	entities[0].shield = entities[0].max_shield;
	entities[0].health_regen = 0.5;
	entities[0].mana_regen = 0;
	entities[0].damage = 5;
	entities[0].armor = 0;
	entities[0].resist_fire = 0;
	entities[0].resist_air = 0;
	entities[0].resist_water = 0;
	entities[0].resist_earth = 0;
}

void setupEntities(){
	createPlayer();
	createGoblins();
}

void createGoblins(){
	createBasicEntity("Goblin Assassin", 50, 0, 0, 0.2, 0, 4.5, 10);
	createBasicEntity("Goblin Archer", 30, 0, 0, 0.2, 0, 7, 8);
	createBasicEntity("Goblin Tank", 80, 0, 0, 0.5, 0, 5, 25);
	createBasicEntity("Goblin Looter", 20, 0, 0, 0.2, 0, 3, 0);
	createComplexEntity("Goblin Earth Mage", 60, 150, 20, 0.2, 2, 5, 5, 0, 0, 0.2, 0.5);
	createComplexEntity("Goblin Commander", 150, 100, 55, 1.2, 0.8, 15, 30, 0, 0, 0, 0);
	createComplexEntity("Goblin King", 500, 100, 55, 1.2, 0.8, 30, 50, 0, 0.1, 0.2, 0.5);
}

void mainMenu(){
	int input=1;
	while(input!=0){
		printf("\n\tPressione qualquer tecla para continuar."); getch();
		system("cls");
		printf("\n\t\tMain menu options: (Choose by option number)");
		printf("\n");
		printf("\n\t1) Open enemy catalog");
		printf("\n\t2) Choose enemy by code");
		printf("\n\t3) Duel a random enemy");
		printf("\n\t4) ");
		printf("\n\t5) ");
		printf("\n\t0) Exit");
		printf("\n\t");
		scanf("%d", &input);
		switch(input){
			case 1:
				enemyCatalog();
				break;
			case 2:
				duelByCode();
				break;
			case 3:
				duelRandom();
				break;
			case 4:
				break;
			case 5:
				break;
			case 0:
				break;
			default:
				printf("\n\tOpção inválida.\n");
				break;
		}
	}
}

void enemyCatalog(){
	for(int i=1; i<last_entity_created; i++){
		printf("\n\tCode:  %d", i);
		printf("\n\tName:  %s", entities[i].name);
		printf("\n");
	}
}

void duelByCode(){
	int cod;
	printf("\n\tCódigo do inimigo:  ");
	scanf("%d", &cod);
	duel(cod);
}

void duelRandom(){
	duel(1+(rand()%(last_entity_created-1)));
}

void duel(int code){
	struct entity enemy = entities[code];
	bool fugiu = false;
	int input=1;
	while(entities[0].health>0 && entities[code].health>0 && !fugiu){
		printf("\n\t\t%s's life:  %.2f/%d\t\t%s's life:  %.2f/%d", player.name, player.health, player.max_health, enemy.name, enemy.health, enemy.max_health);
		printf("\n\t\t%s's mana:  %.2f/%d\t\t%s's mana:  %.2f/%d", player.name, player.mana, player.max_mana, enemy.name, enemy.mana, enemy.max_mana);
		printf("\n\t\t%s's damage:  %.2f\t\t%s\'s damage:  %.2f", player.name, player.damage, enemy.name, enemy.damage);
		printf("\n");
		printf("\n\tOpções de combate:");
		printf("\n");
		printf("\n\t1) Atacar");
		printf("\n\t2) Defender");
		printf("\n\t3) Usar Habilidade");
		printf("\n\t4) Fugir");
		printf("\n");
		scanf("%d", &input);
		switch(input){
			case 1:
				playerAttack(enemy);
				break;
			case 2:
				playerDefend(enemy);
				break;
			case 3:
				useSkill();
				break;
			case 4:
				fugiu = flee(enemy);
				break;
			default:
				printf("\n\tOpção inválida.");
				break;
		}
	}
}

void playerAttack(struct entity enemy){
	
}

void playerDefend(struct entity enemy){
	
}

void useSkill(){
	
}

bool flee(struct entity enemy){
	/*
	if (){
		return true;
	} else if (){
		
	} else {
		
	}
	*/
}














