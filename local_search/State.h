#include <list>
#include "Operator.h"

using namespace std;

class State {

private:

    list<Operator> operators;

public:

    State();

    list<State> generate_children();

    list<State> generate_random_child();

    virtual double get_score() const = 0;

    // Sets this state as a current one in the local search
    virtual void sync() = 0;

};