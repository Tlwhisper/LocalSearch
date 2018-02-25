#include "LocalSearch.h"
#include <iostream>

LocalSearch::LocalSearch(int n_iterations) {
    this->n_iterations = n_iterations;
}

shared_ptr<State> LocalSearch::search(State& initial_state) {
    return search(initial_state, false, 0);
}

shared_ptr<State> LocalSearch::search(State& initial_state, bool verbose, int interval) {
    state = shared_ptr<State>(&initial_state);
    best_state = shared_ptr<State>(&initial_state);
    history.push_back(initial_state.get_score());
    if(verbose) {
        cout << "Initial state with score: " << initial_state.get_score();
    }

    bool stopped = false;

    for(int i = 0; i < n_iterations && !stopped; ++i) {
        if(verbose) {
            cout << "Iteration: " << i << endl;
        }

        shared_ptr<State> next_state = get_next_state();
        if(next_state == NULL) {
            break;
        }

        state = next_state;
        state->sync();
        history.push_back(state->get_score());

        if(state->get_score() > best_state->get_score()) {
            if(verbose) {
                cout << "Found better state with score: " << best_state->get_score();
            }
            best_state = state;
        }

        if(interval > 0 && i % interval == 0) {
            cout << "Do you want to stop the search at iteration " << i 
            << " with a local optimum of " << best_state->get_score() << " ?" << endl;
            char c;
            cin >> c;
            if(c == 'n') {
                stopped = true;
            }
        }
    }

    return state;
}

list<double> LocalSearch::get_history() {
    return history;
}

void LocalSearch::plot_history() {

}