#ifndef LOCAL_SEARCH_SIMULATE_ANNEALING_H
#define LOCAL_SEARCH_SIMULATE_ANNEALING_H

#include "LocalSearch.h"
#include <random>

class SimulatedAnnealing : public LocalSearch {

private:

    double temp;
    double lambda;

    default_random_engine generator;

public:

    SimulatedAnnealing(int n_iterations, double temp, double lambda);

    SimulatedAnnealing(int n_iterations, double temp, double lambda, unsigned int seed);

    shared_ptr<State> get_next_state();

};

#endif