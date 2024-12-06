#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void generarNumeros(vector<int>&arreglo, int cantidad);
void mostrarArreglo(vector<int>arreglo);
void bubbleSort(vector<int>&arreglo);
void intercambio(int &a, int &b);

int main(){

    vector<int> numerosAleatorios;
    generarNumeros(numerosAleatorios, 5e2);
    mostrarArreglo(numerosAleatorios);
    bubbleSort(numerosAleatorios);
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

void bubbleSort(vector<int>&arreglo){

    char ordenamiento = 't';

    for(int i = 0; i < arreglo.size(); i++){

        ordenamiento = 't';

        for(int j = 0; j < arreglo.size() - 1; j++){

            if(arreglo[j] > arreglo[j + 1]){

                ordenamiento = 'f';
                intercambio(arreglo[j], arreglo[j + 1]);
            }
        }

        if(ordenamiento == 't'){

            return;
        }
    }
}

void intercambio(int &a, int &b){

    int auxiliar = a;
    a = b;
    b = auxiliar;
}