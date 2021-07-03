//
// Created by mi on 07.12.2020.
//

#ifndef LAB6_PROG_ANT_H
#define LAB6_PROG_ANT_H

#include <random>
#include "GraphMatrix.h"

class Ant {
    int startVortex;
    GraphMatrix<int>& graphLength;
    GraphMatrix<double>& graphPheromones;
    double alpha;
    double beta;
    int currentVortex;
    std::uniform_real_distribution<double>& urd;
    std::default_random_engine& dre;
    std::vector<int>& shortestPath;
    size_t& shortestLength;

public:
    size_t pathLength;
    std::vector<int> path;

    Ant(GraphMatrix<int>& lengths, GraphMatrix<double>& pheromones, int start, double a, double b,
        std::vector<int>& shortestPath, size_t& shortestLength,
        std::uniform_real_distribution<double>& urd, std::default_random_engine& dre);

    void runAnt();

};


#endif //LAB6_PROG_ANT_H
