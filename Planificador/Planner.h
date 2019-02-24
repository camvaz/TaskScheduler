#pragma once
class Planner
{
	vector<Proceso>		Tabla;
	vector<Proceso>		Lista;
	uint32				contador, numProcesos, canales;
	void				ejecuta();
	bool				keepExecuting();
	bool				procesoTerminado(Proceso&);
	
public:
	Planner();
	Planner(uint32&&, uint32&&);
	void addProceso(Proceso);
	void llenaLista(uint32&);
	bool isEmpty();
	void printLista();
	void printTabla();
	void Lista_ordenaPEASC(uint32&);
	void Lista_ordenaEPASC(uint32&);
	void Lista_ordenaPEDESC(uint32&);
	void Lista_ordenaEPDESC(uint32&);

	void eliminaCeros(uint32&);
	void agregaListaMonotarea(uint32&);
	void runMonotarea();
	~Planner();
};

