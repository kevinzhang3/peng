#include <iostream>
#include <Vec2.h>
#include <Body.h>

Body ComputeForce() {
    Vec2 p, v, m;

    p = Vec2(0, 0);

    return Body(p, v, m);
}

int main(void) {
    std::cout << "main\n";
    return 0;
}
