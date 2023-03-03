// CalculaorWithSobrecargaOperadores.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
//Mejora 1: Calculadora mejorada con sobrecarga de operadores y la posibilidad de usar tanto numeros enteros como decimales.

#include <iostream>

using namespace std;

class Numero 
{
	public:
		int valorEntero;
		double valorDecimal;

		Numero() 
		{
			valorEntero = 0;
			valorDecimal = 0.0;
		}

		Numero(int v) 
		{
			valorEntero = v;
			valorDecimal = static_cast<double>(v);
		}

		Numero(double v)
		{
			valorDecimal = v;
			valorEntero = static_cast<int>(v);
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
		Numero operator+(const double& d)
		{
			return Numero(valorDecimal + d);
		}

		Numero operator-(const double& d)
		{
			return Numero(valorDecimal - d);
		}

		Numero operator*(double& d)
		{
			return Numero(valorDecimal * d);
		}

		Numero operator/(double& d)
		{
			return Numero(valorDecimal / d);
		}

		friend ostream& operator<< (ostream& os, const Numero& n);

};


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

		//Pedir al usuario el valor de los numeros y una operación matematica
		cout << "Ingrese el valor del primer numero que desea operar: " << endl;
		cin >> op1.valorDecimal;
		op1.valorEntero = static_cast<int>(op1.valorDecimal);
		cout << endl;

		cout << "Que operacion desea realiza? (+,-,*,/,%)" << endl;
		cin >> operacion;
		cout << endl;


		cout << "Ingrese el valor del segundo numero que desea operar: " << endl;
		cin >> op2.valorDecimal;
		op2.valorEntero = static_cast<int>(op2.valorDecimal);
		cout << endl;

		//Realizar la operacion matematica que se nos indica
		switch (operacion)
		{
		case '+':

			if (op1.valorEntero && op2.valorEntero) 
			{
				result = op1.operator+(op2.valorEntero);
			}
			else 
			{
				result = op1.operator+(op2.valorDecimal);
			}
			
			break;
		case '-':

			if (op1.valorEntero && op2.valorEntero)
			{
				result = op1.operator-(op2.valorEntero);
			}
			else
			{
				result = op1.operator-(op2.valorDecimal);
			}

			break;
		case '*':

			if (op1.valorEntero && op2.valorEntero)
			{
				result = op1.operator*(op2.valorEntero);
			}
			else
			{
				result = op1.operator*(op2.valorDecimal);
			}

			break;
		case '/':

			if (op1.valorEntero && op2.valorEntero)
			{
				result = op1.operator/(op2.valorEntero);
			}
			else
			{
				result = op1.operator/(op2.valorDecimal);
			}

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

