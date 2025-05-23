#ifndef MAT_H
#define MAT_H

#include "Vec2.h"

struct Mat4 {
    float data[16];
    
    static Mat4 identity() {
        Mat4 mat = {};
        mat.data[0] = 1.0f;
        mat.data[5] = 1.0f;
        mat.data[10] = 1.0f;
        mat.data[15] = 1.0f;
        return mat;
    };

    static Mat4 translate(const Vec2& v) {
        Mat4 mat = Mat4::identity();
        mat.data[3] = v.x;
        mat.data[7] = v.y;
        return mat;
    }



};

#endif

