#ifndef BODY_H
#define BODY_H

#include "Vec2.h"

struct Body {
    Body() {}

    Body(Vec2 p, Vec2 v, float m, float r) {
        position = p;
        velocity = v;
        mass = m;
        radius = r;
    } 
    
    Vec2 position;
    
    Vec2 velocity;
    
    float mass, radius;
};

#endif
