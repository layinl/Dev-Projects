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

struct quest{
	char name[100];
	char briefing[500];
	int status; // 0 = inactive;  
};
struct quest questDB[1000];

struct quest findQuestByName(char name[]){
	for(int i=0; i<1000; i++){
		if(strcmp(questDB[i].name, name)==0){
			return questDB[i];
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
	struct quest quests[300];
	int last_quest_added = 0;
	int quests_completed[300];
	void addQuest(char name[]){
		quests[last_quest_added] = findQuestByName(name);
		last_quest_added++;
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


// Variables to define measurement sizes
int miliseconds_in_a_second = 1000;
int seconds_in_a_minute = 60;
int minutes_in_an_hour = 60;
int hours_in_a_day = 24;
int days_in_a_month = 30;
int months_in_a_year = 12;


// Variables
int miliseconds = 0;
int seconds = 0;
int minutes = 0;
int hours = 0;
int days = 0;
int months = 0;
int years = 0;

// Functions

	// Declarations
void addMilisecond();
void passMilisecond();
void passXMiliseconds();
void addSecond();
void passSecond();
void passXSeconds();
void addMinute();
void passMinute();
void passXMinutes();
void addHour();
void passHour();
void passXHours();
void addDay();
void passDay();
void passXDays();
void addMonth();
void passMonth();
void passXMonths();
void addYear();
void passYear();
void passXYears();


void addMilisecond(){
	miliseconds++;
	addSecond();
}

void addSecond(){
	if(miliseconds>=miliseconds_in_a_second){
		miliseconds = miliseconds - miliseconds_in_a_second;
		seconds++;
		addMinute();
	}
}

void addMinute(){
	if(seconds>=seconds_in_a_minute){
		seconds = seconds - seconds_in_a_minute;
		minutes++;
		addHour();
	}
}

void addHour(){
	if(minutes>=minutes_in_an_hour){
		minutes = minutes - minutes_in_an_hour;
		hours++;
		addDay();
	}
}

void addDay(){
	if(hours>=hours_in_a_day){
		hours = hours - hours_in_a_day;
		days++;
		addMonth();
	}
}

void addMonth(){
	if(days>=days_in_a_month){
		days = days - days_in_a_month;
		months++;
		addYear();
	}
}

void addYear(){
	if(months>=months_in_a_year){
		months = months - months_in_a_year;
		years++;
	}
}

void passXMiliseconds(int x){
	for(int i=0; i<x; i++){
		addMilisecond();
	}
}

void passSecond(){
	passXMiliseconds(miliseconds_in_a_second);
}

void passXSeconds(int x){
	for(int i=0; i<x; i++){
		passSecond();
	}
}

void passMinute(){
	passXSeconds(seconds_in_a_minute);
}

void passXMinutes(int x){
	for(int i=0; i<x; i++){
		passMinute();
	}
}

void passHour(){
	passXMinutes(minutes_in_an_hour);
}

void passXHours(int x){
	for(int i=0; i<x; i++){
		passHour();
	}
}

void passDay(){
	passXHours(hours_in_a_day);
}

void passXDays(int x){
	for(int i=0; i<x; i++){
		passDay();
	}
}

void passMonth(){
	passXDays(days_in_a_month);
}

void passXMonths(int x){
	for(int i=0; i<x; i++){
		passMonth();
	}
}

void passYear(){
	passXMonths(months_in_a_year);
}

void passXYears(int x){
	for(int i=0; i<x; i++){
		passYear();
	}
}

void create_enemy(char name[50], int damage, int max_health){
	strcpy (ey_db[last_ey_created].name, name);
	ey_db[last_ey_created].damage = damage;
	ey_db[last_ey_created].max_health = max_health;
	ey_db[last_ey_created].health = max_health;
	last_ey_created++;
}

void explorar101_loot(int max){
	int die2 = rng(1, max);
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
	if(die<=50){
		explorar101_loot();
	} else if(die<=75) {
		int die2 = rng(1,20);
		if(die2<=12){
			if(!py.jaDescobriu("Poço", "this")){
				py.desc_lug("Poço");
				printf("\nDescobriu um Poço!");
				py.addQuest("Reconstruir Poço");
			} else {
				explorar101_loot(50);
			}
		} else if(die2<=19){
			if(!py.jaDescobriu("Floresta", "this")){
				py.desc_lug("Floresta");
				printf("\nDescobriu uma Floresta!");
			} else {
				explorar101_loot(80);
			}
		} else if(die2==20){
			if(!py.jaDescobriu("Biblioteca", "this")){
				py.desc_lug("Biblioteca");
				printf("\nDescobriu uma Biblioteca!");
			} else {
				explorar101_loot(150);
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





