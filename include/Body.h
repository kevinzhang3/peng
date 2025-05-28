#ifndef BODY_H
#define BODY_H

#include "Vec2.h"

#define NUM_BODIES 1

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

    Box(Vec2 p, Vec2 v, float h, float w, float m) {
        height = h;
        width = w;
        mass = m;
        position = p;
        l_velocity = v;
        torque = 0;
        angle = 0;
        a_velocity = 0;
        com = 0;
        m_inertia = m * (w * w + h * h) / 12;
    }

    void ComputeTorque(Vec2 force, Vec2 r) {
        torque = r.x * force.y - r.y * force.x;
    }

    float height;
    
    float width;
    
    float com;
};

struct Circle : public Body {
    float radius;
};

void InitBodies();
void PrintBodies();

#endif
