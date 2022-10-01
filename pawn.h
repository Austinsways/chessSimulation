#pragma once

#include <list>

#include "move.h"
#include "piece.h"
#include "board.h"

class TestPawn;

class Pawn : public Piece
{
public:
	friend TestPawn;

	Pawn() : Piece() {}
	Pawn(int row, int col, bool white) : Piece(row, col, white) {}

	char getLetter() { return 'P'; }
	void display(ogstream gout) {}
	std::list<Move> getMoves(Board board) { return std::list<Move>(); }

private:

};
