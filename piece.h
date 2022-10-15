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
	void incrementNMoves() { nMoves++; }
	Position getPosition() const { return position; }
	void setPosition(Position position) { this->position = position; }
	bool justMoved(const Board& board) const;
	virtual char getLetter() const = 0;
	virtual void display(ogstream gout) const = 0;
	virtual std::list<Move> getMoves(const Board& board) const = 0;
	virtual std::unique_ptr<Piece> clone() const = 0;
	virtual void draw() const = 0;

protected:
	Position position;
	bool white;
	int nMoves;
	int lastMove;
	std::list<Move> getSlideMoves(const Board& board, const Delta& delta) const;
	
	void glColor(const int* rgb) const;
	struct Rect
	{
		int x0;
		int y0;
		int x1;
		int y1;
		int x2;
		int y2;
		int x3;
		int y3;
	};
	void drawPiece(int x, int y, bool black, Rect rectangle[], int num) const;
	int xFromPosition(int position) const
	{
		return (int)((double)(position % 8) * 32.0);
	}
	int yFromPosition(int position) const
	{
		return (int)((double)(position / 8) * 32.0);
	}
};
	

bool operator==(const Piece& lhs, char rhs);
bool operator!=(const Piece& lhs, char rhs);
