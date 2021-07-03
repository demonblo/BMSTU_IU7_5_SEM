#pragma once

#include <chrono>
#include <iostream>
#include <string>

namespace time_counter {

using namespace std;
using namespace std::chrono;
class LogDuration {
public:
    explicit LogDuration(const string& msg = "", long long times = 1LL)
    : message(msg + ": ")
    , repeat(times)
    , start(steady_clock::now())
      { }

    ~LogDuration() {
        auto finish = steady_clock::now();
        cerr << message
            << duration_cast<nanoseconds>(finish - start).count() / repeat
            << " ns" << endl;
    }
private:
    string message;
    long long repeat;
    steady_clock::time_point start;
};



};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
    LogDuration UNIQ_ID(__LINE__){message};

#define LOG_DURATION_N(message, rep) \
    LogDuration UNIQ_ID(__LINE__){message, rep};
