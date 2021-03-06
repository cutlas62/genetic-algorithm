#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <stdint.h>
#include <algorithm>

#include "individual.h"

class Population
{

public:
    Population(uint32_t population_n, std::string *target_genome, uint32_t target_genome_size);
    void print_info(void);
    void repopulate_next_gen (void);
    Individual* get_best_individual(void);
    void sort_by_fitness (void);
    std::vector<Individual> * get_population (void);

private:
	uint32_t population_size;
	std::string *target_genome;
	uint32_t target_genome_size;
    std::vector<Individual> population;

protected:
};

bool compare_by_fitness (Individual ind1, Individual ind2);

