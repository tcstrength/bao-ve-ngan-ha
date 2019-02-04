#ifndef CONTEXT_H
#define CONTEXT_H

#include "Utils/Log.h"
#include "Utils/Misc.h"
#include "Utils/Indexer.h"
#include "Entities/Transformer.h"
#include "Renderers/Window.h"

class Context
{
public:
    Config& config;
    Window window;
    Shader2D shader;
    Transformer transformer;

    Context(Config& config_);

    ~Context();

    void clear();

private:


};

#endif // CONTEXT_H
