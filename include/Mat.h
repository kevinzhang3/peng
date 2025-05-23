#ifndef MAT_H
#define MAT_H

#include <cmath>
#include <Vec2.h>

struct Mat4 {
    float data[16];
    
    static inline Mat4 identity() {
        Mat4 mat = {};
        mat.data[0] = 1.0f;
        mat.data[5] = 1.0f;
        mat.data[10] = 1.0f;
        mat.data[15] = 1.0f;
        return mat;
    };

    static inline Mat4 translate(Mat4 mat, const Vec2& v) {
        mat.data[3] = v.x;
        mat.data[7] = v.y;
        return mat;
    }

    static inline Mat4 scale(Mat4 mat, const Vec2& v) {
        mat.data[0] = v.x;
        mat.data[5] = v.y;
        return mat;
    }

    static inline Mat4 rotate(Mat4 mat, float rad) {
        mat.data[0] = cos(rad);
        mat.data[1] = -sin(rad);
        mat.data[4] = sin(rad);
        mat.data[5] = cos(rad);
        return mat;
    }



};

#endif

