#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <stdint.h>

#include "individual.h"

class Population
{

public:
    Population(uint32_t population_n, const char *target_genome, uint32_t target_genome_size);
    void print_info(void);
    void repopulate_next_gen (std::string * prev_fittest_genome, uint32_t genome_size);
    Individual* get_best_individual(void);

private:
	uint32_t population_size;
	const char *target_genome;
	uint32_t target_genome_size;
    std::vector<Individual> population;

protected:
};

