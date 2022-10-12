/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include "move.h"
#include "piece.h"
#include "board.h"

#include <list>
#include <memory>

class TestPawn;

class Pawn : public Piece
{
public:
   friend TestPawn;

   Pawn() : Piece() {}
   Pawn(int col, int row, bool white) : Piece(col, row, white) {}

   char getLetter() const { return 'p'; }
   void display(ogstream gout) const {}
   std::list<Move> getMoves(const Board& board) const;
   virtual std::unique_ptr<Piece> clone() const { return std::make_unique<Pawn>(*this); };
};
