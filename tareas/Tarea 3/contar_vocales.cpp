//suma_digitos.cpp
//Lectura de texto y suma de sus vocales.
//Imprime el conteo de las vocales sin acentos. Indiferente a mayúsculas y minúsculas.
//
//Compilar: g++ -o contar_vocales contar_vocales.cpp
//Ejecutar: ./contar_vocales

#include <iostream>
#include <string>
#include <cctype> // para tolower (volver todos los caracteres a minúsculas)

int main() {
    std::string linea;
    std::getline(std::cin, linea);

    int contador = 0;

    for (char c : linea) {
        c = std::tolower(c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    std::cout << contador << std::endl;

    return 0;
}