#ifndef LAB4_PROG_PARALLELQUEUE_H
#define LAB4_PROG_PARALLELQUEUE_H

#include <string>
#include <cstring>
#include <vector>
#include <thread>
#include <mutex>

std::vector<std::vector<int>> countWordsInStringParallelQueue(const std::vector<std::string>& strings, int threadsAmount);

#endif //LAB4_PROG_PARALLELQUEUE_H
