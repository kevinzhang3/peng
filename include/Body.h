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
    
    // linear stuff 
    Vec2 position;
    
    Vec2 l_velocity;
    
    Vec2 l_accel;
    
    Vec2 force;
    
    // rotational stuff 
    float torque;
    
    float angle;
    
    float a_velocity;

    float a_accel;

    float mass;

    float m_inertia;

    Vec2 ComputeLinearAccel(Vec2 force) {
        return force / mass;
    }

    float ComputeRotAccel(float torque) {
        return a_accel = torque / m_inertia;
    }

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

    float ComputeTorque(Vec2 force, Vec2 r) {
        return r.x * force.y - r.y * force.x;
    }

    /*
     *  0-------1
     *  |       |
     *  |       |
     *  2-------3
     */
    void ComputeCorner(Vec2* corner) {
        corner[0] = Vec2(position.x - width/2, position.y + height/2); 
        corner[1] = Vec2(position.x + width/2, position.y + height/2); 
        corner[2] = Vec2(position.x - width/2, position.y - height/2); 
        corner[3] = Vec2(position.x + width/2, position.y - height/2);         

        corner[0].x = corner[0].x * cos(angle) - corner[0].y * sin(angle);
        corner[0].y = corner[0].y * cos(angle) + corner[0].x * sing(angle);
        
        corner[1].x = corner[1].x * cos(angle) - corner[1].y * sin(angle);
        corner[1].y = corner[1].y * cos(angle) + corner[1].x * sing(angle);
        
        corner[2].x = corner[2].x * cos(angle) - corner[2].y * sin(angle);
        corner[2].y = corner[2].y * cos(angle) + corner[2].x * sing(angle);
        
        corner[3].x = corner[3].x * cos(angle) - corner[3].y * sin(angle);
        corner[3].y = corner[3].y * cos(angle) + corner[3].x * sing(angle);
    }

    float height;
    
    float width;
    
    float com;

    Vec2 corner[4];
};

struct Circle : public Body {
    float radius;
};

void InitBodies();
void PrintBodies();

#endif
