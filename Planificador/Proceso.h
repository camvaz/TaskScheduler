#pragma once
class Planner;
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
		 bool		pVueltaMulti;
		 bool		comparacionPEASC(Proceso);
	 	 bool		comparacionEPASC(Proceso&);
	     bool		comparacionPEDESC(Proceso&);
		 bool		comparacionEPDESC(Proceso&);
		 void		agregaTiempoFinal(uint32&);
		 void		setTiempoEspera();
		 void		pVueltaSuccess();
		 void		ejecuta();
		 void		setUejecucion(uint32&&);
public:
	Proceso();
	Proceso(uint32&&, uint32&&, uint32&&, uint32&&);
	Proceso(const Proceso&);

	uint32		getLlegada();
	uint32		getUejecucion();
	uint32		getTExe();
	void		print();
	void		setObject(uint32&&, uint32&&, uint32&&, uint32&&);
	bool		operator=(Proceso);
	bool		operator==(Proceso);
	friend class Planner;
	~Proceso();
};