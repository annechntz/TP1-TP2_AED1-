


int checaCoordenadas(int cordX, int cordY, int tamanho, int** Mat, char** MatChar); 
/*Essa função checa se uma coordenada é válida, verificando se ela está contida dentro da matriz ou se o usuário já não havia a inserido anteriormente. */
void imprimeMatriz(int tamanho, int** Mat); 
/*Nessa função, ocorrerá a impressão da matriz de inteiros*/
void checaVizinhos(int x, int y, int tamanho, int** Mat); 
/*Ela irá checar se existem bombas nas casas "vizinhas", percorrendo as linhas abaixo, acima e a mesma da coordenada selecionando, se houver uma bomba, será atribuida a coordenada selecionada, a quantidade de bombas no seu redor.*/
void sorteiaPosicao(int tamanho, int qtdBombas, int** Mat); 
/*Essa função irá sortear as posições e atribuir a elas uma bomba, tudo utilizando  uma geração rândomica.*/
void inicializaMatrizes(int tamanho, char** MatChar); 
/*Nela, será inicializada a matriz de char atribuindo a letra "x" a todas as suas coordenadas.*/
void liberaMatrizes(int tamanho, int** Mat, char** MatChar); 
/*Como já diz o nome, ocorrerá a liberação de ambas as matrizes*/
void verificaNivel(int *tamanho, int *qtdBombas); 
/*O usuário escolherá um nível se baseando na frase imprimida no início, essa função irá verificar o nível que o jogador escolher e atribuirá uma quantidade de bombas e tamanho das matrizes se baseando na escolha.*/
void imprimeMatrizChar(int tamanho, char** MatChar); 
/*Será imprimida a matriz de char.*/
void rodaJogo(); 
/*Funcionará como a antiga main, nela, serão lidas as coordenadas, será chamada as outras funçôes para verificar a validade da posição inserida pelo usuário, terá a impressão de mensagens que guiarão o jogador para uma melhor experiência de jogo, e também ocorrerá a impressão das mensagens finais, que indicarão se o jogador ganhou ou perdeu a partida */