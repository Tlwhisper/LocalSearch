#include "State.h"

class LocalSearch {

private:

    int n_iterations;

    State state;
    State best_state;

    list<double> history;

public:

    LocalSearch(int n_iterations);

    State search(const State& initial_state);

    State search(const State& initial_state, bool verbose, int interval);

    State get_next_state();

    list<double> get_history();

    void plot_history();

};