// UsoBuclesEjemplosConsoleApplication.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

int main()
{
	/*bucle for*/
	for (int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}

	
	/*while*/
	int numero = 101;
	while (numero <= 100)
	{
		cout << "ingrese un numero" << endl;
		cin >> numero;
	}

	/*do-while*/
	do
	{
		cout << "ingrese un numero" << endl;
		cin >> numero;

	} while (numero <= 100);

	/*¿Bucles anidados? te animo a que hagas uno*/
}


