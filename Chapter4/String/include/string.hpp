#ifndef STRING_HPP
#define STRING_HPP

#include <vector>

class String {
protected:
    std::vector<char> list;
    char* cstr = nullptr;
    unsigned int cstrSize = 0;

public:
    String() {};
    String (char character);
    String(const char* cstr);
    String(const String& str);
    ~String();
    char& operator[](int index) { return list[index]; }
    char operator[](int index) const { return list[index]; }
    const char* cstring(void);
    int size(void) const { return list.size(); }
    int length(void) const { return list.size(); }
    void clear(void) { list.clear(); }
    void push(char c) { list.push_back(c); }
    char pop(void);
    int indexOf(char character);
    int indexOf(const char* cstr);
    int indexOf(const String& str);
    int indexOf(String& str);
    String& operator=(char character);
    String& operator=(const char* cstr);
    String& operator=(const String& str);
    String& operator+(char character);
    String& operator+(const char* cstr);
    String& operator+(const String& str);
    bool operator==(char character) const;
    bool operator==(const char* cstr) const;
    bool operator==(const String& str) const;
    bool operator!=(char character) const;
    bool operator!=(const char* cstr) const;
    bool operator!=(const String& str) const;
};

#endif //STRING_HPP