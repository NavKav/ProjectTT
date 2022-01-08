#include <stdio.h>
#include <memory>
#include <windows.h>

#include "Displayer/Window.h"
#include "GameEngine/GameEngine.h"
#include "Player/Player.h"

#undef main

using namespace std;

int main( int argc, char *argv[] )
{
    Window window("test", 1000, 700);
    window.drawIMG(0, 0, "fond.png");
    window.refresh();
    DisplayerConnection displayerConnection(&window);

    PhysicRuler physicRuler(new Ball(), &displayerConnection);
    physicRuler.addHitbox(new Hitbox(400, 620, 894, 680, false, new BounceEffect(0, 1.7)), "table");

    Player player(&physicRuler);
    player.start();

    //Sleep(1000);
    return 0;
}