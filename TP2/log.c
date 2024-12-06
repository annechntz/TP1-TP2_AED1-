#include "log.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>


FILE* criarArquivo(){
    FILE* arquivo = fopen("log.txt", "w"); 
    if(arquivo == NULL){
        exit(1); 
    }

    time_t horarioDeAgora; 
    time(&horarioDeAgora); 
    fprintf(arquivo, "Data do jogo: %s\n", ctime(&horarioDeAgora)); 
    fclose(arquivo); 
    return arquivo; 
}
FILE* abrirArquivo(){
    FILE* campo = fopen("log.txt", "a"); 
    if(campo == NULL){
        exit(1); 
    }
    return campo; 
}
void imprimirEntradaSaida(int estado, int x, int y, int tamanho, int **Mat, char **MatChar){
    FILE* log = abrirArquivo();
    int contL, contC; 
	
    if(estado == 1){
     for(contL = 0; contL < tamanho; contL++){
		for(contC = 0; contC < tamanho; contC++){
			fprintf(log, "%c ", MatChar[contL][contC]); 
		}

		fprintf(log, "\n"); 
	} 
    }
    else if(estado == 0){
     for(contL = 0; contL < tamanho; contL++){
		for(contC = 0; contC < tamanho; contC++){
			fprintf(log, "%d ", Mat[contL][contC]); 
		}

		fprintf(log, "\n"); 
	
    }

}

    fprintf(log, "Insira as coordenadas.\n");
    fprintf(log, "%d,%d\n", x, y); 
    

	if((((x < 1) || (x > tamanho)) || ((y < 1) || (y > tamanho)) ||  MatChar[x - 1][y - 1] != 'x')){
      fprintf(log, "Coordenada inválida ou repetida, Digite outra para prosseguir com o jogo.\n");
    } 

    fclose(log); 
}

void imprimeGanhadorPerdedor(int estado2, int tamanho, int **Mat, char **MatChar){
     FILE* log = abrirArquivo();
    int contL, contC; 
    if(estado2){
      fprintf(log, "Parabéns, vc é fera!\n"); 
      for(contL = 0; contL < tamanho; contL++){
		for(contC = 0; contC < tamanho; contC++){
			fprintf(log, "%c ", MatChar[contL][contC]); 
		}

		fprintf(log, "\n"); 
	} 
	}
	else{
		fprintf(log, "Game over! \n"); 
        for(contL = 0; contL < tamanho; contL++){
		for(contC = 0; contC < tamanho; contC++){
			fprintf(log, "%d ", Mat[contL][contC]); 
		}

		fprintf(log, "\n"); 
	}
}
       fclose(log); 
}
