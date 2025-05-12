#ifndef VEC2_H
#define VEC2_H

#include <math.h>

// 2d vector class
struct Vec2 {
    Vec2() {} // default constructor 
    Vec2(float x, float y) : x(x), y(y) {} // parameterized constructor 
    float x, y; 
};

#endif
