#include "pch.h"
#include "Proceso.h"


using namespace std;

Proceso::Proceso() {
	pid = 0;
	t_Exe = 0;
	Prioridad = 0;
	t_Esp = 0;
	t_Lle = 0;
	t_Fin = 0;
	unidadesEjecucion = 0;
}

Proceso::Proceso(uint32&& newPid, uint32&& newExe, uint32&& newPrioridad, uint32&& newLlegada) :
	pid(newPid), t_Exe(newExe), Prioridad(newPrioridad), t_Esp(0), t_Lle(newLlegada), t_Fin(0), unidadesEjecucion(newExe){}

Proceso::Proceso(const Proceso &tmp)
{
	this->pid = tmp.pid;
	this->t_Exe = tmp.t_Exe;
	this->Prioridad = tmp.Prioridad;
	this->t_Esp = tmp.t_Esp;
	this->t_Lle = tmp.t_Lle;
	this->t_Fin = tmp.t_Fin;
	this->unidadesEjecucion = tmp.unidadesEjecucion;
}

bool Proceso::comparacionPEASC(Proceso tmp) {
	if ((this->Prioridad < tmp.Prioridad) || 
		(this->Prioridad == tmp.Prioridad && this->t_Exe < tmp.t_Exe) || 
		(this->Prioridad == tmp.Prioridad && this->t_Exe == tmp.t_Exe && this->pid > tmp.pid)) {
		return true;
	}
	return false;
}

bool Proceso::comparacionEPASC(Proceso &tmp) {
	if ((this->t_Exe < tmp.t_Exe) ||
		(this->t_Exe == tmp.t_Exe && this->Prioridad < tmp.Prioridad) ||
		(this->Prioridad == tmp.Prioridad && this->t_Exe == tmp.t_Exe && this->pid > tmp.pid)) {
		return true;
	}
	return false;
}

bool Proceso::comparacionPEDESC(Proceso &tmp) {
	if ((this->Prioridad < tmp.Prioridad) ||
		(this->Prioridad == tmp.Prioridad && this->t_Exe < tmp.t_Exe) ||
		(this->Prioridad == tmp.Prioridad && this->t_Exe == tmp.t_Exe && this->pid < tmp.pid)) {
		return true;
	}
	return false;
}

bool Proceso::comparacionEPDESC(Proceso &tmp) {
	if ((this->t_Exe < tmp.t_Exe) ||
		(this->t_Exe == tmp.t_Exe && this->Prioridad < tmp.Prioridad) ||
		(this->Prioridad == tmp.Prioridad && this->t_Exe == tmp.t_Exe && this->pid < tmp.pid)) {
		return true;
	}
	return false;
}

uint32 Proceso::getLlegada()
{
	return t_Lle;
}

bool Proceso::ejecuta()
{
	if (--unidadesEjecucion)
		return true;
	return false;
}

void Proceso::print() {
	cout << "\nPID: " << pid << "\nPrioridad: " << Prioridad << "\nTiempo de ejecucion: " << t_Exe << "\nTiempo de espera: " << t_Esp << endl;
}

bool Proceso::operator=(Proceso tmp)
{
	this->pid = tmp.pid;
	this->t_Exe = tmp.t_Exe;
	this->Prioridad = tmp.Prioridad;
	this->t_Esp = tmp.t_Esp;
	this->t_Lle = tmp.t_Lle;
	this->t_Fin = tmp.t_Fin;
	this->unidadesEjecucion = tmp.unidadesEjecucion;
	return 1;
}


Proceso::~Proceso()
{
}
