//
// Created by Gonzalo Solera on 25/02/2018.
//

#include "TestState.h"
#include <iostream>
using namespace std;

TestState::TestState() = default;

list<shared_ptr<State>> TestState::generate_children() {
    list<shared_ptr<State>> children;

//    class Modifier : State::Modifier {
//
//        bool modify(State* state) {
//            return ((TestState*) state)->increase();
//        }
//
//    } modifier;

    shared_ptr<TestState> child = make_shared<TestState>(*this);
    if(child->increase()) {
        children.push_back(child);
        child = make_shared<TestState>(*this);
    }
    if(child->decrease()) {
        children.push_back(child);
        child = make_shared<TestState>(*this);
    }
    return children;
}

State* TestState::clone() {
    TestState* clone = new TestState;
    *clone = *this;

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
    return true;
}
