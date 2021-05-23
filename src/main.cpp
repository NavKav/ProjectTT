#include <stdio.h>
#include <memory>
#include <windows.h>

#include "Window.h"
#include "GameEngine/GameEngine.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("test", 1000, 700);

    window.drawIMG(0, 0, "fond.png");
    window.refresh();

    DisplayerConnection displayerConnection(&window);

    PhysicRuler physicRuler(new Ball(), &displayerConnection);
    physicRuler.addHitbox(new Hitbox(400, 600, 500, 700, false, new ChangeTrajectoryEffect(drop)), "table");
    Sleep(2000);
    return 0;
}