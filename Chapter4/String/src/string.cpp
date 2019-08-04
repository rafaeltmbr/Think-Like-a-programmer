#include "../include/string.hpp"
#include <cstring>

String::String (char character)
{
    list.push_back(character);
}

String::String(const char* cstr)
{
    unsigned int length = strlen(cstr);
    for (unsigned int i=0; i < length; i++)
        list.push_back(cstr[i]);
}

String::String(const String& str)
{
    list = str.list;
}

String::~String()
{
    delete cstr;
}

const char* String::cstring(void)
{
    unsigned int len= list.size();
    if (cstrSize != len) {
        delete cstr;
        cstr = new char[len+1];
        cstrSize = len;
    }

    for (unsigned int i=0; i < len; i++)
        cstr[i] = list[i];
    cstr[len] = '\0';
    return cstr;
}

char String::pop(void)
{
    int size = list.size();
    if (size < 1)
        return '\0';

    char c = list.back();
    list.pop_back();
    return c;
}

int String::indexOf(char character)
{
    cstring();
    for (unsigned int i=0; cstr[i]; i++)
        if (cstr[i] == character)
            return i;
    return -1;
}

int String::indexOf(const char* cstr)
{
    cstring();
    char* strptr = strstr(this->cstr, cstr);
    return strptr ? strptr - this->cstr: -1;
}

int String::indexOf(const String& str)
{
    unsigned int len = str.size();
    char temp[len+1];
    for (unsigned int i = 0; i < len; i++)
        temp[i] = str[i];
    temp[len] = '\0';
    return indexOf(temp);
}

int String::indexOf(String& str)
{
    return indexOf(str.cstring());
}

String& String::operator=(char character)
{
    list.clear();
    list.push_back(character);
    return *this;
}

String& String::operator=(const char* cstr)
{
    list.clear();
    for (unsigned int i=0, len = strlen(cstr); i < len; i++)
        list.push_back(cstr[i]);
    return *this;
}

String& String::operator=(const String& str)
{
    list = str.list;
    return *this;
}

String& String::operator+(char character)
{
    list.push_back(character);
    return *this;
}

String& String::operator+(const char* cstr)
{
    for (unsigned int i=0; cstr[i]; i++)
        list.push_back(cstr[i]);
    return *this;
}

String& String::operator+(const String& str)
{
    unsigned int len= str.list.size();
    for (unsigned int i=0; i < len; i++)
        list.push_back(str.list[i]);

    return *this;
}

bool String::operator==(char character) const
{
    return list.size() == 1 && character == list[0];
}

bool String::operator==(const char* cstr) const
{
    unsigned int len = strlen(cstr);
    if (len != list.size())
        return false;
    for (unsigned int i=0; i < len; i++)
        if (cstr[i] != list[i])
            return false;
    return true;
}

bool String::operator==(const String& str) const
{
    unsigned int len= str.list.size();
    if (len != list.size())
        return false;
    for (unsigned int i=0; i < len; i++)
        if (str.list[i] != list[i])
            return false;
    return true;
}

bool String::operator!=(char character) const
{
    return ! (*this == character);
}

bool String::operator!=(const char* cstr) const
{
    return ! (*this == cstr);
}

bool String::operator!=(const String& str) const
{
    return ! (*this == str);
}