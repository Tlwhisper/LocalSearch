#include <list>

using namespace std;

class State {

private:

public:

    State();

    double get_score();

    list<State> generate_children();

    list<State> generate_random_child();

};