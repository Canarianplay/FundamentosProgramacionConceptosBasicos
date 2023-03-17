/*ChatConsoleApplication.cpp : Este archivo contiene la función "main".La ejecución del programa comienza y termina ahí.
**¡Conversación!** Crea un programa que haga una serie de preguntas al usuario (por ejemplo, su nombre, edad, ciudad de origen, etc.) 
y luego imprima una respuesta utilizando la información proporcionada (por ejemplo, "Hola [nombre], ¡es genial saber que tienes [edad] años 
y que vienes de [ciudad de origen]!").*/


/*Si quieres profundizar más en estop y mejorar este codigo ahora es el momento no lo dudes y mejerola*/

#include <iostream>

using namespace std;

int main()
{
    //variables
    string nombre;
    int edad;
    string pais;
    string comida;
    string aficion;

    cout << "Hola Como te llamas ? " << endl;
    cin >> nombre;

    cout << "Cuantos años tienes ? " << endl;
    cin >> edad;

    cout << "Cual es tu pais de origen ? " << endl;
    cin >> pais;

    cout << "Cual es tu comida favorita ? " << endl;
    cin >> comida;

    cout << "Cual es tu mayor aficion ? " << endl;
    cin >> aficion;

    cout << "Espera un momento estoy procesando la información ... " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    cout << "Hola " << nombre << " encantado de conocerte y saber que tienes la edad de " << edad << ", la verdad es que " << pais
        << " es muy bonito y me apasiona la culura de alli" << " .Me gusta saber que al igual que yo tu eres un apasionado de la comida " << comida
        << " . Anda, no sabia que te gustaba " << aficion << " cuentame mas por favor, me esta resultado muy interesante nuestra conversacion" << endl;

}


