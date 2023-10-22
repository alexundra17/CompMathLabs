// Spline.cpp : Defines the entry point for the application.
//

#include "CubicSpline.h"

#include <iostream>
#include <vector>
#include <fstream>



int main()
{
    std::vector <double> error;
    double l = 10;


    std::ofstream outfile("output_spline.txt");
    for (int j = 0; j < 6; j++) {
        int step = 5;
        int N = step * pow(2, j);
        std::vector <double> x, y;
        for (int i = 0; i < N; i++) {
            x.push_back(i * l / (N - 1));
            y.push_back(exp(x[i]));
        }

        CubicSpline A(x, y);

        double delta_max = 0;
        for (int k = 0; k < 1000; k++) {
            double theory = exp(k * l / 999);
            double real = A.interpolate(k * l / 999);
            double delta = theory - real;
            if (delta < 0) delta = delta * (-1);
            if (delta > delta_max) delta_max = delta;
        }
        error.push_back(delta_max);
        std::cout << N << ' ' << delta_max << std::endl;
        outfile << N << " ";
        outfile << delta_max;
        outfile << std::endl;

    }
    outfile.close();
}

