#include "stack.h"

Stack::Stack()
{

}

Stack::Stack(const Vector& vector)
{
    stack = vector;
}

Stack::Stack(const Stack& other)
{
    stack = other.stack;
}

int& Stack::top()
{
    return stack.back();
}

void Stack::pop()
{
    stack.pop_back();
}

void Stack::push(int element)
{
    stack.push_back(element);
}

int Stack::size()
{
    return stack.size();
}

bool Stack::empty()
{
    return stack.empty();
}