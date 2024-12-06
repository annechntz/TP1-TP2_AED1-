#include "campominado.h"
#include "log.h" 
#include <stdio.h>
#include <stdlib.h>

int casasAbertas(int tamanho, char **MatChar){
    /*Um for irá percorrer a matriz, identificando quais posições já foram "abertas" pelo usuário com o auxilio de um if, se a posição não contiver mais a letra "x", então um acumulador irá receber mais um, repetindo até que todas as entradas já abertas sejam contabilizadas.*/
    int acumulador = 0;
    for(int contL = 0; contL < tamanho; contL++){
    for(int contC = 0; contC < tamanho; contC++){
        if(MatChar[contL][contC] != 'x'){
        acumulador++; 
      }
     }
    }
    
    return acumulador; 
}
void expandeLugares(int x, int y, int tamanho, int **Mat, char **MatChar){
    /*Essa função agirá de forma semelhante a função que "checa a vizinhança", o usuário escolherá uma coordenada válida e três laços de repetição serão implementados, um irá percorrer a linha imediatamente acima da posição escolhida, o outro, a mesma linha, e o terceiro "for" percorrerá a linha imediatamente abaixo. Se nesses laços for encontrada uma posição diferente de '0', ela será exibida. Ou, se a coordenada for igual a '0', assim como a inicialmente digitada pelo usuário, a funçâo será chamada novamente de uma forma recursiva e será executada da mesma forma, percorrendo as linhas vizinhas dessa nova posição. */
   MatChar[x][y] = Mat[x][y] + 48; 

    for(int contC = y - 1; contC < y + 2; contC++){
     if(checaCoordenadas(x - 1, contC, tamanho, Mat, MatChar)){
        if(Mat[x - 1][contC] == 0){
            expandeLugares(x - 1, contC, tamanho, Mat, MatChar); 
        }
        else{
            MatChar[x - 1][contC] = Mat[x - 1][contC] + 48; 
        }
    } 
    }

    for(int contC = y - 1; contC < y + 2; contC++){
     if(checaCoordenadas(x, contC, tamanho, Mat, MatChar)){
        if(Mat[x][contC] == 0){
            expandeLugares(x, contC, tamanho, Mat, MatChar); 
        }
        else{
            MatChar[x][contC] = Mat[x][contC] + 48; 
        }
    }
    }
	

    for(int contC = y - 1; contC < y + 2; contC++){
     if(checaCoordenadas(x + 1, contC, tamanho, Mat, MatChar)){
        if(Mat[x + 1][contC] == 0){
            expandeLugares(x + 1, contC, tamanho, Mat, MatChar); 
        }
        else{
            MatChar[x + 1][contC] = Mat[x + 1][contC] + 48; 
        }
    }
    }
   
}
void rodaJogoVersao2(){
    FILE* log = criarArquivo();

    

	int tamanho, qtdBombas;  
	int cordX, cordY; 
	qtdBombas = 0; 
	tamanho = 0; 
	
	printf("Ola usuario!\n"); 
	printf("Escolha um nivel de jogo pressionando 1 para facil, 2 para medio, 3 para dificil.\n");

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
	printf("Insira as coordenadas.\n");
    
    log = abrirArquivo();

    while((qtdEspacos - casasAbertas(tamanho, MatChar) > 0) && estado2){
		scanf("%d,%d", &cordX, &cordY); 
        imprimirEntradaSaida(estado2, cordX, cordY,tamanho, Mat, MatChar); 
        cordX--; 
        cordY--; 
        if(checaCoordenadas(cordX, cordY, tamanho, Mat, MatChar) == 1){
            if(Mat[cordX][cordY] == -1){
                estado2 = 0; 
            }
            else if(Mat[cordX][cordY] == 0){
               expandeLugares(cordX, cordY, tamanho, Mat, MatChar); 
            }
            else{
			    MatChar[cordX][cordY] = Mat[cordX][cordY] + 48;  
            }

        }
        else{
            printf("Coordenada inválida ou repetida, Digite outra para prosseguir com o jogo.\n");
        }
        
        imprimeMatrizChar(tamanho, MatChar); 
    }

	if(estado2){
		   printf("Parabéns, vc é fera!\n"); 
		   imprimeMatrizChar(tamanho, MatChar); 
           imprimeGanhadorPerdedor(estado2, tamanho, Mat, MatChar); 
	}
	else{
		   printf("Game over! \n"); 
		   imprimeMatriz(tamanho, Mat);
           imprimeGanhadorPerdedor(estado2, tamanho, Mat, MatChar); 
	}
   
	liberaMatrizes(tamanho, Mat, MatChar); 
	
	free(Mat); 
	free(MatChar); 
}
int main(){
    rodaJogoVersao2(); 
}
