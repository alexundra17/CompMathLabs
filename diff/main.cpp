
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
//#include "newtonian_interpolator.cpp"
#include "diff_scheme_uc.cpp"

int main() {

    std::vector<double> nodes = {-2, -1, 0, 1, 2};
    std::vector<double> res = firstDer(nodes);
    for (double re : res) {
        std::cout << re << " ";
    }
    std::cout << std::endl;
    double pi = acos(-1.0);
    double x0 = 1;
    double h = 1E-15;
    double proizv = 0;
    double proizv0 = std::exp(x0);
    std::cout << proizv0 << std::endl;

    std::ofstream lab1_data("data.csv");

    while (h < 10) {
        for (int i = 0; i < nodes.size(); i++)
            proizv += exp(x0 + nodes[i] * h) * res[i] / h;
        std::cout << "Epsilon: " << fabs(proizv - proizv0) << " step h = " << h << std::endl;
        lab1_data << fabs(proizv - proizv0) << " " << h << "\n";
        h = h * 10;
        proizv = 0;
    }
 

    lab1_data.close();
    return 0;


}