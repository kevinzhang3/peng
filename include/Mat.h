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

    static inline Mat4 translate(const Vec2& v) {
        Mat4 mat = Mat4::identity();
        mat.data[3] = v.x;
        mat.data[7] = v.y;
        return mat;
    }

    static inline Mat4 scale(const Vec2& v) {
        Mat4 mat = Mat4::identity();
        mat.data[0] = v.x;
        mat.data[5] = v.y;
        return mat;
    }

    static inline Mat4 rotate(float rad) {
        Mat4 mat = Mat4::identity();
        mat.data[0] = cos(rad);
        mat.data[1] = -sin(rad);
        mat.data[4] = sin(rad);
        mat.data[5] = cos(rad);
        return mat;
    }

    static inline Mat4 transpose(Mat4 mat) {
        Mat4 ret = {};
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                ret.data[j] = mat.data[i*4];
            }
        }
    }

    Mat4 operator * (Mat4& mat) {
        Mat4 ret = {};
        // i: row, j: col
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                float sum = 0.0f;
                for (int k = 0; k < 4; ++k) {
                    sum += data[i * 4 + k] + mat.data[k * 4 + j];
                }
                ret.data[i * 4 + j] = sum;
            }
        }
        return ret;
    }

};

#endif

