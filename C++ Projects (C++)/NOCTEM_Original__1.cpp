#include <stdio.h>
#include <string.h>
#include <thread>
#include <ctype.h>
#include <iostream>
#include <chrono>
#include <ctime>

int local = 101;
int rng(int min, int max){
	return (min+(rand()%((max-min)+1)));
}

// GAME TIMER
long time_start = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
int time_total_seconds(){
	long now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() - time_start;
}
int miliseconds = 0;;
int seconds = 0;
void add_second();
int minutes = 0;
void add_minute();
int hours = 0;
void add_hour();
int days = 0;
void add_day();
int months = 0;
void add_month();
int years = 0;
void add_year();

struct quest{
	char name[100];
	char briefing[500];
	int status; // 0 = inactive;  
};
struct quest quests[1000];

struct quest findQuestByName(char name[]){
	for(int i=0; i<1000; i++){
		if(strcmp(quests[i].name, name)==0){
			return quests[i];
		}
	}
}

struct player {
	// xp, damage, health, gold
	int experience = 0;
	int damage = 5;
	int max_health = 500;
	int health = max_health;
	int gold = 15;
	
	// quests
	struct quest quests[25];
	int last_quest_added = 0;
	int quests_completed[25];
	void addQuest(char name[100]){
		quests[last_quest_added] = findQuestByName("Reconstruir Poço");
		last_quest_added;
	};
	
	// attributes
	
	
	// inventory
	int wood;
	int stone;
	int rope;
	
	// discoveries
	char lugares_descobertos[200][50];
	int lug_desc = 0;
	char receitas_descobertas[500][100];
	int rec_desc = 0;
	bool jaDescobriu(char lugar[], char which[]) {
		bool ja_descobriu = false;
		if(strcmp(which, "this")){
			for(int i = 0; i<lug_desc; i++){
				printf("%d", i);
				if(strcmp(lugares_descobertos[i], lugar)==0){
					ja_descobriu = true;
				}
			}
		} else {
			// ANY
		}
		return ja_descobriu;
	}
	void desc_lug(char lugar[]) {
		strcpy(lugares_descobertos[lug_desc], lugar);
		lug_desc++;
	}
	void desc_rec(char receita[]) {
		strcpy(receitas_descobertas[rec_desc], receita);
		rec_desc++;
	}
};
struct player py;

struct enemy {
	char name[50];
	int damage;
	int max_health;
	int health;
	int rewardGold() {
		return (max_health/10) * (damage/2);
	}
	int rewardExperience() {
		return (max_health/5) * damage;
	}
};
struct enemy ey;
struct enemy ey_db[50];
int last_ey_created = 0;
void create_enemy(char name[50], int damage, int max_health);
bool enemies1_not_exist = true;
void create_enemies1();
bool enemies2_not_exist = true;
void create_enemies2();
bool enemies3_not_exist = true;
void create_enemies3();

void create_enemies1() {
	if (enemies1_not_exist){
		create_enemy("Capivara", 2, 10);
		create_enemy("Goblin", 5, 25);
		create_enemy("Kobold", 10, 50);
		create_enemy("Stone Golem", 15, 100);
		create_enemy("Goblin King", 25, 250);
		enemies1_not_exist = false;
	}
}

/*
void create_enemies2() {
	if (enemies2_not_exist){
		create_enemy("Capivara", 2, 10);
		create_enemy("Goblin", 5, 25);
		create_enemy("Kobold", 10, 50);
		create_enemy("Stone Golem", 15, 100);
		create_enemy("Goblin King", 25, 250);
		enemies2_not_exist = false;
	}
}
*/



/*
void create_enemies3() {
	if (enemies3_not_exist){
		create_enemy("Capivara", 2, 10);
		create_enemy("Goblin", 5, 25);
		create_enemy("Kobold", 10, 50);
		create_enemy("Stone Golem", 15, 100);
		create_enemy("Goblin King", 25, 250);
		enemies3_not_exist = false;
	}
}
*/

void add_milisecond(){
	miliseconds++;
	add_second();
}

void add_second(){
	if(miliseconds>=1000){
		miliseconds = miliseconds - 1000;
		seconds++;
		add_minute();
	}
}

void add_minute(){
	if(seconds>=50){
		seconds = seconds - 50;
		minutes++;
		add_hour();
	}
}

void add_hour(){
	if(minutes>=50){
		minutes = minutes - 50;
		hours++;
		add_day();
	}
}

void add_day(){
	if(hours>=20){
		hours = hours - 20;
		days++;
		add_month();
	}
}

void add_month(){
	if(days>=40){
		days = days - 40;
		months++;
		add_year();
	}
}

void add_year(){
	if(months>=10){
		months = months - 60;
		years++;
	}
}

void pass_x_miliseconds(int x){
	for(int i=0; i<x; i++){
		add_milisecond();
	}
}

void pass_second(){
	pass_x_miliseconds(1000);
}

void pass_x_seconds(int x){
	for(int i=0; i<x; i++){
		pass_second();
		printf("\nPassed %d second(s).", i);
	}
}

void create_enemy(char name[50], int damage, int max_health){
	strcpy (ey_db[last_ey_created].name, name);
	ey_db[last_ey_created].damage = damage;
	ey_db[last_ey_created].max_health = max_health;
	ey_db[last_ey_created].health = max_health;
	last_ey_created++;
}

void explorar101_loot(){
	int die2 = rng(1, 100);
	if(die2<=10){
		printf("\nNão encontrou nada de útil.");
	} else if(die2<=30) {
		printf("\nEncontrou 1 Madeira!");
	} else if(die2<=50) {
		printf("\nEncontrou 1 Pedra!");
	} else if(die2<=60){
		printf("\nEncontrou 1 Corda!");
	} else if(die2<=65){
		printf("\nEncontrou 1 Madeira, 1 Pedra e 1 Corda!");
	} else if(die2<=80){
		printf("\nEncontrou 2 Madeiras!");
	} else if(die2<=90){
		printf("\nEncontrou 2 Pedras!");
	} else if(die2<=98){
		printf("\nEncontrou 2 Cordas!");
	} else {
		printf("\nEncontrou 2 Madeira, 2 Pedra e 2 Corda!");
	}
}
void explorar101(){
	int die = rng(1, 100);
	if(die<=75){
		explorar101_loot();
	} else if(die<=90) {
		int die2 = rng(1,20);
		if(die2<=12){
			if(!py.jaDescobriu("Poço", "this")){
				py.desc_lug("Poço");
				printf("\nDescobriu um Poço!");
				py.addQuest("Reconstruir Poço");
			} else {
				explorar101_loot();
			}
		} else if(die2<=19){
			if(!py.jaDescobriu("Floresta", "this")){
				py.desc_lug("Floresta");
				printf("\nDescobriu uma Floresta!");
			} else {
				explorar101_loot();
			}
		} else if(die2==20){
			if(!py.jaDescobriu("Biblioteca", "this")){
				py.desc_lug("Biblioteca");
				printf("\nDescobriu uma Biblioteca!");
			} else {
				explorar101_loot();
			}
		}
	} else if(die<=90) {
		explorar101_loot();
	} else if(die<=99) {
		explorar101_loot();
	} else {
		explorar101_loot();
	}
}
void vila101(){
	while(local==101){
		int op;
		printf("\n\n - -   Você está na Vila   - - ");
		printf("\n");
		printf("\n1) Explorar a Vila");
		printf("\n2) Ir para Casa");
		if(py.jaDescobriu("Floresta", "this")){
			printf("\n3) Ir para a Floresta");
		}
		printf("\n    "); scanf("%d", &op);
		switch(op){
			case 1:
				explorar101();
				break;
			case 2:
				local = 201;
				break;
			case 3:
				local = 301;
				break;
			case 4:
				break;
			case 5:
				break;
		}
	}
};

void casa201() {
	printf("\n - -   Você está em Casa   - - ");
	printf("\n");
	printf("\n1) Descansar");
	printf("\n2) Inventário da Casa");
	printf("\n3) Voltar para a Vila");
	if(py.jaDescobriu("Mina", "this")){
		printf("\n3) Ir para a Mina");
	}
}

void mina401() {
	printf("\n - -   Você está na Mina   - - ");
	printf("\n");
	printf("\n1) Explorar a Mina");
	printf("\n2) Minerar");
	if(py.jaDescobriu("Mina", "this")){
		printf("\n3) Ir para a Mina");
	}
}

void locais(){
	bool sair = false;
	local = 101;
	while(sair != true){
		switch(local){
			case 101:
				vila101();
				break;
			case 201:
				casa201();
				break;
			case 102:
				//biblioteca102();
				break;
			case 301:
				//floresta301();
				break;
			case 401:
				mina401();
				break;
		}
	}
}

void combat(int ey_code){
	ey = ey_db[ey_code];
	while (py.health>0){
		printf("\n  %s's Health: %d", ey.name, ey.health);
		printf("\n  Player Health: %d", py.health);
		
	// Deal Hit!
		ey.health = ey.health - py.damage;
		printf("\n    Dealt %d damage to %s!", py.damage, ey.name);
		printf("\n    Current Goblin's Health: %d", ey.health);
		printf("\n");
		printf("\n");
	
	// Get Hit!
		py.health = py.health - ey.damage;
		printf("\n    Taken %d damage from %s!", ey.damage, ey.name);
		printf("\n    Current Player's Health: %d", py.health);
		printf("\n");
		printf("\n");
		
	// Kill
		if (ey.health <= 0){
			printf("\n    You 've killed the %s!", ey.name);
			py.experience += ey.rewardExperience();
			printf("\n    Recieved %d Experience Points", ey.rewardExperience());
			py.gold += ey.rewardGold();
			printf("\n    Enemy dropped %d Coins", ey.rewardGold());
		}
	
	}
	// Die
	printf("\nYou've collected %d Gold.", py.gold);
	printf("\nFinal Experience: %d", py.experience);
	if(py.jaDescobriu("Casa", "this")){
		//py.respawnOnHome();
	} else if (py.jaDescobriu("Cidade", "any")){
		//py.respawnOnNearestTown();
	} else {
		//py.respawnOnVillage();
	}
}

main() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	// Combat
	locais();
}





