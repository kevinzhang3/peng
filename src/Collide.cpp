#include <Body.h>
#include <Util.h>



int CollideBody(Body& bodyA, Body& bodyB) {
    // explosion
    return 0;
}

int CollideBarrier(Body& body) {
    if (body.position.x + body.radius >= X_BORDER) {
        //
    }
    return 0;
}
