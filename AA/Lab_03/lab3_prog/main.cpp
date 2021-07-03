#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <limits>
#include "counter.h"
//#include <chrono>


void bubbleSort(std::vector<int>& arr, size_t size);
void selectionSort(std::vector<int>& arr, size_t size);
void myQsort(std::vector<int>& arr, int left, int right);
void myQsortKiller(std::vector<int>& arr, int left, int right);
int tests();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::cout << tests();
    return 0;
}

const size_t INITIAL_ARR_SIZE = 100;
const int ITERATIONS = 100;
const size_t MAX_ARR_SIZE = 1000;
int tests() {
    for (size_t arr_size = INITIAL_ARR_SIZE; arr_size <= MAX_ARR_SIZE; arr_size += 100) {
        std::vector<int> arr_initial;  // Initial
        std::vector<int> arr1;  // Bubble
        std::vector<int> arr2;  // Selection
        std::vector<int> arr3;  // Qsort
        std::vector<int> arr4;  // std::sort

        for (size_t indx = 0; indx < arr_size; indx++) {
            arr_initial.push_back(rand() % 100);
        }
        arr1 = arr2 = arr3 = arr4 = arr_initial;

        std::cout << "size is " << arr_size << std::endl;
        StartCounter();
        for (int i = 0; i < ITERATIONS; i ++) {
            arr1 = arr_initial;
            bubbleSort(arr1, arr_size);
        }
        std::cout << "Bubble sort time: " << GetCounter() / ITERATIONS << " ";

        StartCounter();
        for (int i = 0; i < ITERATIONS; i ++) {
            arr2 = arr_initial;
            selectionSort(arr2, arr_size);
        }
        std::cout << "Selection sort time: " << GetCounter() / ITERATIONS << " ";

        StartCounter();
        for (int i = 0; i < ITERATIONS; i ++) {
            arr3 = arr_initial;
            myQsort(arr3, 0, arr_size - 1);
        }
        std::cout << "Qsort sort time: " << GetCounter() / ITERATIONS << " " << std::endl;

//        StartCounter();
        for (int i = 0; i < ITERATIONS; i ++) {
            arr4 = arr_initial;
            sort(arr4.begin(), arr4.end());
        }
//        std::cout << "std::sort sort time: " << GetCounter() / ITERATIONS << std::endl;

//        for(int i = 0; i < arr_size; i++) {
//            std::cout << arr1[i] << " " << arr2[i] << " " << arr3[i] << " " << arr4[i] << std::endl;
//        }

        if (arr1 != arr2 || arr1 != arr3 || arr1 != arr4 || arr2 != arr3 || arr2 != arr4 || arr3 != arr4) { return EXIT_FAILURE; }
    }

    return EXIT_SUCCESS;
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(std::vector<int>& arr, size_t size) {
    if (size <= 1) { return; }

    for (size_t i = 0; i < size; i++) {
        bool flg = false;
        for (size_t j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                flg = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!flg) { break; }
    }
}

void selectionSort(std::vector<int>& arr, size_t size) {
    if (size <= 1) { return; }

    for (size_t i = 0; i < size - 1; i++) {
        size_t minIndx = i;
        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndx]) { minIndx = j; }
        }
        if (minIndx != i) { swap(arr[i], arr[minIndx]); }
    }
}

void myQsort(std::vector<int>& arr, int left, int right) {
//    std::cout << "ITERATIONS IS: " << iters << std::endl;
    int l = left;
    int r = right;
    int pivot = arr[(l + r) / 2];
    while (l < r) {
        while (arr[l] < pivot) { l++; }
        while (arr[r] > pivot) { r--; }

        if (l <= r) { swap(arr[l++], arr[r--]); }
    }

    if (left < r) {myQsort(arr, left, r);}
    if (right > l) {myQsort(arr, l, right);}
}

void myQsortKiller(std::vector<int>& arr, int left, int right) {
    int l = left;
    int r = right;
    int pivot = arr[(l + r) / 2];
    while (l < r) {
        while (arr[l] < pivot) { l++; }
        while (arr[r] > pivot) { r--; }

        //if (l <= r) { swap(arr[l++], arr[r--]); }
    }

    arr[(left + right) / 2] = std::numeric_limits<int>::max();
    if (left < r) {myQsort(arr, left, r);}
    if (right > l) {myQsort(arr, l, right);}
}

