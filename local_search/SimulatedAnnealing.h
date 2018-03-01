#ifndef LOCAL_SEARCH_SIMULATE_ANNEALING_H
#define LOCAL_SEARCH_SIMULATE_ANNEALING_H

#include "LocalSearch.h"
#include <random>

class SimulatedAnnealing : public LocalSearch {

private:

    int limit;
    double k;
    double lambda;

    default_random_engine generator;
    uniform_real_distribution<double> distribution;

    double get_temperature(int iteration);

public:

    SimulatedAnnealing(int n_iterations, int steps, int k, double lambda);

    SimulatedAnnealing(int n_iterations, int steps, int k, double lambda, unsigned int seed);

    shared_ptr<State> get_next_state(int iteration);

};

#endif