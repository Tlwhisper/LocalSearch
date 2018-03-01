#ifndef LOCAL_SEARCH_HILL_CLIMBING_H
#define LOCAL_SEARCH_HILL_CLIMBING_H

#include "LocalSearch.h"

class HillClimbing : public LocalSearch {

private:

public:

    HillClimbing(int n_iterations);

    shared_ptr<State> get_next_state(int iteration);

};

#endif