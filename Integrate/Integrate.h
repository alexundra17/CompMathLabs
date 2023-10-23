// Integrate.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <fstream>
#include <cmath>

[[nodiscard]] double integrateOneSeg(double a, double b, unsigned n, const std::function<double(double)>& func) noexcept
{

    std::vector<std::vector<double>> solution = { { sqrt(15.) / (-5.), 0, sqrt(15.) / 5.},
                                                  {(-1.) * sqrt((15. + 2. * sqrt(30.)) / 35.), (-1.) * sqrt((15. - 2. * sqrt(30.)) / 35.), sqrt((15. - 2. * sqrt(30.)) / 35.), sqrt((15. + 2. * sqrt(30.)) / 35.)},
                                                  {(-1.) * sqrt((35. + 2. * sqrt(70.)) / 63.), (-1.) * sqrt((35. - 2. * sqrt(70.)) / 63.), 0., sqrt((35. - 2. * sqrt(70.)) / 63.), sqrt((35. + 2. * sqrt(70.)) / 63.)} };

    std::vector<std::vector<double>> w = { {5. / 9., 8. / 9., 5. / 9.},
                                           {(18. - sqrt(30.)) / 36., (18. + sqrt(30.)) / 36., (18. + sqrt(30.)) / 36., (18. - sqrt(30.)) / 36.},
                                           {(322. + 13. * sqrt(70.)) / 900., (322. - 13. * sqrt(70.)) / 900., 128. / 225., (322. - 13. * sqrt(70.)) / 900., (322. + 13. * sqrt(70.)) / 900.} };

    double I = 0;
    n = n - 3;
    for (int i = 0; i < n + 3; i++) {
        I = I + func((b + a) / 2. + (b - a) / 2. * solution[n][i]) * w[n][i];
    }
    I = (b - a) / 2. * I;
    return I;
}


[[nodiscard]] double integrate(double a, double b, unsigned n, unsigned s, const std::function<double(double)>& func) noexcept
{
    double I = 0.;
    for (int i = 0; i < s; i++)
    {
        I = I + integrateOneSeg(a + ((b - a) / s) * i, a + ((b - a) / s) * (i + 1.), n, func);
    }
    return I;
}

double SIN(double x) {
    return std::sin(x);
}

// TODO: Reference additional headers your program requires here.
