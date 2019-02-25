#pragma once
class Planner
{
private:
	vector<Proceso>		Tabla;
	vector<Proceso>		Lista;
	vector<Proceso>		ListaAEjecutar;
	uint32				contador, numProcesos, canales;
	
	void				ejecuta();
	bool				keepExecuting();
	bool				procesoTerminado(Proceso&);
	void				eliminaCeros(uint32&);
	void				agregaListaMonotarea(uint32&);
	bool				isEmpty();

	
public:
	Planner();
	Planner(uint32&&, uint32&&);
	void addProceso(Proceso);
	void llenaLista(uint32&);
	void printLista();
	void printTabla();
	void Lista_ordenaPEASC(uint32&&);
	void Lista_ordenaEPASC(uint32&);
	void Lista_ordenaPEDESC(uint32&);
	void Lista_ordenaEPDESC(uint32&);
	void runMonotarea();
	void runMultitarea();
	~Planner();
};

