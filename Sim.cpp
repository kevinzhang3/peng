#include <iostream>
#include <Vec2.h>
#include <Body.h>

#define NUM_BODIES 1

Body Bodies[NUM_BODIES];

void InitBodies(void) {
    for (int i = 0; i < NUM_BODIES; ++i) {
        Bodies[i] = Body();
    }
} 

Body ComputeForce(Body& b) {
    Vec2 p, v;
    float m;

    p = Vec2(0, 0);
    v = Vec2(0, b.mass * -9.81);
    m = 0;

    return Body(p, v, m);
}

int main(void) {
    std::cout << "SIMULATION:\n";


    return 0;
}
