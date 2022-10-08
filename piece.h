/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include <list>

#include "uiDraw.h"
#include "move.h"
//#include "board.h"
#include "position.h"

class Board;
class TestPiece;

/**************************************************
 * PIECE
 * The base class for all chess pieces
 **************************************************/
class Piece
{
public:
	friend TestPiece;

	Piece() : nMoves(0), lastMove(-1) {}
	Piece(int row, int col, bool white) : nMoves(0), lastMove(-1) {}
	void assign(Position pos) {}
	void assign(Piece& piece) {}
	bool isWhite() const { return white; }
	bool isMove() const {}
	int getNMoves() const { return nMoves; }
	Position getPosition() const { return position; }
	bool justMoved(const Board& board) const;
	virtual char getLetter() const = 0;
	virtual void display(ogstream gout) const = 0;
	virtual std::list<Move> getMoves(const Board& board) const = 0;

protected:
	Position position;
	bool white;
	int nMoves;
	int lastMove;

};

