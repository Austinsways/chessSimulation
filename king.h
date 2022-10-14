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
   King(int col, int row, bool white) : Piece(col, row, white) {}

   char getLetter() const { return 'k'; }
   void display(ogstream gout) const {}
   std::list<Move> getMoves(const Board& board) const;
   virtual std::unique_ptr<Piece> clone() const { return std::make_unique<King>(*this); };
};
