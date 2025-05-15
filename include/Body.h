#ifndef BODY_H
#define BODY_H

#include "Vec2.h"

struct Body {
    Body() {}

    Body(Vec2 p, Vec2 v) {
        position = p;
        l_velocity = v;
        torque = 0;
        angle = 0;
        a_velocity = 0;
    } 
    
    Vec2 position;
    
    Vec2 l_velocity;
    
    Vec2 force;
    
    float torque;
    
    float angle;
    
    float a_velocity;

    float mass;

    float m_inertia;

};

struct Box : public Body {
    Box() {};

    Box(float h, float w, float m, float mi) {
        height = h;
        width = w;
        mass = m;
        m_inertia = m * (w * w + h * h) / 12;
    }

    float height, width;
};

struct Circle : public Body {
    float radius;
};

#endif
