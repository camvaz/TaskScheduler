#include "pch.h"
#include "Planner.h"


Planner::Planner()
{
	contador = 0;
	numProcesos = 0;
	canales = 0;
}

Planner::Planner(uint32 &&size, uint32&& newCanales): numProcesos(size), canales(newCanales)
{
	Tabla.reserve(size);
	Lista.reserve(size);
	ListaAEjecutar.reserve(newCanales);
	contador = 0;
}

void Planner::addProceso(Proceso nuevo)
{
	this->Tabla.insert(Tabla.end(), nuevo);
}

void Planner::llenaLista(uint32 &tiempo)
{
	for (vector<Proceso>::iterator i = Tabla.begin(); i != Tabla.end(); ++i) {
		if (i->getLlegada() == 0) {
			Lista.push_back(*i);
		}
	}
}

bool Planner::isEmpty()
{
	return Lista.size() == 0;
}

void Planner::printLista()
{
	for (vector<Proceso>::iterator i = Lista.begin(); i != Lista.end(); ++i) {
		i->print();
		cout << endl;
	}
}

void Planner::printTabla()
{
	for (vector<Proceso>::iterator i = Tabla.begin(); i != Tabla.end(); ++i) {
		i->print();
		cout << endl;
	}
}

void Planner::Lista_ordenaPEASC(uint32 &&i)
{
	Proceso temp;
	for ( i = 0; i < Lista.size(); ++i) {
		for (uint32 j = i; j < Lista.size(); ++j) {
			if (Lista[j].comparacionPEASC(Lista[i])) {
				temp = Lista[j];
				Lista[j] = Lista[i];
				Lista[i] = temp;
			}
		}
	}
}

void Planner::Lista_ordenaEPASC(uint32 &i)
{
	Proceso temp;
	for ( i = 0; i < Lista.size(); ++i) {
		for (uint32 j = i; j < Lista.size(); ++j) {
			if (Lista[j].comparacionEPASC(Lista[i])) {
				temp = Lista[j];
				Lista[j] = Lista[i];
				Lista[i] = temp;
			}
		}
	}
}

void Planner::Lista_ordenaPEDESC(uint32 &i)
{
	Proceso temp;
	for (i = 0; i < Lista.size(); ++i) {
		for (uint32 j = i; j < Lista.size(); ++j) {
			if (Lista[j].comparacionPEDESC(Lista[i])) {
				temp = Lista[j];
				Lista[j] = Lista[i];
				Lista[i] = temp;
			}
		}
	}
}

void Planner::Lista_ordenaEPDESC(uint32 &i)
{
	Proceso temp;
	for (i = 0; i < Lista.size(); ++i) {
		for (uint32 j = i; j < Lista.size(); ++j) {
			if (Lista[j].comparacionEPDESC(Lista[i])) {
				temp = Lista[j];
				Lista[j] = Lista[i];
				Lista[i] = temp;
			}
		}
	}
}

bool Planner::keepExecuting()
{
	for (vector<Proceso>::iterator i = Tabla.begin(); i != Tabla.end(); ++i) {
		if (i->getUejecucion() > 0) {
			return true;
		}
	}
	return false;
}

bool Planner::procesoTerminado(Proceso &i)
{
	return i.getUejecucion() == 0;
}

void Planner::ejecuta()
{
	for (vector<Proceso>::iterator i = ListaAEjecutar.begin(); i != ListaAEjecutar.end(); ++i) {
		if (i->getUejecucion() > 0) {
			i->ejecuta();	
		} 
	}
}

void Planner::eliminaCeros(uint32& Fin)
{
	for (vector<Proceso>::iterator i = ListaAEjecutar.begin(); i != ListaAEjecutar.end(); ++i) {
		if (i->getUejecucion() == 0) {
			
			for (vector<Proceso>::iterator it = Tabla.begin(); it != Tabla.end(); ++it) {
				if (*i == *it) {
					it->agregaTiempoFinal(Fin);
					it->setUejecucion(0);
					it->setTiempoEspera();	
				}
			}

			for (vector<Proceso>::iterator it = Lista.begin(); it != Lista.end(); ++it) {
				if (*i == *it) {
					it->setUejecucion(0);
				}
			}

		}
	}

	Lista.erase(remove_if(Lista.begin(), Lista.end(), [](Proceso x) {
		return x.getUejecucion() == 0;
	}), Lista.end());

	ListaAEjecutar.erase(remove_if(ListaAEjecutar.begin(), ListaAEjecutar.end(), [](Proceso x) {
		return x.getUejecucion() == 0;
	}), ListaAEjecutar.end());
}

void Planner::agregaListaMonotarea(uint32 &i)
{
	for (vector<Proceso>::iterator it = Tabla.begin(); it != Tabla.end(); ++it) {
		if (it->getLlegada() == i) {
			Lista.insert(Lista.end(), *it);
		}
	}
}

void Planner::runMonotarea()
{
	uint32 it;
	uint32 uExe = 0;
	while (keepExecuting()) {
		eliminaCeros(uExe);
		agregaListaMonotarea(uExe);
		Lista_ordenaPEASC(0);

		if (this->ListaAEjecutar.size() < canales) {
			if (Lista.size() > 0) {
				it = 0;
				for (size_t i = ListaAEjecutar.size(); i < canales; ++i) {
					if (ListaAEjecutar.size() > 0) {
						if (ListaAEjecutar[i - 1] == Lista[it]) {
							if (Lista.size() > 1) {
								this->ListaAEjecutar.insert(ListaAEjecutar.end(), Lista[it + 1]);
								break;
							}
						}
					}
					this->ListaAEjecutar.insert(ListaAEjecutar.end(), Lista[it]);
					++it;
				}
			}
		} 

		ejecuta();
		cout << uExe;
		++uExe;
	}

}

void Planner::runMultitarea()
{
	uint32 uExe = 0;
	while (keepExecuting()) {
		agregaListaMonotarea(uExe);
		Lista_ordenaPEASC(0);

	}
}



Planner::~Planner()
{
}
