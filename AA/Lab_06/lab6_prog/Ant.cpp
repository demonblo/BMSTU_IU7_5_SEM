//
// Created by mi on 07.12.2020.
//

#include "Ant.h"

Ant::Ant(GraphMatrix<int>& lengths, GraphMatrix<double>& pheromones, int start, double a, double b,
        std::vector<int>& shortestPath, size_t& shortestLength,
        std::uniform_real_distribution<double>& urd, std::default_random_engine& dre) :
graphLength(lengths), graphPheromones(pheromones), startVortex(start),
currentVortex(startVortex), pathLength(0), alpha(a), beta(b), urd(urd), dre(dre),
shortestLength(shortestLength), shortestPath(shortestPath)
{
    path.push_back(start);
    runAnt();
}

void Ant::runAnt() {
    if (path.size() == graphLength.getRowsAmount()) {
        path.push_back(startVortex);
        pathLength += graphLength[currentVortex][startVortex];
        // Check for new shortest path
        if (pathLength < shortestLength) {
            shortestLength = pathLength;
            shortestPath = path;
        }
        return;
    }


    std::vector<double> possibilities;
    for (int i = 0; i < graphLength.getRowsAmount(); i++) {
        // the same city
        if (graphLength[currentVortex][i] == -1) { possibilities.push_back(0); }
            // the city, which was already visited
        else if (std::find(path.begin(), path.end(), i) != path.end()) {
            possibilities.push_back(0);
        } else {
            possibilities.push_back(std::pow((double) 1 / graphLength[currentVortex][i], beta) *
                                    std::pow(graphPheromones[currentVortex][i], alpha));
        }
    }

    double denominator = 0;
    for (const auto& possibility : possibilities) {denominator += possibility;}
    std::for_each(possibilities.begin(), possibilities.end(), [&](double& possibility) { possibility /= denominator; });

    double r = urd(dre);
    int newVortex = 0;
    for (int i = 0; i < possibilities.size(); i++) {
        if (possibilities[i] > 0) {
            r -= possibilities[i];
            newVortex = i;
        }
        if (r <= 0) { break; }
    }
    path.push_back(newVortex);
    pathLength += graphLength[currentVortex][newVortex];
    currentVortex = newVortex;
    runAnt();
}