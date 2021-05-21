#include <stdio.h>
#include <memory>
#include <windows.h>

#include "Window.h"
#include "GameEngine.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window x("test", 500, 500);

    x.drawIMG(0, 0, "fond.png");
    x.refresh();



    PhysicRuler physicRuler(new Ball());
    physicRuler.addHitbox(new Hitbox(0, 0, 500, 500, false, new ChangeTrajectoryEffect(drop)), "test");
    Sleep(1000);
    return 0;
}