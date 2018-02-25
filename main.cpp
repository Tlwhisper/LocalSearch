#include <iostream>
#include "local_search/SimulatedAnnealing.h"
#include "PizzaState.h"
#include "local_search/HillClimbing.h"

using namespace std;

int main() {

    HillClimbing local_search(1000);

    PizzaState* initial_state = new PizzaState();

    local_search.search(initial_state);

}