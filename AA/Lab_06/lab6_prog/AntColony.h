//
// Created by mi on 07.12.2020.
//

#ifndef LAB6_PROG_ANTCOLONY_H
#define LAB6_PROG_ANTCOLONY_H

#include "Ant.h"
#include "GraphMatrix.h"
#include <cstring>

class AntColony {
//    int startVertex;
//    size_t antsAmount;
    std::vector<Ant> ants;
    size_t days;
    GraphMatrix<int> graphLength;
    GraphMatrix<double> graphPheromones;
    std::vector<int> shortestPath;
    size_t shortestLength;
//    GraphMatrix<double> graphChance; // Chance on visiting the vertexes
    const double lowPheromoneBorder = 1;
    const double highPheromoneBorder = 100;
    const double defaultPheromoneLevel = 10;
    double Q;
    double p;
    double alpha;
    double beta;
    double& averagePathLength;

public:
    AntColony(GraphMatrix<int> lengths, size_t days, double alpha, double beta, double Q, double p, double& averagePathLength);

    void updatePheromones(GraphMatrix<double>& graphPheromones, std::vector<Ant>& ants);

    std::vector<int> getShortestPath() const;
    size_t getShortestLength() const;
};


#endif //LAB6_PROG_ANTCOLONY_H
