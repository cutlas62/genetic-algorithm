#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <stdint.h>

#include "individual.h"

class Population{

public:
	Population(uint32_t population_n, const char * target_genome, uint32_t target_genome_size);
	void print_info(void);

private:
	std::vector<Individual> population;

protected:
};

