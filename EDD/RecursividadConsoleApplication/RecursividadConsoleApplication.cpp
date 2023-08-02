// RecursividadConsoleApplication.cpp : En este archivo veremos el uso de la Recursividad

#include <iostream>
using namespace std;

//Funcion recursiva para calcular el factorial de un numero
int factorial(int num);

int main()
{
    //Ejemplo de calculo del factorial de un numero
    int num = 15;

    int fact = factorial(5);

    cout << "El factorial del numero " << num << " es: " << fact << endl;
}

int factorial(int num) 
{
    if (num == 0) 
    {
        return 1;
    }

    return num * factorial(num - 1);
}