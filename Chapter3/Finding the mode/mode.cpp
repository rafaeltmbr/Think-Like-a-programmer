/**
 * @page
 * @mainpage
 * 
 * Problem: Finding the mode
 * In statistics, the mode of a set of values is the value that appears most
 * often. Write code that processes an array of survey data, where survey takers
 * have responded to a question with a number in the range 1–10, to determine
 * the mode of the data set. For our purpose, if multiple modes exist, any may
 * be chosen.
 * 
 * Build commands: <em>
 *      g++ mode.cpp -Wall -g -std=c++14 -O0 -o mode.exe
 * </em>
 */

#include <cstdint>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define ABS(x) ( (x) < 0 ? -(x) : (x) )
#define ARRAY_LENGTH 10

void fillArray(int* arrayInt, int arrayLength, int rangeStart, int rangeEnd);
void printArray(int* arrayInt, int arrayLength, const char* separator);
int mode(int* arrayInt, const int arrayLength, const int rangeStart,
        const int rangeEnd);
int biggerCountIndex(int* arrayInt, int arrayLength);

int main()
{
    int survey[ARRAY_LENGTH];
    fillArray(survey, ARRAY_LENGTH, 1, 10);
    printArray(survey, ARRAY_LENGTH, ", ");
    std::cout << "\nmode: " << mode(survey, ARRAY_LENGTH, 1, 10) << std::endl;
}

void fillArray(int* arrayInt, int arrayLength, int rangeStart, int rangeEnd)
{
    const int mod = rangeEnd - rangeStart + 1;

    srand(time(nullptr));
    for (int i=0; i < arrayLength; i++)
        arrayInt[i] = rand() % mod + rangeStart;
}

void printArray(int* arrayInt, int arrayLength, const char* separator)
{
    const int lastItem = arrayLength - 1;
    for (int i=0; i < lastItem; i++)
        std::cout << arrayInt[i] << separator;
    std::cout << arrayInt[lastItem];
}

int mode(int* arrayInt, const int arrayLength, const int rangeStart,
        const int rangeEnd)
{
    const int countLength = ABS(rangeEnd - rangeStart + 1);
    int count[countLength] = {0};

    for (int i=0; i < arrayLength; i++)
        count[ arrayInt[i] - rangeStart ]++;

    return biggerCountIndex(count, countLength) + rangeStart;
}

int biggerCountIndex(int* arrayInt, int arrayLength)
{
    int biggerIndex = 0;
    int biggerCount = arrayInt[0];
    for (int i=1; i < arrayLength; i++) {
        if (arrayInt[i] > biggerCount) {
            biggerIndex = i;
            biggerCount = arrayInt[i];
        }
    }
    return biggerIndex;
}