#pragma once
#include "move.h"
#include "piece.h"
#include "board.h"

#include <list>


class Space : public Piece
{
public:

	Space() : Piece() {}
	Space(int row, int col, bool white) : Piece(row, col, white) {}

	char getLetter() const { return ' '; }
	void display(ogstream gout) const {}
	std::list<Move> getMoves(const Board& board) const { return std::list<Move>() ; };
	virtual std::unique_ptr<Piece> clone() const { return std::make_unique<Space>(*this); };
};
