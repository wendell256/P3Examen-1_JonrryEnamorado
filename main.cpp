#include <iostream>
#include <string>
using namespace std;
char** createMatrix(int);
void printMatrix(char**,int);
void iniciarTablero(char**,int);
void moverPieza(char**,char);

int main(){
	string player1, player2;
	bool win=false;
	int turno = 0;
	cout<<"Ingrese nombre de jugador 1:"<<endl;
	cin>>player1;
	cout<<"Ingrese nombre jugador 2:"<<endl;
	cin>>player2;
	char** tablero=createMatrix(11);
	iniciarTablero(tablero,11);
	
	while(!win){
		switch(turno){
			case 0:
				printMatrix(tablero,11);
				cout<<"Turno de "<<player1<<endl;
				moverPieza(tablero,'+');
				turno=1;
				break;
			case 1:
				printMatrix(tablero,11);
				cout<<"Turno de "<<player2<<endl;
				moverPieza(tablero,'#');
				turno=0;
				break;
		}
	}

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
	int pos=0;
	cout<<"   0 1 2 3 4 5 6 7 8 9 10"<<endl;
	for(int i=0;i<size;i++){
		if(pos<10)
			cout<<pos<<"  ";
		else
			cout<<pos<<" ";
		for (int j=0;j<size;j++){
			cout<<matrix[i][j]<<" ";
		}
		pos++;
		cout<<endl;
	}
}

//mover pieza
void moverPieza(char** tablero, char turno){
	int fila=0,columna=0,validarpieza=0;
	
	while(validarpieza==0){
		
		cout<<"Ingrese NUMERO DE FILA de posicion de pieza que desea mover:"<<endl;
		cin>>fila;
		while(fila<0 && fila>10){
			cout<<"ERROR FILA NO VALIDA INGRESE DE NUEVO:"<<endl;
			cin>>fila
		}
	
		cout<<"Ingrese NUMERO DE COLUMNA de posicion de pieza que desea mover:"<<endl;
		cin>>columna;
		while(columna<0 && columna>10){
			cout<<"ERROR COLUMNA NO VALIDA INGRESE DE NUEVO:"<<endl;
			cin>>columna
		}
		if(tablero[fila][columna]==turno){
			cout<<"ERROR NO HAY PIEZA TUYA EN ESA CASILLA"<<endl;
			validarpieza=0;
		}else{
			validarpieza=1;
		}

		
	}

}
