#include "parallelGood.h"

static const int DICT_SIZE = 256;

static void parallelGoodThreadFunction(const std::vector<std::string>& strings,
                                       int start, int end,
                                       std::vector<std::vector<int>>& arr) {
    for (int i = start; i < end; i++) {
        for (const auto& chr : strings[i]) {
            arr[i][chr]++;
        }
    }
}

std::vector<std::vector<int>> countWordsInStringParallelGood(const std::vector<std::string>& strings, int threadsAmount = 8) {
    std::vector<std::vector<int>> arr;
    for (int i = 0; i < strings.size(); i++) {
        std::vector<int> subArr(DICT_SIZE);
        arr.push_back(subArr);
    }

    std::vector<std::thread> threadVector;
    for (int i = 0; i < threadsAmount; i++) {
        int start = ((double)strings.size() / threadsAmount * i);
        int end = ((double)strings.size() / threadsAmount * (i + 1));
        threadVector.emplace_back(std::thread(parallelGoodThreadFunction, std::ref(strings), start, end, std::ref(arr)));
    }

    for (int i = 0; i < threadsAmount; i++) {
        threadVector[i].join();
    }

    return arr;

//    int* dictionary = new int[DICT_SIZE];
//    memset(dictionary, 0, DICT_SIZE * sizeof(int));
//
//    std::vector<std::thread> threadVector;
//    std::vector<int*> dictionaries;
//
//    size_t length = string.length();
//    for (int i = 0; i < threadsAmount; i++) {
//        dictionaries.push_back(new int[DICT_SIZE]);
//        memset(dictionaries[i], 0, DICT_SIZE * sizeof(int));
//
//        int start = ((double)length / threadsAmount * i);
//        int end = ((double)length / threadsAmount * (i + 1));
//        threadVector.emplace_back(parallelGoodThreadFunction, std::ref(string), start, end, dictionaries[i]);
//    }
//
//    for (int thread = 0; thread < threadsAmount; thread++) {
//        threadVector[thread].join();
//        for (int i = 0; i < DICT_SIZE; i++) {
//            dictionary[i] += dictionaries[thread][i];
//        }
//    }
//
//    return dictionary;
}