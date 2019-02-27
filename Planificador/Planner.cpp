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

void Planner::reboot()
{
	Lista.clear();
	Tabla.clear();
	ListaAEjecutar.clear();
	ColaEspera.clear();
	canales = 0;
	numProcesos = 0;
	contador = 0;
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

void Planner::Lista_ordenaEPASC(uint32 &&i)
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

void Planner::Lista_ordenaPEDESC(uint32 &&i)
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

void Planner::Lista_ordenaEPDESC(uint32 &&i)
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

void Planner::eligeOrdenamiento(uint32 &opc)
{
	switch (opc) {
	case 0:
		Lista_ordenaPEASC(0);
		break;

	case 1:
		Lista_ordenaEPASC(0);
		break;

	case 2:
		Lista_ordenaPEDESC(0);
		break;

	case 3:
		Lista_ordenaEPDESC(0);
		break;

	default:
		cout << "No se recibio opcion de ordenamiento";
		break;
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

void Planner::ejecutaMonoTarea()
{
	for (vector<Proceso>::iterator i = ListaAEjecutar.begin(); i != ListaAEjecutar.end(); ++i) {
		if (i->getUejecucion() > 0) {
			i->ejecuta();	
		} 
	}
}

void Planner::ejecutaMultiTarea()
{
	for (size_t i = 0; i < canales; ++i) {
		if (Lista[i].getUejecucion() > 0) {
			Lista[i].ejecuta();
		}
	}
}

void Planner::eliminaCerosMonotarea(uint32& Fin)
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

void Planner::eliminaCerosMultitarea(uint32 &uExe)
{
	
}

void Planner::agregaLista(uint32 &i)
{
	for (vector<Proceso>::iterator it = Tabla.begin(); it != Tabla.end(); ++it) {
		if (it->getLlegada() == i) {
			Lista.insert(Lista.end(), *it);
		}
	}
}

void Planner::runMonotarea(uint32 &Alg)
{
	uint32 uExe = 0;
	size_t ct = 0;
	while (keepExecuting()) {
		cout << "Unidad: " << uExe << "\n\n";
		eliminaCerosMonotarea(uExe);
		agregaLista(uExe);
		eligeOrdenamiento(Alg);
		printLista();

		cout << "\nTamanio vector ejecutar: " << ListaAEjecutar.size() << endl;
		if (this->ListaAEjecutar.size() < size_t(canales)) {
			if (Lista.size() > 0) {
				if (ListaAEjecutar.size() > 0) {
					ct = 0;
					while(ListaAEjecutar.size() < size_t(canales) && (size_t(ct) < ListaAEjecutar.size() && size_t(ct) < Lista.size())) {
						if (Lista[ct] == ListaAEjecutar[ct]) {		
							++ct;
						}
						else {
							this->ListaAEjecutar.insert(ListaAEjecutar.end(), Lista[ct]);
							++ct;
						}
					}
				}
				else {
					ct = 0;
					while (ListaAEjecutar.size() < size_t(canales) && size_t(ct) <= Lista.size())
					{
						this->ListaAEjecutar.insert(ListaAEjecutar.end(), Lista[ct]);
						++ct;
					}
				}
			}
		} 
		ejecutaMonoTarea();
		++uExe;
	}

}

void Planner::runMultitarea(uint32 &Alg)
{
	uint32 uExe = 0, it = 0;
	while (keepExecuting()) {
		eliminaCerosMultitarea(uExe);
		agregaLista(uExe);
		eligeOrdenamiento(Alg);
		ejecutaMultiTarea();
		

		if (Lista.size() > 0) {
			for (size_t i = ColaEspera.size(); i < Lista.size(); ++i)
			{
				if (Lista.size() > 0) {
					ColaEspera.insert(ColaEspera.end(), Lista[it]);
					++it;
				}
			}
		}
	}
}



Planner::~Planner()
{
}