//
// Created by mi on 07.12.2020.
//

#ifndef LAB6_PROG_ROW_H
#define LAB6_PROG_ROW_H

#include <cstdlib>
#include <vector>

template<class T>
class Row {
    std::vector<T> data;

public:
    Row() = default;

    Row(size_t size) : data(size, 0) { ; }

    void push(const T& elem) { data.push_back(elem); }

    T& operator[] (int index) { return data[index]; }

    size_t getSize() { return data.size(); }
};


#endif //LAB6_PROG_ROW_H
