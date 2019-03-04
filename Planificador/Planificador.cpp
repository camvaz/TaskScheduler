/*Planificador de Tareas. 
	Administracion de Sistemas Operativos.
	Profesor: M.C. Josue Perez Lucero.
	Integrantes: Campos Vazquez Victor Manuel
					Perez Montiel Daniel
	
	Facultad de Ciencias de la Computacion. Benemerita Universidad Autonoma de Puebla.
*/


#include "pch.h"
#include <iostream>

void ClearScreen();

int main()
{
	vector<Proceso> procesos;
	vector<int>estructuraDatos;
	uint32 Algoritmo, canales;
	Proceso temp;
	Planner planificador;
	string filename;
	char opc, dato;
	ifstream archivo;
	bool SHUTDOWN = false;

	while (!SHUTDOWN) {
		cout << "\tPlanificador de tareas.\n";
		cout << "Materia: Administracion de Sistemas Operativos.\nProfesor: M.C. Josue Perez Lucero\nIntegrantes:\n\tCampos Vazquez Victor Manuel.\n\tPerez Montiel Daniel.\n\n\n";
		cout << "Favor de introducir el nombre del archivo a continuacion: \n$ ";
		getline(cin, filename);
		archivo.open("H:/ASO/Proyecto1/Procesos/" + filename + ".txt" ,ios::binary);

		if (!(archivo.is_open())) {
			cout << "Error: El archivo no puede ser abierto.";
			SHUTDOWN = true;
		}
		else {
			while (!archivo.eof()) {
				archivo.get(dato);
				if (dato != '\n' && dato != '\t') {
					estructuraDatos.push_back(atoi(&dato));
				}
				else if (dato == '\n') {
					temp.setObject(uint32(estructuraDatos[0]), uint32(estructuraDatos[1]), uint32(estructuraDatos[2]), uint32(estructuraDatos[3]));
					temp.print();
					planificador.addProceso(temp);
					estructuraDatos.clear();
				}
			}
			archivo.close();
			cout << "\n\nArchivo leido. Introduce la cantidad de canales:\n$ ";
			cin >> canales;

			planificador.setCanales(canales);

			cout << "Selecciona modo:\n\na: MonoTarea\nb: Multitarea\n\n$ ";
			/*cin.ignore();*/
			cin >> opc;
	/*		cin.ignore();*/
			cout << "\n\nPEDASC: Algoritmo: Prioridad(Alta), Ejecucion(Ligero) y PID Ascendente";
			cout << "\nEPASC: Algoritmo: Ejecucion (Ligero), Prioridad (Alta) y PID Ascendente";
			cout << "\nPEDESC: Algoritmo: Prioridad (Alta), Ejecucion (Ligero) y PID Descendente";
			cout << "\nEPDESC: Algoritmo: Ejecucion (Ligero), Prioridad (Alta) y PID Descendente\n";

			switch (opc) {
			case 'a':
				cout << "\nSelecciona Algoritmo: \n 1: PEASC \n 2: EPASC \n 3:PEDESC \n 4:EPDESC \n\n$";
				cin >> opc;
				cin.ignore();
				switch (opc) {
				case '1':
					Algoritmo = 0;
					planificador.runMonotarea(Algoritmo);
					planificador.reboot();
					cout << "Empezar de nuevo: y/n\n$ ";
					cin >> opc;
					if (opc == 'y') {
						ClearScreen();
						cin.ignore();
					}
					else {
						SHUTDOWN = true;
					}
					break;

				case '2':
					Algoritmo = 1;
					planificador.runMonotarea(Algoritmo);
					planificador.reboot();
					cout << "Empezar de nuevo: y/n\n$ ";
					cin >> opc;
					if (opc == 'y') {
						ClearScreen();
						cin.ignore();
					}
					else {
						SHUTDOWN = true;
					}
					break;

				case '3':
					Algoritmo = 2;
					planificador.runMonotarea(Algoritmo);
					planificador.reboot();
					cout << "Empezar de nuevo: y/n\n$ ";
					cin >> opc;
					if (opc == 'y') {
						ClearScreen();
						cin.ignore();
					}
					else {
						SHUTDOWN = true;
					}
					break;

				case '4':
					Algoritmo = 3;
					planificador.runMonotarea(Algoritmo);
					planificador.reboot();
					cout << "Empezar de nuevo: y/n\n$ ";
					cin >> opc;
					if (opc == 'y') {
						ClearScreen();
						cin.ignore();
					}
					else {
						SHUTDOWN = true;
					}
					break;

				default:
					cout << "\nAlgoritmo no valido. Intente de nuevo";
					break;
				}
				break;

			case 'b':
				cout << "\nSelecciona Algoritmo: \n 1: PEASC \n 2: EPASC \n 3:PEDESC \n 4:EPDESC \n\n$";
				cin >> opc;
				cin.ignore();
				switch (opc) {
				case '1':
					Algoritmo = 0;
					planificador.runMultitarea(Algoritmo);
					planificador.reboot();
					cout << "Empezar de nuevo: y/n\n$ ";
					cin >> opc;
					if (opc == 'y') {
						ClearScreen();
						cin.ignore();
					}
					else {
						SHUTDOWN = true;
					}
					break;

				case '2':
					Algoritmo = 1;
					planificador.runMultitarea(Algoritmo);
					planificador.reboot();
					cout << "Empezar de nuevo: y/n\n$ ";
					cin >> opc;
					if (opc == 'y') {
						ClearScreen();
						cin.ignore();
					}
					else {
						SHUTDOWN = true;
					}
					break;

				case '3':
					Algoritmo = 2;
					planificador.runMultitarea(Algoritmo);
					planificador.reboot();
					cout << "Empezar de nuevo: y/n\n$ ";
					cin >> opc;
					if (opc == 'y') {
						ClearScreen();
						cin.ignore();
					}
					else {
						SHUTDOWN = true;
					}
					break;

				case '4':
					Algoritmo = 3;
					planificador.runMultitarea(Algoritmo);
					planificador.reboot();
					cout << "Empezar de nuevo: y/n\n$ ";
					cin >> opc;
					if (opc == 'y') {
						ClearScreen();
						cin.ignore();
					}
					else {
						SHUTDOWN = true;
					}
					break;

				default:
					cout << "\nAlgoritmo no valido. Intente de nuevo";
					break;
				}
				break;
				
			default:
				cout << "\nOpcion invalida. Intente de nuevo.\n";
				break;
			}

		}
	}
}

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	SetConsoleCursorPosition(hStdOut, homeCoords);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file