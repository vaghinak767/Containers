#include "vector.h"

Vector::Vector()
{
    m_size = 0;
    arr = new int[m_size + 1];
    arr[0] = 0;
}

Vector::Vector(int size)
{
    m_size = 0;
    arr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        arr[i] = 0;
    }
    m_capacity = size;
}

Vector::Vector(const Vector &obj)
{
    m_size = obj.m_size;
    m_capacity = obj.m_capacity;
    arr = new int[obj.m_capacity];
    for(int i = 0; i < obj.m_size; ++i)
    {
        arr[i] = obj.arr[i];
    }
}

Vector::Vector(int count, int value)
{
    arr = new int[count];
    for (int i = 0; i < count; ++i)
    {
        arr[i] = value;
    }
    m_size = count;
    m_capacity = count;
}

// Vector::Vector(int first, int last)
// {

// }

Vector::Vector(std::initializer_list<int> init)
{
    for(int i = 0; i < init.size(); ++i)
    {
        arr[i] = *(init.begin() + i);
    }
}

Vector::~Vector()
{
    delete[] arr;
}

int Vector::size()
{
    return m_size;
}

int Vector::capacity()
{
    return m_capacity;
}

bool Vector::empty()
{
    return !m_size;
}

int Vector::at(int index)
{
    if (index >= m_size)
    {
        throw std::out_of_range(" ");
    }
    return arr[index];
}

void Vector::push_back(int value)
{
    if (m_size == m_capacity)
    {
        resize();
    }
    arr[m_size] = value;
    ++m_size;
}

void Vector::pop_back()
{
    arr[m_size - 1] = 0;
    --m_size;
}

int *Vector::data()
{
    return arr;
}

void Vector::clear()
{
    delete[] arr;
    arr = nullptr;
    m_size = 0;
    m_capacity = 0;
}

void Vector::insert(int index, int value)
{
    if (index >= m_capacity)
    {
        throw std::out_of_range(" ");
    }
    if (m_size == m_capacity)
    {
        m_capacity *= 2;
    }
    int *tmp = new int[m_capacity];
    for (int i = 0; i < index; ++i)
    {
        tmp[i] = arr[i];
    }
    tmp[index] = value;
    for (int i = index + 1; i < m_size + 1; ++i)
    {
        tmp[i] = arr[i - 1];
    }
    arr = tmp;
    delete[] arr;
    ++m_size;
}


void Vector::display()
{
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void Vector::swap(Vector &other)
{
    int tmp = m_size;
    m_size = other.m_size;
    other.m_size = tmp;
    int cmp = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = cmp;
    int *a = arr;
    arr = other.arr;
    other.arr = a;
}

void Vector::assign(int count, const int &value)
{
    if (count > m_capacity)
    {
        int *arr1 = new int[count];
        delete[] arr;
        arr = arr1;
        m_capacity = count;
    }
    for (int i = 0; i < count; ++i)
    {
        arr[i] = value;
    }
}

int Vector::front()
{
    if (empty())
    {
        throw std::out_of_range(" ");
    }
    return arr[0];
}

int& Vector::back()
{
    if (empty())
    {
        throw std::out_of_range(" ");
    }
    return arr[m_size - 1];
}

int *Vector::begin()
{
    if (empty())
    {
        return nullptr;
    }
    return arr;
}

int *Vector::end()
{
    if (empty())
    {
        return nullptr;
    }
    return arr + m_size;
}
void Vector::revers()
{
    for (int i = 0; i < m_size / 2; ++i)
    {
        int tmp = arr[i];
        arr[i] = arr[m_size - 1 - i];
        arr[m_size - 1 - i] = tmp;
    }
}

void Vector::resize(int size)
{
    int *arr1 = new int[size];
    for (int i = 0; i < m_size; ++i)
    {
        arr1[i] = arr[i];
    }
    delete[] arr;
    arr = arr1;
    m_capacity = size - 1;
}

void Vector::erase(int index)
{
    at(index);
    for (int i = index; i < m_size - 2; ++i)
    {
        arr[i] = arr[i + 1];
    }
    arr[m_size - 1] = 0;
    --m_size;
}

void Vector::erase(int first, int last)
{
    at(first);
    at(last);
    for(int i = first; i < last; ++i)
    {
        arr[i] = 0;
    } 
    for (int i = first; i < last; ++i)
    {
        int tmp = arr[i];
        arr[i] = arr[last + 1 + i];
        arr[last + 1 + i] = tmp;
    }
    m_size -= (last - first + 1);
}

Vector &Vector::operator=(const Vector &other)
{
    if (this != &other)
    {
        this->clear();
        this->m_capacity = other.m_capacity;
        this->arr = new int[m_capacity];
        this->m_size = other.m_size;
        for(int i = 0; i < m_size; ++i)
        {
            this->arr[i] = other.arr[i];
        } 
    }
    return *this;
}
const int Vector::operator[](int index)
{
    return this->arr[index];
}

const Vector Vector::operator+(Vector& ob)
{
    Vector tmp;
    if(ob.m_size >= this->m_size)
    {
        for(int i = 0; i < this->m_size; ++i)
        {
            tmp.push_back(this->arr[i] + ob[i]);
        }
        for(int i = this->m_size; i < ob.m_size; ++i)
        {
            tmp.push_back(ob[i]);
        }
    }
    else
    {
        for(int i = 0; i < ob.m_size; ++i)
        {
            tmp.push_back(this->arr[i] + ob[i]);
        }
        for(int i = ob.m_size; i < this->m_size; ++i)
        {
            tmp.push_back(this->arr[i]);
        }
    }
    return tmp;
}

// const Vector operator-(Vector& ob)
// {
//     Vector tmp;
//     if(ob.m_size >= this->m_size)
//     {
//         for(int i = 0; i < this->m_size; ++i)
//         {
//             tmp.push_back(this->arr[i] + ob[i]);
//         }
//         for(int i = this->m_size; i < ob.m_size; ++i)
//         {
//             tmp.push_back(ob[i]);
//         }
//     }
//     else
//     {
//         for(int i = 0; i < ob.m_size; ++i)
//         {
//             tmp.push_back(this->arr[i] + ob[i]);
//         }
//         for(int i = ob.m_size; i < this->m_size; ++i)
//         {
//             tmp.push_back(this->arr[i]);
//         }
//     }
//     return tmp;
// }
