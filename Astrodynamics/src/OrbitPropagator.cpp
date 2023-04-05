#include "OrbitPropagator.h"

using namespace kharsair::astk;

void OrbitPropagator::acceleration_ode(
    const std::vector<double>& state_vector, 
    std::vector<double>& state_vecotr_dot,
    const double& t) {

    state_vecotr_dot[0] = state_vector[3];
	state_vecotr_dot[1] = state_vector[4];
	state_vecotr_dot[2] = state_vector[5];

	auto denominator = std::pow(
        std::sqrt(
            std::inner_product(
                state_vector.begin(), 
                state_vector.begin() + 3, 
                state_vector.begin(), 
                0.0)), 
                3);

	state_vecotr_dot[3] = -central_body_mu * state_vector[0] / denominator;
	state_vecotr_dot[4] = -central_body_mu * state_vector[1] / denominator;
	state_vecotr_dot[5] = -central_body_mu * state_vector[2] / denominator;
}

OrbitPropagator::OrbitPropagator(
                        const std::vector<double> initial_state,
                        const double& central_body_mu,
                        const double& timespan,
                        const double& timestep) 
                        : 
    state_vector_size(initial_state.size()),
    central_body_mu(central_body_mu),
    timespan(timespan),
    timestep(timestep),
    n_step(timespan / timestep),
    current_step(0)
    {
        store.resize(state_vector_size);
        k1.resize(state_vector_size);
        k2.resize(state_vector_size);
        k3.resize(state_vector_size);
        k4.resize(state_vector_size);

        states.resize(n_step, std::vector<double>(state_vector_size, -1.));
        states[0] = initial_state;

        current_time = 0.0;

        times.resize(n_step, -1.);
        times[0] = current_time;

        current_step = 1;
}

void OrbitPropagator::rk4_step() {
    const std::vector<double>& current_state = states.at(current_step-1);

    acceleration_ode(current_state, k1, current_time);
    for (int i = 0; i < state_vector_size; i++)
        store[i] = current_state[i] + k1[i] * timestep / 2.0;
  
    acceleration_ode(store, k2, current_time);
    for (int i = 0; i < state_vector_size; i++)
        store[i] = current_state[i] + k2[i] * timestep / 2.0;

    acceleration_ode(store, k3, current_time);
    for (int i = 0; i < state_vector_size; i++)
        store[i] = current_state[i] + k3[i] * timestep;

    acceleration_ode(store, k4, current_time);
	for (int i = 0; i < state_vector_size; i++) 
		states[current_step][i] = 
            current_state[i] + 
            (k1[i] + 2.0 * k2[i] + 2.0 * k3[i] + k4[i]) * timestep / 6.0;
    
    current_time += timestep;
    times[current_step] = current_time;

    current_step++;
}

void OrbitPropagator::propagate_all() {
    while (current_step < n_step) rk4_step();
}

void OrbitPropagator::propagate_one_step() {
    rk4_step();
}


const std::vector<std::vector<double>>& OrbitPropagator::get_states() const{
    return this->states;
}
const std::vector<double>& OrbitPropagator::get_timestamps() const{
    return this->times;
}
const std::vector<double>& OrbitPropagator::get_most_recent_state() const{
    return states.at(current_step-1);
}

// bool OrbitPropagator::check_stop_condition(){}
