/* Version 1:
En este ejemplo, se crea una pila (std::stack<int>) que almacena enteros. A continuación, se realizan las siguientes operaciones:
    1.	Insertamos elementos en la pila utilizando la función push(). Después de cada inserción, mostramos el elemento superior de la pila utilizando top().
    2.	Eliminamos elementos de la pila utilizando la función pop(). Después de cada eliminación, mostramos el elemento superior de la pila para verificar los cambios.
    3.	Al final, mostramos el elemento restante en la pila utilizando top().
Este ejemplo te ayudará a presentar la creación, inicialización, inserción y eliminación de elementos en una pila utilizando la biblioteca estándar de C++.

*/

/* Version 2:
* Se añade la iteración a los elementos de la lista
*/

#include <iostream>
//Librería para el uso de Pilas
#include <stack>

using namespace std;

int main()
{
    // Crear una pila vacia de enteros
    stack<int> miPila;

    //Inserción de elementos en la pila
    miPila.push(10);
    cout << "Elemento sacado de la Pila: " << miPila.top();
    miPila.pop();

    //Inserción de elementos en la pila
    miPila.push(20);
  
    //Inserción de elementos en la pila
    miPila.push(30);
    miPila.pop();

    //Inserción de elementos en la pila
    miPila.push(40);
    
    //Inserción de elementos en la pila
    miPila.push(50);
    

    //Iteramos los elementos de la pila
    cout << " Elementos de la pila: ";
    while(!miPila.empty())
    {
        cout << miPila.top() << " ";
        miPila.pop();
    }
    cout << endl;
}

