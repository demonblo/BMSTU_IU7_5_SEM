#include "Dictionary.h"

void runTestsIterations(Dictionary<std::string, int>&);
void runTestsBin(Dictionary<std::string, int>&);
void runTestsFreq(Dictionary<std::string, int>&);
int tests();
int main() {
//    runTestsIterations();
//    runTestsBin();
//    runTestsFreq();
    std::string line;
//    Dictionary<std::string, int> dict(comparator<std::string>, comparatorForSort<std::string, int>, "american-english");
//    Dictionary<std::string, int> dict(comparator<std::string>, comparatorForSort<std::string, int>, "linux_dict.txt");
//    runTestsIterations();

    Dictionary<std::string, int> dict(&(comparator<std::string>),
                                      &(comparatorForSort<std::string, int>),
                                      "linux_dict.txt");

    std::cout << tests();
//    runTestsIterations(dict);
//    runTestsBin(dict);
//    runTestsFreq(dict);
//    std::string line;
//    std::ifstream fileIn("american-english");
//    std::ofstream fileOut("linux_dict.txt");
//    std::vector<std::string> words;
//    while(getline(fileIn, line)) {
//        words.push_back(line);
//    }
//    for (int i = 0; i < 10000; i++) {
//        fileOut << words[std::rand() % words.size() - 1] << std::endl;
//    }
//    return 0;
}

const int ITERATIONS = 1000;
void runTestsIterations(Dictionary<std::string, int>& dict) {
    // BEST CASE - FIRST MEMBER
    std::string firstKey = dict.getKeyByIndex(0);
    MyTimer timer;
    for (int i = 0; i < ITERATIONS; i++) {
        dict.getValIterations(firstKey);
    }
    std::cout << "Best case iterations time: " << timer.elapsed() / ITERATIONS << std::endl;

    // WORST CASE - LAST MEMBER
    std::string lastKey = dict.getKeyByIndex(dict.getDictSize() - 1);
    timer.reset();
    for (int i = 0; i < ITERATIONS; i++) {
        try {
            dict.getValIterations("zzzzzz");
        } catch (...) { ; }
    }
    std::cout << "Worst case iterations time: " << timer.elapsed() / ITERATIONS << std::endl;

    // AVERAGE CASE - RANDOM MEMBER
    std::vector<std::string> keys;
    std::ifstream file("wap2.txt");
    std::string line;
    while(getline(file, line)) {
        std::istringstream strstream(line);
        std::string word;
        while (strstream >> word) {
            if (tolower(word[0]) >= 'a' && tolower(word[0]) <= 'z') {
                keys.push_back(word);
            }
        }
    }
    file.close();

    compareTime = 0;
    timer.reset();
    for (const auto& key : keys) {
        try {
            dict.getValIterations(key);
        } catch (...) { ; }
    }
    std::cout << "Average case iterations time: " << timer.elapsed() / keys.size() << std::endl;
}

void runTestsBin(Dictionary<std::string, int>& dict) {
    dict.sortByKeys();
    // BEST CASE - MIDDLE
    std::string middleKey = dict.getKeyByIndex((dict.getDictSize() - 1) / 2);
    MyTimer timer;
    for (int i = 0; i < ITERATIONS; i++) {
        dict.getValBinSearch(middleKey);
    }
    std::cout << "Best case bin time: " << timer.elapsed() / ITERATIONS << std::endl;

    compareTime = 0;
    // WORST CASE - LAST MEMBER
    std::string firstKey = dict.getKeyByIndex(dict.getDictSize() - 1);
    timer.reset();
    for (int i = 0; i < ITERATIONS; i++) {
        try {
            dict.getValBinSearch(dict.getKeyByIndex((dict.getDictSize() - 1) / 3) + 'z');
        } catch (...) { ; }
    }
    std::cout << "Worst case bin time: " << timer.elapsed() / ITERATIONS << " COMPARE_TIME: " << compareTime / ITERATIONS << std::endl;


    // AVERAGE CASE - TEXT
    std::vector<std::string> keys;
    std::ifstream file("wap2.txt");
    std::string line;
    while(getline(file, line)) {
        std::istringstream strstream(line);
        std::string word;
        while (strstream >> word) {
            if (tolower(word[0]) >= 'a' && tolower(word[0]) <= 'z') {
                keys.push_back(word);
            }
        }
    }
    file.close();

    compareTime = 0;
    timer.reset();
    for (const auto& key : keys) {
        try {
            dict.getValBinSearch(key);
        } catch (...) { ; }
    }
    std::cout << "Average case bin time: " << timer.elapsed() / keys.size() << " COMPARE_TIME: " << compareTime / ITERATIONS << std::endl;
}

void runTestsFreq(Dictionary<std::string, int>& dict) {
    dict.sortByFreq("wap1.txt");

    // BEST CASE - MIDDLE
    std::string firstKey = dict.getKeyByIndex(0);
    MyTimer timer;
    for (int i = 0; i < ITERATIONS; i++) {
        dict.getValFreqSearch(firstKey);
    }
    std::cout << "Best case freq time: " << timer.elapsed() / ITERATIONS << std::endl;

    compareTime = 0;
    // WORST CASE - LAST MEMBER
    timer.reset();
    for (int i = 0; i < ITERATIONS; i++) {
        try {
            dict.getValFreqSearch(dict.getKeyByIndex(0) + "zzzzzzzz");
        } catch (...) { ; }
    }
    std::cout << "Worst case freq time: " << timer.elapsed() / ITERATIONS << " COMPARE_TIME: " << compareTime / ITERATIONS << std::endl;


    // AVERAGE CASE - TEXT
    std::vector<std::string> keys;
    std::ifstream file("wap2.txt");
    std::string line;
    while(getline(file, line)) {
        std::istringstream strstream(line);
        std::string word;
        while (strstream >> word) {
            if (tolower(word[0]) >= 'a' && tolower(word[0]) <= 'z') {
                keys.push_back(word);
            }
        }
    }
    file.close();

    compareTime = 0;
    timer.reset();
    for (const auto& key : keys) {
        try {
            dict.getValFreqSearch(key);
        } catch (...) { ; }
    }
    std::cout << "Average case bin time: " << timer.elapsed() / keys.size() << " COMPARE_TIME: " << compareTime / ITERATIONS << std::endl;
}

int tests() {
    Dictionary<std::string, int> dictIter(&(comparator<std::string>),
                                      &(comparatorForSort<std::string, int>),
                                      "linux_dict.txt");
    Dictionary<std::string, int> dictBin(&(comparator<std::string>),
                                      &(comparatorForSort<std::string, int>),
                                      "linux_dict.txt");
    Dictionary<std::string, int> dictFreq(&(comparator<std::string>),
                                      &(comparatorForSort<std::string, int>),
                                      "linux_dict.txt");

    dictBin.sortByKeys();
    dictFreq.sortByFreq("wap1.txt");

    for (int i = 0; i < dictIter.getDictSize(); i++) {
        int resIter = dictIter.getValIterations(dictIter.getKeyByIndex(i));
        int resBsearch = dictBin.getValBinSearch(dictIter.getKeyByIndex(i));
        int resFreq = dictFreq.getValFreqSearch(dictIter.getKeyByIndex(i));

        if (resIter != resBsearch || resIter != resFreq || resBsearch != resFreq) {
            return EXIT_FAILURE;
        }
    }

    // TESTING AN NON-IN-DICTIONARY CASE
    int throws = 0;
    try {
        dictIter.getValIterations("THIS VALUE IS NOT IN DICTIONARY!");
    } catch (...) {
        throws++;
    }
    try {
        dictBin.getValBinSearch("THIS VALUE IS NOT IN DICTIONARY!");
    } catch (...) {
        throws++;
    }
    try {
        dictFreq.getValFreqSearch("THIS VALUE IS NOT IN DICTIONARY!");
    } catch (...) {
        throws++;
    }

    if (throws == 3) { return EXIT_SUCCESS; }
    return EXIT_FAILURE;
}