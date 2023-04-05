#include <AstrodynamicsTool.h>

using namespace kharsair::astk;

std::vector<double> extract_state_xs(const OrbitPropagator& propagator) {
    const std::vector<std::vector<double>>& states = propagator.get_states();
    std::vector<double> xs;
    xs.resize(states.size());
    std::transform(states.begin(), states.end(), xs.begin(), [] (auto state) {return state[0];});
    return xs; // Copy Elision
}

std::vector<double> extract_state_ys(OrbitPropagator* propagator) {
    const std::vector<std::vector<double>>& states = propagator->get_states();
    std::vector<double> ys;
    ys.resize(states.size());
    std::transform(states.begin(), states.end(), ys.begin(), [] (auto state) {return state[1];});
    return ys;
}

std::vector<double> extract_state_zs(OrbitPropagator* propagator) {
    const std::vector<std::vector<double>>& states = propagator->get_states();
    std::vector<double> zs;
    zs.resize(states.size());
    std::transform(states.begin(), states.end(), zs.begin(), [] (auto state) {return state[2];});
    return zs;
}