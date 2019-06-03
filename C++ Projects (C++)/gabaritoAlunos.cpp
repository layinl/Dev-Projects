#include <stdio.h>
#include <string.h>

int i=0, i2=0, alunos=0, questoes=0;

main() {
	printf("Informe o numero de alunos a serem avaliados:\n");
fflush(stdin);
	scanf("%d", &alunos);
	char nome[alunos][15], curso[alunos][70];
	
	for (i=0;i<alunos;i++){
		printf("Informe o nome do %do aluno:\n", i+1);
fflush(stdin);
		gets(nome[i]);
	}
	
	for (i=0;i<alunos;i++){
		printf("Informe o curso do %do aluno:\n", i+1);
fflush(stdin);
		gets(curso[i]);
	}
	
	printf("Informe o numero de questoes na prova:\n");
fflush(stdin);
	scanf("%d", &questoes);
	
	char respostasPorAluno[alunos][questoes+1];
	char gabarito[questoes];
	float acertosPorAluno[alunos];
	float notaPorAluno[alunos];
	
	for (i=0;i<alunos;i++){
		printf("Informe as respostas do aluno %s: (no modelo \"ABACECADDCAE...\"\n", nome[i]);
fflush(stdin);
		gets(respostasPorAluno[i]);
	}
	
	printf("Informe o Gabarito, no modelo \"ABAACEDACED...\":\n");
fflush(stdin);
	gets(gabarito);
	
	for (i=0;i<alunos;i++){
		acertosPorAluno[i] = 0;
		notaPorAluno[i] = 0;
	}
	
	for (i=0;i<alunos;i++){
		for (i2=0;i2<questoes;i2++){
			if (respostasPorAluno[i][i2] == gabarito [i2]){
				acertosPorAluno[i]++;
			}
		}
		notaPorAluno[i] = acertosPorAluno[i] / questoes;
		printf("\n%s acertou %.0f de %d questoes. Ficou com nota: %.2f\n", nome[i], acertosPorAluno[i], questoes, notaPorAluno[i]*10);
	}
}





