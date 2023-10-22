// Spline.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class CubicSpline {
private:
    std::vector <double> X, a, b, c, d, m, l, z, alpha;
    double h;
    int n;


public:


    explicit CubicSpline(const std::vector<double>& xArr, const std::vector<double>& yArr) : n(yArr.size() - 1), h(xArr[1] - xArr[0])
    {
        a.insert(a.begin(), yArr.begin(), yArr.end());

        X.insert(X.begin(), xArr.begin(), xArr.end());
        b.resize(n);
        d.resize(n);
        c.resize(n + 1);
        l.resize(n + 1);
        m.resize(n + 1);
        z.resize(n + 1);

        l[0] = 1.0;
        z[0] = 0.0;
        m[0] = 0.0;
        alpha.push_back(0.0);

        for (int i = 1; i < n; i++)
            alpha.push_back((3.0 * (a[i + 1] - a[i]) - 3.0 * (a[i] - a[i - 1])) / h); //n-1 ýëåìåíòîâ

        for (int i = 1; i < n; i++) {
            l[i] = 2 * (xArr[i + 1] - xArr[i - 1]) - h * m[i - 1];
            m[i] = h / l[i];
            z[i] = (alpha[i] - h * z[i - 1]) / l[i];
        }

        l[n] = 1.0;
        z[n] = 0.0;
        c[n] = 0.0;

        for (int i = n - 1; i > 0; i--) {
            c[i] = z[i] - m[i] * c[i + 1];
            b[i] = (a[i + 1] - a[i]) / h - h * (c[i + 1] + 2.0 * c[i]) / 3.0;
            d[i] = (c[i + 1] - c[i]) / (3.0 * h);
        }
    }


    [[nodiscard]] double interpolate(double x) const
    {
        if (x == X[n]) return a[n];
        else
        {
            const unsigned int i = x / h;
            const double b_coeff = x - X[i];
            const double c_coeff = b_coeff * b_coeff;
            const double d_coeff = c_coeff * b_coeff;
            return a[i] + b[i] * b_coeff + c[i] * c_coeff + d[i] * d_coeff;
        }
    }
};
