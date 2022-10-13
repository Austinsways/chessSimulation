/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "position.h"

 /**************************************************
  * POSITION :: SET
  * Set the position with a row and column
  **************************************************/
void Position::set(int col, int row)
{
   if (row < 0 || row > 7 || col < 0 || col > 7)
      location = -1;
   else
      location = col + row * 8;
}

Position Position::operator+(const Delta& rhs)
{
   Position newPos(*this);
   newPos.adjustCol(rhs.col);
   newPos.adjustRow(rhs.row);
   return newPos;
}

Position& Position::operator+=(const Delta& rhs)
{
   adjustCol(rhs.col);
   adjustRow(rhs.row);
   return *this;
}