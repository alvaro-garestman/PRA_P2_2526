#ifndef DYV_H
#define DYV_H

#include <vector>

// ===============================
// Búsqueda Binaria (Ascendente)
// ===============================
template <typename T>
int BusquedaBinaria(const T& x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // No encontrado
    }

    int mid = ini + (fin - ini) / 2;

    if (v[mid] == x) {
        return mid;
    } else if (v[mid] > x) {
        return BusquedaBinaria(x, v, ini, mid - 1);
    } else {
        return BusquedaBinaria(x, v, mid + 1, fin);
    }
}

// ===============================
// Búsqueda Binaria (Descendente)
// ===============================
template <typename T>
int BusquedaBinaria_INV(const T& x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // No encontrado
    }

    int mid = ini + (fin - ini) / 2;

    if (v[mid] == x) {
        return mid;
    } else if (v[mid] < x) { // Invertimos la comparación
        return BusquedaBinaria_INV(x, v, ini, mid - 1);
    } else {
        return BusquedaBinaria_INV(x, v, mid + 1, fin);
    }
}

#endif // DYV_H

