#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

// Storing how much time has passed since the program started
long time_start = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
int time_total_seconds(){
	long now = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() - time_start;
}



// Variables to define measurement sizes
int miliseconds_in_a_second = 1000;
int seconds_in_a_minute = 60;
int minutes_in_an_hour = 60;
int hours_in_a_day = 24;
int days_in_a_month = 30;
int months_in_a_year = 12;



/*	====	====	====	Storing how much time has passed	====	====	====	*/

// Variables
int minutes = 0;
int hours = 0;
int days = 0;
int months = 0;
int years = 0;

// Functions

	// Declarations
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

	// Definitions
void addMinute(){
	minutes++;
	addHour();
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



/*	====	====	====	Passing time	====	====	====	*/

void passMinute(){
	addMinute();
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

void passTime(bool pass){
	int previous = time_total_seconds();
	while(pass){
		int now = time_total_seconds() - previous;
		if(now!=0){
			passMinute();
			previous = time_total_seconds();
			now = 0;
		}
	}
}

main(){
	printf("seconds passed:");
	passTime(true);
}



