#include <stdio.h>
#include <stdlib.h>


struct vaca{
	
	int cod;
	float leite;
	float alimen;
	int ano;
	char abate;
	
};

struct vaca rebanho[2000];

int codVaca = 0;

void cadastro(){
	/*
	definir cod automatico,
	pedir leite, alimento, ano -- OK
	definir abate.
	*/
	
	char resposta;
	while (resposta != 'n'){
		rebanho[codVaca].cod = codVaca;
		printf("\n\tDigite Leite ");
		scanf("%f", &rebanho[codVaca].leite);
		printf("\tDigite quantidade de alimento ");
		scanf("%f", &rebanho[codVaca].alimen);
		printf("\tDigite o ano de nascimento ");
		scanf("%d", &rebanho[codVaca].ano);
		// abate = 'S' se:
		bool velha = rebanho[codVaca].ano < 2014;
		bool improdutiva = rebanho[codVaca].leite < 40;
		bool gorda = rebanho[codVaca].leite >= 50 && rebanho[codVaca].leite <= 70 && rebanho[codVaca].alimen/7 > 50;
		if (velha || improdutiva || gorda) {
			rebanho[codVaca].abate = 'S';
		} else {
			rebanho[codVaca].abate = 'N';
		}
		
		printf("\n\n\tCodigo: %d", rebanho[codVaca].cod);
		printf("\n\tLeite: %.2f", rebanho[codVaca].leite);
		printf("\n\tAlimento: %.2f", rebanho[codVaca].alimen);
		printf("\n\tNascimento: %d", rebanho[codVaca].ano);
		printf("\n\tAbate: %c", rebanho[codVaca].abate);
		printf("\n");
		
		codVaca++;
		printf("Deseja cadastrar outro?\n (s ou n)");
fflush(stdin);
		scanf("%c", &resposta);
		
		
	}
system("cls");
	
}

main(){
	int resposta = 1;
	
	/*
	se escolher 1, entra no cadastro
	  criar modulo de cadastro
	se escolher 2, leite da semana
	(...)
	*/
	
	while (resposta != 0){
		printf("\n\tMenu Principal");
		printf("\n");
		printf("\n\t1-Cadastro");
		printf("\n\t2-leite semana");
		printf("\n\t3- alimento semana");
		printf("\n\t4-leite semana pos abate");
		printf("\n\t5-Alimento semana pos abate");
		printf("\n\t6-Vacas para Abate");
		printf("\n\t0- Sair do programa\n");
		
		printf("\n Digite uma opcao  ");
		scanf("%d", &resposta);
	
		switch(resposta){
			case 1:
				cadastro();
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 0:
				
				break;
		}
	}
}
