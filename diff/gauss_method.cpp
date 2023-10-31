
#include <iostream>
#include "limits"
#include "gauss_method.h"
#include "cmath"


int col_max(const std::vector<std::vector<double>>& A, int col, int n) {
    double max = std::abs(A[col][col]);
    int maxPos = col;
    for (int i = col + 1; i < n; ++i) {
        double element = std::abs(A[i][col]);
        if (element > max) {
            max = element;
            maxPos = i;
        }
    }
    return maxPos;
}

/***
 * Ищет решение СЛАУ Ах=b
 * @param A - матрица
 * @param b - правый столбец
 * @return решение
 */
std::vector<double> GaussMethod(matrix A, std::vector<double> b) {
    int n = (int)b.size();
    std::vector<double> res(n, 0);
    for (int i = 0; i < n; ++i) {
        A[i].push_back(b[i]);
    }
    const unsigned int num_cols = A[0].size();
    for (int i = 0; i < n - 1; ++i) {
        unsigned int imax = col_max(A, i, n);
        if (i != imax) {
            swap(A[i], A[imax]);
        }
        for (int j = i + 1; j < n; ++j) {
            double mul = -A[j][i] / A[i][i];
            for (int k = i; k < num_cols; ++k) {
                A[j][k] += A[i][k] * mul;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (std::abs(A[i][i]) < std::numeric_limits<double>::min()) throw std::exception();
        for (int j = i + 1; j < n; ++j) {
            A[i][n] -= A[i][j] * res[j];
        }
        res[i] = A[i][n] / A[i][i];
    }
    return res;

}