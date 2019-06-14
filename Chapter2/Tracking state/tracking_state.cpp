/**
 * @file
 * @mainpage
 * Problem: Decode a message (from Think Like a Programmer: An Introduction to
 *                            Creative Problem Solving - V. Anton Spraul)
 * A message has been encoded as a text stream that is to be read character by
 * character. The stream contains a series of comma-delimited integers, each a
 * positive number capable of being represented by a C++ int. However, the
 * character represented by a particular integer depends on the current decoding
 * mode. There are three modes: uppercase, lowercase, and punctuation.
 * In uppercase mode, each integer represents an uppercase letter: The integer
 * modulo 27 indicates the letter of the alphabet (where 1 = A and so on). So an
 * input value of 143 in uppercase mode would yield the letter H because 143
 * modulo 27 is 8 and H is the eighth letter in the alphabet.
 * The lowercase mode works the same but with lowercase letters; the remainder
 * of dividing the integer by 27 represents the lowercase letter (1 = a and so
 * on). So an input value of 56 in lowercase mode would yield the letter b
 * because 56 modulo 27 is 2 and b is the second letter in the alphabet.
 * In punctuation mode, the integer is instead considered modulo 9, with the
 * interpretation given by Table 2-3 below. So 19 would yield an exclamation
 * point because 19 modulo 9 is 1.
 * At the beginning of each message, the decoding mode is uppercase letters.
 * Each time the modulo operation (by 27 or 9, depending on mode) results in 0,
 * the decoding mode switches. If the current mode is uppercase, the mode
 * switches to lowercase letters. If the current mode is lowercase, the mode
 * switches to punctuation, and if it is punctuation, it switches back to
 * uppercase.
 *      Table 2-3:
 *  | NUMBER | SYMBOL |
 *  |   1    |    !   |
 *  |   2    |    ?   |
 *  |   3    |    ,   |
 *  |   4    |    .   |
 *  |   5    | [space]|
 *  |   6    |    ;   |
 *  |   7    |    "   |
 *  |   8    |    '   |
 * 
 * Built commands: <em>
 *  g++ tracking_state.cpp tracking_state.hpp -Wall -g -std=c++14 -o track.exe
 * </em>
 */

#include "tracking_state.hpp"
#include <iostream>

using namespace std;

string receiveInputStream(void);
void displayDecodedStream(const string &s);

int main()
{
    string input = receiveInputStream();
    Decoder d(input);
    displayDecodedStream(d.decode());
}

string receiveInputStream(void)
{
    cout << "\tTracking state decoder\n"
            "Enter the coded message: ";
    string buff;
    cin >>  buff;
    return buff;
}

void displayDecodedStream(const string &s)
{
    cout << "Decoded message: " << s << endl;
}