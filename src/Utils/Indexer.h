#ifndef INDEXER_H
#define INDEXER_H

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include "Log.h"

template <class T>
class Indexer
{
public:
    uint alloc(const T& t) {
        uint index = alloc();

        if (m_data.size() != size())
            m_data.resize(size());

        m_data[index] = t;

        return index;
    }

    void dealloc(uint index) {
        if (index == m_index)
        {
            --m_index;
        }
        else
        {
            m_stack.push(index);
        }
    }

    bool pop(uint& index) {
        if (m_index == 0 && m_stack.empty())
            return false;
        if (m_stack.empty())
        {
            index = m_index--;
        }
        else
        {
            index = m_stack.top();
            m_stack.pop();
        }

        return true;
    }

    uint size() {
        return m_index;
    }

private:
    uint alloc() {
        if (m_stack.empty())
            return m_index++;

        uint top = m_stack.top();
        m_stack.pop();
        return top;
    }

private:
    uint m_index = 0;
    std::stack<uint> m_stack;
    std::vector<T> m_data;
};

#endif // INDEXER_H
