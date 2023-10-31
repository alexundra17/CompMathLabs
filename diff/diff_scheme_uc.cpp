

#include <vector>
#include "cmath"
#include "factorial.h"
#include "gauss_method.h"

/***
 * Метод, вычисляющий коэффициенты в n-точечном шаблоне для производной (в долях шага шаблона h)
 * @param points - коэффициенты, при h для каждой точки в шаблоне
 * @return коэффициенты в n-точечном шаблоне для производной (в долях шага шаблона h)
 */
[[nodiscard]] std::vector<double> firstDer(const std::vector<double>& points) noexcept{
    matrix A(points.size());
    for (int i = 0; i < points.size(); i++)
        A[i].resize(points.size());

    for (int col = 0; col<points.size(); col++){
        A[0][col] = 1;
    }
    for (int row=1; row<points.size(); row++){
        for (int col=0; col<points.size(); col++){
            A[row][col] = std::pow(points[col],row)/fact(row);
        }
    }

    std::vector<double> b(points.size());
    for (int i = 0; i<points.size(); i++){
        b[i] = 0;
    }
    b[1] = 1;
    return GaussMethod(A, b);
}