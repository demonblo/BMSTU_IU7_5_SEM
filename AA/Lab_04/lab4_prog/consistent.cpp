#include "consitent.h"

static const int DICT_SIZE = 256;

std::vector<std::vector<int>> countWordsInStringConsistent(const std::vector<std::string>& strings) {
    std::vector<std::vector<int>> arr;
    for (int i = 0; i < strings.size(); i++) {
        std::vector<int> subArr(DICT_SIZE);
        arr.push_back(subArr);
    }

    for (int i = 0; i < strings.size(); i++) {
        for (const auto& word: strings[i]) {
            arr[i][word]++;
        }
    }

    return arr;
}