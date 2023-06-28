// EDDListConsoleApplication --> Algoritmo de utilización de listas simples EDD (estructura de datos dinamica)

/*
* Este programa crea una lista enlazada de enteros (std::list<int>) y realiza las siguientes operaciones
1.	Agrega elementos a la lista utilizando push_back().
2.	Muestra los elementos de la lista utilizando un bucle for.
3.	Accede al primer y último elemento de la lista utilizando front() y back().
4.	Inserta un elemento en la posición 2 utilizando insert().
5.	Elimina el segundo elemento utilizando erase().
6.	Muestra los elementos de la lista después de las operaciones.

*/

#include <iostream>
//librería para usar lista
#include <list>
#include <cstring>

using namespace std;

//Ejemplo de creación de un nodo (No lo utilizaremos)
struct  _nodo
{
    int dato;
    struct tipoNodo* siguiente;
} tipoNodo;

int main()
{
    //Crear una lista vacia para almacenar datos economicos
    list<int> miLista;

    //Agregar elementos a la lista
    miLista.push_back(10);
    miLista.push_back(20);
    miLista.push_back(30);
    miLista.push_back(40);

    //Recorremos la lista y mostramos los elementos
    cout << "Elementos de la lista\n";
    for (const auto& elemento: miLista)
    {
        cout << elemento << " ";
    }
    cout << endl;

    //Acceder al primer y al ultimo elemento de la lista 
    cout << "Primer elemento de la lista " << miLista.front() << "\n";
    cout << "Ultimo elemento de la lista " << miLista.back() << "\n";

    //Insertar un elemento en la posicion 2
    list<int>::iterator it = miLista.begin();
    advance(it, 1);
    miLista.insert(it, 15);

    //Recorremos la lista y mostramos los elementos
    cout << "Elementos de la lista después de inserción\n";
    for (const auto& elemento : miLista)
    {
        cout << elemento << " ";
    }
    cout << endl;

    //Eliminar el segundo elemento de la lista
    it = miLista.begin();
    advance(it, 1);
    miLista.erase(it);

    //Recorremos la lista y mostramos los elementos
    cout << "Elementos de la lista después de eliminacion\n";
    for (const auto& elemento : miLista)
    {
        cout << elemento << " ";

        if (elemento == NULL) 
        {
            miLista.insert(it, 20);
        }
    }
    cout << endl;
}

