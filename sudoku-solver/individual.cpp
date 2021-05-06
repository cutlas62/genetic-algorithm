#include "individual.h"
#include <stdlib.h>
#include <unordered_set>

Individual::Individual (vector<vector<uint8_t>> &bone) :
genome (9, vector<uint8_t> (9)) {
    // Fill grid randomly according to the boneGenome
    for(uint8_t i = 0; i < 9; i++) {
        for(uint8_t j = 0; j < 9; j++) {
            if (bone[i][j] == 0) {
                genome[i][j] = rand() % 9 + 1;	// Values from 1 to 9
            } else {
                genome[i][j] = bone[i][j];
            }
        }
    }

    // Set the initial fitness to the worst possible value
    fitness = numeric_limits<uint32_t>::max();
}

uint32_t Individual::calculateFitness (void) {
    /*
     * Let's define the fitness function as the sum of the sizes of three histograms.
     *
     * For the first histogram, we traverse all the rows and for each row, we see how many
     * uniques digits there are. We add the number of unique digits to the fitness value
     * and continue to the next row.
     *
     * And do the same for each column and then for each local 3x3 square
     */

    fitness = 9 * 9 + 9 * 9 + 9 * 9;	// Worst possible initial case is if all the numbers are the same
    unordered_set<uint8_t> digitHistogram;

    uint8_t i;
    uint8_t j;
    // For each row
    for (i = 0; i < 9; i++) {
        digitHistogram.clear();
        for(j = 0; j < 9; j++) {
            digitHistogram.insert(genome[i][j]);
        }
        fitness -= digitHistogram.size();
    }

    // For each column
    for (j = 0; j < 9; j++) {
        digitHistogram.clear();
        for(i = 0; i < 9; i++) {
            digitHistogram.insert(genome[i][j]);
        }
        fitness -= digitHistogram.size();
    }

    // For each local square
    for (uint8_t localI = 0; localI < 3; localI++) {
        for(uint8_t localJ = 0; localJ < 3; localJ++) {
            digitHistogram.clear();
            for(i = 0; i < 3; i++) {
                for(j = 0; j < 3; j++) {
                    digitHistogram.insert(genome[localI * 3 + i][localJ * 3 + j]);
                }
            }
            fitness -= digitHistogram.size();
        }
    }

    return fitness;
}

uint32_t Individual::getFitness (void){
	return fitness;
}