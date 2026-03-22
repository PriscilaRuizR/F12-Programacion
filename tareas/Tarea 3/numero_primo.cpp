//numero_primo.cpp
//Lectura de un número natural y determinación si es primo o compuesto mediante búsqueda de divisores.
//Imprime "primo" o "no primo" (compuesto).
//
//Compilar: g++ -o numero_primo numero_primo.cpp
//Ejecutar: ./numero_primo

#include <iostream>
#include <cmath>      //para sqrt(n)

int main() {
    int n;
    std::cin >> n;

    if (n == 2) {
        std::cout << "primo" << std::endl;
        return 0;
    }

    if (n % 2 == 0) {
        std::cout << "no primo" << std::endl;
        return 0;
    }

    bool esPrimo = true;

    for (int i = 3; i <= std::sqrt(n); i += 2) {     //Búsqueda de divisores impares empezando en 3 y terminando en la raíz cuadrada de n, para minimizar uso de recursos.
        if (n % i == 0) {
            esPrimo = false;
            break;
        }
    }

    if (esPrimo) {
        std::cout << "primo" << std::endl;
    } else {
        std::cout << "no primo" << std::endl;
    }

    return 0;
}