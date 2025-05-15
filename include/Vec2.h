#ifndef VEC2_H
#define VEC2_H

#include <math.h>
#include <string>

// 2d vector class
struct Vec2 {
    Vec2() : x(0), y(0) {} // default constructor 
    
    Vec2(float x, float y) : x(x), y(y) {} // parameterized constructor
    
    /* set the x and y pos */
    void Set(float x_val, float y_val) {
        x = x_val;
        y = y_val;
    }

    float Length() {
        return sqrtf(x * x + y * y);
    }

    std::string toString() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    /* define the operators on Vec2 data type */
    
    /* compound assignment */
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

    /* normal arithmetic */
    Vec2 operator - (Vec2& vec) const {
        float x_n = x - vec.x;
        float y_n = y - vec.y;
        return Vec2(x_n, y_n);
    }
    
    Vec2 operator + (Vec2& vec) const {
        float x_n = x + vec.x;
        float y_n = y + vec.y;
        return Vec2(x_n, y_n);
    }

    Vec2 operator * (float val) const {
        float x_n = x * val;
        float y_n = y * val;
        return Vec2(x_n, y_n);
    }
    
    float x, y;
};

#endif
