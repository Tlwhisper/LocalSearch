#ifndef LOCAL_SEARCH_SIMULATE_ANNEALING_H
#define LOCAL_SEARCH_SIMULATE_ANNEALING_H

#include "LocalSearch.h"

class SimulatedAnnealing : public LocalSearch {

private:

    double temp;
    double lambda;

public:

    SimulatedAnnealing(int n_iterations, double temp, double lambda);

    shared_ptr<State> get_next_state();

};

#endif