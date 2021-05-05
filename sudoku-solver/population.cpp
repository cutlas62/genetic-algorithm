#include "population.h"

Population::Population (vector<vector<uint8_t>> &bone, uint32_t nInd, uint32_t nAlp) :
boneGenome(9, vector<uint8_t> (9)) {
    // Copy boneGenome, nIndividuals and nAlphas
    for(uint8_t i = 0; i < 9; i++) {
        for(uint8_t j = 0; j < 9; j++) {
            boneGenome[i][j] = bone[i][j];
        }
    }
    nIndividuals = nInd;
    nAlphas = nAlp;

    // Create initial population
    createInitialPopulation();

    // Calculate population's avg fitness
    updateAvgFitness();
}


void Population::repopulate (enum geneticOperator) {
    // TODO: Randomly pick a set of Individuals, the Alphas
    // TODO: Sort Alphas according to their fitness
    // TODO: Repopulate the population according to the genetic operator
}

double Population::getFitness (void) {
    return avgFitness;
}

void Population::createInitialPopulation (void) {
    // Create random initial set of Individuals
    for (uint32_t i = 0; i < nIndividuals; i++) {
        population.push_back(Individual(boneGenome));
    }
}

void Population::updateAvgFitness (void) {
    // Calculate the avg fitness of all the individuals of this generation
    avgFitness = 0;
    for (Individual i : population){
    	avgFitness += i.calculateFitness() / nIndividuals;
    }
}