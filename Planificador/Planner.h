#pragma once
class Planner
{
private:
	vector<Proceso>		Tabla;
	vector<Proceso>		Lista;
	vector<Proceso>		ListaAEjecutar;
	vector<Proceso>		ColaEspera;
	uint32				contador, numProcesos, canales, esperaTotal;

	void				ejecutaMonoTarea();
	void				ejecutaMultiTarea();
	void				ejecutaMultiTarea2daVuelta(uint32&, uint32&);
	bool				keepExecuting();
	bool				procesoTerminado(Proceso&);
	void				eliminaCerosMonotarea(uint32&);
	void				eliminaCerosMultitarea(uint32);
	void				agregaLista(uint32&);
	void				agregaColaEspera(uint32&);
	bool				isEmpty();
	void				vaciaColaEspera();

public:
	Planner();
	Planner(uint32&&, uint32&&);
	void addProceso(Proceso);
	void llenaLista(uint32&);
	void printLista();
	void printTabla();
	void printColaEspera();
	void reboot();
	void Cola_ordenaPEASC(uint32&&);
	void Cola_ordenaEPASC(uint32&&);
	void Cola_ordenaEPDESC(uint32&&);
	void Cola_ordenaPEDESC(uint32&&);
	void Lista_ordenaPEASC(uint32&&);
	void Lista_ordenaEPASC(uint32&&);
	void Lista_ordenaPEDESC(uint32&&);
	void Lista_ordenaEPDESC(uint32&&);
	void eligeOrdenamientoLista(uint32&);
	void eligeOrdenamientoCola(uint32&);
	void runMonotarea(uint32&);
	void runMultitarea(uint32&);
	~Planner();
};
