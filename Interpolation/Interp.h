#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>

class NewtonianInterpolator {
private:
    double** matrix;
    int size;

public:
    explicit NewtonianInterpolator(const std::vector<double>& x, const std::vector<double>& y) : size(int(x.size())) {
        matrix = new double* [size];
        for (int i = 0; i < size; i++) {
            matrix[i] = new double[i + 2];
            matrix[i][0] = x[i];
            matrix[i][1] = y[i];
        }
        for (int i = 2; i < size + 2; i++) {
            for (int j = i - 1; j < size; j++) {
                double p = (matrix[j][i - 1] - matrix[j - 1][i - 1]);
                double q = (matrix[j][0] - matrix[j - i + 1][0]);
                matrix[j][i] = p / q;
            }
        }
    }
    [[nodiscard]] double interpolate(double x) const {
        double func = matrix[size - 1][size];
        for (int i = 1; i < size; i++) {
            double p = matrix[size - i - 1][size - i];
            func = func * (x - matrix[size - i - 1][0]) + p;
        }
        return func;
    }
    ~NewtonianInterpolator() {
        for (unsigned int i = 0; i < size; i++) delete matrix[i];
        delete[]matrix;
    }
};