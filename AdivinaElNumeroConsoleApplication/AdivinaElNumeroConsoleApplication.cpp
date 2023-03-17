/* AdivinaElNumeroConsoleApplication.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
*¡Adivina el número!* Crea un programa que genere un número aleatorio y luego pregunte al usuario para adivinar cuál es. Si el 
usuario eligió un número demasiado grande o demasiado pequeño, dé una pista para ayudarlo a adivinar. Repita hasta que el usuario adivine correctamente.*/


#include <iostream>
#include <ctime> //Librería para utilizar el tiempo actual (reloj) como semilla
#include <cstdlib> //Libreria que nos genera numeros aleatorios

using namespace std;

int main()
{
    //variables
    int num_intento;

    //Generar un número aleatorio entre 1 y 100
    srand(time(nullptr)); //Configurar semilla calculo numero aleatorio
    int num_aleatorio = rand() % 100 + 1;

    
    cout << "Bienvenido al juego de ADIVINA EL NUMERO " << endl;
    cout << "Baby para ganar tendrás que adivinar un numero entre el 1 y el 100. Mucha suerte" << endl;

    do
    {
        cin >> num_intento;

        if (num_intento < num_aleatorio) 
        {
            cout << "Demasiado pequeno, intentalo again" << endl;
        }
        else if (num_intento > num_aleatorio)
        {
            cout << "Demasiado grande, intentalo again" << endl;
        }
    } while(num_intento != num_aleatorio);

    cout << "Felicidades platanito, acabas de adivinar el numero " << num_aleatorio << endl;
}

