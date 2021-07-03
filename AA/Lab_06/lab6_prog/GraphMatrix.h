//
// Created by mi on 07.12.2020.
//

#ifndef LAB6_PROG_GRAPHMATRIX_H
#define LAB6_PROG_GRAPHMATRIX_H

#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <algorithm>
#include <random>
#include "Row.h"

template<class T>
class GraphMatrix {
    std::vector<Row<T>> rows;
    size_t rows_amount;
    size_t cols_amount;
public:
    std::vector<int> shortestPath;
    size_t shortestLength;

    GraphMatrix(size_t rows_amount, size_t cols_amount) : rows_amount(rows_amount), cols_amount(cols_amount) {
        for (size_t i = 0; i < rows_amount; i++) {
            rows.push_back(Row<T>(cols_amount));
            for (size_t j = 0; j < rows_amount; j++) {
                if (j == i) { rows[i][j] = -1; }
                else { rows[i][j] = 0; }
            }
        }

        std::uniform_int_distribution<int> distribution(10, 99);
        std::random_device rd;
        std::default_random_engine generator(rd());
        for (size_t i = 0; i < rows_amount; i++) {
            for (size_t j = 0; j < rows_amount; j++) {
                if (j > i) { rows[i][j] = distribution(generator); }
            }
        }

        for (size_t i = 0; i < rows_amount; i++) {
            for (size_t j = 0; j < rows_amount; j++) {
                if (j < i) { rows[i][j] = rows[j][i]; }
            }
        }
    }

    GraphMatrix(const std::string& fileName) : shortestLength(std::numeric_limits<size_t>::max()) {
        std::ifstream fileStream(fileName);
        fileStream >> rows_amount;
        fileStream >> cols_amount;
        for (size_t i = 0; i < rows_amount; i++) {
            rows.push_back(Row<T>(cols_amount));
            for (size_t j = 0; j < rows_amount; j++) {
                fileStream >> rows[i][j];
            }
        }
        fileStream.close();
    }

    void getBruteForceShortestWay() {
        for (int i = 0; i < rows_amount; i++) {
            getBruteForceShortestWayIteration(i);
        }
    }

    void getBruteForceShortestWayIteration(int startVertex, int goalVertex = 0, int currentVertex = 0, std::vector<int> path = {}, int pathLength = 0) {
        // Only at the start of algorithm
        if (goalVertex == currentVertex) {
            path.push_back(startVertex);
            currentVertex = goalVertex = startVertex;
        }
        else {
            path.push_back(goalVertex);
            pathLength += rows[currentVertex][goalVertex];
//            std::cout << path.size() << " " << rows_amount << std::endl;
        }
        if (path.size() == rows_amount) {
            // Go to starting vertex
            pathLength += rows[goalVertex][startVertex];
            path.push_back(startVertex);
            // Checking if this is the new shortest way
            if (pathLength < shortestLength) {
                shortestLength = pathLength;
                shortestPath = path;
            }
            return;
        }
        for (int i = 0; i < cols_amount; i++) {
            if (rows[goalVertex][i] != -1 && std::find(path.begin(), path.end(), i) == path.end()) {
                getBruteForceShortestWayIteration(startVertex, i, goalVertex, path, pathLength);
            }
        }
    }

    size_t getRowsAmount() {
        return rows_amount;
    }

    size_t getColsAmount() {
        return cols_amount;
    }

    Row<T>& operator[](int index) {
        return rows[index];
    }

    friend std::ostream& operator <<(std::ostream& stream, GraphMatrix<T>& matrix) {
        for (auto& row : matrix.rows) {
            for (size_t i = 0; i < row.getSize(); i++) { stream << row[i] << " "; }
            stream << std::endl;
        }

        return stream;
    }


    void fillWithRandomNumbers(double lowBorder, int highBorder) {
        std::uniform_real_distribution<double> distribution(lowBorder, highBorder);
        std::random_device rd;
        std::default_random_engine generator(rd());

        for (auto& row : rows) {
            for (size_t i = 0; i < row.getSize(); i++) {
                row[i] = distribution(generator);
            }
        }
    }

    size_t findQ() {
        size_t accumulator = 0;
        for (int i = 0; i < rows_amount; i++) {
            for (int j = 0; j < cols_amount; j++) {
                if (i != j) { accumulator += rows[i][j]; }
            }
        }
        return accumulator / rows_amount;
    }
};


#endif //LAB6_PROG_GRAPHMATRIX_H
