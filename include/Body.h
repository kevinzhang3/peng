#ifndef BODY_H
#define BODY_H

#include "Vec2.h"
#include "Shape.h"

struct Body {
    Body() {}

    Body(Vec2 p, Vec2 v, Shape s) {
        position = p;
        l_velocity = v;
        shape = s;
        torque = 0;
        angle = 0;
        a_velocity = 0;
    } 
    
    Shape shape;

    Vec2 position;
    
    Vec2 l_velocity;
    
    Vec2 force;
    
    float torque;
    
    float angle;
    
    float a_velocity;


};

#endif
