#include <iostream>
#include <OrbitPropagator.h>
#include <matplot/matplot.h>
#include <GroundTrackDashboard.h>

int main() {

    kharsair::astk::OrbitPropagator propagator(
        {6378.0 + 500, 0., 0., 0., 7800., 0.},
        3.986e5, 
        90 * 60,
        100
    );

    propagator.propagator_orbit();

    const std::vector<std::vector<double>>& states = propagator.states;
    for (auto& state: states) {
        for (auto& elem: state) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }

    using namespace matplot;
    std::vector<double> t = iota(0, pi / 50, 10 * pi);
    std::vector<double> st = transform(t, [](auto x) { return sin(x); });
    std::vector<double> ct = transform(t, [](auto x) { return cos(x); });
    auto l = plot3(st, ct, t);
    show();

    kharsair::astk::GroundTrackDashboard dashboard("hello");
    dashboard.show(1080, 720, 1, 1);
    
    return 0;
}