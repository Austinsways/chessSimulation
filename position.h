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
   Position() : location(0), squareWidth(50), squareHeight(50) {}
   Position(int col, int row) : squareWidth(50), squareHeight(50)
   {
      set(col, row);
   }
   int getLocation() const { return location; }
   int getRow() const { return (int)location / 8; }
   int getCol() const { return (int)location % 8; }
   int getX() const { return getCol() * squareWidth; }
   int getY() const { return getRow() * squareHeight; }
   bool isValid() const { return 0 <= location && location < 64; }
   void setRow(int row) { set(getCol(), row); }
   void setCol(int col) { set(col, getRow()); }
   void set(int col, int row);
   void adjustRow(int delta) { set(getCol(), getRow() + delta); }
   void adjustCol(int delta) { set(getCol() + delta, getRow()); }
   bool operator==(const Position& rhs) { return location == rhs.getLocation(); }

private:
   char location;
   double squareWidth;
   double squareHeight;
};

