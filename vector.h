#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector
{
    private:
        int m_size;
        int m_capacity;
        int *arr;
        void resize()
        {
            m_capacity *= 2;
            int *tmp = new int[m_capacity];
            for (int i = 0; i < m_size; ++i)
            {
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
        }
    public:
        Vector();
        Vector(int);
        Vector(const Vector&);
        Vector(int, int);
        //Vector(int first, int last);
        Vector(std::initializer_list<int>);
        ~Vector();
        int size();
        int capacity();
        bool empty();
        int at(int);
        void push_back(int);
        void pop_back();
        int *data();
        void clear();
        void insert(int, int);
        void display();
        void swap(Vector&);
        void assign(int, const int&);
        int front();
        int& back();
        int* begin();
        int* end();
        void revers();
        void resize(int);
        void erase(int);
        void erase(int, int);
        Vector& operator=(const Vector&);
        const int operator[](int index);
        const Vector operator+(Vector&);
        //const Vector operator-(Vector&);
};

#endif
