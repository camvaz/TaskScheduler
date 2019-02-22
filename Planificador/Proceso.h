#pragma once
typedef unsigned int uint32;

using namespace std;

class Proceso {

private: uint32     pid;
		 uint32     t_Lle;
		 uint32     t_Exe;
		 uint32		unidadesEjecucion;
		 uint32     Prioridad;
		 uint32     t_Esp;
		 uint32     t_Fin;

public:

	Proceso();
	Proceso(uint32&&, uint32&&, uint32&&, uint32&&);
	Proceso(const Proceso&);
	bool comparacionPEASC(Proceso);
	bool comparacionEPASC(Proceso&);
	bool comparacionPEDESC(Proceso&);
	bool comparacionEPDESC(Proceso&);
	uint32 getLlegada();
	bool ejecuta();
	void print();
	bool operator=(Proceso);
	~Proceso();
};