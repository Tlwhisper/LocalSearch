#include <iostream>
#include "local_search/SimulatedAnnealing.h"
#include "TestState.h"
#include "local_search/HillClimbing.h"

using namespace std;

int main() {

    HillClimbing local_search(1000);

    TestState* initial_state = new TestState();

    local_search.search(initial_state, true);

}