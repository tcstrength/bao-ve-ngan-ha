#include "Indexer.h"

uint Indexer::allocate()
{
    if (m_index >= 10000)
    {
        LOG_DEBUG("Current objects: " << m_index);
        LOG_DEBUG("Becareful!!!");
    }

    if (m_stack.empty())
        return m_index++;
    uint top = m_stack.top();
    m_stack.pop();
    return top;
}

void Indexer::deallocate(uint index)
{
    if (index == m_index)
    {
        --m_index;
    }
    else
    {
        m_stack.push(index);
    }

}

uint Indexer::size()
{
    return m_index;
}
