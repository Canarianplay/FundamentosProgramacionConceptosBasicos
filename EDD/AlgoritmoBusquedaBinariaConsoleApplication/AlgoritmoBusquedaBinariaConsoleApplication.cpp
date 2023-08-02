// AlgoritmoBusquedaBinariaConsoleApplication.cpp : Vamos a ver el funcionamiento de un codigo que contiene el algoritmo de busqueda binaria

#include <iostream>
#include <vector>

using namespace std;


//Funcion recursiva para realizar la busqueda binaria
int binarySearch(const vector<int> &arr, int target, int left, int right);

int main()
{
    vector<int> numbers = { 2,5,6,9,8,45,6 };

    int target = 45;

    //Realizamos la busqueda binaria;
    int index = binarySearch(numbers, target, 0, numbers.size() - 1);

    if (index == -1)
    {
        cout << "El elemento" << target << " no se encuentra en la lista" << endl;
    }
    else 
    {
        cout << "Elemento encontrado" << endl;
    }
}

int binarySearch(const vector<int>& arr, int target, int left, int right)
{
    if (left > right) 
    {
        //El elemento no esta en la lista
        return -1;
    }

    //Calcular el elemento central
    int mid = left + (right - left) / 2;

    if(arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        //Elemento buscado es menor que el mid y por lo tanto buscamos en la mitad izquierda de la lista
        return binarySearch(arr, target, left, mid -1);
    }
    else if (arr[mid] < target)
    {
        //Elemento buscado es mayor que el mid y por lo tanto buscamos en la mitad derecha de la lista
        return binarySearch(arr, target, mid + 1 , right);
    }
}
