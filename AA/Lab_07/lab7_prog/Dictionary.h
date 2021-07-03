#ifndef LAB7_PROG_DICTIONARY_H
#define LAB7_PROG_DICTIONARY_H

#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "Cell.h"
#include "MyTimer.h"


enum compare {
    BIGGER = 0,
    LESS,
    EQUALS,
};

template<class T>
compare comparator(const T& key1, const T& key2);

template<class TKey, class TVal>
bool comparatorForSort(const Cell<TKey, TVal>& t1, const Cell<TKey, TVal>& t2);

namespace errors {
    struct NoElem : public std::exception {
        NoElem() { ; }
    };

    struct KeyExists : public std::exception {
        KeyExists() { ; }
    };
}

template<class TKey, class TVal>
class Dictionary {
    struct Zone {
        TKey key;
        int start;
        int end;
        int inTextKeyAppearance;
    };
    static bool zoneComparator(const Zone& z1, const Zone& z2) {
        return z1.inTextKeyAppearance > z2.inTextKeyAppearance;
    }

    std::vector<Cell<TKey, TVal>> cells;
    std::vector<Zone> zones;
    compare (*comparator)(const TKey& key1, const TKey& key2);
    bool (*comparatorForSort)(const Cell<TKey, TVal>&, const Cell<TKey, TVal>&);
public:
    Dictionary(compare (*comp)(const TKey&, const TKey&),
               bool (*comparatorForSort)(const Cell<TKey, TVal>&, const Cell<TKey, TVal>&),
               const std::string& fileName);

    void pushToDictionary(TKey k, TVal v);
    TVal getValIterations(const TKey& key);
    TVal getValBinSearch(const TKey& key, int left = 0, int right = -1);
    TVal zoneSearch(const TKey& key);
    TVal getValFreqSearch(const TKey& key);

    void sortByKeys();
    void sortByFreq(std::string fileName);
    void stringZoning();

    TKey getKeyByIndex(int index);
    int getDictSize();

private:
    bool isKeyExists(const TKey& key);
    const int LETTERS_IN_ENG_ALPHABET = 26;
};

template<class T>
compare comparator(const T& key1, const T& key2) {
    if (key1 > key2) { return BIGGER; }
    else if (key1 < key2) { return LESS; }
    return EQUALS;
}

template<>
compare comparator(const std::string& key1, const std::string& key2) {
    const int res = strcasecmp(key1.c_str(), key2.c_str());
    if (res > 0) { return BIGGER; }
    else if (res < 0) { return LESS; }
    return EQUALS;
}

template<class TKey, class TVal>
bool comparatorForSort(const Cell<TKey, TVal>& t1, const Cell<TKey, TVal>& t2) {
    compare status = comparator<TKey>(t1.getKey(), t2.getKey());
    if (status == LESS) { return true; }
    return false;
}


double compareTime = 0;

template<class TKey, class TVal>
Dictionary<TKey, TVal>::Dictionary(compare (*comp)(const TKey&, const TKey&),
                                   bool (*comparatorForSort)(const Cell<TKey, TVal>&, const Cell<TKey, TVal>&),
                                   const std::string& fileName) : comparator(comp), comparatorForSort(comparatorForSort) {
    std::ifstream file(fileName);
    std::string line;
    while(getline(file, line)) {
        try {
            this->pushToDictionary(line, 0);
        } catch(...) { ; }
//            std::cout << line << std::endl;
    }
    std::cout << "Dictionary size: " << cells.size() << std::endl;
    file.close();
}
template<class TKey, class TVal>
void Dictionary<TKey, TVal>::pushToDictionary(TKey k, TVal v) {
    if (isKeyExists(k)) { throw errors::KeyExists(); }
    cells.push_back(Cell<TKey, TVal>(k, v));
}

template<class TKey, class TVal>
TVal Dictionary<TKey, TVal>::getValIterations(const TKey& key) {
    for (const auto& cell : cells) {
        if (comparator(cell.getKey(), key) == EQUALS) { return cell.getVal(); }
    }
    throw errors::NoElem();
}

template<class TKey, class TVal>
TVal Dictionary<TKey, TVal>::getValBinSearch(const TKey& key, int left, int right) {
    int iterations = 0;
    if (right == -1) { right = cells.size() - 1; }

    while (left < right) {
        iterations++;
        int mid = (left + right) / 2;
        MyTimer timer;
        compare status = comparator(key, cells[mid].getKey());
        compareTime += timer.elapsed();
        if (status == EQUALS) { return cells[mid].getVal(); }
        if (status == LESS) { right = mid - 1; }
        else { left = mid + 1; }
    }
    if (cells[left].getKey() == key) { return cells[left].getVal(); }

    throw errors::NoElem();
}


template<class TKey, class TVal>
TKey Dictionary<TKey, TVal>::getKeyByIndex(int index) {
    return cells[index].getKey();
}

template<class TKey, class TVal>
int Dictionary<TKey, TVal>::getDictSize() { return cells.size(); }

template<class TKey, class TVal>
void Dictionary<TKey, TVal>::sortByKeys() {
    std::sort(cells.begin(), cells.end(), comparatorForSort);
}

template<class TKey, class TVal>
void Dictionary<TKey, TVal>::stringZoning() {
    zones.clear();
    this->sortByKeys();
    for (int i = 0; i < LETTERS_IN_ENG_ALPHABET; i++) {
        std::string str;
        str.push_back('a' + i);
        Dictionary<TKey, TVal>::Zone zone{str, 0, 0};
        zones.push_back(zone);
    }
    for (const auto& cell: cells) {
        (zones[tolower(cell.getKey()[0]) - 'a'].end++);
    }
    for (int i = 0; i < LETTERS_IN_ENG_ALPHABET; i++) {
        if (i != 0) {
            zones[i].start = zones[i - 1].end;
            zones[i].end += zones[i].start;
        }
    }
}

template<class TKey, class TVal>
TVal Dictionary<TKey, TVal>::zoneSearch(const TKey& key) {
    int left = zones[tolower(key[0]) - 'a'].start;
    int right = zones[tolower(key[0]) - 'a'].end;
    return getValBinSearch(key, left, right - 1);
}

template<class TKey, class TVal>
void Dictionary<TKey, TVal>::sortByFreq(std::string fileName) {
    zones.clear();
    stringZoning();

    std::ifstream file(fileName);
    std::string line;
    while(getline(file, line)) {
        std::istringstream strstream(line);
        std::string word;
        while (strstream >> word) {
            if (tolower(word[0]) >= 'a' && tolower(word[0]) <= 'z') {
                int a = tolower(word[0]) - 'a';
                zones[tolower(word[0]) - 'a'].inTextKeyAppearance++;
            }
        }
    }
    file.close();

    std::sort(zones.begin(), zones.end(), &(zoneComparator));
    std::vector<Cell<TKey, TVal>> tmp;
    for (const auto& zone : zones) {
        tmp.insert(tmp.end(), cells.begin() + zone.start, cells.begin() + zone.end);
    }
    for (int i = 0; i < LETTERS_IN_ENG_ALPHABET; i++) {
        if (i == 0) {
            zones[i].end = zones[i].end - zones[i].start;
            zones[i].start = 0;
        } else {
            zones[i].end = (zones[i].end - zones[i].start) + zones[i - 1].end;
            zones[i].start = zones[i - 1].end;
        }
    }
    cells = tmp;
}

template<class TKey, class TVal>
bool Dictionary<TKey, TVal>::isKeyExists(const TKey& key) {
    for (const auto& cell : cells) {
        if (comparator(cell.getKey(), key) == EQUALS) {
//                std::cout << key << " " << cell.getKey() << std::endl;
            return true;
        }
    }
    return false;
}

template<class TKey, class TVal>
TVal Dictionary<TKey, TVal>::getValFreqSearch(const TKey& key) {
    int start = 0;
    int end = 0;
    for (const auto& zone : zones) {
        if (zone.key[0] == tolower(key[0])) {
            start = zone.start;
            end = zone.end;
            break;
        }
    }

    for (int i = start; i < end; i++) {
        if (comparator(cells[i].getKey(), key) == EQUALS) { return cells[i].getVal(); }
    }
    throw errors::NoElem();
}

#endif //LAB7_PROG_DICTIONARY_H
