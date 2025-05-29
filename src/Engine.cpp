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
            Vec2 gravityForce = Vec2(0, 9.81*body->mass);
            
            body->force += gravityForce;
            body->torque = body->ComputeTorque(gravityForce, Vec2()); // apply gravity at centre of mass
            body->l_accel = body->ComputeLinearAccel(body->force);
            
            // calc the new velocity
            Vec2 newVel = body->l_accel * dt;
            body->l_velocity += newVel;
            
            // calc the new position based on new velocity
            Vec2 newPos = body->l_velocity * dt;
            body->position += newPos;

            // same for rotation (but luckily they are not vectors lol)
            body->a_velocity += body->a_accel * dt;
            body->angle += body->a_velocity * dt;

        }
        PrintBodies(); 
        currTime += dt;
        usleep(step);
    }

}
