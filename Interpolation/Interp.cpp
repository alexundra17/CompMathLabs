#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include"interp.h"

int main()
{
    const int j_max = 6;
    std::vector <double> ox, error, length;
    double step = 0.0625;
    for (int j = 0; j < j_max; j++) {
        std::vector <double> x, vect;
        double l = pow(2, j) * step;
        ox.push_back(l);

        int N = 4;
        //равномерное распределение узлов
    //    for (int i = 0; i < N; i++) {
    //        x.push_back(i * l / (N - 1));
    //        vect.push_back(exp(x[i]));
    //    }

    //    NewtonianInterpolator A(x, vect);

    //    double delta_max = 0;
    //    for (int k = 0; k < 1000; k++) {
    //        double theory = exp(k * l / 999);
    //        double real = A.interpolate(k * l / 999);
    //        double delta = theory - real;
    //        if (delta < 0) delta = delta * (-1);
    //        if (delta > delta_max) delta_max = delta;
    //    }
    //    error.push_back(delta_max);
    //    length.push_back(l);

    //}
    //std::ofstream outfile("output_interp_uni_5.txt");
    //for (int i = 0; i < j_max; i++) {
    //    std::cout << length[i] << ' ' << error[i] << std::endl;
    //    outfile << length[i] << " ";
    //    outfile << error[i];
    //    outfile << std::endl;

    //}
    //outfile.close();
  //Чебышевское распределение узлов
        for (int i = 0; i < N; i++) {
            double pi = std::acos(-1);
            x.push_back(l / 2 + l / 2 * std::cos(pi * (2 * i + 1) / (2 * N + 2)));
            vect.push_back(exp(x[i]));
        }

        NewtonianInterpolator A(x, vect);

        double delta_max = 0;
        for (int k = 0; k < 1000; k++) {
            double theory = exp(k * l / 999);
            double real = A.interpolate(k * l / 999);
            double delta = theory - real;
            if (delta < 0) delta = delta * (-1);
            if (delta > delta_max) delta_max = delta;
        }
        error.push_back(delta_max);
        length.push_back(l);

    }
    std::ofstream outfile("output_interp_ch_4.txt");
    for (int i = 0; i < j_max; i++) {
        std::cout << length[i] << ' ' << error[i] << std::endl;
        outfile << length[i] << " ";
        outfile << error[i];
        outfile << std::endl;

    }
    outfile.close();
}