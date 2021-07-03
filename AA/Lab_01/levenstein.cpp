#include <algorithm>

#include "levenstein.h"


using namespace std;


template <typename Type>
Type u_min(Type value) {
    return value;
}

template <typename Type, typename... Args>
Type u_min(Type value, Args&&... args) {
    return min(value, u_min(forward<Args>(args)...));
}

size_t RecursiveImpl(string_view first, string_view second,
            const size_t i, const size_t j) {
    if (i * j == 0) {
        return i | j;
    } else if (first[i - 1] == second[j - 1]) {
        return RecursiveImpl(first, second, i - 1, j - 1);
    }
    return 1 + u_min(RecursiveImpl(first, second, i, j - 1),
                     RecursiveImpl(first, second, i - 1, j),
                     RecursiveImpl(first, second, i - 1, j - 1)
                     );
}



size_t RecursiveMatrImpl(Matrix<size_t>& matrix, string_view& first,
                   string_view& second, const size_t i, const size_t j)
{
    if (matrix[i][j] != -1) {
        return matrix[i][j];
    }
    if (i * j == 0) {
        return matrix[i][j] = i | j;
    }
    auto cost = (first[i - 1] != second[j - 1]);
    return matrix[i][j] = cost + u_min(
                   RecursiveMatrImpl(matrix, first, second, i, j - 1),
                   RecursiveMatrImpl(matrix, first, second, i - 1, j),
                   RecursiveMatrImpl(matrix, first, second, i - 1, j - 1)
                                       );
}

Matrix<size_t> Levenstein(string_view first, string_view second) {
    auto rows = first.size() + 1;
    auto cols = second.size() + 1;
    Matrix<size_t> result(rows, cols);
    
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (i * j == 0) {
                result[i][j] = i | j;
            } else if (first[i - 1] == second[j - 1]) {
                result[i][j] = result[i - 1][j - 1];
            } else {
                result[i][j] = 1 + u_min(
                                            result[i - 1][j - 1],
                                            result[i][j - 1],
                                            result[i - 1][j]
                                        );
            }
        }
    }
    return result;
}



Matrix<size_t> DamerauLevenstein(string_view first, string_view second) {
    auto rows = first.size() + 1;
    auto cols = second.size() + 1;
    Matrix<size_t> result(rows, cols);
    
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            if (i * j == 0) {
                result[i][j] = i | j;
            } else if (first[i - 1] == second[j - 1]) {
                result[i][j] = result[i - 1][j - 1];
            } else {
                result[i][j] = 1 + u_min(
                                          result[i - 1][j - 1],
                                          result[i][j - 1],
                                          result[i - 1][j]
                                        );
            }
            if (i > 1 && j > 1 && first[i - 1] == second[j - 2]
                && first[i - 2] == second[j - 1])
            {
                result[i][j] = u_min(
                                     result[i][j],
                                     result[i - 2][j - 2] + 1
                                    );
            }
        }
    }
    return result;
}

size_t RecursiveLevenstein(string_view first, string_view second) {
    return RecursiveImpl(first, second, first.size() + 1, second.size() + 1);
}

Matrix<size_t> RecursiveMatrLevenstein(string_view first, string_view second) {
    Matrix<size_t> result(first.size() + 1, second.size() + 1);
    result.assign(-1);
    RecursiveMatrImpl(result, first, second, first.size(), second.size());
    return result;
}
