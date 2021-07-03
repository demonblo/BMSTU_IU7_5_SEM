#include <iostream>

#include "GraphMatrix.h"
#include "AntColony.h"
#include "MyTimer.h"

struct Result {
    double alpha;
    double rho;
    int days;
    size_t difference;
    double timeCalc;

    inline bool operator() (const Result& res1, const Result& res2) {
        return res1.difference < res2.difference;
    }
};

int main() {
//    GraphMatrix<int> matrix("matrix.TXT");
    GraphMatrix<int> matrix2(7, 7);
//    std::cout << matrix2;
//    return 0;
    MyTimer timer;
    matrix2.getBruteForceShortestWay();
    std::cout << "TIME FOR BRUTE: " << timer.elapsed() << std::endl;
    std::cout << matrix2.shortestLength << std::endl;
    for (const auto& vertex : matrix2.shortestPath) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;
    std::vector<Result> results;
    double averagePathLength = 0;
    const int ITERATIONS = 2;
    const double ALPHA_PLUS_BETA = 1;
    for (double alpha = 0; alpha <= 1.05; alpha += 0.1) {
        for (double rho = 0.1; rho <= .95; rho += 0.1) {
            for (int days = 1; days < 8; days++) {
                size_t shortestLength = std::numeric_limits<size_t>::max();
                timer.reset();
                for (int i = 0; i < ITERATIONS; i++) {
                    AntColony colony(matrix2, days, alpha, ALPHA_PLUS_BETA - alpha, matrix2.findQ(), rho, averagePathLength);
                    shortestLength = std::min(shortestLength, colony.getShortestLength());
                }
//                std::cout << "ALPHA: " << alpha << " RHO: " << rho << " DAYS: " << days << "RESULT DIFFERENCE: " << shortestLength - matrix.shortestLength << std::endl;
                results.push_back(Result{alpha, rho, days, shortestLength - matrix2.shortestLength, timer.elapsed() / ITERATIONS});
            }
        }
    }
    std::sort(results.begin(), results.end(), Result());
    for (const auto& res : results) {
        std::cout << "ALPHA: " << res.alpha << " RHO: " << res.rho << " DAYS: " << res.days << " TIME: " << res.timeCalc << " RESULT DIFFERENCE: " << res.difference << std::endl;
    }
    return 0;
}

//Столбцы: коэффициент либо жадности
// коэффициент испарения феромона,
// количество поколений ("суток" жизни колонии),
// значение длины лучшего найденного за 2-3 прогона муравьиного алгоритма пути и разность между этим значением и эталонным (по паре столбцов длина, разность длин на каждую "карту" класса данных). До таблицы приводят эталонные длины маршрутов, полученные методом полного перебора.
