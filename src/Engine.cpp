#include <Body.h>
#include <Vec2.h>

extern Box Bodies[NUM_BODIES];

int main() {
    float simTime = 10;
    float currentTime = 0;
    float dt = 0; // time step

    InitBodies();
    for (int i = 0; i < NUM_BODIES; ++i) {
        Box *body = &Bodies[i];
        body->ComputeTorque(Vec2(0, 9.81*body->mass), Vec2()); // apply gravity at centre of mass
        PrintBodies(); 
    }

}
