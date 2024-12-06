#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void generarNumeros(vector<int>&arreglo, int cantidad);
void mostrarArreglo(vector<int>arreglo);
void selectionSort(vector<int>&arreglo);
void intercambio(int &a, int &b);

int main(){

    vector<int> numerosAleatorios;
    generarNumeros(numerosAleatorios, 5e2);
    mostrarArreglo(numerosAleatorios);
    selectionSort(numerosAleatorios);
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

void selectionSort(vector<int>&arreglo){

    for(int i = 0; i < arreglo.size(); i++){

        int minimo = 10e8;
        int posicion = 0;

        for(int j = i; j < arreglo.size(); j++){

            if(minimo > arreglo[j]){

                minimo = arreglo[j];
                posicion = j;

            }
        }

        intercambio(arreglo[i], arreglo[posicion]);
    }
}

void intercambio(int &a, int &b){

    int auxiliar = a;
    a = b;
    b = auxiliar;
}