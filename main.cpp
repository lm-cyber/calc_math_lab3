#include "trapezoidal_rule.h"
#include "util.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

double f1(double x) { return 1 / x; }
double f2(double x) { return std::sin(x); }
double f3(double x) { return 3 * x * x - 2 * x + 13; }
double f4(double x) { return std::fabs(x); }

int main() {
    std::cout.precision(std::numeric_limits<double>::max_digits10 - 1);
    std::vector<double> p;
    size_t choose;
    std::cout << "1)1/x\n2)sin(x)\n3)3*x^2-2*x+13\n4)|x|\n";
    std::cin >> choose;
    choose--;
    size_t n;
    double left, right;
    std::vector<func> f_vector = {f1, f2, f3, f4};
    std::cout << "left = ";
    std::cin >> left;
    std::cout << "right = ";
    std::cin >> right;
    std::cout << "n = ";
    std::cin >> n;

    if (find_discontinuities(f_vector[choose], left, right, n, p)) {
        std::cout << "result = "
                  << trapezoidal_integration(f_vector[choose], left, right, n,
                                             p);
        std::cout << "\n";
    } else {
        std::cout << "irreparable function break\n";
        return 1;
    }
    return 0;
}
