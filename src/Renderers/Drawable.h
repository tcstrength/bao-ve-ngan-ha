#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "../Utils/Log.h"
#include "../Utils/NonCopyable.h"

class Drawable
{
public:
    Drawable();

    virtual ~Drawable();

    virtual void update() = 0;

    virtual void draw() = 0;

private:
    static uint m_count;
};

#endif // DRAWABLE_H
