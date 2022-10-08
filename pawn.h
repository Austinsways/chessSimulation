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

class TestPawn;

class Pawn : public Piece
{
public:
   friend TestPawn;

   Pawn() : Piece() {}
   Pawn(int row, int col, bool white) : Piece(row, col, white) {}

   char getLetter() const { return 'p'; }
   void display(ogstream gout) const {}
   std::list<Move> getMoves(const Board& board) const;
};
