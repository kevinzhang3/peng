#include <Body.h>

#define NUM_BODIES 1

Box boxes[NUM_BODIES];

void InitBodies() {
    for (int i = 0; i < NUM_BODIES; ++i) {
        Vec2 pos = Vec2();
        Vec2 velocity = Vec2();
        float h = 1;
        float w = 1;
        float m = 1;

        boxes[i] = Box(pos, velocity, h, w, m);
        boxes[i].ComputeTorque(Vec2(), Vec2());
    }
}

void PrintBodies() {
    for (int i = 0; i < NUM_BODIES; ++i) {
        printf("BOX:%d { POSITION: (%f, %f), ANGLE: %f }", i, 
                boxes[i].position.x, boxes[i].position.y, boxes[i].angle);
    }
}
