/*
* En este ejercicio podemos ver las operacione básicas de una cola y su uso através de la libre queue, como son front, pop, push,....
* 
* TODO para ti platanito: Comprueba si miColaCopia está vacía y luego comprueba si miCola está también vacía, si no es asi, muestra todos sus elementos.
* 
*/

#include <iostream>

//Incluimos la librería para tratar Colas
#include <queue>
using namespace std;

int main()
{
    //Creamos una cola vacia de enteros
    queue<int> miCola;

    //Insercion de elementos en la cola
    miCola.push(10);
    cout << "Primer elemento insertado: \n" << miCola.back();

    miCola.push(20);
    miCola.push(30);
    miCola.push(40);
    miCola.push(50);

    //Iteracion a través de los elementos de la cola (Version 1)
    cout << "Version 1: Iteracion a través de los elementos de la cola - utilizando pop()" << endl;

    while (!miCola.empty()) 
    {
        cout << "Elemento actual (Version 1): " << miCola.front() << endl;
        miCola.pop();
    }
    cout << endl;

    //Insertamos de nuevo elementos en la cola
    miCola.push(20);
    cout << "Primer elemento insertado nuevamente: \n" << miCola.back() << endl;
    miCola.push(30);
    miCola.push(40);
    miCola.push(50);

    //Iteracion a través de los elementos de la cola (Version 2)
    cout << "Version 2: Iteracion a través de los elementos de la cola - sin modificar la cola" << endl;
    queue<int> miColaCopia = miCola;

    while (!miColaCopia.empty())
    {
        cout << "Elemento actual (Version 2): " << miColaCopia.front() << endl;;
        miColaCopia.pop();
    }
    cout << endl;

}

