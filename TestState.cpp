#include "TestState.h"
using namespace std;

TestState::TestState(ifstream& input) {

}


list<shared_ptr<State>> TestState::generate_children() {
    list<shared_ptr<State>> children;

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

shared_ptr<State> TestState::generate_random_child() {
    return generate_children().back();
}

double TestState::get_score() const {
    return value;
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