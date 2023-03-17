// ESDataConsoleApplicationEjemplos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    /***************************/
    int edad;
    string nombre; 

    cout << "Introduzca su nombre:" << endl;
    cin >> nombre;

    
    cout << "Hola " << nombre << " Que edad tienes?" << endl;
    cin >> edad;


    cout << "Bienvenido/a " << nombre << " con la edad de " << edad << "\n";

}

