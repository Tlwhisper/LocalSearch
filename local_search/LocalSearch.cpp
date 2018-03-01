#include "LocalSearch.h"
#include <iostream>

LocalSearch::LocalSearch(int n_iterations) {
    this->n_iterations = n_iterations;
}

shared_ptr<State> LocalSearch::search(State* initial_state, bool verbose) {
    state = shared_ptr<State>(initial_state);
    best_state = shared_ptr<State>(state);
    history.push_back(initial_state->get_score());
    if(verbose) {
        cout << "Initial state with score: " << initial_state->get_score() << endl;
    }

    bool stopped = false;
    int total_iterations = 0;

    for(int i = 0; i < n_iterations && !stopped; ++i) {
        if(verbose) {
            cout << "Iteration: " << total_iterations << endl;
        }

        shared_ptr<State> next_state = get_next_state(i);

        if(next_state == nullptr) {
            break;
        }

        bool needs_sync = next_state == state;

        state = next_state;
        if(needs_sync) {
            state->sync();
        }
        history.push_back(state->get_score());

        if(state->get_score() > best_state->get_score()) {
            if(verbose) {
                cout << "Found better state with score: " << best_state->get_score() << endl;
            }
            best_state = state;
        }

        if(verbose && i == n_iterations - 1) {
            cout << "Do you want to stop the search at iteration " << total_iterations
                 << " with a local optimum of " << best_state->get_score() << " ?" << endl;
            char c = ' ';
            while(c != 'y' and c != 'n') {
                cin >> c;
            }
            if(c == 'y') {
                stopped = true;
            } else {
                i = -1;
            }
        }

        total_iterations++;
    }

    return best_state;
}

list<double> LocalSearch::get_history() {
    return history;
}

void LocalSearch::print_history() {
    for(double score : history) {
        cout << score << endl;
    }
}