#include <iostream>
#include "consitent.h"
#include "parallelQueue.h"
#include "parallelGood.h"


static const int DICT_SIZE = 256;

class Timer {
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now()) {
    }

    void reset() {
        m_beg = clock_t::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

void printDict(int* dict, int dictSize = DICT_SIZE) {
    for (int i = 0; i < dictSize; i++) {
        if (dict[i]) {
            std::cout << "Word " << (char)i << " meets " << dict[i] << " times in string." << std::endl;
        }
    }
}



const int ITERATIONS = 2;
const int STRING_SIZE = 10000;
int startTests () {
    Timer timer;
    //5000000
    int stringsAmount = 400000;
    std::vector<std::string> strings;
    for (int i = 0; i < stringsAmount; i++) {
        std::string string;
        for (int j = 0; j < STRING_SIZE; j++) {
            string.push_back((rand() % 26) + 'a');
        }
        strings.push_back(string);
    }
    for (int threads = 1; threads <= 32; threads *= 2) {
        timer.reset();
        for (int i = 0; i < ITERATIONS; i++) {
            countWordsInStringParallelGood(strings, threads);
        }
        std::cout << threads << " " << timer.elapsed() / ITERATIONS << std::endl;
    }
    /*
    for (int stringsAmount = 100; stringsAmount < 10000000 ; stringsAmount *= 10) {
        std::cout << "Strings amount is " << stringsAmount << std::endl;
        std::vector<std::vector<int>> dict1;
        std::vector<std::vector<int>> dict2;
        std::vector<std::vector<int>> dict3;

        std::vector<std::string> strings;
        for (int i = 0; i < stringsAmount; i++) {
            std::string string;
            for (int j = 0; j < STRING_SIZE; j++) {
                string.push_back((rand() % 26) + 'a');
            }
            strings.push_back(string);
        }

        timer.reset();
        dict1 = countWordsInStringConsistent(strings);
        std::cout << "Average time for consistent is " << timer.elapsed() / ITERATIONS << " Seconds" << std::endl;

        timer.reset();
        dict2 = countWordsInStringParallelQueue(strings, 8);
        std::cout << "Average time for Parallel bad is " << timer.elapsed() / ITERATIONS << " Seconds" << std::endl;

        timer.reset();
        dict3 = countWordsInStringParallelGood(strings, 8);
        std::cout << "Average time for Parallel good is " << timer.elapsed() / ITERATIONS << " Seconds" << std::endl;


        for (int i = 0; i < stringsAmount; i++) {
            for (int j = 0; j < DICT_SIZE; j++) {
                if (dict1[i][j] != dict3[i][j]) {
                    std::cout << "DICT";
                }
            }
        }
        if (dict1 != dict2 || dict1 != dict3 || dict2 != dict3) { return EXIT_FAILURE; }
    }
     */

    return EXIT_SUCCESS;
}

int main() {
    std::cout << startTests();
    return EXIT_SUCCESS;
}
