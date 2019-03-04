#include "pch.h"
#include <iostream>

void ClearScreen();

int main()
{
	uint32 Algoritmo, canales;
	Proceso temp;
	Planner planificador;
	string filename;
	char opc;
	ifstream archivo;
	bool SHUTDOWN = false;

	while (!SHUTDOWN) {

		cout << "\tPlanificador de tareas.\n";
		cout << "Materia: Administracion de Sistemas Operativos.\nProfesor: M.C. Josue Perez Lucero\nIntegrantes:\n\tCampos Vazquez Victor Manuel.\n\tPerez Montiel Daniel.\n\n\n";
		cout << "Favor de introducir el nombre del archivo a continuacion: \n$ ";
		getline(cin, filename);
		archivo.open("H:/ASO/Proyecto1/Procesos/" + filename + ".txt", ios::binary);

		if (!(archivo.is_open())) {
			cout << "Error: El archivo no puede ser abierto.";
		}
		else {
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
				cout << "\nSelecciona Algoritmo: \n 1: PEASC \n 2: EPASC \n 3:PEDESC \n 4:EPDESC \n\n";
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
				cout << "\nSelecciona Algoritmo: \n 1: PEASC \n 2: EPASC \n 3:PEDESC \n 4:EPDESC \n\n";
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

	//Proceso procesos[12];
	//procesos[0].setObject(0,3,5,1);
	//procesos[1].setObject(1,3,4,2);
	//procesos[2].setObject(1,4,3,3);
	//procesos[3].setObject(0,3,4,4);
	//procesos[4].setObject(0,2,5,5);
	//procesos[5].setObject(3,1,4,6);
	//procesos[6].setObject(3,2,4,7);
	//procesos[7].setObject(0,2,3,8);
	//procesos[8].setObject(5,1,4,9);
	//procesos[9].setObject(4,3,2,10);
	//procesos[10].setObject(4,2,4,11);
	//procesos[11].setObject(4,3,5,12);
//	Proceso procesos[9];
//	Proceso procesosMulti[10];
//
//	uint32 algo = 1, algoMulti = 2;
//
//	//llegada, ejecucion, prioridad, pid
//
//	procesos[0].setObject(0, 2, 0, 1);
//	procesos[1].setObject(2, 1, 1, 2);
//	procesos[2].setObject(0, 2, 2, 3);
//	procesos[3].setObject(2, 1, 5, 4);
//	procesos[4].setObject(0, 1, 4, 5);
//	procesos[5].setObject(4, 2, 3, 6);
//	procesos[6].setObject(3, 2, 2, 7);
//	procesos[7].setObject(6, 1, 1, 8);
//	procesos[8].setObject(0, 3, 0, 9);
//
//	procesosMulti[0].setObject(0, 3, 5, 1);
//	procesosMulti[1].setObject(0, 2, 4, 2);
//	procesosMulti[2].setObject(4, 3, 2, 3);
//	procesosMulti[3].setObject(6, 2, 3, 4);
//	procesosMulti[4].setObject(5, 3, 2, 5);
//	procesosMulti[5].setObject(6, 2, 2, 6);
//	procesosMulti[6].setObject(4, 3, 3, 7);
//	procesosMulti[7].setObject(4, 2, 4, 8);
//	procesosMulti[8].setObject(5, 3, 1, 9);
//	procesosMulti[9].setObject(5, 3, 0, 10);
//
//	Planner planification(9, 2);
//	Planner planificationMulti(10, 2);
//
//	for (size_t i = 0; i < 9; ++i) {
//		planification.addProceso(procesos[i]);
//	}
//
//	planification.printTabla();
//	planification.runMonotarea(algo);
//	planification.printTabla();
//	planification.printLista();
//
//	for (size_t i = 0; i < 10; ++i) {
//		planificationMulti.addProceso(procesosMulti[i]);
//	}
//
//	planificationMulti.printTabla();
//	planificationMulti.runMultitarea(algoMulti);
//	planificationMulti.printTabla();
//	planificationMulti.printLista();
//
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file