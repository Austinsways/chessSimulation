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

   char getLetter() { return 'K'; }
   void display(ogstream gout) {}
   std::list<Move> getMoves(Board board) { return std::list<Move>(); }

private:

};
