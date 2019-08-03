/* Build commands:
    g++ string-testbench.cpp ../src/string.cpp -g -Wall -std=c++14 -o string.exe
 */

#include "../include/string.hpp"
#include <cstring>
#include <iostream>

using namespace std;

#define ASSERT(cmp, msg)                                                              \
    {                                                                                 \
        if (cmp)                                                                      \
            std::cout << "#";                                                         \
        else {                                                                        \
            std::cerr << "\n Test failed (" << __LINE__ << "): " << msg << std::endl; \
            exit(EXIT_FAILURE);                                                       \
        }                                                                             \
    }

void testConstructor(void);
void testArrayAccess(void);
void testPushPop(void);
void testIndexOf(void);
void testAssignment(void);
void testConcatenation(void);
void testEqualityInequality(void);

int main()
{
    cout << "----------------------- String Testbench -----------------------\n";
    testConstructor();
    testArrayAccess();
    testPushPop();
    testIndexOf();
    testAssignment();
    testConcatenation();
    testEqualityInequality();
    cout << "----------------------- Testbench Succeed-----------------------" << endl;
}

void testConstructor(void)
{
    cout << " Constructor Test: ";

    char c[2] = { 'C', '\0' };
    String charstr(c[0]);
    ASSERT(strcmp(charstr.cstring(), c) == 0, "charstring constructor failed");

    String cstr("Okay");
    ASSERT(strcmp(cstr.cstring(), "Okay") == 0, "cstring constructor failed");

    String strstring(cstr);
    ASSERT(strcmp(strstring.cstring(), cstr.cstring()) == 0, "string constructor failed");

    cout << " PASSED\n";
}

void testArrayAccess(void)
{
    cout << " Array Access Test: ";

    char cstr[] = { 'T', 'E', 'S', 'T' };
    String str = "test";

    for (int i = 0; i < str.size(); i++)
        str[i] = str[i] + ('A' - 'a');

    ASSERT(strcmp(str.cstring(), cstr) == 0, "array access failed");

    cout << " PASSED\n";
}

void testPushPop(void)
{
    cout << " Push and Pop Test: ";

    const int arraySize = 3;
    char cArray[arraySize] = { '4', '5', '6' };
    String str = ("123");

    for (int i = 0; i < arraySize; i++)
        str.push(cArray[i]);
    ASSERT(strcmp(str.cstring(), "123456") == 0, "push() failed");

    ASSERT(str.pop() == '6', "pop() failed");
    ASSERT(str.pop() == '5', "pop() failed");
    ASSERT(strcmp(str.cstring(), "1234") == 0, "pop() failed");

    str.clear();
    ASSERT(str.size() == 0, "clear() failed");
    ASSERT(str.pop() == 0, "pop() failed");
    ASSERT(str.size() == 0, "size() failed");

    cout << " PASSED\n";
}

void testIndexOf(void)
{
    cout << " IndexOf Test: ";

    String str = "Banana";
    ASSERT(str.indexOf('a') == 1, "indexOf() failed");
    ASSERT(str.indexOf('A') == -1, "indexOf() failed");
    ASSERT(str.indexOf("na") == 2, "indexOf() failed");
    ASSERT(str.indexOf("nas") == -1, "indexOf() failed");
    ASSERT(str.indexOf("Banana") == 0, "indexOf() failed");
    ASSERT(str.indexOf("Bananas") == -1, "indexOf() failed");
    ASSERT(str.indexOf(str) == 0, "indexOf() failed");
    ASSERT(str.size() == 6, "size() failed");

    cout << " PASSED\n";
}

void testAssignment(void)
{
    cout << " Assignment Test: ";

    String str;
    ASSERT(str.size() == 0, "size() failed");

    str = "Okay";
    ASSERT(strcmp(str.cstring(), "Okay") == 0, "assignment failed");
    ASSERT(str.size() == 4, "size() failed");

    char c[] = { 'X', '\0' };
    str = c[0];
    ASSERT(strcmp(str.cstring(), c) == 0, "assignment failed");
    ASSERT(str.size() == 1, "size() failed");

    String str2 = "Huge";
    str = str2;
    ASSERT(strcmp(str.cstring(), "Huge") == 0, "assignment failed");
    ASSERT(str.size() == 4, "size() failed");

    str = "";
    ASSERT(strcmp(str.cstring(), "") == 0, "assignment failed");
    ASSERT(str.size() == 0, "size() failed");

    cout << " PASSED\n";
}

void testConcatenation(void)
{
    cout << " Concatenation Test: ";

    String date;
    String month = "August";
    String day = '3';

    date = month + ' ' + day + ", 2019";
    ASSERT(strcmp(date.cstring(), "August 3, 2019") == 0, "concatenation failed");
    ASSERT(date.length() == strlen("August 3, 2019"), "length() failed");

    cout << " PASSED\n";
}

void testEqualityInequality(void)
{
    cout << " Equality and Inequality Test: ";

    String str1 = "Apple", str2 = "Apples";
    ASSERT(str1 != str2, "inequality failed");

    ASSERT(str2 == str2, "equality() failed");

    str2.pop();
    ASSERT(str1 == str2, "equality failed");

    cout << " PASSED\n";
}