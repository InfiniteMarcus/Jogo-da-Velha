/*
	Implementacao em C++ de jogo da velha entre um jogador e a maquina
	
	Levemente baseado em: https://gist.github.com/Alequine/2909172
	
	by: Infinitemarcus
*/

#include <iostream>

using namespace std;

// Imprime na tela cada elemento da matriz, com a formatacao correta
void printMatriz(char matriz[][3]){
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << "| ";
			cout << matriz[i][j];
			cout << " |";
		}
		cout << endl;
	}
}

// Verifica se ha algum ganhador, dada a presenca de tres simbolos iguais na matriz diferentes do simbolo vazio
bool verifyWinner(char matriz[][3]){ 
	if((matriz[0][0] != '*' && matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2])||
	(matriz[0][0] != '*' && matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2])||
	(matriz[0][0] != '*' && matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0])||
	(matriz[0][1] != '*' && matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1])||
	(matriz[0][2] != '*' && matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2])||
	(matriz[1][0] != '*' && matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2])||
	(matriz[2][0] != '*' && matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2])||
	(matriz[2][0] != '*' && matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2]))
		return true;
	else
		return false;
}

// Zera a matriz de jogo com o simbolo *, que sera considerado posicao vazia
void zeraMatriz(char matriz[][3]){
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			matriz[i][j] = '*';
}

// Funcao de jogada do bot, utilizando de valores x e y aleatorios
void botPlays(char matriz[][3], char escolhaBot, char escolhaPlayer){
	while(true){
		int x = (rand()% 3);
		int y = (rand()% 3);
		
		if(matriz[x][y] == '*'){
			matriz[x][y] = escolhaBot;
			return;
		}
	}
}

// Funcao de jogada do usuario, dadas as coordenadas desejadas pelo mesmo, com conferencia de validade da jogada
void playerPlays(char matriz[][3], char escolha){
	while(true){
		cout << "Digite os numeros (1-3) da linha e da coluna de onde voce quer preencher:" << endl;
		
		int x, y;
		cin >> x;
		cin >> y;
				
		if((x > 3 || x < 1) || (y > 3 || y < 1)){
			cout << "Coordenadas invalidas" << endl;
		}else{
			if(matriz[x-1][y-1] == '*'){
				matriz[x-1][y-1] = escolha;
				break;
			}else
				cout << "Posicao ocupada" << endl;
			}
	}
}

// Funcao principal do jogo
int main(){
	
	char matriz[3][3];
	char escolhaPlayer, escolhaBot;

	zeraMatriz(matriz);

	while(true){
		cout << "Deseja ser X ou O?" << endl;
		cin >> escolhaPlayer;	
		
		escolhaPlayer = toupper(escolhaPlayer);
		
		if(escolhaPlayer == 'X' || escolhaPlayer == 'O')
			break;
		else
			cout << "Opcao invalida!" << endl;
	}
	
	if(escolhaPlayer == 'X')
		escolhaBot = 'O';
	else
		escolhaBot = 'X';
		
	printMatriz(matriz);
		
	while(true){
		playerPlays(matriz, escolhaPlayer);
		
		if(verifyWinner(matriz)){
			cout << "Voce venceu!\n";
			printMatriz(matriz);
			return 0;
		}
		
		printMatriz(matriz);
		
		cout << "Minha vez!\n";
		
		botPlays(matriz, escolhaBot, escolhaPlayer);
		
		if(verifyWinner(matriz)){
			cout << "Eu venci!\n";
			printMatriz(matriz);
			return 0;
		}
		printMatriz(matriz);
	}
	
	return 0;
}

