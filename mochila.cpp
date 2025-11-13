#include <iostream>
#include <vector>
#include <algorithm>

// Función mochila: devuelve el vector solución x^ (0 o 1) y calcula beneficio máximo
int mochila(int N, const std::vector<int>& p, const std::vector<int>& b, int M, int* x) {
    // Crear tabla DP: filas = N+1, columnas = M+1
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, 0));

    // Llenar tabla
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= M; w++) {
            if (p[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], b[i - 1] + dp[i - 1][w - p[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Reconstrucción del vector solución
    int w = M;
    for (int i = N; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            x[i - 1] = 1;  // tomar el objeto
            w -= p[i - 1];
        } else {
            x[i - 1] = 0;  // no tomar
        }
    }

    return dp[N][M]; // beneficio máximo
}

int main() {
    int N = 4;
    std::vector<int> pesos = {1, 3, 2, 4};
    std::vector<int> beneficios = {10, 20, 15, 20};
    int M = 5;

    int* solucion = new int[N];
    int beneficioMax = mochila(N, pesos, beneficios, M, solucion);

    std::cout << "Peso máximo: " << M << std::endl;
    std::cout << "Beneficio máximo: " << beneficioMax << std::endl;
    std::cout << "Vector solución (objetos a tomar 1/0): ";
    for (int i = 0; i < N; i++) std::cout << solucion[i] << " ";
    std::cout << std::endl;

    delete[] solucion;
    return 0;
}

