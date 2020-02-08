#include<bits/stdc++.h>
#include "DNA.hpp"
using namespace std;

bool sortPopulation(DNA a, DNA b) {
    return a.getFitness() > b.getFitness();
}

int main(int argc, char const *argv[])
{
    // Seed for random numbers
    srand(time(NULL));

    // The string that will be generated
    string target = "Hello world";
    // Total number of DNAs and mutation rate
    int totalPopulation = 200, mutationRate = 10;

    vector<DNA> population(totalPopulation);

    for (int i = 0; i < totalPopulation; i++) {
        population[i].generateGene(target.length());
    }
    
    while (true) {
        // Calculating the fitness for all DNA
        for (int i = 0; i < totalPopulation; i++) {
            population[i].calculateFitness(target);
        }

        // Create a mating pool for selection
        vector<DNA> matingPool;
        for (int i = 0; i < totalPopulation; i++) {
            int freq = (int) (population[i].getFitness() * 100);
            for (int j = 0; j < freq; j++) {
                matingPool.push_back(population[i]);
            }
        }

        // Selecting parent and generating child
        for (int i = 0; i < totalPopulation; i++)
        {
            if(matingPool.size()) {
                int a = rand() % matingPool.size();
                int b = rand() % matingPool.size();
                DNA parentA = matingPool[a];
                DNA parentB = matingPool[b];
                DNA child = parentA.crossover(parentB);
                child.mutate(mutationRate);
                population[i] = child;
            }
        }

        // Sorting the population
        sort(population.begin(), population.end(), sortPopulation);
        cout << population[0].getString() << "\t" << population[0].getFitness() << endl;
    }

    return 0;
}
