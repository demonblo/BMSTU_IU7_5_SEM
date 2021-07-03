#include "Row.h"


Row::Row(size_t size) {
    for (size_t i = 0; i < size; i++) {
        data.push_back(0);
    }
}

Row::Row(std::initializer_list<double> list) {
    for(auto element : list) {
        data.push_back(element);
    }
}

Row::Row(const Row& base) {
    data.clear();

    for(auto element : base.data) {
        data.push_back(element);
    }
}

Row& Row::operator=(Row &base) {
    data.clear();

    for(auto element : base.data) {
        data.push_back(element);
    }

    return *this;
}

Row& Row::operator=(std::initializer_list<double> list) {
    data.clear();

    for(auto element : list) {
        data.push_back(element);
    }

    return *this;
}

void Row::addElement(const double element) {
    data.push_back(element);
}

double& Row::getElement(const size_t index) {
    if (index >= data.size())
        throw (std::exception());
    return data[index];
}

double& Row::operator[](const size_t index) {
    return this->getElement(index);
}


std::ostream&operator<<(std::ostream& stream, Row& row) {
    for(auto element : row.data) {
        stream << element <<  " ";
    }

    return stream;
}