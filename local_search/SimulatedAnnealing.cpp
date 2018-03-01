#include "SimulatedAnnealing.h"
#include <math.h>

SimulatedAnnealing::SimulatedAnnealing(int n_iterations, int limit, int k, double lambda) : LocalSearch(n_iterations) {
    this->limit = limit;
    this->k = k;
    this->lambda = lambda;

    this->generator.seed(time(nullptr));
    this->distribution = uniform_real_distribution<double>(0, 1);
}

SimulatedAnnealing::SimulatedAnnealing(int n_iterations, int limit, int k, double lambda, unsigned int seed) : SimulatedAnnealing(n_iterations, limit, k, lambda) {
    generator.seed(seed);
}

shared_ptr<State> SimulatedAnnealing::get_next_state(int iteration) {

    double temp = get_temperature(iteration);
//    cout << temp << endl;

    if(temp <= 0) {
        return nullptr;
    }

    shared_ptr<State> child = state->generate_random_child();
    if(child == nullptr) {
        return nullptr;
    }

    double delta_energy = child->get_score() - state->get_score();
    double rand_value = distribution(generator);
    double prob_accept = 1.0 / (1.0 + exp(delta_energy / temp));
//    cout << prob_accept << endl;

    bool accept_state = rand_value > prob_accept;

    if(delta_energy > 0.0 || accept_state) {
        return child;
    } else {
        return state;
    }

    //for(int i = 0; i < limit && next_state == nullptr; ++i) {
    //}
}

double SimulatedAnnealing::get_temperature(int iteration) {
    double temp_d = (double)iteration / (limit * limit);
    double temp = k * exp(-1.0 * lambda * temp_d);
    return temp;
}
