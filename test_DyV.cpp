#include <iostream>
#include <vector>
#include "DyV.h"

int main() {
    // Vector ascendente
    std::vector<int> v1 = {1, 3, 5, 7, 9, 11, 13};

    std::cout << "Búsqueda Binaria Ascendente:\n";
    int pos = BusquedaBinaria(7, v1, 0, v1.size() - 1);
    std::cout << "7 está en la posición: " << pos << std::endl;

    pos = BusquedaBinaria(2, v1, 0, v1.size() - 1);
    std::cout << "2 está en la posición: " << pos << " (no encontrado = -1)" << std::endl;

    // Vector descendente
    std::vector<int> v2 = {20, 15, 10, 5, 0, -5};

    std::cout << "\nBúsqueda Binaria Descendente:\n";
    pos = BusquedaBinaria_INV(10, v2, 0, v2.size() - 1);
    std::cout << "10 está en la posición: " << pos << std::endl;

    pos = BusquedaBinaria_INV(8, v2, 0, v2.size() - 1);
    std::cout << "8 está en la posición: " << pos << " (no encontrado = -1)" << std::endl;

    // Prueba con otro tipo de datos
    std::vector<char> v3 = {'a','c','e','g','i'};
    pos = BusquedaBinaria('e', v3, 0, v3.size() - 1);
    std::cout << "\n'Búsqueda Binaria Char':\n'e' está en la posición: " << pos << std::endl;

    return 0;
}

