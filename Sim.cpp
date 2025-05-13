#include <iostream>
#include <Vec2.h>
#include <Body.h>

#define NUM_BODIES 1

Body Bodies[NUM_BODIES];

/* initialize the bodies */
void InitBodies(void) {
    for (int i = 0; i < NUM_BODIES; ++i) {
        Vec2 p, v;
        p = Vec2((rand() % 10) + 1, (rand() % 10) + 1);
        v = Vec2(0, 0);
        Bodies[i] = Body(p, v, 1);
    }
} 

Body ComputeForce(Body& b) {
    Vec2 p, v;

    p = Vec2(0, 0);
    v = Vec2(0, b.mass * -9.81);

    return Body(p, v, 0);
}

int main(void) {
    Body b;

    std::cout << "SIMULATION:\n";


    return 0;
}
