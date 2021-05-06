#include "population.h"
#include <unordered_set>
#include <algorithm>

#include <iostream>

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

// Custom comparator for Individuals according to their fitness
struct compareIndividuals {
    inline bool operator()(Individual &first, Individual &second) {
        return (first.getFitness() < second.getFitness());
    }
};

void Population::repopulate (geneticOperator op) {
    // Sort the population according to their fitness
    sort(population.begin(), population.end(), compareIndividuals());

    // Select the fittest individuals
    vector<Individual> alphas;
    alphas.reserve(nAlphas);
    for(uint32_t i = 0; i < nAlphas; i++) {
        alphas.push_back(population[i]);
    }

    // Repopulate the population according to the genetic operator
    population.clear();
    for (uint32_t i = 0; i < nAlphas; i++) {
        population.push_back(alphas[i]);
    }

    switch(op) {
    case RANDOMIZE:
        for (uint32_t i = nAlphas; i < nIndividuals; i++) {
            population.push_back(Individual(boneGenome));
        }

        break;

    case MUTATION:


        break;

    case BREEDING:

        break;
    }
}

double Population::getFitness (void) {
    return avgFitness;
}

void Population::createInitialPopulation (void) {
    // Create random initial set of Individuals
    population.reserve(nIndividuals);
    for (uint32_t i = 0; i < nIndividuals; i++) {
        population.push_back(Individual(boneGenome));
    }
}

void Population::updateAvgFitness (void) {
    // Calculate the avg fitness of all the individuals of this generation
    avgFitness = 0;
    for (Individual &i : population) {
        avgFitness += (double)i.calculateFitness() / nIndividuals;
    }
}

