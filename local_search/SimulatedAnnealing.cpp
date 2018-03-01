#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing(int n_iterations, double temp, double lambda) : LocalSearch(n_iterations) {
    this->temp = temp;
    this->lambda = lambda;
}

SimulatedAnnealing::SimulatedAnnealing(int n_iterations, double temp, double lambda, unsigned int seed) : SimulatedAnnealing(n_iterations, temp, lambda) {
    generator.seed(seed);
}

shared_ptr<State> SimulatedAnnealing::get_next_state() {
    
}
