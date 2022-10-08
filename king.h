/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include <list>

#include "move.h"
#include "piece.h"
#include "board.h"

class TestKing;

class King : public Piece
{
public:
   friend TestKing;

   King() : Piece() {}
   King(int row, int col, bool white) : Piece(row, col, white) {}

   char getLetter() const { return 'k'; }
   void display(ogstream gout) const {}
   std::list<Move> getMoves(const Board& board) const { return std::list<Move>(); }

private:

};
