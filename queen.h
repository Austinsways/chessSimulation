#pragma once
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

class TestQueen;

class Queen : public Piece
{
public:
	friend TestQueen;

	Queen() : Piece() {}
	Queen(int row, int col, bool white) : Piece(row, col, white) {}

	char getLetter() const { return 'q'; }
	void display(ogstream gout) const {}
	std::list<Move> getMoves(const Board& board);
	virtual std::unique_ptr<Piece> clone() const { return std::make_unique<Queen>(*this); };



private:
	void checkPossibleMove(bool& blocked, list<Move>& moves, Position possiblePosition, const Board &board) {
		if (possiblePosition.isValid() && board.get(possiblePosition).getLetter() == ' ')
		{
			Move move(position, possiblePosition, white);
			moves.push_back(Move(position, possiblePosition, white));
		}
		else {
			blocked = true;
		};
	};
};
