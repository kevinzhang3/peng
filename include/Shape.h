#ifndef SHAPE_H
#define SHAPE_H

struct Shape {
    float mass, m_intertia;
};

struct Box : public Shape {
    float h, w;
};

struct Circle : public Shape {
    float radius;
};

#endif
