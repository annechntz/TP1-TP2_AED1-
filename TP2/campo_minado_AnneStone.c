
#include "campominado.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
	
//O intuito dessa função é checar se as coordendadas digitadas pelo usuário são validas e se elas já não foram anteriormente digitadas;
int checaCoordenadas(int cordX, int cordY, int tamanho, int** Mat, char** MatChar){
    int estado; 
    estado = 0; 
    if((cordX >= 0) && (cordX < tamanho) && (cordY >= 0) && (cordY < tamanho)){
		 if(MatChar[cordX][cordY] == 'x'){
			 estado = 1; 
		 }
    }
    return estado; 
}

//Aqui ocorrerá a impressão da matriz com números inteiros, uma função que será chamada se o usuário perder. 
void imprimeMatriz(int tamanho, int** Mat){
	
	int contL, contC; 
	
	for(contL = 0; contL < tamanho; contL++){
		for(contC = 0; contC < tamanho; contC++){
			printf("%d ", Mat[contL][contC]); 
		}

		printf("\n"); 
	} 
} 

/*Nessa função, será atribuido o número de bombas "vizinhas" a  uma coordenada. Serão checadas três linhas, a superior, a linha
	da coordenada digitada e a inferior, e então, a coordenada que anteriormente era '0', receberá mais '1'. 
	*/
void checaVizinhos(int x, int y, int tamanho, int** Mat){
	
		
    int linha, coluna; 

    for(linha = x - 1; linha < x; linha++){
        for(coluna = y - 1; coluna < y + 2; coluna++){
         if((linha >= 0) && (linha < tamanho) && (coluna >= 0) && (coluna < tamanho)){
            if(Mat[linha][coluna] != -1){
            Mat[linha][coluna] = 1 + Mat[linha][coluna];
        }
        else{
            coluna++; 
      	   }
        }
      }
    }

    for(linha = x; linha < x + 1; linha++){
        for(coluna = y - 1; coluna < y + 2; coluna++){

            if((linha >= 0) && (linha < tamanho) && (coluna >= 0) && (coluna < tamanho)){
                if(Mat[linha][coluna] != -1){
                    Mat[linha][coluna] = 1 + Mat[linha][coluna]; 

           		 }
            }
        }
    }
    for((linha = x + 1); linha < x + 2; linha++){
        for(coluna = y - 1; coluna < y + 2; coluna++){

            if((linha >= 0) && (linha < tamanho) && (coluna >= 0) && (coluna < tamanho)){
                if(Mat[linha][coluna] != -1){
                    Mat[linha][coluna] = 1 + Mat[linha][coluna]; 

            }
            else{
                coluna++;  
            	}
            }
    
        }
    }
}

//Nessa função será sorteada a posição das bombas e inicializa a matriz. 
void sorteiaPosicao(int tamanho, int qtdBombas, int** Mat){
	int x, y, cont, contL, contC; 
	
	srand(time(NULL)); 
	
	for(cont = 0; cont < qtdBombas; cont++){
	x = rand() % tamanho; 	
	y = rand() % tamanho;

    Mat[x][y] = -1; 
	
    }

    for(contL = 0; contL < tamanho; contL++){
        for(contC = 0; contC < tamanho; contC++){
            if(Mat[contL][contC] == -1){
                checaVizinhos(contL, contC, tamanho, Mat);
            } 
        }
    } 
    
}
// Essa função irá inicializar a matriz de char com todos os espaços sendo preenchidos com 'x'. 
void inicializaMatrizes(int tamanho, char** MatChar){
	int contL, contC; 
	
	
	for(contL = 0; contL < tamanho; contL++){
		for(contC = 0; contC < tamanho; contC++){
			MatChar[contL][contC] = 'x'; 
		}
	}
}

void liberaMatrizes(int tamanho, int** Mat, char** MatChar){
	for(int cont = 0; cont < tamanho; cont++){
		free(Mat[cont]); 
	}
	for(int cont = 0; cont < tamanho; cont++){
		free(MatChar[cont]); 
	}
}

//Aqui irá ler a variável nível e, de acordo com o que o usuário digitar, será atribuido o nível de dificuldade do jogo. 
void verificaNivel(int *tamanho, int *qtdBombas){
	int nivel; 
	

	scanf("%d", &nivel); 

	if((nivel >= 1) && (nivel <= 3)){
		if(nivel == 1){
		*tamanho = 10; 
	    *qtdBombas = 15; 
	}
	else if(nivel == 2){
		*tamanho = 20; 
		*qtdBombas = 60; 	
	}
	else{
		*tamanho = 30; 
		*qtdBombas = 135; 
	}
	}
	else{
		verificaNivel(tamanho, qtdBombas);
	}
}

//Aqui será imprimida a matriz de char. 
void imprimeMatrizChar(int tamanho, char** MatChar){
	int contL, contC; 

	for(contL = 0; contL < tamanho; contL++){
		for(contC = 0; contC < tamanho; contC++){
			printf("%c ", MatChar[contL][contC]); 
		}
		printf("\n"); 
	}
}
void rodaJogo(){
	int tamanho, qtdBombas; 
	int cordX, cordY; 
	qtdBombas = 0; 
	tamanho = 0; 
	
	printf("Olá usuário!\n"); 
	printf("Escolha um nível de jogo pressionando 1 para fácil, 2 para médio, 3 para difícil.\n");

	verificaNivel(&tamanho, &qtdBombas); 
	
	int**  Mat = (int**) calloc(tamanho, sizeof(int*));
	if(Mat == NULL){
		exit(1); 
	} 

	for(int contL = 0; contL < tamanho; contL++){
		Mat[contL] = (int*) calloc(tamanho, sizeof(int)); 
		if(Mat[contL] == NULL){
			exit(1); 
		}
	}
	
	char** MatChar = (char**) malloc(tamanho * sizeof(char*)); 
	if(MatChar == NULL){
		exit(1); 
	}
	
	for(int contL = 0; contL < tamanho; contL++){
		MatChar[contL] = (char*) malloc(tamanho * sizeof(char)); 
		if(MatChar[contL] == NULL){
			exit(1); 
		}
	}

	inicializaMatrizes(tamanho, MatChar); 
	sorteiaPosicao(tamanho, qtdBombas, Mat); 

    int qtdEspacos = (tamanho * tamanho) - qtdBombas;
    int estado2 = 1; 

	imprimeMatrizChar(tamanho, MatChar); 
	printf("Insira as coordenadas para começar com o jogo.\n");
    while((qtdEspacos > 0) && estado2){
		scanf("%d,%d", &cordX, &cordY); 
        cordX--; 
        cordY--; 
        if(checaCoordenadas(cordX, cordY, tamanho, Mat, MatChar) == 1){
            if(Mat[cordX][cordY] == -1){
                estado2 = 0; 
            }
            else{
				MatChar[cordX][cordY] = Mat[cordX][cordY] + 48; 
				imprimeMatrizChar(tamanho, MatChar);  
            }

        }
        else{
			qtdEspacos++; 
            printf("Coordenada inválida ou repetida, Digite outra para prosseguir com o jogo.\n");
			imprimeMatrizChar(tamanho, MatChar); 
        }
		qtdEspacos--; 
    }
	
	if(estado2){
		printf("Parabéns, vc é fera!\n"); 
		imprimeMatrizChar(tamanho, MatChar); 
	}
	else{
		printf("Game over! \n"); 
		imprimeMatriz(tamanho, Mat);
	}

	liberaMatrizes(tamanho, Mat, MatChar); 
	
	free(Mat); 
	free(MatChar); 
}

