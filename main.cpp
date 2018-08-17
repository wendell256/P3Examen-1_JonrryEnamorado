#include <iostream>
#include <string>
using namespace std;
char** createMatrix(int);
void printMatrix(char**,int);
void iniciarTablero(char**,int);

int main(){
	string player1, player2;
	cout<<"Ingrese nombre de jugador 1:"<<endl;
	cin>>player1;
	cout<<"Ingrese nombre jugador 2:"<<endl;
	cin>>player2;
	char** tablero=createMatrix(11);
	iniciarTablero(tablero,11);
	printMatrix(tablero,11);


	return 0;
}

//crear matrix
char** createMatrix(int size){
	char** matrix = new char*[size];

        for(int i=0;i<size;i++)
                matrix[i]= new char[size];

        return matrix;


}

//crear tablero al inicio
void iniciarTablero(char** tablero, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if((i==0 && j==5)||(i==10&&j==5)){
				tablero[i][j]='+';
			}else if((i==5 && j==0)||(i==5&&j==10)){
				tablero[i][j] = '#';
			}else{
				tablero[i][j]='.';
			}

		}
	}
}

//imprimir matrix
void printMatrix(char** matrix,int size){
	for(int i=0;i<size;i++){
		for (int j=0;j<size;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
