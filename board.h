/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include <memory>
#include <array>

#include "uiDraw.h"
#include "piece.h"
#include "pawn.h"
#include "position.h"
#include "move.h"

class TestBoard;

/**************************************************
 * BOARD
 * The chess board
 **************************************************/
class Board
{
public:
   friend TestBoard;

   Board();
   int getCurrentMove() const { return currentMove; }
   bool whiteTurn() const { return currentMove % 2 == 1; }
   void display(const Position& hover, const Position& selected) const {}
   const Piece& get(const Position& pos) const;
   void reset() {}
   void move(const Move& move) {}
   void assign(const Piece& piece);

private:
   std::array<std::unique_ptr<Piece>, 64> board;
   int currentMove;
   void swap(Position pos1, Position pos2) {}
};

