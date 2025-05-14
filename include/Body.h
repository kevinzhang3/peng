#ifndef BODY_H
#define BODY_H

#include "Vec2.h"

struct Body {
    Body() {}

    Body(Vec2 p, Vec2 v) {
        position = p;
        l_velocity = v;
    } 
    
    Vec2 position, l_velocity, force;
    float torque, angle, a_velocity;
};

#endif
