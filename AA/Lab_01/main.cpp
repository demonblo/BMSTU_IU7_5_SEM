#include <iostream>
#include <iomanip>
#include <cctype>

#include "levenstein.h"
#include "profile.hpp"

using namespace std;
using time_counter::LogDuration;

inline void Menu(void) noexcept {
    cout << "\nMenu:\n"
         << "Standard Levenstein - 1\n"
         << "Recursive Levenstein - 2\n"
         << "Recursive-Martix Levenstein - 3\n"
         << "Damerau-Levenstein - 4\n"
         << "Time test - 5\n"
         << "Exit - 0\n"
         << "\nEnter your choice: ";
}

void TestTime(string_view first, string_view second) {
    constexpr size_t N = 50u;
    {
        LOG_DURATION_N("Standard Levenstein", N);
        for (size_t i = 0; i < N; i++) {
//            LOG_DURATION("Standard Levenstein");
            Levenstein(first, second);
        }
    }
    {
        LOG_DURATION_N("Recursive Levenstein", N);
        for (size_t i = 0; i < N; i++) {
//            LOG_DURATION("Recursive Levenstein");
            RecursiveLevenstein(first, second);
        }
    }
    {
        LOG_DURATION_N("Recursive-Martix Levenstein", N);
        for (size_t i = 0; i < N; i++) {
//            LOG_DURATION("Recursive-Martix Levenstein");
            RecursiveMatrLevenstein(first, second);
        }
    }
    {
        LOG_DURATION_N("Damerau-Levenstein", N);
        for (size_t i = 0; i < N; i++) {
//            LOG_DURATION("Damerau-Levenstein");
            DamerauLevenstein(first, second);
        }
    }
}

template <typename T>
ostream& operator << (ostream& os, const Matrix<T>& matr) {
    for (const auto& v : matr) {
        for (const auto& elem : v) {
            os << setw(4) << elem << ' ';
        }
        os << '\n';
    }
    return os;
}



int main() {
    string first, second;
    int choice = 0;
    do {
        Menu();
        cin >> choice;
        if (cin.fail() || choice < 0 ||
            choice > 5 || !isspace(cin.peek())) {
            throw logic_error("\nIncorect choice");
        }
        if (choice) {
            cout << "Input first string:\n";
            cin >> first;
            cout << "Input second string:\n";
            cin >> second;
            cout << "\nResult:\n";
        }
        if (choice == 1) {
            cout << Levenstein(first, second);
        } else if (choice == 2) {
            cout << RecursiveLevenstein(first, second) << endl;
        } else if (choice == 3) {
            cout << RecursiveMatrLevenstein(first, second);
        } else if (choice == 4) {
            cout << DamerauLevenstein(first, second);
        } else if (choice == 5) {
            TestTime(first, second);
        }

    } while (choice);
    return 0;
}
