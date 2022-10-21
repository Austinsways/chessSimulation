/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include "uiDraw.h"
#include "move.h"
#include "piece.h"
#include "board.h"

#include <list>
#include <memory>

class TestBishop;

class Bishop : public Piece
{
public:
   friend TestBishop;

   Bishop() : Piece() {}
   Bishop(int col, int row, bool white) : Piece(col, row, white) {}

   char getLetter() const { return 'p'; }
   void display(ogstream gout) const {}
   std::list<Move> getMoves(const Board& board) const;
   virtual std::unique_ptr<Piece> clone() const { return std::make_unique<Bishop>(*this); };
   void draw(ogstream& gout) const;
};
