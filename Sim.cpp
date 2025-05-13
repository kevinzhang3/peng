#include <iostream>
#include <Vec2.h>
#include <Body.h>

#define NUM_BODIES 1
#define TIME_LIM   20

Body bodies[NUM_BODIES];

/* initialize the bodies */
void InitBodies(void) {
    for (int i = 0; i < NUM_BODIES; ++i) {
        Vec2 p, v;
        p = Vec2((rand() % 10) + 1, (rand() % 10) + 1);
        v = Vec2(0, 0);
        bodies[i] = Body(p, v, 1);
    }
} 

Vec2 ComputeForce(Body& b) {
    return Vec2(0, b.mass * -9.81);
}

Vec2 ComputeAcceleration(Body& b) {
    Vec2 p, v;
    return Vec2(0, -9.81);
}

void PrintBody(Body& b) {
    std::cout << "Position: " << b.position;
}

int main(void) {
    float currTime = 0, dt = 1; 
    std::cout << "SIMULATION:\n";
    

    InitBodies();
    while (currTime < TIME_LIM) {
        for (int i = 0; i < NUM_BODIES; ++i) {
            Vec2 force = ComputeForce(bodies[i]);
            Vec2 acceleration = ComputeAcceleration(bodies[i]);
            bodies[i].velocity += acceleration * dt;

        }
    }

    return 0;
}
