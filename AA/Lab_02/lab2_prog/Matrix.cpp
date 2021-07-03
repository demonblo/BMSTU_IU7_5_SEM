#include <iostream>
#include "Matrix.h"

Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    for(size_t i = 0; i < rows; i++) {
        data.emplace_back(cols);
    }
}

Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) : rows(list.size()), cols(list.begin()->size()) {
    //std::cout << *(*list.begin()).begin();
    for (size_t i = 0; i < list.size(); i++) {
        data.push_back(Row(list.begin()->size()));
        for (size_t j = 0; j < list.begin()->size(); j++) {
            data[i][j] = (*((*(list.begin() + i)).begin() + j));
        }
    }
}

double &Matrix::getElement(size_t row, size_t col) {
    return data[row][col];
}

Row& Matrix::operator[](size_t row) {
    return data[row];
}

std::ostream &operator<<(std::ostream &stream, Matrix& matrix) {
    for(auto row : matrix.data) {
        stream << row << "\n";
    }

    return stream;
}

bool Matrix::operator==(Matrix& matrix) {
    if (this->rows != matrix.rows ||
        this->cols != matrix.cols) {
        return false;
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            if ((*this)[i][j] != matrix[i][j]) { return false; }

        }
    }

    return true;
}

Matrix defaultMultiply(Matrix& matrix1, Matrix& matrix2) {
    if (matrix1.getCols() != matrix2.getRows()) {
        throw std::exception();
    }

    Matrix result(matrix1.getRows(), matrix2.getCols());

    const int M = matrix1.getRows();
    const int N = matrix1.getCols();
    const int Q = matrix2.getCols();;

    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < Q; j++) {
            result[i][j] = 0;
            for (size_t k = 0; k < N; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

Matrix vinogradMultiply(Matrix& matrix1, Matrix& matrix2) {
    if (matrix1.getCols() != matrix2.getRows()) {
        throw std::exception();
    }

    const size_t M = matrix1.getRows();
    const size_t N = matrix1.getCols();
    const size_t Q = matrix2.getCols();

    Matrix result(M, Q);

    Row mulH(M);
    for (size_t i = 0; i < M; i++) {
        mulH[i] = 0;
        for (size_t j = 0; j < N / 2; j++) {
            mulH[i] = mulH[i] + matrix1[i][j * 2] * matrix1[i][j * 2 + 1];
        }
    }

    Row mulV(Q);
    for (size_t i = 0; i < Q; i++) {
        mulV[i] = 0;
        for (size_t j = 0; j < N / 2; j++) {
            mulV[i] = mulV[i] + matrix2[j * 2][i] * matrix2[j * 2 + 1][i];
        }
    }

    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < Q; j++) {
            result[i][j] = -mulH[i] - mulV[j];
            for (size_t k = 0; k < N / 2; k++) {
                result[i][j] = result[i][j] +
                        (matrix1[i][2 * k] + matrix2[2 * k + 1][j]) *
                        (matrix1[i][2 * k + 1] + matrix2[2 * k][j]);
            }
        }
    }

    if (N % 2 == 1) {
        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < Q; j++) {
                result[i][j] = result[i][j] + matrix1[i][N - 1] * matrix2[N - 1][j];
            }
        }
    }

    return result;
}


// <<
// +=
// -= for mulH mulV
// cycles merge
Matrix advancedVinogradMultiply(Matrix& matrix1, Matrix& matrix2) {
    if (matrix1.getCols() != matrix2.getRows()) {
        throw std::exception();
    }

    const size_t M = matrix1.getRows();
    const size_t N = matrix1.getCols();
    const size_t Q = matrix2.getCols();

    Matrix result(M, Q);

    Row mulH(M);
    Row mulV(Q);
    const size_t limit = M > Q ? M : Q;
    for (size_t i = 0; i < limit; i++) {
        if (i < M && i < Q) {
            mulH[i] = 0;
            mulV[i] = 0;
            for (size_t j = 0; j < N / 2; j++) {
                mulH[i] -= matrix1[i][j * 2] * matrix1[i][j * 2 + 1];
                mulV[i] -= matrix2[j * 2][i] * matrix2[j * 2 + 1][i];
            }
        }
        else if (i < M) {
            mulH[i] = 0;
            for (size_t j = 0; j < N / 2; j++) {
                mulH[i] -= matrix1[i][j * 2] * matrix1[i][j * 2 + 1];
            }
        }
        else if (i < Q) {
            mulV[i] = 0;
            for (size_t j = 0; j < N / 2; j++) {
                mulV[i] -= matrix2[j * 2][i] * matrix2[j * 2 + 1][i];
            }
        }
    }

    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < Q; j++) {
            result[i][j] = mulH[i] + mulV[j];
            for (size_t k = 0; k < N >> 1; k++) {
                result[i][j] +=
                               (matrix1[i][k << 1] + matrix2[(k << 1) + 1][j]) *
                               (matrix1[i][(k << 1) + 1] + matrix2[k << 1][j]);
            }
        }
    }

    if (N & 1) {
        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < Q; j++) {
                result[i][j] += matrix1[i][N - 1] * matrix2[N - 1][j];
            }
        }
    }

    return result;
}


//if (matrix1.getCols() != matrix2.getRows()) {
//throw std::exception();
//}
//
//const size_t M = matrix1.getRows();
//const size_t N = matrix1.getCols();
//const size_t Q = matrix2.getCols();
//
//Matrix result(M, Q);

//    Row mulH(M);
//    for (size_t i = 0; i < M; i++) {
//        mulH[i] = 0;
//        for (size_t j = 0; j < N / 2; j++) {
//            mulH[i] += + matrix1[i][j * 2] * matrix1[i][j * 2 + 1];
//        }
//    }
//
//    Row mulV(Q);
//    for (size_t i = 0; i < Q; i++) {
//        mulV[i] = 0;
//        for (size_t j = 0; j < N / 2; j++) {
//            mulV[i] += matrix2[j * 2][i] * matrix2[j * 2 + 1][i];
//        }
//    }

//Row mulH(M);
//Row mulV(Q);
//const size_t limit = M > Q ? M : Q;
//for (size_t i = 0; i < limit; i++) {
//// 1 - only M segment
//// 2 - only N segment
//// 3 - Both segments
//unsigned short selector = (i < M) + ((i < N )+ 1);
//switch (selector) {
//case 1: {
//mulH[i] = 0;
//for (size_t j = 0; j < N / 2; j++) {
//mulH[i] += matrix1[j * 2][i] * matrix1[j * 2 + 1][i];
//}
//break;
//}
//case 2: {
//mulV[i] = 0;
//for (size_t j = 0; j < N / 2; j++) {
//mulV[i] += matrix2[j * 2][i] * matrix2[j * 2 + 1][i];
//}
//break;
//}
//case 3: {
//mulH[i] = 0;
//mulV[i] = 0;
//for (size_t j = 0; j < N / 2; j++) {
//mulH[i] += +matrix1[i][j * 2] * matrix1[i][j * 2 + 1];
//mulV[i] += matrix2[j * 2][i] * matrix2[j * 2 + 1][i];
//}
//break;
//}
//}
//}
//
//
//
//for (size_t i = 0; i < M; i++) {
//for (size_t j = 0; j < Q; j++) {
//result[i][j] = -mulH[i] - mulV[j];
//for (size_t k = 0; k < N / 2; k++) {
//result[i][j] +=
//(matrix1[i][2 * k] + matrix2[2 * k + 1][j]) *
//(matrix1[i][2 * k + 1] + matrix2[2 * k][j]);
//}
//}
//}
//
//if (N % 2) {
//for (size_t i = 0; i < M; i++) {
//for (size_t j = 0; j < Q; j++) {
//result[i][j] += matrix1[i][N - 1] * matrix2[N - 1][j];
//}
//}
//}
//
//return result;