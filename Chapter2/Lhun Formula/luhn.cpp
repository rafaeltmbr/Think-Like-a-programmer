/**
 * @mainpage
 *
 * Problem: Luhn checksum validation
 * The Luhn formula is a widely used system for validating identification
 * numbers. Using the original number, double the value of every other digit.
 * Then add the values of the individual digits together (if a doubled value
 * now has two digits, add the digits individually). The identification number
 * is valid if the sum is divisible by 10.Write a program that takes an
 * identification number of arbitrary length and determines whether the number
 * is valid under the Luhn formula. The program must process each character
 * before reading the next one.
 * <br>
 * Build commands: <b>
 *  g++ luhn.cpp -Wall -g -std=c++14 -o luhn.exe
 * </b>
 */

#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;

#define LUHN_NUMBER_LENGTH 10

/**
 * Luhn class
 */
class Luhn {
    unsigned long evenSum = 0;
    unsigned long oddSum = 0;
    unsigned int length = 0;
    int getDoubledSum(int i) {
        i *= 2;
        return i / 10 + i % 10;
    }
public:
    void add(char i) {
        int temp = getDoubledSum(i);
        bool even = ++length % 2 == 0;
        oddSum += even ? temp : i;
        evenSum += !even ? temp : i;
    }
    bool addChar(char c) {
        if (! isdigit(c) )
            return false;
        add(c - '0');
        return true;
    }
    bool isValid(void) {
        return length % 2 == 0 ? evenSum % 10 == 0 : oddSum % 10 == 0;
    }
    unsigned long getSum(void) {
        return length % 2 == 0 ? evenSum : oddSum;
    }
};

/**
 * This is where the party begin.
 */
int main() {
    Luhn check;
    cout << "\tLuhn check sum\n"
            "Please enter a " << LUHN_NUMBER_LENGTH << " digit number: ";
    while ( check.addChar( cin.get() ) )
        ;
    cout << ( check.isValid() ? "Valid" : "Invalid" ) << " number" << endl;
    cout << "Sum: " << check.getSum() << endl;
}