#ifndef DYV_H
#define DYV_H

#include <vector>
#include <iostream>

// ===============================
// Búsqueda Binaria (Ascendente)
// ===============================
template <typename T>
int BusquedaBinaria(const T& x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) return -1;
    int mid = ini + (fin - ini) / 2;
    if (v[mid] == x) return mid;
    else if (v[mid] > x) return BusquedaBinaria(x, v, ini, mid - 1);
    else return BusquedaBinaria(x, v, mid + 1, fin);
}

// ===============================
// Búsqueda Binaria (Descendente)
// ===============================
template <typename T>
int BusquedaBinaria_INV(const T& x, const std::vector<T>& v, int ini, int fin) {
    if (ini > fin) return -1;
    int mid = ini + (fin - ini) / 2;
    if (v[mid] == x) return mid;
    else if (v[mid] < x) return BusquedaBinaria_INV(x, v, ini, mid - 1);
    else return BusquedaBinaria_INV(x, v, mid + 1, fin);
}

// ===============================
// QuickSort
// ===============================

// Partition: divide el vector usando el último elemento como pivote
template <typename T>
int Partition(std::vector<T>& v, int ini, int fin) {
    T pivot = v[fin]; // pivote = último elemento
    int i = ini - 1;

    for (int j = ini; j <= fin - 1; j++) {
        if (v[j] <= pivot) { // elementos <= pivote a la izquierda
            i++;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[fin]); // poner pivote en su posición final
    return i + 1;
}

// QuickSort recursivo
template <typename T>
void QuickSort(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pi = Partition(v, ini, fin);
        QuickSort(v, ini, pi - 1);
        QuickSort(v, pi + 1, fin);
    }
}

#endif // DYV_H

