#ifndef INDEXER_H
#define INDEXER_H

#include <iostream>
#include <stack>
#include <map>
#include "Log.h"

class Indexer
{
public:
    uint allocate();

    void deallocate(uint index);

    bool pop(uint& index);

    uint size();

private:
    uint m_index = 0;
    std::stack<uint> m_stack;
};

#endif // INDEXER_H
