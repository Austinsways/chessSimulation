/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#include "piece.h"

using namespace::std;
class TestKing;

class Rook : public Piece
{
public:
   friend TestKing;

   Rook() : Piece() {}
   Rook(int row, int col, bool white) : Piece(row, col, white) {}

   char getLetter() const { return 'r'; }
   void display(ogstream gout) const {}
   std::list<Move> getMoves(const Board& board) const { return std::list<Move>(); }

};