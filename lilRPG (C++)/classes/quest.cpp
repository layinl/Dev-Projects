#include <stdlib.h>

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

