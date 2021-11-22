#ifndef CUBESPLINE_H
#define CUBESPLINE_H
#include <vector>
#include <map>

struct Polinom
{
    double a, b, c, d, x_i, h; // S_i(x) = a + b(x - x_i) + (c_i / 2) *
                                //(x - x_i) ^ 2 + ( d / 2 ) * (x - x_i) ^ 3
};


class CubeSpline
{
private:
    std::vector<Polinom> spline;
    std::map<double, double> points;
public:
    CubeSpline(const std::map<double, double>& _points) : points(_points) {}

    void build();

    double f(double x);

    std::vector<std::vector<double>> get();
};

#endif // CUBESPLINE_H
