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


class Space : public Piece
{
public:

	Space() : Piece() {}
	Space(int col, int row, bool white) : Piece(col, row, white) {}

	char getLetter() const { return ' '; }
	void display(ogstream gout) const {}
	std::list<Move> getMoves(const Board& board) const { return std::list<Move>() ; };
	virtual std::unique_ptr<Piece> clone() const { return std::make_unique<Space>(*this); };
	virtual void draw(ogstream& gout) const {}
};
