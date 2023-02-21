// TipoEstructuradodatosConsoleApplication.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;;

int main()
{
    cout << "Ejemplos de uso de vectores y matrices" << endl;;

    /*Array*/
    string alumnos[5];
    string clases[5];

    cout << "Completar el calendario" << endl;
    for (int i = 0; i < 5; i++) 
    {
        cout << "Alumno con nombre: " << endl;
        cin >> alumnos[i];

        cout << endl;

        cout << "Asignado a la clase:" << endl;
        cin >> clases[i];
    }

    cout << endl;
    cout << "El calendario queda de la siguiente forma " << endl;

    for (int j = 0; j < alumnos->length(); j++) 
    {
        cout << alumnos[j] << endl;
        cout << clases[j] << endl;
    }

    /*Matrices*/
    string universidad[5][5] = { {"pepe","informatica"},{"maria","fisica"},{"marcos","educacion fisica"},{"manuel","arte"},{"blanca","marketing"} };

    for (int x = 0; x < 5; x++) 
    {
        for (int y = 0; y < 5; y++)
        {
            cout << universidad[x][y] << endl;
        }
    }
}

