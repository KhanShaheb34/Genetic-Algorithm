#include<bits/stdc++.h>
using namespace std;

class DNA {
    private:
        // The genetic sequence
        string genes;
        float fitness;
        
    public:
        // Constructor creates a random gene
        DNA() {
            // Seed for random function
            srand(time(NULL));
        }

        // Generate a random gene
        void generateGene(int stringLength) {
            genes = "";
            for (int i = 0; i < stringLength; i++) {
                genes += createRandomChar();
            }
        }

        // Getter for string from genes
        string getString() {
            return genes;
        }

        // Getter for fitness
        float getFitness() {
            return fitness;
        }

        // Generate random char
        char createRandomChar() {
            return (char) (rand() % 96) + 32;
        }

        // Method to calculate fitness
        void calculateFitness(string target) {
            int score = 0, length = target.length();
            for (int i = 0; i < length; i++) {
                if(target[i] == genes[i]) score++;
            }
            fitness = (float) score / (float) length;
        }

        // Crossover function
        DNA crossover(DNA partner) {
            int length = genes.length();
            DNA child;
            child.generateGene(length);
            int midPoint = rand() % length;

            for (int i = 0; i < length; i++) {
                if(i < midPoint) child.genes[i] = genes[i];
                else child.genes[i] = partner.genes[i];
            }
            
            return child;
        }

        // Mutate the DNA
        void mutate(int mutationRate) {
            for (int i = 0; i < genes.length(); i++) {
                if((rand() % 100) < mutationRate) genes[i] = createRandomChar();
            }
        }
};
