#include <cmath>
#include <matplot/matplot.h>

int main() {
    using namespace matplot;
    auto [X, Y] = meshgrid(iota(-8, .5, +8));
    auto Z = transform(X, Y, [](double x, double y) {
        double eps = std::nextafter(0.0, 1.0);
        double R = sqrt(pow(x, 2) + pow(y, 2)) + eps;
        return sin(R) / R;
    });
    mesh(X, Y, Z);

    wait();
    return 0;
}