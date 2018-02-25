//
// Created by Gonzalo Solera on 25/02/2018.
//

#ifndef LOCAL_SEARCH_PIZZA_STATE_H
#define LOCAL_SEARCH_PIZZA_STATE_H


#include "local_search/State.h"

class TestState : public State {

private:

    int value = 0;

    bool increase();
    bool decrease();

public:

    TestState();

    list<shared_ptr<State>> generate_children();

    shared_ptr<State> generate_random_child();

    double get_score() const;

    void sync();

};


#endif
