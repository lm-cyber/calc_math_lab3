#include "trapezoidal_rule.h"
#include "util.h"
#include <algorithm>
#define EPS 1
bool find_discontinuities(func f, double left, double right, size_t n,
                          std::vector<double> &points) {
    double h = (right - left) / n;
    bool fixed = true;

    for (size_t i = 0; i != n + 1; ++i) {
        double point = left + i * h;
        if (derivative(1, point + h / 4, f) < derivative(1, point - h / 4, f)) {
            points.push_back(point);
            if (delta(f(point - h / 4), f(point + h / 4)) > EPS) {
                fixed = false;
                break;
            }
        }
    }
    return fixed;
}

double trapezoidal_integration(func f, double left, double right, size_t n,
                               std::vector<double> &points) {
    double h = (right - left) / n;
    double sum = 0;
    double right_after = n * h + left;
    for (size_t i = 0; i != n + 1; ++i) {
        double point = left + i * h;
        if (std::find(points.begin(), points.end(), point) != points.end()) {
            sum += (f(point + h / 4) + f(point - h / 4)) / 2;
        } else {
            sum += f(point);
        }
    }
    if (std::find(points.begin(), points.end(), left) != points.end()) {
        sum -= (f(left + h / 4) + f(left - h / 4)) / 2;
    } else {
        sum -= f(left);
    }
    if (std::find(points.begin(), points.end(), right) != points.end()) {
        sum -= (f(right + h / 4) + f(right - h / 4)) / 2;
    } else {
        sum -= f(right);
    }

    return h * sum;
}
