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
#include "position.h"
#include "move.h"
#include "uiInteract.h"

class TestBoard;
enum Winner;

/**************************************************
 * BOARD
 * The chess board
 **************************************************/
class Board
{
public:
   friend TestBoard;

   Board() : currentMove(0) { reset(); }
   int getCurrentMove() const { return currentMove; }
   bool whiteTurn() const { return currentMove % 2 == 1; }
   void display(const Position& hover, const Position& selected) const {}
   const Piece& get(const Position& pos) const;
   void reset();
   void clear();
   void move(const Move& move);
   void setCurrentMove(int currentMove) { this->currentMove = currentMove; }
   void assign(const Piece& piece) { board[piece.getPosition().getLocation()] = piece.clone(); }
   void draw(Interface* pUI, Winner winner) const;

private:
   std::array<std::unique_ptr<Piece>, 64> board;
   int currentMove;
   void moveTo(Position pos1, Position pos2);
};
