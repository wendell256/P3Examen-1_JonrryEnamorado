#include "reiniciar.h"

#include <iostream>
using namespace std;

reiniciar::reiniciar(){
	reinicio=false;
}

reiniciar::reiniciar(bool ver){
	reinicio=ver;
}

bool reiniciar::getReinicio(){
	return reinicio;
}

void reiniciar::setReinicio(bool ver){
	reinicio = ver;
}

reiniciar::~reiniciar(){
	cout<<"Memoria Liberada"<<endl;
}
