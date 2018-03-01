#include <iostream>
#include <fstream>
#include "local_search/SimulatedAnnealing.h"
#include "TestState.h"
#include "local_search/HillClimbing.h"

using namespace std;

int main(int num_args, char* args[]) {

    if(num_args != 3) {
        cout << "usage: ./main input_file.in" << endl;
//        exit(1);
    }

    ifstream input;
    input.open(args[1]);

    HillClimbing local_search(1000);

    TestState* initial_state = new TestState(input);

    shared_ptr<TestState> result = std::static_pointer_cast<TestState>(local_search.search(initial_state, false));
    local_search.print_history();

    cout << result->value << endl;

}