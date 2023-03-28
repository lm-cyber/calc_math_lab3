#ifndef UTIL_H
#define UTIL_H

#include <cmath>

double derivative(int dif, double point, double (*f)(double),
                  double eps = 0.00001);
double delta(double x_k, double x_k_minus_one);

#endif
