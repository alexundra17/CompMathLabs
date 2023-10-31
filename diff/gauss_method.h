
#ifndef LABS_COMP_MATH_GAUSS_METHOD_H
#define LABS_COMP_MATH_GAUSS_METHOD_H

#include <vector>

using matrix = std::vector<std::vector<double>>;

std::vector<double> GaussMethod(matrix A, std::vector<double> b);
#endif //LABS_COMP_MATH_GAUSS_METHOD_H