/**
 * @file
 * @mainpage
 * This is a series of problems suggested by the book "Think like a programmer".
 * <br>
 * The goal here is to solve the problem with the techniques i've learned
 * during the reading.
 * <br><br>
 * 
 * <h3>Problem: Half of a square</h3>
 * <em>Write a program that uses only two output statements, cout << "#" and
 * cout << "\n", to produce a pattern of hash symbols shaped like half of a
 * perfect 5 × 5 square (or a right triangle): </em><br>
 * <pre>
 * #####
 * ####
 * ###
 * ##
 * #
 * </pre>
 * <br>
 * 
 * <h3>Problem: A sideways triangle</h3>
 * <em>Write a program that uses only two output statements, cout << "#" and
 * cout << "\n", to produce a pattern of hash symbols shaped like a sideways
 * triangle: </em><br>
 * <pre>
 * #
 * ##
 * ###
 * ####
 * ###
 * ##
 * #
 * </pre>
 * <br>
 * 
 * Build commands: g++ shape.cpp -Wall -std=c++14 -g -o shape.exe
 */

#include <iostream>

void drawHalfSquare(int);
void drawHalfSquareReverse(int);
void drawSidewaysTriangle(int);
void drawSquares(int);

int main()
{
    drawHalfSquareReverse(5);
    drawSidewaysTriangle(4);
}

/**
 * Prints the determined amount of hash characters in the <b>cout</b> before the
 * new line. The printing in done in the decreasing order (1 up to side).
 * @param side number of hash characters to be printed in the largest side.
 * 
 * <h4>Example - Printing 3 hash width half square</h4>
 * 
 *      drawHalfSquare(3)
 * 
 * output (cout)
 * 
 *      #
 *      ##
 *      ###
 */
void drawHalfSquare(int side)
{
    for (int i=1; i <= side; i++)
        drawSquares(i);
}

/**
 * Prints the determined amount of hash characters in the <b>cout</b> before the
 * new line. The printing in done in the decreasing order (side down to 1).
 * @param side number of hash characters to be printed in the largest row.
 * 
 * <h4>Example - Printing 3 hash width half square reversed</h4>
 * 
 *      drawHalfSquareReverse(3)
 * 
 * output (cout)
 * 
 *      ###
 *      ##
 *      #
 */
void drawHalfSquareReverse(int side)
{
    for (; side > 0; side--)
        drawSquares(side);
}

/**
 * Prints multiple lines of hash characters in the <b>cout</b>, with the initial line
 * being 1 hash wide, then it increases each line until get to the maximum width (side),
 * then shrinks down to 1 again.
 * @param number of hash characters printed in the largest row.
 * 
 * <h4>Example - Printing 3 hash width sideways triangle</h4>
 * 
 *      drawSidewaysTriangle(3)
 * 
 * output (cout)
 * 
 *      #
 *      ##
 *      ###
 *      ##
 *      #
 */
void drawSidewaysTriangle(int side)
{
    drawHalfSquare(side-1);
    drawHalfSquareReverse(side);
}

/**
 * Prints multiple lines of hash characters in the <b>cout</b>, with the initial line
 * being the largest. Then after each line, a shorter line (by one) is printend bellow.
 * @param times number of interations.
 * 
 * <h4>Example - Printing 3 hash width line</h4>
 * 
 *      drawSquares(5)
 * 
 * output (cout)
 * 
 *      #####
 */
void drawSquares(int times)
{
    for (; times > 0; times--)
        std::cout << "#";
    std::cout << "\n";
}