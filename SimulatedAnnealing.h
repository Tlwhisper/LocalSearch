#include "LocalSearch.h"

class SimulatedAnnealing : public LocalSearch {

private:

    double temp;
    double lambda;

public:

    SimulatedAnnealing(double temp, int lambda);

};
