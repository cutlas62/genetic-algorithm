#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <iterator>


#include "individual.h"
#include "population.h"


#define POPULATION_SIZE     1000
#define N_GENERATIONS		10000

std::string target_genome = {"Test String with a bunch of characters !@#$%^&*()_+"};



int main(int argc, char *argv[])
{
    srand (time(NULL));


    Population pop(POPULATION_SIZE, &target_genome, target_genome.size());

    //pop.print_info();

    Individual *tmp = new Individual;
    pop.sort_by_fitness();
    *tmp = (pop.get_population())->at(0);

    printf("Generation 0:\t");
        tmp->print_info();

    for(uint32_t i = 1; i < N_GENERATIONS; i++)
    {
        pop.repopulate_next_gen();
        pop.sort_by_fitness();
        *tmp = (pop.get_population())->at(0);

        printf("Generation %d:\t", i);
        tmp->print_info();
        if(tmp->get_fitness() == 0){
        	break;
        }
    }


}

