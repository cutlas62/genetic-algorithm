#pragma once

#include <cstdlib>
#include <stdio.h>
#include <stdint.h>
#include <string>

class Individual
{
public:
	Individual (void);
    Individual (uint32_t genome_size);
    Individual (uint32_t genome_size, std::string * new_genome);
    void print_genome(void);
    void calculate_fitness(const char *target, uint32_t target_size);
    void print_info(void);
    uint32_t get_fitness (void);
    std::string * get_genome (void);
    void set_genome (std::string * new_genome);
private:
    std::string genome;
    uint32_t fitness;

protected:

};

void generate_random_genome(std::string *genome, uint32_t size);
void generate_mutated_genome(std::string *genome, uint32_t size, std::string *prev_genome, double p);
void mate (std::string *child_genome, uint32_t genome_size, std::string *parent_1_genome, std::string *parent_2_genome);