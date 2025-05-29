#include <Body.h>
#include <Vec2.h>
#include <unistd.h>

extern Box Bodies[NUM_BODIES];

int main() {
    
    float simTime = 10;
    float currTime = 0;
    
    int step = 1000000; // time step (500 000 microsec == 0.5 sec)
    float dt = 1;

    InitBodies();
    while (currTime < simTime) {
        
        usleep(step);
        
        for (int i = 0; i < NUM_BODIES; ++i) {
            Box *body = &Bodies[i];
            
            Vec2 gravityForce = Vec2(0, -9.81*body->mass);
           
            // set force and acceleration for linear and angular
            body->force = gravityForce;
            body->torque = body->ComputeTorque(gravityForce, Vec2()); // apply gravity at centre of mass
            body->l_accel = body->ComputeLinearAccel(body->force);
            body->a_accel = body->ComputeRotAccel(body->torque);

            // calc the new velocity and the avg
            Vec2 oldVelocity = body->l_velocity;
            body->l_velocity += body->l_accel * dt;
            Vec2 avgVelocity = (oldVelocity + body->l_velocity) / 2; // could use Euler integration here instead 
                                                                     // maybe for smaller time step?
            
            // calc the new position
            body->position += avgVelocity * dt;

            // same for rotation (but luckily they are not vectors lol)
            body->a_velocity += body->a_accel * dt;
            body->angle += body->a_velocity * dt;

        }
        
        PrintBodies(); 
        currTime += dt;
    }

}
