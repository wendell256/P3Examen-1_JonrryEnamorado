#ifndef PIEZAS_H
#define PIEZAS_H


class piezas{
	private:
		String player;
		int cantidad;
		bool turno;

	public:
		piezas();
		piezas(string,int,bool);
		string getPlayer();
		void setPlayer(string);
		int getCantidad();
		void setCantidad(int);
		bool getTurno();
		void setTurno(bool);

}; 
