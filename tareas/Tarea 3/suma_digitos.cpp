//suma_digitos.cpp
//Lectura de un entero y suma de sus dígitos.
//Imprime la suma de los dígitos del entero leído.
//
//Compilar: g++ -o suma_digitos suma_digitos.cpp
//Ejecutar: ./suma_digitos

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int suma = 0;

    while (n > 0) {
        suma += n % 10;  // obtener el último dígito
        n = n / 10;      // eliminar el último dígito
    }

    std::cout << suma << std::endl;

    return 0;
}

