#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

// Función cambio: devuelve el vector solución x^ (número de monedas de cada tipo)
int* cambio(const std::vector<int>& v, int N, int M) {
    // Matriz de tamaño N x (M+1)
    std::vector<std::vector<int>> dp(N, std::vector<int>(M + 1, std::numeric_limits<int>::max()));

    // Columna 0 = 0 monedas para devolver 0
    for (int i = 0; i < N; i++) dp[i][0] = 0;

    // Llenamos la primera fila: usando solo la primera moneda
    for (int j = 1; j <= M; j++) {
        if (j >= v[0] && dp[0][j - v[0]] != std::numeric_limits<int>::max())
            dp[0][j] = 1 + dp[0][j - v[0]];
    }

    // Llenamos el resto de la tabla
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            int opcion1 = dp[i - 1][j]; // no usamos la moneda i
            int opcion2 = std::numeric_limits<int>::max(); // usamos la moneda i
            if (j >= v[i] && dp[i][j - v[i]] != std::numeric_limits<int>::max()) {
                opcion2 = 1 + dp[i][j - v[i]];
            }
            dp[i][j] = std::min(opcion1, opcion2);
        }
    }

    // Reconstrucción del vector solución x^
    int* x = new int[N];
    for (int i = 0; i < N; i++) x[i] = 0;

    int i = N - 1;
    int j = M;
    while (j > 0 && i >= 0) {
        if (i == 0) { // primera fila
            if (dp[i][j] != std::numeric_limits<int>::max() && j >= v[i]) {
                x[i]++;
                j -= v[i];
            } else {
                break;
            }
        } else {
            if (dp[i][j] == dp[i - 1][j]) {
                i--; // no usamos la moneda i
            } else {
                x[i]++;
                j -= v[i];
            }
        }
    }

    return x;
}

int main() {
    std::vector<int> monedas = {1, 4, 6};
    int M = 8;
    int N = monedas.size();

    int* solucion = cambio(monedas, N, M);

    std::cout << "Cantidad a devolver: " << M << std::endl;
    std::cout << "Vector de monedas: ";
    for (int c : monedas) std::cout << c << " ";
    std::cout << std::endl;

    std::cout << "Solución óptima (número de monedas de cada tipo): ";
    for (int i = 0; i < N; i++) std::cout << solucion[i] << " ";
    std::cout << std::endl;

    // Liberamos memoria dinámica
    delete[] solucion;

    return 0;
}

