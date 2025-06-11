#include <Body.h>
#include <Util.h>

int DetectCollisionBox(Box& boxA, Box& boxB) {
    boxA.ComputeCorner();
    boxB.ComputeCorner();

    Vec2 projA[4];
    Vec2 projB[4];
    Vec2 axis[4];

    // calculate the axes 
    axis[0] = boxA.corner[0] - boxA.corner[1];
    axis[1] = boxA.corner[1] - boxA.corner[3];
    axis[2] = boxA.corner[0] - boxA.corner[2];
    axis[3] = boxA.corner[2] - boxA.corner[3];

    return 0;
}

int CollideBody(Body& bodyA, Body& bodyB) {
    // call after detect
    return 0;
}

int CollideBarrier(Body& body) {
    
    return 0;
}
