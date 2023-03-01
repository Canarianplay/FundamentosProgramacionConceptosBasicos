// CalculaorWithSobrecargaOperadores.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

class Numero 
{
	public:
		int valorEntero;
		float valorDecimal;

		Numero() {}

		Numero(int v) 
		{
			valorEntero = v;
		}

		Numero(float v)
		{
			valorDecimal = v;
		}

		//Entero
		Numero operator+(const Numero& n) 
		{
			return Numero(valorEntero + n.valorEntero);
		}

		Numero operator-(const Numero& n)
		{
			return Numero(valorEntero - n.valorEntero);
		}

		Numero operator*(const Numero& n)
		{
			return Numero(valorEntero * n.valorEntero);
		}

		Numero operator/(const Numero& n)
		{
			return Numero(valorEntero / n.valorEntero);
		}

		//decimal
		Numero operator+(const Numero& n)
		{
			return Numero(valorDecimal + n.valorDecimal);
		}

		Numero operator-(const Numero& n)
		{
			return Numero(valorDecimal - n.valorDecimal);
		}

		Numero operator*(const Numero& n)
		{
			return Numero(valorDecimal * n.valorDecimal);
		}

		Numero operator/(const Numero& n)
		{
			return Numero(valorDecimal / n.valorDecimal);
		}

		friend ostream& operator<< (ostream& os, const Numero& n);

};

ostream& operator<< (ostream& os, const Numero& n)
{
	os << n.valorEntero;
	return os;
}

ostream& operator<< (ostream& os, const Numero& n)
{
	os << n.valorDecimal;
	return os;
}

int main()
{
	char continuar;

	do
	{
		Numero op1, op2, result = 0;
		char operacion;

		//Pedir al usuario el valor de los numeros y una operación matimatica
		cout << "Ingrese el valor del primer numero que desea operar: " << endl;
		cin >> op1.valorDecimal;
		cout << endl;

		cout << "Que operacion desea realiza? (+,-,*,/,%)" << endl;
		cin >> operacion;
		cout << endl;


		cout << "Ingrese el valor del segundo numero que desea operar: " << endl;
		cin >> op2.valorDecimal;
		cout << endl;

		//Realizar la operacion matematica que se nos indica
		switch (operacion)
		{
		case '+':
			result = op1.operator+(op2.valorDecimal);
			break;
		case '-':
			result = op1.operator-(op2.valorDecimal);
			break;
		case '*':
			result = op1.operator*(op2.valorDecimal);
			break;
		case '/':
			result = op1.operator/(op2.valorDecimal);
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

