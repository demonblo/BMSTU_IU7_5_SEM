#ifndef LAB1_PROG_MATRIX_H
#define LAB1_PROG_MATRIX_H


#include "Row.h"


class Matrix {
    std::vector<Row> data;
    size_t rows;
    size_t cols;
public:
    Matrix(size_t rows, size_t cols);
    Matrix(std::initializer_list<std::initializer_list<double>> list);

    double &getElement(size_t row, size_t col);

    size_t &getRows() {return rows;}
    size_t &getCols() {return cols;}

    Row &operator[](size_t row);
    bool operator==(Matrix& matrix);

    friend std::ostream &operator<<(std::ostream &stream, Matrix& matrix);
};

Matrix defaultMultiply(Matrix& matrix1, Matrix& matrix2);
Matrix vinogradMultiply(Matrix& matrix1, Matrix& matrix2);
Matrix advancedVinogradMultiply(Matrix& matrix1, Matrix& matrix2);


#endif //LAB1_PROG_MATRIX_H
