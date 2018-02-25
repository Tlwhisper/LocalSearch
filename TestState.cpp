//
// Created by Gonzalo Solera on 25/02/2018.
//

#include "TestState.h"
#include <iostream>
using namespace std;

TestState::TestState() = default;

list<shared_ptr<State>> TestState::generate_children() {
    list<shared_ptr<State>> children;

    shared_ptr<TestState> child = make_shared<TestState>(*this);
    child->increase();

    children.push_back(child);

    return children;
}

shared_ptr<State> TestState::generate_random_child() {
    return State::generate_random_child();
}

double TestState::get_score() const {
    return value;
}

void TestState::sync() {
}

bool TestState::increase() {
    if(value >= 100) {
        return false;
    }
    ++value;
    return true;
}

bool TestState::decrease() {
    --value;
}
