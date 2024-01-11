#include "queue.h"

int &Queue::front()
{
    if(m_queue.size == 0)
    {
        throw out_of_range(" ");
    }
    return m_queue.arr[0]; 
}

int& Queue::back()
{
    if(m_queue.size == 0)
    {
        throw out_of_range(" ");
    }
    return m_queue.arr[size - 1];    
}

bool Queue::empty()
{
    return !m_queue.size;
}

int Queue::size()
{
    return m_queue.size;
}

void Queue::push(int element)
{
    m.queue.push_back(element);
}