//busqueda_dos_en_dos.cpp
//Busqueda de un objetivo en una lista de valores ordenados con método de dos en dos con retroceso.
//Retorna el índice (base 0) del objetivo, o -1 si no se encuentra.
//
//Compilar: g++ -o busqueda_dos_en_dos busqueda_dos_en_dos.cpp
//Ejecutar: ./busqueda_dos_en_dos

#include <iostream>
#include <vector>
#include <algorithm> // necesario para max y min


int busqueda_dos_en_dos(const std::vector<int>& lista, int n, int objetivo) {
    int i = 0;

    // Avanzar de 2 en 2 mientras el elemento sea menor al objetivo
    while (i < n && lista[i] < objetivo) {
        i = i + 2;
    }

    // Retroceder 1 posición
    i = i - 1;

    // Revisar hasta 2 posiciones: i y i+1
    int inicio = std::max(0, i);
    int fin = std::min(i + 1, n - 1);

    for (int j = inicio; j <= fin; j++) {
        if (lista[j] == objetivo) {
            return j; // primera ocurrencia en lo revisado
        }    
    }

    return -1; // no encontrado
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> lista(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lista[i];
    }

    int objetivo;
    std::cin >> objetivo;

    int resultado = busqueda_dos_en_dos(lista, n, objetivo); 
    std::cout << resultado << std::endl;

    return 0;
}
