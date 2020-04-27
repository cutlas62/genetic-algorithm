#include "population.h"



Population::Population(uint32_t population_n, const char *_target_genome, uint32_t _target_genome_size)
{
    population_size = population_n;
    target_genome = _target_genome;
    target_genome_size = _target_genome_size;
    for(uint32_t i = 0; i < population_size; i++)
    {
        Individual tmp(target_genome_size);
        tmp.calculate_fitness(target_genome, target_genome_size);
        population.push_back(tmp);
    }
}


void Population::repopulate_next_gen (std::string *prev_fittest_genome, uint32_t genome_size)
{

    std::vector<Individual> last_gen = population;
    population.clear();

    std::string offspring_genome = {""};
    for(uint32_t i = 0; i < population_size; i++)
    {
        mate(&offspring_genome, genome_size, prev_fittest_genome, last_gen.at(i).get_genome());
        Individual new_ind(genome_size, &offspring_genome);
        new_ind.calculate_fitness(target_genome, target_genome_size);
        population.push_back(new_ind);
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

Individual *Population::get_best_individual(void)
{
    std::vector<Individual>::iterator ptr;
    Individual *best_ptr;
    uint32_t best_fitness = UINT32_MAX;

    for(ptr = population.begin(); ptr != population.end(); ptr++)
    {
        Individual tmp = *ptr;
        if(tmp.get_fitness() < best_fitness)
        {
            best_fitness = tmp.get_fitness();
            best_ptr = &(*ptr);
        }
    }
    return best_ptr;
}

std::vector<Individual> * Population::get_population (void){
    return &population;
}

void Population::sort_by_fitness (void){
    std::sort(population.begin(), population.end(), compare_by_fitness);
}


bool compare_by_fitness (Individual ind1, Individual ind2){
    return (ind1.get_fitness() < ind2.get_fitness());
}