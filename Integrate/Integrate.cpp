#include <iostream>
#include <vector>
#include <functional>
#include <fstream>
#include <cmath>
#include"Integrate.h"


int main()
{
    double a = 0, b = 10;
    unsigned n = 3, s;
    double I1 = integrateOneSeg(a, b, n, SIN);
    std::cout << I1 << ' ' << sin(b) << std::endl;
    std::ofstream outfile("output_integrate.txt");
    for (int s = 1; s < 15; s++)
    {
        double I = integrate(a, b, n, s, SIN);
        std::cout << "s=" << s << " : " << I << ' ' << sin(b) << std::endl;
        outfile << (b - a) / s << " ";
        outfile << abs(I - sin(b));
        outfile << std::endl;

    }
    outfile.close();
}
