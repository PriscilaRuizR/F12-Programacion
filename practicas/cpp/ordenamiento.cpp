//ordenamiento.cpp
//Ordenamiento de una lista de enteros con algoritmos de Burbuja, Selección y Merge Sort.
//Retorna la lista en orden de menor a mayor.
//
//Compilar: g++ ordenamiento.cpp -o ordenamiento
//Ejecutar: ./ordenamiento

#include <iostream>
#include <vector>
#include <string>
using namespace std; //Para simplificar la escritura y lectura del código sin std::.

void burbuja(vector<int>& arr) { //Definición de la función burbuja con el Algoritmo de Ordenamiento de Burbuja.
    int n = arr.size();

    for (int i = 0; i <= n - 2; i++) {
        bool intercambiado = false;

        for (int j = 0; j <= n - 2 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; // Realiza el intercambio de posiciones si hay un valor mayor que esté antes de uno de menor valor.
                intercambiado = true;
            }
        }

        if (!intercambiado) {
            break; // Optimización: lista ya ordenada, porque no hubo intercambio.
        }
    }
}

void seleccion(vector<int>& arr) {  //Definición de la función seleccion con el Algoritmo de Ordenamiento de Selección.
    int n = arr.size();

    for (int i = 0; i <= n - 2; i++) {
        int min_idx = i; // Punto de partida: asunción que el menor valor está en la posición i.

        for (int j = i + 1; j <= n - 1; j++) { //Ciclo de comparación para que j, de ser necesario, se actualice al valor mínimo.
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) { // El intercambio si i no corresponde al mínimo.
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

vector<int> mezclar(const vector<int>& izq, const vector<int>& der) { // Definición de la función mezclar para unir dos listas de enteros ya ordenados a una sola lista ordenada.
    vector<int> resultado;
    int i = 0, j = 0;

    while (i < izq.size() && j < der.size()) { // Ciclos mientras para guardar los valores ordenados en resultado vía la comparación de elementos en las listas.
        if (izq[i] <= der[j]) {
            resultado.push_back(izq[i]);
            i++;
        } else {
            resultado.push_back(der[j]);
            j++;
        }
    }

    while (i < izq.size()) { 
        resultado.push_back(izq[i]);
        i++;
    }

    while (j < der.size()) {
        resultado.push_back(der[j]);
        j++;
    }

    return resultado;
}

vector<int> mergesort(const vector<int>& arr) { //Definición de la función mergesort con el Algoritmo de Ordenamiento de Merge Sort.
    if (arr.size() <= 1) {
        return arr; // Caso Base: ya está ordenada la lista por estar vacía o tener un único elemento.
    }

    int medio = arr.size() / 2;

    vector<int> izquierda(arr.begin(), arr.begin() + medio); // Creacíón de la lista izquierda que llega hasta la mitad.
    vector<int> derecha(arr.begin() + medio, arr.end());  // Creacíón de la lista derecha que empieza a la mitad.

    izquierda = mergesort(izquierda); //Llamada recursiva para la lista izquierda.
    derecha = mergesort(derecha); //Llamada recursiva para la lista derecha.

    return mezclar(izquierda, derecha); //Llamanda a la función mezclar definida también para el Algoritmo de Ordenamiento de Selección.
}

int main() {
    string algoritmo; //Define que el nombre de la función del algoritmo de ordenamiento a usar sea tipo string al ser descrito.
    int n; //Define que la cantidad de números a ordenar sea un número entero.

    cin >> algoritmo >> n; //Pide el nombre del algoritmo y la cantidad de números a ordenar.

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    } 

    if (algoritmo == "burbuja") { //Llama la función burbuja si esa fue la solicitada por el usuario.
        burbuja(arr);
    }
    else if (algoritmo == "seleccion") { //Llama la función seleccion si esa fue la solicitada por el usuario.
        seleccion(arr);
    }
    else if (algoritmo == "mergesort") { //Llama la función mergesort si esa fue la solicitada por el usuario.
        arr = mergesort(arr);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }

    cout << endl;

    return 0; //Si se ejecutó todo y bien.
}