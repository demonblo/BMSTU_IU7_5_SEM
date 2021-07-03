//
// Created by mi on 07.12.2020.
//

#include "AntColony.h"

AntColony::AntColony(GraphMatrix<int> lengths, size_t days, double alpha, double beta, double Q, double p, double& averagePathLength) :
graphLength(lengths), graphPheromones(lengths.getRowsAmount(), lengths.getColsAmount()),
days(days), alpha(alpha), beta(beta), Q(Q), p(p), shortestLength(std::numeric_limits<size_t>::max()), averagePathLength(averagePathLength) {

    // Random generator for ants!
    std::uniform_real_distribution<double> distribution(0,1);
    std::random_device rd;
    std::default_random_engine generator(rd());

    // filling pheromones graph with random values. This should increase end result
    graphPheromones.fillWithRandomNumbers(defaultPheromoneLevel, defaultPheromoneLevel);
    std::vector<double> averagePathLengthEachDay;
    for (int i = 0; i < days; i++) {
        averagePathLengthEachDay.push_back(0);
        for (int k = 0; k < graphPheromones.getRowsAmount(); k++) {
            ants.emplace_back(lengths, graphPheromones, k, alpha, beta, shortestPath, shortestLength,
                              distribution, generator);
            averagePathLengthEachDay[i] += ants[k].pathLength;
        }
        updatePheromones(graphPheromones, ants);

//            std::cout << "Day  " << i << "\nShortest way length:" << shortestLength << std::endl;
//            std::cout << "Shortest path:" << shortestLength << std::endl;
//            for (int i = 0; i < graphPheromones.getRowsAmount(); i++) {
//                std::cout << shortestPath[i] << " ";
//            }
//            std::cout << std::endl << std::endl;
        averagePathLengthEachDay[i] /= ants.size();
    }
    std::for_each(averagePathLengthEachDay.begin(), averagePathLengthEachDay.end(), [&](const double& elem) { averagePathLength += elem; });
    averagePathLength /= days;
}

void AntColony::updatePheromones(GraphMatrix<double>& graphPheromones, std::vector<Ant>& ants) {
    for (int i = 0; i < graphPheromones.getRowsAmount(); i++) {
        for (int j = 0; j < graphPheromones.getColsAmount(); j++) {
            graphPheromones[i][j] = (1 - p) * graphPheromones[i][j];
        }
    }
    for (const auto& ant : ants) {
        double deltaT = Q / ant.pathLength;
        for (int i = 0; i < ant.path.size() - 1; i++) {
            graphPheromones[ant.path[i]][ant.path[i + 1]] += deltaT;
            graphPheromones[ant.path[i]][ant.path[i + 1]] = std::max(graphPheromones[ant.path[i]][ant.path[i + 1]], lowPheromoneBorder);
            graphPheromones[ant.path[i]][ant.path[i + 1]] = std::min(graphPheromones[ant.path[i]][ant.path[i + 1]], highPheromoneBorder);
        }
    }
}

std::vector<int> AntColony::getShortestPath() const { return shortestPath; }
size_t AntColony::getShortestLength() const { return shortestLength; }
