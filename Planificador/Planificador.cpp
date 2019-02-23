// Planificador.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	Proceso p1(1, 3, 1, 0), p2(2, 2, 0, 0), p3(3, 5, 2, 0), p4(4, 2, 3, 0), p5(5, 1, 1, 0);
	Planner planification(5,2);

	planification.addProceso(p1);
	planification.addProceso(p2);
	planification.addProceso(p3);
	planification.addProceso(p4);
	planification.addProceso(p5);
	
	planification.runMonotarea();
	planification.printTabla();
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
