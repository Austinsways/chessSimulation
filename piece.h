/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include <list>
#include <memory>

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

	Piece() : white(true), nMoves(0), lastMove(-1), position(Position()) {}
	Piece(int col, int row, bool white) : white(white), nMoves(0), lastMove(-1), position(Position(col, row)) {}
	void assign(const Position& pos) {}
	void assign(const Piece& piece) {}
	bool isWhite() const { return white; }
	bool isMove() const {}
	int getNMoves() const { return nMoves; }
	Position getPosition() const { return position; }
	bool justMoved(const Board& board) const;
	virtual char getLetter() const = 0;
	virtual void display(ogstream gout) const = 0;
	virtual std::list<Move> getMoves(const Board& board) const = 0;
	virtual std::unique_ptr<Piece> clone() const = 0;

protected:
	Position position;
	bool white;
	int nMoves;
	int lastMove;
	std::list<Move> getSlideMoves(const Board& board, const Delta& delta) const;
};

bool operator==(const Piece& lhs, char rhs);
bool operator!=(const Piece& lhs, char rhs);
