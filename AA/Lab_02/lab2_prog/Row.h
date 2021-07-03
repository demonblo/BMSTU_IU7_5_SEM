#ifndef LAB1_PROG_ROW_H
#define LAB1_PROG_ROW_H


#include <vector>
#include <limits>
#include <exception>
#include <ostream>


class Row {
    std::vector<double> data;
public:
    explicit Row(size_t size);
    Row(std::initializer_list<double> list);
    Row(const Row& base);

    Row& operator=(Row &base);
    Row& operator=(std::initializer_list<double> list);

    void addElement(double element);
    double& getElement(size_t index);
    double& operator[](size_t index);


    friend std::ostream&operator<<(std::ostream& stream, Row& row);
};


#endif //LAB1_PROG_ROW_H
