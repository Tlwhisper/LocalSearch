#include "LocalSearch.h"

LocalSearch::LocalSearch(int n_iterations) {
    this->n_iterations = n_iterations;
}

State LocalSearch::search(const State& initial_state) {
    return search(initial_state, false, interval);
}

State LocalSearch::search(const State& initial_state, bool verbose, int interval) {
    state = initial_state;
    best_state = initial_state;
    history.push_back(initial_state.get_score());
    if(verbose) {
        "Initial state with score: " << initial_state.get_score();
    }

    bool stopped = false;

    for(int i = 0; i < n_iterations && !stopped; ++i) {
        if(verbose) {
            cout << "Iteration: " << i << endl;
        }

        state = get_next_state();
        history.push_back(state.get_score());
        if(state.get_score() > best_state.get_score()) {
            if(verbose) {
                cout << "Found better state with score: " << best_state.get_score();
            }
            best_state = state;
        }

        if(interval > 0 && i % interval == 0) {
            cout << "Do you want to stop the search at iteration " << i 
            << " with a local optimum of " << best_state.get_score() << " ?" << endl;
            char c;
            cin >> c;
            if(c == 'n') {
                stopped = true;
            }
        }
    }

    return state;
}

list<double> get_history() {
    return history;
}

void plot_history() {

}