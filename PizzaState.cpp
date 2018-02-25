//
// Created by Gonzalo Solera on 25/02/2018.
//

#include "PizzaState.h"
#include <iostream>
using namespace std;

PizzaState::PizzaState() = default;

list<shared_ptr<State>> PizzaState::generate_children() {
    return State::generate_children();
}

shared_ptr<State> PizzaState::generate_random_child() {
    return State::generate_random_child();
}

double PizzaState::get_score() const {
    return 0;
}

void PizzaState::sync() {
    cout << "sync" << endl;
}
