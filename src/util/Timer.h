/**
 * @file   util/Timer.h
 * @author Gernot Walzl
 * @date   2013-06-25
 */

#ifndef UTIL_TIMER_H
#define UTIL_TIMER_H

#include <chrono>

namespace util {

class Timer {
public:
    virtual ~Timer();
    static double now();
protected:
    Timer();
};

}

#endif /* UTIL_TIMER_H */

