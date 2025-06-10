#include <Body.h>
#include <Util.h>

int DetectCollisionBox(Box& boxA, Box& boxB) {
    boxA.ComputeCorner();
    boxB.ComputeCorner();
}

int CollideBody(Body& bodyA, Body& bodyB) {
    // call after detect
    return 0;
}

int CollideBarrier(Body& body) {
    
    return 0;
}
