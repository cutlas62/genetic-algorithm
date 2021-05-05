#include "population.h"

Population::Population (vector<vector<uint8_t>> &bone, uint32_t nInd, uint32_t nAlp) {
    // TODO: Copy boneGenome, nIndividuals and nAlphas
    // TODO: createInitialPopulation()
    // TODO: calculate population's avg fitness
}

void Population::createInitialPopulation (void) {
    // TODO: Create random initial set of Individuals
}

void Population::repopulate (enum geneticOperator) {
    // TODO: Randomly pick a set of Individuals, the Alphas
    // TODO: Sort Alphas according to their fitness
    // TODO: Repopulate the population according to the genetic operator
}

double Population::getFitness (void) {
    return avgFitness;
}