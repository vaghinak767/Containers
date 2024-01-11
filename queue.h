#ifndef QUEUE_H
#define QUEUE_H
#include "vector.h"
class Queue
{
    private:
        Vector m_queue;
    public:
        int& front();
        int& back();
        bool empty();
        int size();
        void push(int);

};
#endif