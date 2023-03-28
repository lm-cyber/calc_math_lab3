
#ifndef TRAPEZOIDAL_RULE_H
#define TRAPEZOIDAL_RULE_H
#include <cmath>
#include <vector>

typedef double (*func)(double);

bool find_discontinuities(func f, double left, double right, size_t n,
                          std::vector<double> &points);
double trapezoidal_integration(func f, double left, double right, size_t n,
                               std::vector<double> &points);
#endif
