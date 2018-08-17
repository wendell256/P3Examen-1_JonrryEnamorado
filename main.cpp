#include "reiniciar.h"
#include <iostream>
#include <string>
using namespace std;


char** createMatrix(int);
void printMatrix(char**,int);
char** iniciarTablero(char**,int);
void moverPieza(char**,char);
void deleteMatrix(char**, int);
void comer(char**,int,int, char);
bool verTurno(char**,char);
bool cuentapiezas(char**);

int main(){
	reiniciar Reinicio=new reiniciar(true);
	
	while(Reinicio.getReinicio()){
		bool winplayer1=false,winplayer2=false;
		int turno = 0;
		char** tablero=createMatrix(11);
		tablero = iniciarTablero(tablero,11);
	
		while(!winplayer1 && !winplayer2){
			switch(turno){
				case 0:
					printMatrix(tablero,11);
					cout<<"Turno de Player 1 (+)"<<endl;
					if(verTurno(tablero,'+')){
						moverPieza(tablero,'+');
						cout<<endl;
					}else{
						if(cuentapiezas(tablero)){
							winplayer1=true;
						}else{
							winplayer2=true;
						}
					}
					turno=1;
				break;
				case 1:
					printMatrix(tablero,11);
					cout<<"Turno de Player 2 (#)"<<endl;
					if(verTurno(tablero,'#')){
						moverPieza(tablero,'#');
						cout<<endl;
						
					}else{
						if(cuentapiezas(tablero)){
							winplayer1=true;
						}else{
							winplayer2=true;
						}
					
					}
					turno=0;
				break;
			}
		}
		if(winplayer1){
			cout<<"FELICIDADES PLAYER 1 HAS GANADO"<<endl;

		}else{
			cout<<"FELICIDADES PLAYER 2 HAS GANADO"<<endl;
		}
		deleteMatrix(tablero,11);

		cout<<"Desea Reiniciar?y/n"<<endl;
		char resp;
		cin>>resp;
		while(resp!='y'&&resp!='Y'&&resp!='n'&&resp!='N'){
			cout<<"ERROR RESPUESTA NO VALIDA"<<endl<<"Reiniciar?y/n"<<endl;
			cin>>resp;		
		}

		switch(resp){
			case 'y':
				Reinicio.setReinicio(true);
				
				break;
			case 'Y':
				Reinicio.setReinicio(true);
				
				break;
			case 'n':
				Reinicio.setReinicio(false);
				
				
				break;
			case 'N':
				Reinicio.setReinicio(false);
				
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
char** iniciarTablero(char** tablero, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if((i==0 && j==5)||(i==10&&j==5)){
				tablero[i][j]='+';
			}else if((i==5 && j==0)||(i==5&&j==10)){
				tablero[i][j] = '#';
			}else{
				tablero[i][j]='#';
			}

		}
	}
	return tablero;
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
		else if((filam<filap-2 || filam>filap+2) || (columnam>columnap+2 || columnam<columnap-2)||(tablero[filam][columnam]!='.')){
			cout<<"ERROR NO PUEDES MOVER TU PIEZA AHI"<<endl;
			validarpieza=0;
		}else{
			validarpieza=1;
			if((filam < filap-1 || filam > filap+1)  ||(columnam < columnap-1 || columnam > columnap+1)){//se movio dos casillas
				if(filam<filap-1 && columnam<columnap-1){
					if(tablero[filap-1][columnap-1]!='.'){
						cout<<"ERROR HAY UNA PIEZA EN MEDIO"<<endl;
						validarpieza=0;
					}else{
						
						tablero[filap][columnap] ='.';
						tablero[filam][columnam]=turno;
						cout<<"PIEZA SE MOVIO!"<<endl;
					}
				}else if(filam<filap-1 && columnam==columnap){
					if(tablero[filap-1][columnap]!='.'){
						cout<<"ERROR HAY UNA PIEZA EN MEDIO"<<endl;
						validarpieza=0;
					}else{
						tablero[filap][columnap] ='.';
						tablero[filam][columnam]=turno;
						cout<<"PIEZA SE MOVIO!"<<endl;
					}
				}else if(filam<filap-1 && columnam>columnap+1){
					if(tablero[filap-1][columnap+1]!='.'){
					
						cout<<"ERROR HAY UNA PIEZA EN MEDIO"<<endl;
						validarpieza=0;
					}else{
					
						tablero[filap][columnap] ='.';
						tablero[filam][columnam]=turno;
						cout<<"PIEZA SE MOVIO!"<<endl;
					}
				}else if(filam==filap && columnam>columnap+1){
					if(tablero[filap][columnap+1]!='.'){
					
						cout<<"ERROR HAY UNA PIEZA EN MEDIO"<<endl;
						validarpieza=0;
					}else{
					
						tablero[filap][columnap] ='.';
						tablero[filam][columnam]=turno;
						cout<<"PIEZA SE MOVIO!"<<endl;
					}
				}else if(filam>filap+1 && columnam>columnap+1){
					if(tablero[filap+1][columnap+1]!='.'){
					
						cout<<"ERROR HAY UNA PIEZA EN MEDIO"<<endl;
						validarpieza=0;
					}else{
					
						tablero[filap][columnap] ='.';
						tablero[filam][columnam]=turno;
						cout<<"PIEZA SE MOVIO!"<<endl;
					}
				}else if(filam>filap+1&&columnam==columnap){
					if(tablero[filap+1][columnap]!='.'){
					
						cout<<"ERROR HAY UNA PIEZA EN MEDIO"<<endl;
						validarpieza=0;
					}else{
					
						tablero[filap][columnap] ='.';
						tablero[filam][columnam]=turno;
						cout<<"PIEZA SE MOVIO!"<<endl;
					}
				}else if(filam>filap+1&&columnam<columnap-1){
					if(tablero[filap+1][columnap-1]){
					
						cout<<"ERROR HAY UNA PIEZA EN MEDIO"<<endl;
						validarpieza=0;
					}else{
						tablero[filap][columnap] ='.';
						tablero[filam][columnam]=turno;
						cout<<"PIEZA SE MOVIO!"<<endl;
					}
				}else if(filam==filap && columnam<columnap-1){
					if(tablero[filap][columnap-1]!='.'){
						cout<<"ERROR HAY UNA PIEZA EN MEDIO"<<endl;
						validarpieza=0;
					}else{
						tablero[filap][columnap] ='.';
						tablero[filam][columnam]=turno;
						cout<<"PIEZA SE MOVIO!"<<endl;
					}
				}

			}else{//se movio una
				tablero[filam][columnam]=turno;
				cout<<"PIEZA CLONADA!"<<endl;
			}
			cout<<endl;
			
			
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

	
	if(fila!=10 && columna!=10){
		if(tablero[fila+1][columna+1]==enemigo)
			tablero[fila+1][columna+1]=turno;
	}

	if(fila!=0&&columna!=0){
		if(tablero[fila-1][columna-1]==enemigo)
			tablero[fila-1][columna-1]=turno;
	}

	if(columna!=10){
		if(tablero[fila][columna+1]==enemigo)
			tablero[fila][columna+1]=turno;
	}

	if(columna!=0){
		if(tablero[fila][columna-1]==enemigo)
			tablero[fila][columna-1]=turno;
	}

	if(fila!=10){
		if(tablero[fila+1][columna]==enemigo)
			tablero[fila+1][columna]=turno;
	}

	if(fila!=0){
		if(tablero[fila-1][columna]==enemigo)
			tablero[fila-1][columna]=turno;
	}

	if(fila!=10 && columna!=0){
		if(tablero[fila+1][columna-1]==enemigo)
			tablero[fila+1][columna-1]=turno;
	}

	if(fila!=0&&columna!=10){
		if(tablero[fila-1][columna+1]==enemigo)
			tablero[fila-1][columna+1]=turno;
	}

}

//revisa que el turno del jugador actual puede ser jugado
bool verTurno(char** tablero,char turno){
	int size=11,cantEspacios=0,cantP1=0;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(tablero[i][j]=='.'){
				cantEspacios++;
			}else if(tablero[i][j]==turno){
				cantP1++;
			}
                        

		}
	}
	if(cantEspacios==0 || cantP1==0){
		return false;
	}else{
		return true;
	}

}

//cuenta las piezas al final. si player 1 tiene mas, retorna true, si no, false
bool cuentapiezas(char** tablero){
	
	int size=11,cantP1=0,cantP2=0;
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                        switch(tablero[i][j]){
				case '+':
					cantP1++;
				break;
				case '#':
					cantP2++;
				break;
			}

                }
        }
	cout<<"Piezas Player 1: "<<cantP1<<endl;
	cout<<"Piezas Player 2: "<<cantP2<<endl;
        if(cantP1>cantP2){
                return true;
        }else{
                return false;
        }


}

//delete del tablero
void deleteMatrix(char** tablero, int size){
	
	for(int i;i<size;i++)
		delete[] tablero[i];
	
	delete[] tablero;
}
