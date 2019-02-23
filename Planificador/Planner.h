#pragma once
class Planner
{
	vector<Proceso>		Tabla;
	vector<Proceso>		Lista;
	uint32				contador, numProcesos, canales;
	void				ejecuta();
	bool				keepExecuting();
	
public:
	Planner();
	Planner(uint32&&, uint32&&);
	void addProceso(Proceso);
	void llenaLista(uint32&);
	bool isEmpty();
	void printLista();
	void printTabla();
	void Lista_ordenaPEASC();
	void Lista_ordenaEPASC();
	void Lista_ordenaPEDESC();
	void Lista_ordenaEPDESC();

	void eliminaCeros(uint32&);
	void agregaListaMonotarea(uint32&);
	void runMonotarea();
	~Planner();
};

