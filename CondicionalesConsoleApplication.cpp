// CondicionalesConsoleApplication.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>

using namespace std;

int main()
{
	cout << "Uso de condicionales\n";

	int numero1 = 5;
	int numero2 = 2;

	if (numero1 == numero2)
	{
		cout << "Estamos en el if ==" << endl;
	}
	if (numero1 > numero2)
	{
		cout << "Estamos en el if >" << endl;
	}
	if (numero1 >= numero2)
	{
		cout << "Estamos en el if >=" << endl;
	}
	if (numero1 < numero2)
	{
		cout << "Estamos en el if <" << endl;
	}
	if (numero1 <= numero2)
	{
		cout << "Estamos en el if <=" << endl;
	}
	if (numero1 != numero2)
	{
		cout << "Estamos en el if !=" << endl;
	}

	if (numero1 >= numero2)
	{
		cout << "numero1 es mayor o igual que numero 2" << endl;
	}
	else
	{
		cout << "numero 1 es menor que numero2" << endl;
	}

	/*AND*/
	if (numero1 > numero2 && numero1 != numero2)
	{
		cout << "Ambas condiciones se cumplen" << endl;
	}
	else
	{
		cout << "No se cumple ninguna AND" << endl;
	}

	/*OR*/
	if (numero1 > numero2 || numero1 != numero2 || numero1 <= numero2)
	{
		cout << "Al menos una de las condiciones o bien todas se cumplen" << endl;
	}
	else
	{
		cout << "No se cumple ninguna OR" << endl;
	}

	/*Uso del switch*/
	int opcion = 0;
	cout << "Por favor, introduzca una opcion del 1 al 5" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case  1:
		cout << "pusiste la opcion 1 " << endl;
		break;
	case 2:
		cout << "pusiste la opcion 2 " << endl;
		break;
	case 3:
		cout << "pusiste la opcion 3 " << endl;
		break;
	case 4:
		cout << "pusiste la opcion 4 " << endl;
		break;
	case 5:
		cout << "pusiste la opcion 5 " << endl;
		break;
	default:
		cout << "Tu eres bobo mi niño, del 1 al 5 mi platanito" << endl;
		break;
	}
	
}

