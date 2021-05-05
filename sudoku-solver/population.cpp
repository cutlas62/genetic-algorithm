#include "population.h"

static void createInitialPopulation (void);
static void updateAvgFitness (void);


Population::Population (vector<vector<uint8_t>> &bone, uint32_t nInd, uint32_t nAlp) {
    // Copy boneGenome, nIndividuals and nAlphas
	for(uint8_t i = 0; i < 9; i++){
		for(uint8_t j = 0; j < 9; j++){
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

static void createInitialPopulation (void) {
    // TODO: Create random initial set of Individuals
}

static void updateAvgFitness (void) {
	// TODO: Calculate the avg fitness of all the individuals of this generation
}