// MergeSortConsoleApplication.cpp : Implementacion del algoritmo de ordenación merge sort

#include <iostream>
#include <vector>

using namespace std;

//Funcion para realizar la ordenacion a través del merge sort (combinar dos sublista en un sola lista ordenada)
void merge(vector<int> &arr, int left, int mid, int right);

//Funcion recursiva para dividir y ordenar la lista usando Merge Sort
void mergeSort(vector<int>& arr, int left, int right);


int main()
{
    vector<int> numbers = {2,45,6,396,31,654,61,314,65,36,312,64,};

    cout << "Lista original: " << numbers << endl;

    //Ordenar la lista usando Merge Sort
    mergeSort(numbers, 0, numbers.size() - 1);
}

void merge(vector<int>& arr, int left, int mid, int right)
{
    //Declaracion de indices
    int i = left; //Indice inicial de la primera sublista
    int j = mid + 1; //Indice inicial de la segunda sublista
    int k = 0; //Indice inicial del vector aux

    //vector aux para almacenar los elementos ordenados
    vector<int> arrSort(right - left + 1);

    //Combinar las sublistas ordenadas en el vector aux
    while (i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            arrSort[k++] == arr[i++];
        }
        else
        {
            arrSort[k++] == arr[j++];
        }
    }

    //Copiar los elementos restantes de la primera sublista (si lo hay)
    while(i <= mid)
    {
        arrSort[k++] = arr[i++];
    }

    //Copiar los elementos restantes de la segunda sublista (si lo hay)
    while (i <= right)
    {
        arrSort[k++] = arr[j++];
    }

    //Copiar los elementos ordenador del vector aux al original
    for(int m = 0; m < k; m++)
    {
        arr[left + m] = arrSort[m];
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;

        //Ordenar la primera sublista
        mergeSort(arr, left, mid);

        //Ordenar la segunda sublista
        mergeSort(arr, mid, right);

        //Combinar las dos sublistas
        merge(arr, left, mid, right);
    }
}