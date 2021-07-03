#include "parallelQueue.h"
#include <iostream>

static const int DICT_SIZE = 256;
static const int WORDS_IN_ALPHABET = 26;

std::mutex thread_lock;

static void threadInitFunc() { }

static void parallelBadThreadFunction(const std::vector<std::string>& strings,
                                      int& wordIndex,
                                      std::vector<std::vector<int>>& arr) {
    const int size = strings.size();
    while (true) {
        thread_lock.lock();
        if (wordIndex >= size) {
            thread_lock.unlock();
            break;
        }
        int currPosition = wordIndex++;
        thread_lock.unlock();
        for (const auto& chr : strings[currPosition]) {
            ++arr[currPosition][chr];
        }
    }
}

std::vector<std::vector<int>> countWordsInStringParallelQueue(const std::vector<std::string>& strings, int threadsAmount) {
    std::vector<std::vector<int>> arr;
    for (int i = 0; i < strings.size(); i++) {
        std::vector<int> subArr(DICT_SIZE);
        arr.push_back(subArr);
    }

    std::vector<std::thread> threadVector;
    int wordPosition = 0;
    for (int i = 0; i < threadsAmount; i++) {
        threadVector.emplace_back(std::thread(parallelBadThreadFunction,
                                              std::ref(strings),
                                              std::ref(wordPosition),
                                              std::ref(arr)));
    }

    for (int i = 0; i < threadsAmount; i++) {
        threadVector[i].join();
    }


    return arr;
}