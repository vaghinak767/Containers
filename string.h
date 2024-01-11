#ifndef
#define STRING_H

class String
{
    private:
        int m_size;
        char *arr;
    public:
        Srting();
        String(const char *s);
        String(String& other);
        ~String();
        String& operator=(const String& other);
        size_t size();
        char* c_str();
        String& append(const String&);
        String& append(const char*); 
        char& at(size_t);
        char& back();
        void clear();
};

#endif