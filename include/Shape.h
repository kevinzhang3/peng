#ifndef SHAPE_H
#define SHAPE_H

struct Shape {
    float mass, m_intertia;


};

struct Box : public Shape {
    Box() {};

    Box(float h, float w, float m, float mi) {
        height = h;
        width = w;
        mass = m;
        m_intertia = m * (w * w + h * h) / 12;
    }

    float height, width;
};

struct Circle : public Shape {
    float radius;
};

#endif
