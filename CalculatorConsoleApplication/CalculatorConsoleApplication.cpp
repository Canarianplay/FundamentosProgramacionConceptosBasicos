/*
* ¡Calculadora! Crea un programa que permita al usuario ingresar dos números 
y una operación matemática (por ejemplo, suma, resta, multiplicación o división) y luego imprima el resultado de la operación.
*/

/* UPGRADES
*	- 1.  Modularización del programa (Añadimos funciones)
*   - 2.  Ambito de variables y paso por valor y referencia
*   - 3.  Hacer la calculadora más funcional (escribe directamente operandos y operardor y nuestra calculadora hace el resto)
*/


#include <iostream>
#include <sstream>
using namespace std;


//Variables global para el resultado
int resultado = 0;
float resultadof = 0.0;


//Declaración de las funicones que usaremos en le código

//Suma
int Suma(int a, int b);

//Resta
int Resta(int &a, int &b);

//Multiplicación
int Multiplicacion(int a, int b);

//División
float Division(int a, int b);

//Moduilo
int Modulo(int a, int b);


int main()
{
	char continuar;
	
	//variable local del main que contiene la operacion completa que hará nuestra calculadora
	string input;

	do
	{
		int op1, op2;
		char operacion;

		int& op1Ref = op1;
		int& op2Ref = op2;
		
		cout << "Ingrese la operación a realizar (operando1 operador operando2) _ " << endl;
		getline(cin, input);

		stringstream ss(input);

		ss >> op1 >> operacion >> op2;
		
		//Realizar la operacion matematica que se nos indica
		switch (operacion)
		{
		case '+':
			resultado = Suma(op1, op2);
			break;
		case '-':
			resultado = Resta(op1Ref, op2Ref); 
			break;
		case '*':
			resultado = Multiplicacion(op1, op2);
			break;
		case '/':
			resultadof = Division(op1, op2);
			cout << "El resultado de la división es: " << resultadof << endl;
			return 0;
			break;
		case '%':
			resultado = Modulo(op1, op2);
			break;
		default:
			cout << "Operacion introducida es invalida: " << endl;
			break;
		}

		cout << "El resultado es: " << resultado << endl;

		resultado = 0;
		input = "";

		cout << "Desea continuar operando ? (S/N)" << endl;
		cin >> continuar;


		cin.ignore();

		if (continuar == 'N')
		{
			cout << "Gracias por utilizar la calculadora platanito en fase BETA " << endl;
		}
	} while (continuar != 'N');

}

//Definición de las funciones que utilizaremos.

//Suma
int Suma(int a, int b)
{

	return a + b;
}

//Resta
int Resta(int &a, int &b)
{
	return  a-b;
}

//Multiplicación
int Multiplicacion(int a, int b)
{
	return a * b;
}

//División
float Division(int a, int b)
{
	if(b != 0)
	{
		float af = static_cast<float>(a);
		float bf = static_cast<float>(b);
		return af / bf;
	}
	else
	{
		cout << "No se puede dividir entre 0" << endl;
		return 0.0;
	}
}

//Modulo
int Modulo(int a, int b) 
{
	if(b != 0)
	{
		return a % b;
	}
	else
	{
		cout << "No se puede dividir entre 0" << endl;
		return 0;
	}

}
