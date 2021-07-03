#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Matrix.h"
#include "counter.h"

bool matrix_test1();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::cout << matrix_test1();
    return 0;
}

bool matrix_test1() {
//    size_t M = rand() % 30 + 1;
//    size_t N = rand() % 30 + 1;
//    size_t Q = rand() % 30 + 1;


    for (int q = 0; q < 10; q++) {
        for (int SIZE = 500; SIZE <= 500; SIZE += 100) {
            size_t M = SIZE;
            size_t N = SIZE;
            size_t Q = SIZE;


            Matrix matrix1(M, N);
            Matrix matrix2(N, Q);

            for (size_t i = 0; i < M; i++) {
                for (size_t j = 0; j < N; j++) {
                    matrix1[i][j] = rand() % 100;
                }
            }


            for (size_t i = 0; i < N; i++) {
                for (size_t j = 0; j < Q; j++) {
                    matrix2[i][j] = rand() % 100;
                }
            }

            //    Matrix matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
            //    Matrix matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

            StartCounter();
            for (int i = 0; i < 1; i++) {
                Matrix res1 = defaultMultiply(matrix1, matrix2);
            }
            std::cout << GetCounter() / 1 << " ";

            StartCounter();
            for (int i = 0; i < 1; i++) {
                Matrix res2 = vinogradMultiply(matrix1, matrix2);
            }
            std::cout << GetCounter() / 1 << " ";

            StartCounter();
            for (int i = 0; i < 1; i++) {
                Matrix res3 = advancedVinogradMultiply(matrix1, matrix2);
            }
            std::cout << GetCounter() / 1 << std::endl;

            Matrix res1 = defaultMultiply(matrix1, matrix2);
            Matrix res2 = vinogradMultiply(matrix1, matrix2);

            std::cout << res1;
        }
    }
    return 1;
}
