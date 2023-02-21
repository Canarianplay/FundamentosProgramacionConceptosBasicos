/*
* ¡Calculadora! Crea un programa que permita al usuario ingresar dos números 
y una operación matemática (por ejemplo, suma, resta, multiplicación o división) y luego imprima el resultado de la operación.
*/

#include <iostream>

using namespace std;

int main()
{
	char continuar;
	
	do
	{
		int op1, op2, result = 0;
		char operacion;
		
		//Pedir al usuario el valor de los numeros y una operación matimatica
		cout << "Ingrese el valor del primer numero que desea operar: " << endl;
		cin >> op1;
		cout << endl;

		cout << "Que operacion desea realiza? (+,-,*,/,%)" << endl;
		cin >> operacion;
		cout << endl;


		cout << "Ingrese el valor del segundo numero que desea operar: " << endl;
		cin >> op2;
		cout << endl;

		//Realizar la operacion matematica que se nos indica
		switch (operacion)
		{
		case '+':
			result = op1 + op2;
			break;
		case '-':
			result = op1 - op2;
			break;
		case '*':
			result = op1 * op2;
			break;
		case '/':
			result = op1 / op2;
			break;
		case '%':
			result = op1 % op2;
			break;
		default:
			cout << "Operacion introducida es invalida: " << endl;
			break;
		}

		cout << "El resultado de la operacion " << operacion << " es: " << result << endl;

		cout << "Desea continuar operando ? (S/N)" << endl;
		cin >> continuar;

		if (continuar == 'N')
		{
			cout << "Gracias por utilizar la calculadora platanito en fase BETA " << endl;
		}
	} while (continuar != 'N');

}
