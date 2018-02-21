#include <list>

using namespace std;

class State {

private:

public:

    State();

    list<State> generate_children();

    list<State> generate_random_child();

    virtual double get_score();

    // Sets this state as a current one in the local search
    virtual void sync() {}

};