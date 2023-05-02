#ifndef CPLUSPLUS_PROJECTS_STRING_H
#define CPLUSPLUS_PROJECTS_STRING_H

#include <cstddef> // size_t
#include <limits>

// Определяем структуру String
struct String {

    String(const char *str = "");
    String(size_t n, char c);
    ~String();

    void append(String &other);

    size_t size;
    char *str;
};

#endif //CPLUSPLUS_PROJECTS_STRING_H
