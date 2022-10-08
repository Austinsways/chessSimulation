/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once


/**************************************************
 * POSITION
 * A position on the chess board
 **************************************************/
class Position
{
public:
   int row;
   int col;

   Position() {}
   Position(int row, int col) {}

   bool operator==(const Position& rhs) { return false; }

private:

};

