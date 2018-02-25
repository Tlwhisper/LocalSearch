#include <iostream>
#include "local_search/SimulatedAnnealing.h"
#include "TestState.h"
#include "local_search/HillClimbing.h"

using namespace std;

int main() {

    HillClimbing local_search(1000);

    TestState* initial_state = new TestState();

    shared_ptr<TestState> result = std::static_pointer_cast<TestState>(local_search.search(initial_state, false));
    local_search.print_history();

    cout << result->value << endl;

}