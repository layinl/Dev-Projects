#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


int distancia_x_preco[10][10] = 
{
	{   -2	,  107	,  140	,  429	,   72	, 2981	, 1427	,  422	,  325	,  408	},
	{  100	,   -2	,  223	,  495	,  164	, 3029	, 1379	,  432	,  257	,  396	},
	{  125	,  170	,   -2	,  306	,  212	, 2855	, 1547	,    0	,    0	,  592	},
	{  400	,  450	,  250	,   -2	,  587	,   -1	, 1815	,  813	,  740	,  835	},
	{   70	,  150	,  200	,  450	,   -2	, 3032	, 1398	,  531	,  421	,  414	},
	{  980	,  990	,  990	,   -1	,  995	,   -2	, 4306	,   -1	, 2938	, 3309	},
	{  450	,  450	,  475	,  500	,  450	,  600	,   -2	, 1697	, 1478	,  980	},
	{  350	,  240	,   75	,  600	,  500	,   -1	,  600	,   -2	,    0	,  730	},
	{  400	,  250	,   75	,  175	,  375	,  600	,  650	,   75	,   -2	,  497	},
	{  375	,  350	,  350	,  400	,  325	,  750	,  600	,  550	,  400	,   -2	}
};

void pGuia(int cidade){
	char guia_viagem[10][500] = {
				/* 0 - SP		*/	"",
				/* 1 - Sorocaba */	"",
				/* 2 - Taubate  */	"",
				/* 3 - Rio		*/	"", 
				/* 4 - Santos	*/	"Orquidário Municipal de Santos. Inaugurado em 1945, é um parque zoobotânico com 22.240m2 que mistura características de belos jardins e aspectos de matas naturais. Dispõe de uma floresta urbana exuberante, cuidadosamente plantada e cultivada, em particular com espécies da Mata Atlântica, além de estufa com uma coleção de centenas de orquídeas.",
				/* 5 - Natal	*/	"Um show de história pode ser apreciado por quem visita este lugar. Os guias são muito bem preparados e divertidos(em especial, um chamado Neif). Não tem como não voltar no tempo e imaginar tudo o que acontecia naquele lugar e como viviam os soldados que ali guerreavam e moraram por alguns anos.",
				/* 6 - Pelotas	*/	"Localizado em frente ao Mercado Central, foi elaborado pelo desenhista e aquarelista Dominique Pineau. Concebido inicialmente como escola municipal pelos herdeiros do tenente Coronel Eliseu Antunes Maciel, para prestar-lhe uma homenagem, o prédio foi cedido pelacâmara em 1883 para a fundação da Escola de Medicina Veterinária e Agricultura Prática.",
				/* 7 - Barretos	*/	"O parque Peão de Boiadeiros de Barretos foi inaugurado em 1985, é mais uma obra do renomado arquiteto Oscar Niemeyer e tem mais de 30 mil lugares. É ond acontece o grande evento da cidade, a Festa de Peão de Barretos, todos os anos durante o mês de agosto.",
				/* 8 - Bauru	*/	"",
				/* 9 - Curitiba	*/	"Um dos cartões postais mais famosos do Brasil, o Jardim Botânico funciona como um centro de pesquisas da flora do Paraná. Sua principal atração é uma estufa de ferro e vidro, inspirada no Paláio de Cristal de Londres."
	};
	
	if(strcmp(guia_viagem[cidade], "") != 0 && cidade >= 0 && cidade <= 9){
		printf("\n\t Esta cidade tem um ponto turístico! Descrição:");
		printf("\n\t%s\n", guia_viagem[cidade]);
	}
}

void p();
void pl(){ // pausa e limpa
	p();
	system("cls");
} // pausa e limpa

void p(){ // pausa
	printf("\n\nPressione qualquer tecla para continuar. "); getch();
} // pausa

void l(){ // limpa
	system("cls");
} // limpa

bool calcularViagem(int partida, int chegada){
	bool novamente = false;
	if(distancia_x_preco[partida][chegada]==-1){
		printf("\nInfelizmente, a Prado's Delivery não faz esse percurso.");
		novamente = true;
	} else if(distancia_x_preco[chegada][partida]==-2) {
		printf("\nInfelizmente, a Prado's Delivery não faz entregas municipais.");
		novamente = true;
	} else {
		if (partida > chegada){
			// DISTÂNCIA
			printf("\nDistância: %dkm", distancia_x_preco[chegada][partida]);
			if(distancia_x_preco[chegada][partida]==0){
				printf(". As cidades são vizinhas.");
			}
			
			// PREÇO
			printf("\nPreço: R$%d", distancia_x_preco[partida][chegada]);
		} else {
			// DISTÂNCIA
			printf("\nDistância: %dkm", distancia_x_preco[partida][chegada]);
			if(distancia_x_preco[partida][chegada]==0){
				printf(". As cidades são vizinhas.");
			}
			// PREÇO
			printf("\nPreço: R$%d", distancia_x_preco[chegada][partida]);
		}
	}
	return novamente;
}

int retorna_km(int partida, int chegada){
	int km = 0;
	if(distancia_x_preco[partida][chegada]==-1){
	} else if(distancia_x_preco[chegada][partida]== -2) {
	} else {
		if (partida > chegada){
			km = distancia_x_preco[chegada][partida];
		} else {
			km = distancia_x_preco[partida][chegada];
		}
	}
	return km;
}

retorna_reais(int partida, int chegada){
	int reais = 0;
	if(distancia_x_preco[partida][chegada]==-1){
	} else if(distancia_x_preco[chegada][partida]==-2) {
	} else {
		if (partida > chegada){
			reais = distancia_x_preco[partida][chegada];
		} else {
			reais = distancia_x_preco[chegada][partida];
		}
	}
	return reais;
}

int moduloPartida(){
	int partida = 12;
	while(partida>9 || partida<0){
		printf("\nCidade de partida:");
		printf("\n0) SP");
		printf("\n1) Sorocaba");
		printf("\n2) Taubaté");
		printf("\n3) Rio");
		printf("\n4) Santos");
		printf("\n5) Natal");
		printf("\n6) Pelotas");
		printf("\n7) Barretos");
		printf("\n8) Bauru");
		printf("\n9) Curitiba");
		printf("\n     ");
		scanf("%d", &partida);
		printf("\n");
		if(partida>9 || partida<0){
			printf("Opção inválida!");
			printf("\n");
		}
		pGuia(partida);
	}
	return partida;
}

int moduloChegada(){
	int chegada = 12;
	while(chegada>9 || chegada<0){
		printf("\nCidade de chegada:");
		printf("\n0) SP");
		printf("\n1) Sorocaba");
		printf("\n2) Taubaté");
		printf("\n3) Rio");
		printf("\n4) Santos");
		printf("\n5) Natal");
		printf("\n6) Pelotas");
		printf("\n7) Barretos");
		printf("\n8) Bauru");
		printf("\n9) Curitiba");
		printf("\n     ");
		scanf("%d", &chegada);
		printf("\n");
		if(chegada>9 || chegada<0){
			printf("Opção inválida!");
			printf("\n");
		}
		pGuia(chegada);
	}
	return chegada;
}

int moduloChegadas(){
	int chegada = 12;
	while((chegada>9 || chegada<0) && chegada != 99){
		printf("\nCidade de chegada:");
		printf("\n0) SP");
		printf("\n1) Sorocaba");
		printf("\n2) Taubaté");
		printf("\n3) Rio");
		printf("\n4) Santos");
		printf("\n5) Natal");
		printf("\n6) Pelotas");
		printf("\n7) Barretos");
		printf("\n8) Bauru");
		printf("\n9) Curitiba");
		printf("\n");
		printf("\n99) FINALIZAR TRAJETO");
		printf("\n     ");
		scanf("%d", &chegada);
		printf("\n");
		if((chegada>9 || chegada<0) && chegada != 99){
			printf("Opção inválida!");
			printf("\n");
		}
		pGuia(chegada);
	}
	return chegada;
}

viagemIndividual(){
	int partida = 12, chegada = 12;
	bool novamente = true;
	printf("\n     Viagem Individual");
	printf("\n");
	while(novamente == true) {
		
		partida = moduloPartida();
		
		chegada = moduloChegada();
		
		novamente = calcularViagem(partida, chegada);
		
		pl();
	}
}

viagensConjuntas(){
	int trajeto[100];
	int n_cidade = 0;
	int total_km = 0;
	int total_reais = 0;
	int partida, chegada;
	bool fim = false;
	while (fim != true){
		if (n_cidade == 0){
			trajeto[n_cidade] = moduloPartida();
		} else {
			printf("\nPartida: %d", trajeto[n_cidade-1]);
			trajeto[n_cidade] = moduloChegadas();
		}
		if (n_cidade >= 1 && trajeto[n_cidade] != 99){
			calcularViagem(trajeto[n_cidade-1], trajeto[n_cidade]);
			total_km += retorna_km(trajeto[n_cidade-1], trajeto[n_cidade]);
			total_reais += retorna_reais(trajeto[n_cidade-1], trajeto[n_cidade]);
		}
		if (trajeto[n_cidade]==99){
			fim = true;
		}
		n_cidade++;
	}
	printf("\n\tTotal km:  %d", total_km);
	printf("\n\tTotal R$:  %d", total_reais);
	
	pl();
}

menuPrincipal() {
	bool sair = false;
	while (sair!=true){
		int input = -2;
		while (input<0 || input>2){
			printf("\n     GPS - Menu Principal");
			printf("\n");
			printf("\n1) Viagem individual");
			printf("\n2) Viagens conjuntas");
			printf("\n0) Sair");
			printf("\n     ");
			scanf("%d", &input);
			switch(input){
				case 1:
					viagemIndividual();
					break;
				case 2:
					viagensConjuntas();
					break;
				case 0:
					sair = true;
					break;
			}
		}
	}
}

main(){
	setlocale(LC_ALL, "Portuguese");
	menuPrincipal();
}





