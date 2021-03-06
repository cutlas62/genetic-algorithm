#ifndef _POPULATION_H
#define _POPULATION_H

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

    void createInitialPopulation (void);

public:
    Population (vector<vector<uint8_t>> &bone, uint32_t nInd, uint32_t nAlp);
    void repopulate (geneticOperator op);
    void updateAvgFitness (void);
    double getFitness (void);
};

#endif	// _POPULATION_H