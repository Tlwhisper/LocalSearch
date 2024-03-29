#include "HillClimbing.h"

HillClimbing::HillClimbing(int n_iterations) : LocalSearch(n_iterations) {

}

shared_ptr<State> HillClimbing::get_next_state(int iteration) {
    shared_ptr<State> max = state;

    for(const shared_ptr<State>& child : state->generate_children()) {
        if(max == nullptr || child->get_score() > max->get_score()) {
            max = child;
        }
    }

    return max;
}