#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <list>
#include <queue>

struct Config
{
    const char* title = "Bao Ve Ngan Ha";
    uint width = 1280;
    uint height = 720;
    uint frameRate = 120;
    bool fullscreen = false;
    bool vsync = true;
};

#endif // CONFIG_H
