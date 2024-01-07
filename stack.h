#ifndef STACK_H
#define STACK_H
#include "vector.h"

class Stack
{
    private:
        Vector stack;
    public:
        Stack();
        Stack(const Vector&);
        Stack(const Stack&);
        int& top();
        void pop();
        void push(int);
        int size();
        bool empty();
};

#endif