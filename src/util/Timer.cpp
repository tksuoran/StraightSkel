/**
 * @file   util/Timer.cpp
 * @author Gernot Walzl
 * @date   2013-06-25
 */

#include "util/Timer.h"

namespace util {

Timer::~Timer() {
    // intentionally does nothing
}

double Timer::now() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    return static_cast<double>(millis) / 1000.0;
}

}
