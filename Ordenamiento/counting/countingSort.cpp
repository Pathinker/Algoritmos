#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void generarNumeros(vector<int>&arreglo, int cantidad);
void mostrarArreglo(vector<int>arreglo);
vector<int> countingSort(vector<int>arreglo, int maximo);

int main(){

    vector<int> numerosAleatorios;
    generarNumeros(numerosAleatorios, 5e2);
    mostrarArreglo(numerosAleatorios);
    numerosAleatorios = countingSort(numerosAleatorios, 5e2);
    mostrarArreglo(numerosAleatorios);

    return 0;
}

void generarNumeros(vector<int>&arreglo, int cantidad){

    srand(time(NULL));
    
    for (int i = 0; i < cantidad; i++)
        arreglo.push_back(rand () % cantidad);
}

void mostrarArreglo(vector<int>arreglo){

    for (int i = 0; i < arreglo.size(); i++)
        cout << arreglo[i] << " ";

    cout << endl << endl;
}

vector<int> countingSort(vector<int>arreglo, int maximo){

    vector<int>frecuencia(maximo + 1);
    vector<int>arregloResultante(arreglo.size());

    for (int i = 0; i <= maximo; i++)
        frecuencia[i] = 0;

    for (int i = 0; i < arreglo.size(); i++){

        int valor = arreglo[i];
        frecuencia[valor]++;
    }

    for (int i = 1; i <= maximo; i++){

        frecuencia[i] += frecuencia[i - 1];
    }

    for (int i = 0; i <= arreglo.size(); i++){

        int valor = arreglo[i];
        frecuencia[valor] --;
        int indice = frecuencia[valor] ;

        arregloResultante[indice] = valor;
    }

    return arregloResultante;
}