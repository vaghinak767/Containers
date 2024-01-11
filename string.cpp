#include "string.h"

String::String()
{
    m_size = 1;
    arr = new char[m_size]
    arr[0] = '\0';
}

String::String(const char* s)
{
    m_size = 1;
    char *tmp = s;
    while(*tmp)
    {
        ++m_size;
        ++tmp;
    }
    arr = new char[m_size];
    int i = 0;
    while(s[i])
    {
        arr[i] = s[i];
        ++i;
    }
    arr[i] = '\0';
}

String::String(String& other)
{
    m_size = other.m_size;
    arr = new char[other.m_size];
    int i = 0;
    while(other.arr[i])
    {
        arr[i] = other.arr[i];
    }
    arr[i] = '\0';
}

String::~String()
{
    delete[]arr;
}

String& operator=(const String& other)
{
    this->m_size = other.m_size;
    delete[]this->arr;
    this->arr = new char[m_size];
    int i = 0;
    while(other.arr[i])
    {
        this->arr[i] = other.arr[i];
    }
    this->arr[i] = '\0';
    return *this;
}

size_t String::size()
{
    return m_size; 
}

char* c_str()
{
    return arr;
}

String& String::append(const String& str)
{
    int i = 0;
    while(str[i])
    {
        this->arr[m_size - 1] = str[i];
        ++this->m_size;
    }
    this->arr[m_size - 1] = '\0';
    return *this
}

String& append(const char*)
{
    int i = 0;
    while(str[i])
    {
        this->arr[m_size - 1] = str[i];
        ++this->m_size;
    }
    this->arr[m_size - 1] = '\0';
    return *this
}

char& String::at(size_t pos)
{
    if(m_size < pos)
    {
        throw out_of_range(" ");
    }
    return arr[pos];
}

char& String::back()
{
    return arr[size - 2];
}

void String::clear()
{
    
}