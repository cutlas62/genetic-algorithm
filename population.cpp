#include "population.h"



Population::Population(uint32_t population_n, std::string *_target_genome, uint32_t _target_genome_size)
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


void Population::repopulate_next_gen (void)
{

    std::vector<Individual> last_gen = population;
    population.clear();

    // The fittest 5% of the previous generation will survive to the next one
    uint32_t n_survivors = 5 * last_gen.size() / 100;
    for(uint32_t i = 0; i < n_survivors; i++)
    {
        population.push_back(last_gen.at(i));
    }

    // The other 95% will mate with the fittest individual
    std::string offspring_genome = {""};
    Individual fittest_ind = last_gen.at(0);
    uint32_t genome_size = (fittest_ind.get_genome())->size();
    for(uint32_t i = n_survivors; i < population_size; i++)
    {
        mate(&offspring_genome, genome_size, fittest_ind.get_genome(), last_gen.at(i).get_genome());
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

std::vector<Individual> *Population::get_population (void)
{
    return &population;
}

void Population::sort_by_fitness (void)
{
    std::sort(population.begin(), population.end(), compare_by_fitness);
}


bool compare_by_fitness (Individual ind1, Individual ind2)
{
    return (ind1.get_fitness() < ind2.get_fitness());
}