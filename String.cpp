#include <cstring> // strlen, strcpy
#include "string.h"

String:: String(const char *str)
{
    size_t t = 0;
    while(*str++) {
        t++;
    }
    this->str = new char[t + 1];
    str = str - t - 1;
    strcpy(this->str, str);
    this->size = t;
}

String::String(size_t n, char c)
{
    this->size = n;
    this->str = new char[n + 1];
    for(size_t i = 0; i < n; i++)
    {
        this->str[i] = c;
    }
    this->str[n] = '\0';
}

String::~String()
{
    delete [] str;
}

void String::append(String &other)
{
    size_t new_size = this->size + other.size;
    char * new_t = new char[new_size + 1];
    char * s1 = this->str;
    char * s2 = other.str;

    while(*new_t++ = *(s1++));
    new_t--;
    while(*new_t++ = *(s2++));

    delete [] this->str;

    this->str = (new_t - new_size - 1);
    this->size = new_size;
}