#include <iostream>
#include <string>
using namespace std;
char** createMatrix(int);



int main(){
	string player1, player2;
	cout<<"Ingrese nombre de jugador 1:"<<endl;
	cin>>player1;
	cout<<"Ingrese nombre jugador 2:"<<endl;
	cin>>player2;
	createMatrix(11);



	return 0;
}

char** createMatrix(int size){
	char** matrix;
	for(int i;i<size;i++){
		matrix[i]=new char**[size];
	}
	return matrix

}
