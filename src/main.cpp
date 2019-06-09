#include <irrlicht.h>
#include "Core.hpp"

int main(void)
{
    Core *core = new Core(1920, 1080);
    int i = 0;

    //core->genMap();
    core->menu_loop();
}