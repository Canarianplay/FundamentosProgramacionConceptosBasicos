#include <iostream>

using namespace std;

void main()
{
	cout << "Ejemplos de uso de variables en C++ (Tipo primitivos y constantes)" << endl;

	/*Declarar e inicializar una variable tipo char*/
	char a = 'a';
	/*Declaracion e inicialización por separado*/
	char b;
	b = 'b';

	cout << "El valor de a es: " << a << " mientras que el de b es: " << b << endl;

	/*declaración e inicilizacion variables int, float, double*/
	int numero1 = 1;
	int numero2 = 2;

	float numerof1 = 12345678;
	float numerof2 = 32562556;

	double numerod1 = 3.5;
	double numerod2 = 5.6;

	cout << "El resultado de sumar numero1 + numero2 es " << numero1 + numero2 << endl;
	cout << "El resultado de sumar numerof1 + numerof2 es " << numerof1 + numerof2 << endl;
	cout << "El resultado de sumar numerod1 + numerod2 es " << numerod1 + numerod2 << endl;

	/*declaracion y uso de variable bool*/
	int resultado = numero1 + numero2;
	bool valor = false;

	if (resultado >= 3)
	{
		valor = true;

	}

	cout << "Es correcto el resultado de la suma ? " << valor << endl;;
}

