#ifndef MAT_H
#define MAT_H

struct Mat4 {
    int matrix[4][4];

    Mat4() : matrix{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    } {}

};

#endif

