#ifndef VEC2_H
#define VEC2_H

#include <math.h>

// 2d vector class
struct Vec2 {
    Vec2() {} // default constructor 
    
    Vec2(float x, float y) : x(x), y(y) {} // parameterized constructor
    
    /* set the x and y pos */
    void Set(float x_val, float y_val) {
        x = x_val;
        y = y_val;
    }

    float Length() {
        return sqrtf(x * x + y * y);
    }

    /* define the operators on Vec2 data type */
    void operator -= (Vec2& vec) {
        x -= vec.x;
        y -= vec.y;
    }
    
    void operator += (Vec2& vec) {
        x += vec.x;
        y += vec.y;
    }
    
    void operator *= (float val) {
        x *= val;
        y *= val;
    }

    float x, y; 
    
};

#endif
