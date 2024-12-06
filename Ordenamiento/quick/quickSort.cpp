#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void generarNumeros(vector<int>&arreglo, int cantidad);
void mostrarArreglo(vector<int>arreglo);
void quickSort(vector<int>&arreglo, int inicio, int final);
int pivote(vector<int>&Arreglo, int inicio, int final);
void intercambio(int &a, int &b);

int main(){

    vector<int> numerosAleatorios;
    generarNumeros(numerosAleatorios, 5e2);
    mostrarArreglo(numerosAleatorios);
    quickSort(numerosAleatorios, 0, numerosAleatorios.size() - 1);
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

void quickSort(vector<int>&arreglo, int inicio, int final){

    if(final > inicio){

        int mitadOrdenada = pivote(arreglo, inicio, final);

        quickSort(arreglo, inicio, mitadOrdenada - 1);
        quickSort(arreglo, mitadOrdenada + 1, final);
    }
}

int pivote(vector<int>&arreglo, int inicio, int final){

    int pivote = arreglo[inicio];
    int i = inicio + 1;

    for(int j = i; j <= final; j++){

        if(arreglo[j] < pivote){

            intercambio(arreglo[i], arreglo[j]);
            i++;
        }
    }

    intercambio(arreglo[inicio], arreglo[i - 1]);

    return i -1 ;
}

void intercambio(int &a, int &b){

    int auxiliar = a;
    a = b;
    b = auxiliar;
}