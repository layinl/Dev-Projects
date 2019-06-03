#include <stdio.h>
#include <stdlib.h>

int wallet[6];
int tarefa[7];


calculateTarefa(){
	for(int i=0; i<6; i++){
		wallet[i] += tarefa[i] * tarefa[6];
	}
}
limparTarefa(){
	for(int i=0; i<7; i++){
		tarefa[i]=0;
	}
}
limparWallet(){
	for(int i=0; i<6; i++){
		wallet[i]=0;
	}
}
showWallet(){
	printf("\n    # WALLET: (%d, %d, %d, %d, %d, %d)", wallet[0], wallet[1], wallet[2], wallet[3], wallet[4], wallet[5]);
}
showTarefa(){
	printf("\n    # NOCTEM VALUE: (%d, %d, %d, %d, %d, %d) * (%d)", tarefa[0], tarefa[1], tarefa[2], tarefa[3], tarefa[4], tarefa[5], tarefa[6]);
}
infoWallet(){
	limparWallet();
	printf("\n # Informe os valores da wallet:");
	printf("\n # 1) CRIAÇÃO: ");
	scanf("%d", &wallet[0]);
	printf(" # 2) INOVAÇÃO, AUTONOMIA: ");
	scanf("%d", &wallet[1]);
	printf(" # 3) PRAZO, RENOVAÇÃO: ");
	scanf("%d", &wallet[2]);
	printf(" # 4) ATRIBUIÇÃO, OBRIGATORIEDADE: ");
	scanf("%d", &wallet[3]);
	printf(" # 5) DETALHE OPERACIONAL, BÔNUS: ");
	scanf("%d", &wallet[4]);
	printf(" # 6) DETALHE: ");
	scanf("%d", &wallet[5]);
	showWallet();
}
infoTarefa(){
	limparTarefa();
	printf("\n # Informe os valores da tarefa:");
	printf("\n # 1) CRIAÇÃO: ");
	scanf("%d", &tarefa[0]);
	printf(" # 2) INOVAÇÃO, AUTONOMIA: ");
	scanf("%d", &tarefa[1]);
	printf(" # 3) PRAZO, RENOVAÇÃO: ");
	scanf("%d", &tarefa[2]);
	printf(" # 4) ATRIBUIÇÃO, OBRIGATORIEDADE: ");
	scanf("%d", &tarefa[3]);
	printf(" # 5) DETALHE OPERACIONAL, BÔNUS: ");
	scanf("%d", &tarefa[4]);
	printf(" # 6) DETALHE: ");
	scanf("%d", &tarefa[5]);
	printf("\n # Status da Tarefa: (Multiplicador)");
	printf("\n # 1) OK");
	printf("\n # 2) Impecável");
	printf("\n # -1) Importante");
	printf("\n # -2) INQUESTIONÁVEL");
	printf("\n Status: ");
	scanf("%d", &tarefa[6]);
	showTarefa();
	printf("\n # Confirma?");
	printf("\n # 1) SIM");
	printf("\n # 2) NAO");
	printf("\n ");
	int userR=1;
	scanf("%d", &userR);
	if (userR==2){
		limparTarefa();
	}
	calculateTarefa();
	showWallet();
}

menuPrincipal(){
	int userR=1;
	while (userR!=0){
		printf("\n# Menu Principal");
		printf("\n#");
		printf("\n# 1) Informar Tarefa");
		printf("\n# 2) Informar Wallet");
		printf("\n# 0) Sair");
		printf("\n");
		scanf("%d", &userR);
		switch (userR){
			case 1:
				infoTarefa();
				break;
			case 2:
				infoWallet();
				break;
		}
	}
}

main(){
	menuPrincipal();
}
