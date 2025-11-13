#include <iostream>
#include <vector>
#include <chrono>
#include "DyV.h"

int main() {
    std::vector<int> v = {5, 2, 9, 1, 5, 6};

    std::cout << "Vector original: ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    QuickSort(v, 0, v.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Vector ordenado: ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    std::chrono::duration<float, std::milli> duration = end - start;
    std::cout << "Tiempo QuickSort: " << duration.count() << " ms" << std::endl;

    return 0;
}

