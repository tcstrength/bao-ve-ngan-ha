#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <list>
#include <queue>

struct Config
{
    const char* title = "Bao Ve Ngan Ha";
    uint width = 1600;
    uint height = 900;
    uint frameRate = 120;
    bool fullscreen = false;
    bool vsync = true;
    bool galaxyEffect = true;
};

#endif // CONFIG_H
