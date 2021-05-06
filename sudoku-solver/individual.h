#ifndef _INDIVIDUAL_H
#define _INDIVIDUAL_H

#include <vector>
#include <stdint.h>

using namespace std;

class Individual {
    vector<vector<uint8_t>> genome;
    uint32_t fitness;

public:
	// Constructor with randomly generatd genome
    Individual (vector<vector<uint8_t>> &bone);

    // Constructor with genome generated from two parents
    Individual (vector<vector<uint8_t>> &bone, 
						vector<vector<uint8_t>> &parent1, 
						vector<vector<uint8_t>> &parent2);

    uint32_t calculateFitness (void);
    uint32_t getFitness (void);
    vector<vector<uint8_t>> &getGenome (void);
};

#endif	// _INDIVIDUAL_H