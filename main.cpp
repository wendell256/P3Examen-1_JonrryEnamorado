#include <iostream>
#include <string>
using namespace std;
char** createMatrix(int);
void printMatrix(char**,int);
void iniciarTablero(char**,int);
void moverPieza(char**,char);
void deleteMatrix(char**, int);
void comer(char**,int,int, char);

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
				cout<<"Turno de "<<player1<<" (+)"<<endl;
				moverPieza(tablero,'+');
				comer(tablero,'#')
				turno=1;
				break;
			case 1:
				printMatrix(tablero,11);
				cout<<"Turno de "<<player2<<" (#)"<<endl;
				moverPieza(tablero,'#');
				comer(tablero,'+');
				turno=0;
				break;
		}
	}
	deleteMatrix(tablero,11);
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
	int filap=0,columnap=0,filam=0,columnam=0,
	    validarpieza=0;//validarpieza revisa si la 
			  //pieza seleccionada es del player y ademas si la casilla adonde quiere moverse es valida.
			  
	
	while(validarpieza==0){//que la pieza sea de el
		
		cout<<"Ingrese NUMERO DE FILA de posicion de pieza que desea mover:"<<endl;
		cin>>filap;
		while(filap<0 || filap>10){
			cout<<"ERROR FILA NO VALIDA INGRESE DE NUEVO:"<<endl;
			cin>>filap;
		}
	
		cout<<"Ingrese NUMERO DE COLUMNA de posicion de pieza que desea mover:"<<endl;
		cin>>columnap;
		while(columnap<0 || columnap>10){
			cout<<"ERROR COLUMNA NO VALIDA INGRESE DE NUEVO:"<<endl;
			cin>>columnap;
		}
		if(tablero[filap][columnap]!=turno){
			cout<<"ERROR NO HAY PIEZA TUYA EN ESA CASILLA"<<endl;
			validarpieza=0;
		}else{
			validarpieza=1;
		}

		
	}
	validarpieza =0;
	cout<<"PIEZA SELECCIONADA EXITOSAMENTE!"<<endl;
	while(validarpieza==0){//mover pieza
		
		cout<<"Ingrese NUMERO DE FILA de posicion adonde desea mover pieza:"<<endl;
		cin>>filam;
		while(filam<0 || filam>10){
			cout<<"ERROR FILA NO VALIDA INGRESE DE NUEVO:"<<endl;
			cin>>filam;
		}
	
		cout<<"Ingrese NUMERO DE COLUMNA de posicion adonde desea mover pieza-:"<<endl;
		cin>>columnam;
		while(columnam<0 || columnam>10){
			cout<<"ERROR COLUMNA NO VALIDA INGRESE DE NUEVO:"<<endl;
			cin>>columnam;
		}
		
		if(filam==filap && columnam==columnap){
			cout<<"ERROR LA PIEZA YA ESTA EN ESA CASILA -_-"<<endl;
			validarpieza=0;
		}
		else if((filam<filap-2 || filam>filap+2) || (columnam>columnap+2 || columnam<columnap-2)){
			cout<<"ERROR NO PUEDES MOVER TU PIEZA AHI"<<endl;
			validarpieza=0;
		}else{
			validarpieza=1;
			if((filam < filap-1 || filam > filap+1)  ||(columnam < columnap-1 || columnam > columnap+1)){//se movio dos casillas
				tablero[filap][columnap] ='.';
				tablero[filam][columnam]=turno;
				cout<<"PIEZA SE MOVIO!"<<endl;
			}else{//se movio una
				tablero[filam][columnam]=turno;
				cout<<"PIEZA CLONADA!"<<endl;
			}

			
			
		}

		
	}
	comer(tablero,filam,columnam,turno);


}

//comer piezas si se puede
void comer(char** tablero,int fila, int columna, char turno){
	char enemigo;
	if(turno=='+'){
		enemigo='#';
	}else if(turno=='#'){
		enemigo='+';
	}
	if(tablero 

}

//delete del tablero
void deleteMatrix(char** tablero, int size){
	char* temp;
	for(int i;i<size;i++)
		delete tablero[i];
	
	delete temp;
}
