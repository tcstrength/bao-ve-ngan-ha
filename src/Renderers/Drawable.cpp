#include "Drawable.h"

uint Drawable::m_count = 0;

Drawable::Drawable()
{
    ++m_count;
    LOG_DEBUG("numObjects: " << m_count);
}

Drawable::~Drawable()
{
    --m_count;
    LOG_DEBUG("numObjects: " << m_count);
}
