// CalculaorWithSobrecargaOperadores.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
// 
//Mejora 2: Calculadora mejorada con sobrecarga de operadores y la posibilidad de usar tanto numeros enteros como decimales, 
//esta solucion aparentemente es más fiable que la anterior a la hora de realizar operaciones aritmeticas.

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
		valorDecimal = 0.0;
	}

	Numero(double v)
	{
		valorDecimal = v;
		valorEntero = 0;
	}

	//Entero
	Numero operator+(const Numero& n)
	{
		if(valorEntero && n.valorEntero)
		{
			return Numero(valorEntero + n.valorEntero);
		}
		else 
		{
			return Numero(valorDecimal + n.valorDecimal);
		}
	}

	Numero operator-(const Numero& n)
	{
		if (valorEntero && n.valorEntero)
		{
			return Numero(valorEntero - n.valorEntero);
		}
		else 
		{
			return Numero(valorDecimal - n.valorDecimal);
		}
		
	}

	Numero operator*(const Numero& n)
	{
		if (valorEntero && n.valorEntero)
		{
			return Numero(valorEntero * n.valorEntero);
		}
		else
		{
			return Numero(valorDecimal * n.valorDecimal);
		}
	}

	Numero operator/(const Numero& n)
	{
		if (valorEntero && n.valorEntero)
		{
			return Numero(valorEntero / n.valorEntero);
		}
		else
		{
			return Numero(valorDecimal / n.valorDecimal);
		}
		
	}

	friend ostream& operator<< (ostream& os, const Numero& n);

};


ostream& operator<< (ostream& os, const Numero& n)
{
	if(n.valorEntero)
	{
		return os << n.valorEntero;
	}
	else 
	{
		return os << n.valorDecimal;
	}

}


int main()
{
	char continuar;

	do
	{
		Numero op1, op2, result = 0;
		char operacion;
		char tipoOperacion;

		cout << "Que tipo de operacion desea realizar, decimal o entera ? (d/e)" << endl;
		std::cin >> tipoOperacion;
		cout << endl;

		switch (tipoOperacion)
		{
		case 'd':
			//Pedir al usuario el valor de los numeros y una operación matematica
			cout << "Ingrese el valor del primer numero que desea operar: " << endl;	
			std::cin >> op1.valorDecimal;
			cout << endl;

			cout << "Que operacion desea realiza? (+,-,*,/,%)" << endl;
			std::cin >> operacion;
			cout << endl;


			cout << "Ingrese el valor del segundo numero que desea operar: " << endl;
			std::cin >> op2.valorDecimal;
			cout << endl;
			break;
		case 'e':
			//Pedir al usuario el valor de los numeros y una operación matematica
			cout << "Ingrese el valor del primer numero que desea operar: " << endl;
			std::cin >> op1.valorEntero;
			cout << endl;

			cout << "Que operacion desea realiza? (+,-,*,/,%)" << endl;
			std::cin >> operacion;
			cout << endl;


			cout << "Ingrese el valor del segundo numero que desea operar: " << endl;
			std::cin >> op2.valorEntero;
			cout << endl;
			break;
		default:
			break;
		}

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

		if (result.valorEntero) 
		{
			cout << "El resultado de la operacion " << operacion << " es: " << result.valorEntero << endl;

		}
		else 
		{
			cout << "El resultado de la operacion " << operacion << " es: " << result.valorDecimal << endl;
		}
		
		cout << "Desea continuar operando ? (S/N)" << endl;
		std::cin >> continuar;

		if (continuar == 'N')
		{
			cout << "Gracias por utilizar la calculadora platanito en fase BETA " << endl;
		}
	} while (continuar != 'N');
}

