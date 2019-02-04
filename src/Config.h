#ifndef CONFIG_H
#define CONFIG_H

struct Config
{
    const char* title = "Bao Ve Ngan Ha";
    const char* vsPath = "shaders/shader.vs";
    const char* fsPath = "shaders/shader.fs";
    int width = 1080;
    int height = 720;
    bool fullscreen = false;
    bool vsync = false;
};

#endif // CONFIG_H
