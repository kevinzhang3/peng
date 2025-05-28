#include <Body.h>


Box Bodies[NUM_BODIES];

void InitBodies() {
    for (int i = 0; i < NUM_BODIES; ++i) {
        Vec2 pos = Vec2();
        Vec2 velocity = Vec2();
        float h = 1;
        float w = 1;
        float m = 1;

        Bodies[i] = Box(pos, velocity, h, w, m);
        Bodies[i].ComputeTorque(Vec2(), Vec2());
    }
}

void PrintBodies() {
    for (int i = 0; i < NUM_BODIES; ++i) {
        printf("BODY:%d { POSITION: (%f, %f), ANGLE: %f }\n", i, 
                Bodies[i].position.x, Bodies[i].position.y, Bodies[i].angle);
    }
}
