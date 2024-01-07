#include "stack.h"

int main()
{
    Stack a;
    for(int i = 0; i < 4; ++i)
    {
        int ab = 0;
        std::cin >> ab;
        a.push(ab);
    }
    for(int i = 0; i < 4; ++i)
    {
        std::cout << a.top() << " ";
        a.pop();
    }
}