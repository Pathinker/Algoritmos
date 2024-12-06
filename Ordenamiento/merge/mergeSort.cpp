#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void generarNumeros(vector<int>&arreglo, int cantidad);
void mostrarArreglo(vector<int>arreglo);
void mergeSort(vector<int>&arreglo, int inicio, int final);
void merge(vector<int>&Arreglo, int inicio, int mitad, int final);
void intercambio(int &a, int &b);

int main(){

    vector<int> numerosAleatorios;
    generarNumeros(numerosAleatorios, 5e2);
    mostrarArreglo(numerosAleatorios);
    mergeSort(numerosAleatorios, 0, numerosAleatorios.size() - 1);
    mostrarArreglo(numerosAleatorios);

    return 0;
}

void generarNumeros(vector<int>&arreglo, int cantidad){

    srand(time(NULL));
    
    for(int i = 0; i < cantidad; i++)
        arreglo.push_back(rand () % cantidad);
}

void mostrarArreglo(vector<int>arreglo){

    for (int i = 0; i < arreglo.size(); i++)
        cout << arreglo[i] << " ";

    cout << endl << endl;
}

void mergeSort(vector<int>&arreglo, int inicio, int final){

    if(final > inicio){

        int mitad = inicio + (final - inicio) / 2;

        mergeSort(arreglo, inicio, mitad);
        mergeSort(arreglo, mitad + 1, final);
        merge(arreglo, inicio, mitad, final);
    }
}

void merge(vector<int>&arreglo, int inicio, int mitad, int final){

    int i, j, k;
    int elementosIzquierda = mitad - inicio + 1;
    int elementosDerecha = final - mitad;

    vector<int>arregloIzquierda(elementosIzquierda);
    vector<int>arregloDerecha(elementosDerecha);

    for(i = 0; i < elementosIzquierda; i++)
        arregloIzquierda[i] = arreglo[inicio + i];
    
    for(i = 0; i < elementosDerecha; i++)
        arregloDerecha[i] = arreglo[i + mitad + 1];

    i = 0;
    j = 0;
    k =  inicio;
    
    while(i < elementosIzquierda && j < elementosDerecha){

        if(arregloIzquierda[i] <= arregloDerecha[j]){

            arreglo[k] = arregloIzquierda[i];
            i++;
        }
        else{

            arreglo[k] = arregloDerecha[j];
            j++;

        }
        k++;
    }

    while(i < elementosIzquierda){

        arreglo[k] = arregloIzquierda[i];
        i++;
        k++;
    }

    while(j < elementosDerecha){

        arreglo[k]= arregloDerecha[j];
        j++;
        k++;
    }
}

void intercambio(int &a, int &b){

    int auxiliar = a;
    a = b;
    b = auxiliar;
}