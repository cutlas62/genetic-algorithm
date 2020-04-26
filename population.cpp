#include "population.h"



Population::Population(uint32_t population_n, const char *target_genome, uint32_t target_genome_size)
{

    for(uint32_t i = 0; i < population_n; i++)
    {
        Individual tmp(target_genome_size);
        tmp.calculate_fitness(target_genome, target_genome_size);
        population.push_back(tmp);
    }
}

void Population::print_info(void)
{
    std::vector<Individual>::iterator ptr;

    for(ptr = population.begin(); ptr != population.end(); ptr++)
    {
        Individual tmp = *ptr;
        tmp.print_info();
    }
}

Individual* Population::get_best_individual(void)
{
    std::vector<Individual>::iterator ptr;
    Individual * best_ptr;
    uint32_t best_fitness = UINT32_MAX;

    for(ptr = population.begin(); ptr != population.end(); ptr++)
    {
        Individual tmp = *ptr;
        if(tmp.get_fitness() < best_fitness){
        	best_fitness = tmp.get_fitness();
        	best_ptr = &(*ptr);
        }
    }
    return best_ptr;
}