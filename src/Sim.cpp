#include <iostream>
#include <unistd.h>
#include <Vec2.h>
#include <Body.h>

#define NUM_BODIES 1
#define TIME_LIM   5
#define X_BORDER   400
#define Y_BORDER   400

Body bodies[NUM_BODIES];

/* initialize the bodies */
void InitBodies(void) {
    for (int i = 0; i < NUM_BODIES; ++i) {
        Vec2 p, v;
        p = Vec2((rand() % 10) + 1, (rand() % 10) + 1);
        v = Vec2(0, 0);
        bodies[i] = Body(p, v, 1, 0);
    }
} 

Vec2 ComputeForce(Body& b) {
    return Vec2(0, b.mass * -9.81);
}

/* placeholder */
Vec2 ComputeAcceleration(Body& b) {
    return b.position;
}

int main(void) {
    float currTime = 0, dt = 1; 
    std::cout << "SIMULATION:\n";
    

    InitBodies();
    while (currTime < TIME_LIM) {

        sleep(dt);

        for (int i = 0; i < NUM_BODIES; ++i) {
            // Vec2 force = ComputeForce(bodies[i]);
            
            Vec2 acceleration = Vec2(0, -9.81);
            
            Vec2 delta_v = acceleration * dt;
            
            bodies[i].velocity += delta_v;
            
            Vec2 displacement = bodies[i].velocity * dt; 
            
            bodies[i].position += displacement;

            /* make it collide in collide.cpp */
            



            std::cout << "Position: " << bodies[i].position.toString() << " Time: " << currTime << std::endl;
        }
        currTime += dt;
    }

    return 0;
}
