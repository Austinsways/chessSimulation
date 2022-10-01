#pragma once

#include <list>

#include "uiDraw.h"
#include "move.h"
#include "board.h"
#include "position.h"

class TestPiece;

/**************************************************
 * PIECE
 * The base class for all chess pieces
 **************************************************/
class Piece
{
public:
	friend TestPiece;

	Piece() {}
	Piece(int row, int col, bool white) {}
	void assign(Position pos) {}
	void assign(Piece* piece) {}
	bool isWhite() {}
	bool isMove() {}
	int getNMoves() {}
	Position getPosition() {}
	bool justMoved() {}
	virtual char getLetter() = 0;
	virtual void display(ogstream gout) = 0;
	virtual std::list<Move> getMoves(Board board) = 0;

protected:
	Position position;
	bool white;
	int nMoves;
	int lastMove;

};

