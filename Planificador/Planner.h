#pragma once
class Planner
{
private:
	vector<Proceso>		Tabla;
	vector<Proceso>		Lista;
	vector<Proceso>		ListaAEjecutar;
	vector<Proceso>		ColaEspera;
	uint32				contador, numProcesos, canales;
	
	void				ejecutaMonoTarea();
	void				ejecutaMultiTarea();
	bool				keepExecuting();
	bool				procesoTerminado(Proceso&);
	void				eliminaCerosMonotarea(uint32&);
	void				eliminaCerosMultitarea(uint32&);
	void				agregaLista(uint32&);
	bool				isEmpty();

	
public:
	Planner();
	Planner(uint32&&, uint32&&);
	void addProceso(Proceso);
	void llenaLista(uint32&);
	void printLista();
	void printTabla();
	void reboot();
	void Lista_ordenaPEASC(uint32&&);
	void Lista_ordenaEPASC(uint32&&);
	void Lista_ordenaPEDESC(uint32&&);
	void Lista_ordenaEPDESC(uint32&&);
	void eligeOrdenamiento(uint32&);
	void runMonotarea(uint32&);
	void runMultitarea(uint32&);
	~Planner();
};

