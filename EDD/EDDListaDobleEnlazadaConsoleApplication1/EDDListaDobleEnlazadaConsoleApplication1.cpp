// EDDListaDobleEnlazadaConsoleApplication1.cpp

/*
* 
*/

#include <iostream>

//Usamos libreria para lista
#include <list>

using namespace std;

int main()
{
    //Crear una lista
    list<int> myList;

    //Insertar como si fuera una lista simple
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    //ATENCION!!: Ahora podemos insertar también por el nodo anterior
    myList.push_front(50);
    myList.push_front(60);
    myList.push_front(70);


    //Recorrer la lista de adelante hacia atrás
    cout << "Lista hacia delante\n";
    for(const auto& elemento: myList)
    {
        cout << elemento << " ";
    }
    cout << endl;

    //Recorrer la lista de atrás hacía delante
    cout << "Lista hacia atrás\n";
    for (auto it = myList.rbegin(); it != myList.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //Eliminar un elemento cualquiera de la lista
    list<int>::iterator it = find(myList.begin(), myList.end(), 20); //Con esto podemos encontrar elementos dentro de nuestra lista o EDD
    if ( it != myList.end()) 
    {
        myList.erase(it);
    }

    //Recorrer después de eliminar
    cout << "Lista despues de eliminar\n";
    for (const auto& elemento : myList)
    {
        cout << elemento << " ";
    }
    cout << endl;
}

