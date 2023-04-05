#include <iostream>
#include <OrbitPropagator.h>
#include <AstrodynamicsTool.h>
#include <matplot/matplot.h>
#include <TrackingStationDashboard.h>

int main() {

    using namespace kharsair::astk;
    OrbitPropagator propagator1(
        {6378.0 + 500, 0., 0., 0., 7.7 * 1.3, 0.},
        3.986e5, 
        72 * 60 * 60 * 10,
        100
    );

    OrbitPropagator propagator2(
        {6378.0 + 500, 0., 0., 0., 7.7 * 1.35, 0.},
        3.986e5, 
        72 * 60 * 60 * 10,
        100
    );

    OrbitPropagator propagator3(
        {6378.0 + 500, 0., 0., 0., 7.7 * 1.6, 0.},
        3.986e5, 
        72 * 60 * 60 * 10,
        100
    );

    propagator1.propagate_all();
    propagator2.propagate_all();
    propagator3.propagate_all();

    using namespace matplot;
    
    auto l1 = plot3(extract_state_xs(&propagator1), extract_state_ys(&propagator1), extract_state_zs(&propagator1));
 
    auto l2 = plot3(extract_state_xs(&propagator2), extract_state_ys(&propagator2), extract_state_zs(&propagator2));

    auto l3 = plot3(extract_state_xs(&propagator3), extract_state_ys(&propagator3), extract_state_zs(&propagator3));
    show();

    // kharsair::astk::GroundTrackDashboard dashboard("hello");
    // dashboard.show(1080, 720, 1, 1);
    
    return 0;
}