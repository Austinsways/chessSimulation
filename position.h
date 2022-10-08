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
   Position(int row, int col) : squareWidth(50), squareHeight(50)
   {
      set(row, col);
   }
   int getLocation() const { return location; }
   int getRow() const { return (int)location / 8; }
   int getCol() const { return (int)location % 8; }
   int getX() const { return getCol() * squareWidth; }
   int getY() const { return getRow() * squareHeight; }
   bool isValid() const { return 0 <= location && location < 64; }
   void setRow(int row) { set(row, getCol()); }
   void setCol(int col) { set(getRow(), col); }
   void set(int row, int col);
   void adjustRow(int delta) { set(getRow() + delta, getCol()); }
   void adjustCol(int delta) { set(getRow(), getCol() + delta); }
   bool operator==(const Position& rhs) { return location == rhs.getLocation(); }

private:
   char location;
   double squareWidth;
   double squareHeight;
};

