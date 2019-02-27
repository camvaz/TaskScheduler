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

void Planner::vaciaColaEspera()
{
	for (vector<Proceso>::iterator i = ColaEspera.begin(); i != ColaEspera.end(); ++i) {
		Lista.insert(Lista.end(), *i);
	}
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

void Planner::Cola_ordenaPEASC(uint32 &&i)
{
	Proceso temp;
	for (i = 0; i < ColaEspera.size(); ++i) {
		for (uint32 j = i; j < ColaEspera.size(); ++j) {
			if (ColaEspera[j].comparacionPEASC(ColaEspera[i])) {
				temp = ColaEspera[j];
				ColaEspera[j] = ColaEspera[i];
				ColaEspera[i] = temp;
			}
		}
	}
}

void Planner::Cola_ordenaEPASC(uint32 &&i)
{
	Proceso temp;
	for (i = 0; i < ColaEspera.size(); ++i) {
		for (uint32 j = i; j < ColaEspera.size(); ++j) {
			if (ColaEspera[j].comparacionEPASC(ColaEspera[i])) {
				temp = ColaEspera[j];
				ColaEspera[j] = ColaEspera[i];
				ColaEspera[i] = temp;
			}
		}
	}
}

void Planner::Cola_ordenaEPDESC(uint32 &&i)
{
	Proceso temp;
	for (i = 0; i < ColaEspera.size(); ++i) {
		for (uint32 j = i; j < ColaEspera.size(); ++j) {
			if (ColaEspera[j].comparacionEPDESC(ColaEspera[i])) {
				temp = ColaEspera[j];
				ColaEspera[j] = ColaEspera[i];
				ColaEspera[i] = temp;
			}
		}
	}
}

void Planner::Cola_ordenaPEDESC(uint32 &&i)
{
	Proceso temp;
	for (i = 0; i < ColaEspera.size(); ++i) {
		for (uint32 j = i; j < ColaEspera.size(); ++j) {
			if (ColaEspera[j].comparacionPEDESC(ColaEspera[i])) {
				temp = ColaEspera[j];
				ColaEspera[j] = ColaEspera[i];
				ColaEspera[i] = temp;
			}
		}
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

void Planner::eligeOrdenamientoLista(uint32 &opc)
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

void Planner::eligeOrdenamientoCola(uint32 &opc)
{
	switch (opc) {
	case 0:
		Cola_ordenaPEASC(0);
		break;

	case 1:
		Cola_ordenaEPASC(0);
		break;

	case 2:
		Cola_ordenaPEDESC(0);
		break;

	case 3:
		Cola_ordenaEPDESC(0);
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
	for (size_t i = 0; i < size_t(canales); ++i) {
		if (Lista.size() < i) {
			if (Lista[i].getUejecucion() > 0) {
				Lista[i].ejecuta();
			}
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
	for (vector<Proceso>::iterator i = Lista.begin(); i != Lista.end(); ++i) {
		if (i->getUejecucion() == 0) {
			for (vector<Proceso>::iterator it = Tabla.begin(); it != Tabla.end(); ++it) {
				if (*i == *it) {
					it->setUejecucion(0);
					it->agregaTiempoFinal(uExe);
					it->setTiempoEspera();
					it->pVueltaSuccess();
				}
			}
		}
	}

	Lista.erase(remove_if(Lista.begin(), Lista.end(), [](Proceso x) {
		return x.getUejecucion() == 0;
	}), Lista.end());
}

void Planner::agregaLista(uint32 &i)
{
	for (vector<Proceso>::iterator it = Tabla.begin(); it != Tabla.end(); ++it) {
		if (it->getLlegada() == i) {
			Lista.insert(Lista.end(), *it);
		}
	}
}

void Planner::agregaColaEspera(uint32 &opc)
{
	for (vector<Proceso>::iterator i = Lista.begin(); i != Lista.end(); ++i) {
		if (i->getUejecucion() > 0) {
			this->ColaEspera.insert(ColaEspera.end(), *i);
			Lista.erase(remove_if(Lista.begin(), Lista.end(), [](Proceso x) {
				return x == *i;
			}), Lista.end());
		}
	}
	
	eligeOrdenamientoCola(opc);
}

void Planner::runMonotarea(uint32 &Alg)
{
	uint32 uExe = 0;
	size_t ct = 0;
	while (keepExecuting()) {
		cout << "Unidad: " << uExe << "\n\n";
		eliminaCerosMonotarea(uExe);
		agregaLista(uExe);
		eligeOrdenamientoLista(Alg);
		printLista();

		cout << "\nTamanio vector ejecutar: " << ListaAEjecutar.size() << endl;
		if (this->ListaAEjecutar.size() < size_t(canales)) {
			if (Lista.size() > 0) {
				if (ListaAEjecutar.size() > 0) {
					ct = 0;
					while(ListaAEjecutar.size() < size_t(canales) && (size_t(ct) < ListaAEjecutar.size() && size_t(ct) < Lista.size())) {
						if (Lista[ct] == ListaAEjecutar[ct]) {
							++ct;
							if(ct <Lista.size())
								this->ListaAEjecutar.insert(ListaAEjecutar.end(), Lista[ct]);
						}
						else {
							this->ListaAEjecutar.insert(ListaAEjecutar.end(), Lista[ct]);
							++ct;
						}
					}
				}
				else {
					ct = 0;
					while (ListaAEjecutar.size() < size_t(canales) && size_t(ct) < Lista.size())
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
	bool pVuelta = false, nVuelta = false;
	while (keepExecuting()) {
		cout << "Unidad de Ejecución: " << uExe << endl << endl;
		if (!pVuelta) {
			cout << "Primer vuelta\n\n";
			agregaLista(uExe);
			eligeOrdenamientoLista(Alg);
			ejecutaMultiTarea();
			eliminaCerosMultitarea(uExe);
			agregaColaEspera(Alg);

			pVuelta = true;
			for (vector<Proceso>::iterator i = Tabla.begin(); i != Tabla.end(); ++i) {
				if (pVuelta) {
					if (i->getUejecucion() > 0) {
						for (vector<Proceso>::iterator it = ColaEspera.begin(); it != ColaEspera.end(); ++it) {
							if (*i == *it) {
								pVuelta = true;
								break;
							}
							else {
								pVuelta = false;
							}

						}
					}
				}
				else {
					break;
				}
			}
			++uExe;
		}
		else {
			cout << "Unidad de vuelta n: " << uExe << endl << endl;
			if (Lista.size() == 0)
				vaciaColaEspera();

			ejecutaMultiTarea();
			eliminaCerosMultitarea(Alg);
			agregaColaEspera(Alg);

			/*nVuelta = true;
			for (vector<Proceso>::iterator i = Tabla.begin(); i != Tabla.end(); ++i) {
				if (nVuelta) {
					if (i->getUejecucion() > 0) {
						for (vector<Proceso>::iterator it = ColaEspera.begin(); it != ColaEspera.end(); ++it) {
							if (*i == *it) {
								nVuelta = true;
								break;
							}
							else {
								nVuelta = false;
							}
						}
					}
					else {
						break;
					}
				}
			}

			if (nVuelta) {

			}*/

			++uExe;
		}
	}
}



Planner::~Planner()
{
}