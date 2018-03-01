#ifndef LOCAL_SEARCH_PIZZA_STATE_H
#define LOCAL_SEARCH_PIZZA_STATE_H

#include "local_search/State.h"
#include <fstream>

class TestState : public State {

private:

    bool decrease();

protected:
    bool increase();

public:

    int value = 0;

    TestState(ifstream& input);

    list<shared_ptr<State>> generate_children();

    shared_ptr<State> generate_random_child();

    double get_score() const;
};

#endif
