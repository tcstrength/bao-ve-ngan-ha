#include "Misc.h"

float randf()
{
    bool neg = rand() % 2;
    if (neg)
    {
        return -1 * static_cast<float>(rand()) / RAND_MAX;
    }

    return static_cast<float>(rand()) / RAND_MAX;
}
