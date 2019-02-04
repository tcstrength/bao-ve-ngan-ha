#include "Context.h"

Context::Context(Config& config_)
:   config(config_)
,   window(config_)
,   transformer(config_)
{
    shader.load();
}

Context::~Context()
{
    clear();
}

void Context::clear()
{
    window.close();
}
