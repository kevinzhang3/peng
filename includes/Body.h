#ifndef BODY_H
#define BODY_H

#include "Vec2.h"

struct Body {
    Body() {}

    Body(Vec2 p, Vec2 v, float m) {
        position = p;
        velocity = v;
        mass = m;
    } 
    
    Vec2 position;
    
    Vec2 velocity;
    
    float mass;
};

#endif
