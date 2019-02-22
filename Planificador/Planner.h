#pragma once
class Planner
{
	vector<Proceso>		Tabla;
	vector<Proceso>		Lista;
	uint32				contador, numProcesos, canales;
	
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
	void ejecuta();
	~Planner();
};

