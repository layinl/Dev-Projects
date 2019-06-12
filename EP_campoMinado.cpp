#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MMAX 90
#define NMAX 90

// Declarando funções
void fimDeJogo();
void abrirTabuleiro();
void exibirTabuleiro();
void abrir(int y, int x, char printa);
void abrirAoRedor(int y, int x);
void marcar(int y, int x);
void desmarcar(int y, int x);

int m = 0, n = 0, z = 0, s = 0;
int NO = 0, N = 0, NE = 0, O = 0, L = 0, SO = 0, S = 0, SE = 0;
int tabuleiro[MMAX][NMAX];
int marcadas = 0, abertas = 0;
bool FIM = false;

// OK
int minasAoRedor(int y, int x) {
	NO = 0; N = 0; NE = 0;
	O  = 0;	/*  */ L  = 0;
	SO = 0; S = 0; SE = 0;
	if (tabuleiro[y-1][x-1] == 9 || tabuleiro[y-1][x-1] == 109 || tabuleiro[y-1][x-1] == 209) {
		NO = 1;
	}
	if (tabuleiro[y-1][x] == 9 || tabuleiro[y-1][x] == 109 || tabuleiro[y-1][x] == 209) {
		N = 1;
	}
	if (tabuleiro[y-1][x+1] == 9 || tabuleiro[y-1][x+1] == 109 || tabuleiro[y-1][x+1] == 209) {
		NE = 1;
	}
	if (tabuleiro[y][x-1] == 9 || tabuleiro[y][x-1] == 109 || tabuleiro[y][x-1] == 209) {
		O = 1;
	}
	if (tabuleiro[y][x+1] == 9 || tabuleiro[y][x+1] == 109 || tabuleiro[y][x+1] == 209) {
		L = 1;
	}
	if (tabuleiro[y+1][x-1] == 9 || tabuleiro[y+1][x-1] == 109 || tabuleiro[y+1][x-1] == 209) {
		SO = 1;
	}
	if (tabuleiro[y+1][x] == 9 || tabuleiro[y+1][x] == 109 || tabuleiro[y+1][x] == 209) {
		S = 1;
	}
	if (tabuleiro[y+1][x+1] == 9 || tabuleiro[y+1][x+1] == 109 || tabuleiro[y+1][x+1] == 209) {
		SE = 1;
	}
	return NO + N + NE + O + L + SO + S + SE;
}

// OK
int gerarMina(){
	int r = rand()%(m*n);
	if(r == 0)
		return 9;
	else
		return 0;
}

// OK
int gerarMinas(){
	int minas = 0;
	while(minas < z) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if (minas < z) {
					int celula = gerarMina();
					if(celula == 9 && tabuleiro[i][j] != celula) {
						tabuleiro[i][j] = celula;
						minas++;
					}
				}
			}
		}
	}
	return minas;
}

// OK
void gerarTabuleiro(){
	gerarMinas();
	int celulasGeradas = 0;
	while(celulasGeradas < m*n) {
		for(int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++) {
				if(tabuleiro[i][j] < 100){
					if(tabuleiro[i][j] == 9) {
						tabuleiro[i][j] += 100;
						celulasGeradas++;
					} else {
						tabuleiro[i][j] = minasAoRedor(i,j) + 100;
						celulasGeradas++;
					}
				}
			}
		}
	}
}

// OK
void marcar(int y, int x) {
	if (tabuleiro[y][x] < 100) { // se: Aberta
		printf("Sem efeito.\n");
	}
	else if (tabuleiro[y][x] < 200) { // se: Fechada
		if (marcadas < z) {
			tabuleiro[y][x] += 100;
			marcadas++;
		} else {
			printf("Limite de marcacoes atingido.\n");
		}
	}
	else if (tabuleiro[y][x] < 300) { // se: Fechada e Marcada
		printf("Sem efeito.\n");
	}
}

// OK
void abrirAoRedor(int y, int x){
	abrir(y-1, x-1, 'n');	abrir(y-1, x, 'n');	abrir(y-1, x+1, 'n');
	abrir( y , x-1, 'n');						abrir( y , x+1, 'n');
	abrir(y+1, x-1, 'n');	abrir(y+1, x, 'n');	abrir(y+1, x+1, 'n');
}

// OK
void abrir(int y, int x, char printa) {
	if (tabuleiro[y][x] < 100) { // se: Aberta
		if (printa != 'n')
			printf("Sem efeito.\n");
	} else if (tabuleiro[y][x] < 200) { // se: Fechada
		if (tabuleiro[y][x] == 109) { // se: Bomba
			fimDeJogo();
		} else {
			tabuleiro[y][x] -= 100;
			if (tabuleiro[y][x] == 0) {
				abrirAoRedor(y, x);
			}
			abertas++;
		}
	} else if (tabuleiro[y][x] < 300) { // se: Fechada e Marcada
		printf("Nao e permitido abrir posicoes marcadas.");
	}
}

// OK
void desmarcar(int y, int x) {
	if (tabuleiro[y][x] < 100) // se: Aberta
		printf("Sem efeito.\n");
	else if (tabuleiro[y][x] < 200) // se: Fechada
		printf("Sem efeito.\n");
	else if (tabuleiro[y][x] < 300) { // se: Fechada e Marcada
		tabuleiro[y][x] -= 100;
		marcadas--;
	}
		
}

// OK
void exibirCelula(int y, int x) {
	if (tabuleiro[y][x] < 100) { // se: Aberta
		if (tabuleiro[y][x] == 9) // se: É bomba
			printf("@");
		else
			printf("%d", tabuleiro[y][x]);
	} else if (tabuleiro[y][x] < 200) { // se: Fechada
		printf(".");
	} else // se: Fechada e Marcada
		printf("*");
}

// OK
void exibirTabuleiro() {
	
	if (m > 9 || n > 9) {
		printf("\t   ");
		for (int j = 0; j < n; j++) {
			if ( j > 8)
				printf(" %d ", j+1);
			else
				printf("  %d ", j+1);
		}
		printf("   \n");
		
		printf("\t   +");
		for (int j = 0; j < n; j++) {
			printf("----", j);
		}
		printf("+  \n");
		
		for (int i = 0; i < m; i++) { 
			if ( i > 8)
				printf("\t%d | ", (i+1));
			else
				printf("\t %d | ", (i+1));
			for (int j = 0; j < n; j++) {
				exibirCelula(i, j);
				if(j != (m-1))
					printf("   ");
				else
					printf(" ");
			}
			printf(" | %d\n", (i+1));
		}
		
		printf("\t   +");
		for (int j = 0; j < n; j++) {
			printf("----", j);
		}
		printf("+  \n");
		
		printf("\t   ");
		for (int j = 0; j < n; j++) {
			if ( j > 8)
				printf(" %d ", j+1);
			else
				printf("  %d ", j+1);
		}
		printf("   \n");
		
		
		
		
		
	} else {
		printf("\t   ");
		for (int j = 0; j < n; j++) {
			printf(" %d ", j+1);
		}
		printf("   \n");   
		          
		printf("\t  +");
		for (int j = 0; j < n; j++) {
			printf("---", j);
		}                            
		printf("+  \n");
		
		for (int i = 0; i < m; i++) { 
			printf("\t%d | ", (i+1));
			for (int j = 0; j < n; j++) {
				exibirCelula(i, j);
				if(j != (m-1))
					printf("  ");
			}
			printf(" | %d\n", (i+1));
		}
		
		printf("\t  +");
		for (int j = 0; j < n; j++) {
			printf("---", j);
		}
		printf("+  \n");
		
		printf("\t   ");
		for (int j = 0; j < n; j++) {
			printf(" %d ", j+1);
		}
		printf("   \n\n");
	}
	
	
}

// OK
void abrirTabuleiro() {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if (tabuleiro[i][j] < 100);
			else if (tabuleiro[i][j] < 200)
				tabuleiro[i][j] -= 100;
			else if (tabuleiro[i][j] < 300)
				tabuleiro[i][j] -= 200;
		}
	}
}

// OK
void fimDeJogo() {
	printf("BOOOOM!  Voce acaba de pisar numa mina!\n");
	abrirTabuleiro();
	exibirTabuleiro();
	FIM = true;
}

// OK
void jogar(){
	char jogada[6];
	char comando;
	
	exibirTabuleiro();
	printf("Proximo chute: ");
fflush(stdin);
	gets(jogada);
	
	int i = 0;
	comando = jogada[0];
	int y = 0, x = 0;
	y = jogada[2]-48;
	x = jogada[4]-48;
	
	switch(comando) {
		case 'A':
		case 'a':
			abrir(y-1, x-1, 's');
			break;
		case 'M':
		case 'm':
			marcar(y-1, x-1);
			break;
		case 'D':
		case 'd':
			desmarcar(y-1, x-1);
			break;
	}
	if ( (abertas == m*n - z || abertas + marcadas == m*n) && !FIM){
		exibirTabuleiro();
		FIM = true;
		printf("Parabens, voce venceu o Caca-Minas!");
	}
}

main() {
	while( (m <= 3 || m >= MMAX) || (n <= 3 || n >= NMAX) || (z < 0 || z >= m*n) || (s < 1 || s > 12345) ) {
		printf(" De o numero de linhas do tabuleiro do jogo: ");
		scanf("%d", &m);
		printf(" De o numero de colunas do tabuleiro do jogo: ");
		scanf("%d", &n);
		printf(" De o numero de minas: ");
		scanf("%d", &z);
		printf(" De a semente: ");
		scanf("%d", &s);
		srand(s);
		if ( (m <= 3 || m >= MMAX) || (n <= 3 || n >= NMAX) || (z < 0 || z >= m*n) || (s < 1 || s > 12345) ) {
			printf(" Opcoes invalidas, tente outras.\n");
		}
	}
	gerarTabuleiro();
	printf("Bem vindo ao Caca-Minas!\n");
	printf("Neste jogo, voce pode Abrir (A ou a), Marcar (M ou m) e Desmarcar (D ou d) uma celula de sua escolha.\n");
	printf("Para executar uma acao, digite, por exemplo: A 3 2 e a celula na 3a LINHA e 2a COLUNA sera ABERTA.\n");
	printf("Outro exemplo: m 1 4 e a celula na 1a linha e 4a coluna sera marcada.\n");
	printf("Divirta-se!\n");
	while(!FIM){
		jogar();
	}
}
