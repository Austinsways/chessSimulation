/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

struct Delta
{
   int col;
   int row;
};

/**************************************************
 * POSITION
 * A position on the chess board
 **************************************************/
class Position
{
public:
   Position() : location(0) {}
   Position(int col, int row) { set(col, row); }
   Position(int location) { this->location = location; }
   int getLocation() const { return location; }
   int getRow() const { return (int)location / 8; }
   int getCol() const { return (int)location % 8; }
   bool isValid() const { return 0 <= location && location < 64; }
   void setRow(int row) { set(getCol(), row); }
   void setCol(int col) { set(col, getRow()); }
   void set(int col, int row);
   void adjustRow(int delta) { set(getCol(), getRow() + delta); }
   void adjustCol(int delta) { set(getCol() + delta, getRow()); }
   bool operator==(const Position& rhs) { return location == rhs.getLocation(); }
   Position operator+(const Delta& rhs);
   Position& operator+=(const Delta& rhs);

private:
   char location;
};

