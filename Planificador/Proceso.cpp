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
	pVueltaMulti = 0;
}

Proceso::Proceso(uint32&& newPid, uint32&& newExe, uint32&& newPrioridad, uint32&& newLlegada) :
	pid(newPid), t_Exe(newExe), Prioridad(newPrioridad), t_Esp(0), t_Lle(newLlegada), t_Fin(0), unidadesEjecucion(newExe), pVueltaMulti(0){}

Proceso::Proceso(const Proceso &tmp)
{
	this->pid = tmp.pid;
	this->t_Exe = tmp.t_Exe;
	this->Prioridad = tmp.Prioridad;
	this->t_Esp = tmp.t_Esp;
	this->t_Lle = tmp.t_Lle;
	this->t_Fin = tmp.t_Fin;
	this->unidadesEjecucion = tmp.unidadesEjecucion;
	this->pVueltaMulti = tmp.pVueltaMulti;
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

uint32 Proceso::getUejecucion()
{
	return unidadesEjecucion;
}

uint32 Proceso::getTExe()
{
	return t_Exe;
}

void Proceso::setUejecucion(uint32 &&i)
{
	this->unidadesEjecucion = i;
}

void Proceso::ejecuta()
{
	--unidadesEjecucion;
	cout << "Ejecutando: " << pid << endl;
}

void Proceso::print() {
	cout << "\nPID: " << pid << "\nPrioridad: " << Prioridad << "\nTiempo de ejecucion: " << t_Exe << "\nTiempo de llegada: " << t_Lle << "\nTiempo de espera: " << t_Esp  << "\nTiempo Final: " << t_Fin << "\nEjecuciones restantes: " << unidadesEjecucion << endl;
}

bool Proceso::operator==(Proceso &tmp)
{
	return this->pid == tmp.pid;
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

void Proceso::setObject(uint32 &&tllegada, uint32 &&texe, uint32 &&tp, uint32 &&npid)
{
	this->t_Lle = tllegada;
	this->t_Exe = texe;
	this->Prioridad = tp;
	this->pid = npid;
	this->unidadesEjecucion = texe;
}

void Proceso::agregaTiempoFinal(uint32 &tfin)
{
	t_Fin = tfin;
}

void Proceso::setTiempoEspera()
{
	t_Esp = t_Fin - t_Lle - t_Exe;

	cout << "\n" << "Proceso " << pid << " terminado. t_Esp = " << t_Fin << "  " << t_Lle << "  " << t_Exe << endl;
}

void Proceso::pVueltaSuccess()
{
	pVueltaMulti = true;
}


Proceso::~Proceso()
{
}
