// Planificador.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	Proceso procesos[12];
	procesos[0].setObject(0,3,5,1);
	procesos[1].setObject(1,3,4,2);
	procesos[2].setObject(1,4,3,3);
	procesos[3].setObject(0,3,4,4);
	procesos[4].setObject(0,2,5,5);
	procesos[5].setObject(3,1,4,6);
	procesos[6].setObject(3,2,4,7);
	procesos[7].setObject(0,2,3,8);
	procesos[8].setObject(5,1,4,9);
	procesos[9].setObject(4,3,2,10);
	procesos[10].setObject(4,2,4,11);
	procesos[11].setObject(4,3,5,12);

	Planner planification(12,2);

	for (size_t i = 0; i < 12; ++i) {
		planification.addProceso(procesos[i]);
	}
	
	planification.runMonotarea();
	planification.printTabla();
	cout << "\n";
	planification.printLista();
	cout << "n\n";
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
