#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing(int n_iterations, int limit, double temp, double lambda) : LocalSearch(n_iterations) {
    this->limit = limit;
    this->temp = temp;
    this->lambda = lambda;

    this->generator.seed(time(nullptr));
    this->distribution = uniform_real_distribution<double>(0, 1);
}

SimulatedAnnealing::SimulatedAnnealing(int n_iterations, int limit, double temp, double lambda, unsigned int seed) : SimulatedAnnealing(n_iterations, limit, temp, lambda) {
    generator.seed(seed);
}

shared_ptr<State> SimulatedAnnealing::get_next_state(int iteration) {

    shared_ptr<State> next_state = nullptr;
    double temp = get_temperature(iteration);

    if(temp <= 0) {
        return next_state;
    }

    for(int i = 0; i < limit && next_state == nullptr; ++i) {
        shared_ptr<State> child = state->generate_random_child();
        if(child == nullptr) {
            return next_state;
        }

        double delta_energy = child->get_score() - state->get_score();
        double rand_value = distribution(generator);

        bool accept_state = true;

        if(delta_energy > 0.0 || accept_state) {
            next_state = child;
        }
    }

    return next_state;
}

double SimulatedAnnealing::get_temperature(int iteration) {

    return 1;
}
