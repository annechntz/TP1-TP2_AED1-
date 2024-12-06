#include <stdio.h>

FILE* criarArquivo(); 
/*Cria o arquivo para deixá-lo apto a edição, ele também registrará a hora que o jogador iniciar a partida*/
FILE* abrirArquivo();
/*Realiza a abertura do arquivo.*/ 
void imprimirEntradaSaida(int estado, int x, int y, int tamanho, int **Mat, char **MatChar);
/*Irá realizar as impressões das matrizes de Char e de Inteiros dependento do uso de uma 'flag' denominada "estado", se a flag for falsa, a impressão será da matriz de inteiros, se for verdadeira, imprimirá a matriz de char.*/
void imprimeGanhadorPerdedor(int estado2, int tamanho, int **Mat, char **MatChar); 
/*Também com a ajuda de uma flag, irá imprimir uma mensagem para o usuário, identificando se ele for o ganhador ou o perdedor dessa partida. Também ocorrerá a impressão final das duas matrizes.*/