#include "individual.h"

enum geneticOperator {
    RANDOMIZE,
    MUTATION,
    BREEDING
};

class Population {

    vector<vector<uint8_t>> boneGenome;
    uint32_t nIndividuals;
    uint32_t nAlphas;
    vector<Individual> population;
    double avgFitness;

public:
    Population(vector<vector<uint8_t>> &bone, uint32_t nInd, uint32_t nAlp);
    void createInitialPopulation(void);
    void repopulate(enum geneticOperator);
};