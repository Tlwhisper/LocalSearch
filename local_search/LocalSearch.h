#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include "State.h"

using namespace std;

class LocalSearch {

private:
    list<double> history;

protected:
    int n_iterations;

    shared_ptr<State> state;
    shared_ptr<State> best_state;

public:

    LocalSearch(int n_iterations);

    shared_ptr<State> search(State* initial_state, bool verbose);

    list<double> get_history();

    void print_history();

    virtual shared_ptr<State> get_next_state(int iteration) = 0;

};

#endif