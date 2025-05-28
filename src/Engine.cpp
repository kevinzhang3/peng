#include <Body.h>
#include <Vec2.h>
#include <unistd.h>

extern Box Bodies[NUM_BODIES];

int main() {
    
    float simTime = 10;
    float currTime = 0;
    
    int step = 500000; // time step (500 000 microsec == 0.5 sec)
    float dt = (float)step / 1000000;

    InitBodies();
    while (currTime < simTime) {
        for (int i = 0; i < NUM_BODIES; ++i) {
            Box *body = &Bodies[i];
            body->ComputeTorque(Vec2(0, 9.81*body->mass), Vec2()); // apply gravity at centre of mass
            
            body->l_velocity += 
            PrintBodies(); 
            sleep(step);
        }
        currTime += dt;
    }

}
