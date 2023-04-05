#pragma once
#ifndef ORBIT_PROPAGATOR_H
#define ORBIT_PROPAGATOR_H

#include <cstdint>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
#include <numeric>

namespace kharsair::astk {
    
    class OrbitPropagator {
    public:
        OrbitPropagator(const std::vector<double> initial_state,
                        const double& central_body_mu,
                        const double& timestamp,
                        const double& timestep);

        OrbitPropagator(const OrbitPropagator& propagator) = delete;

        void propagate_all();
        void propagate_one_step();
        void set_stop_condition();
        bool check_stop_condition();
        void set_perturbation();
        void set_config();
    
    public:
        const std::vector<std::vector<double>>& get_states() const;
        const std::vector<double>& get_timestamps() const;
        const std::vector<double>& get_most_recent_state() const;
        
    protected:
        void acceleration_ode(
            const std::vector<double>& prev_state,
            std::vector<double>& state_vecotr_dot,
            const double& t);

        void rk4_step();

    private:
        std::vector<std::vector<double>> states;
        std::vector<double> times;

        uint32_t state_vector_size;
        double central_body_mu;
        double timespan;
        double timestep;

        std::vector<double> store, k1, k2, k3, k4;
        
        uint32_t n_step;

        uint32_t current_step;
        double current_time;
    };
}


#endif