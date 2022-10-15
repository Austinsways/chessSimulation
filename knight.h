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

class TestKnight;

class Knight : public Piece
{
public:
   friend TestKnight;

   Knight() : Piece() {}
   Knight(int col, int row, bool white) : Piece(col, row, white) {}

   char getLetter() const { return 'n'; }
   void display(ogstream gout) const {}
   std::list<Move> getMoves(const Board& board) const { return std::list<Move>(); }
   virtual std::unique_ptr<Piece> clone() const { return std::make_unique<Knight>(*this); };
   virtual void draw(ogstream& gout) const;
private:
	void checkPossibleMove(bool& blocked, std::list<Move>& moves, Position possiblePosition, const Board& board) const {
		//since the knight can capture, the space can be empty or an enemy piece. 
		if (possiblePosition.isValid() && (board.get(possiblePosition).getLetter() == ' ' || board.get(possiblePosition).isWhite() ? false : true))
		{
			Move move(position, possiblePosition, white);
			moves.push_back(Move(position, possiblePosition, white));
		}
		else {
			blocked = true;
		};
	};
};
