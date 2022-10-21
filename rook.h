/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include <list>

#include "uiDraw.h"
#include "move.h"
#include "piece.h"
#include "board.h"

using namespace::std;
class TestKing;
class TestRook;

class Rook : public Piece
{
public:
   friend TestKing;

   Rook() : Piece() {}
   Rook(int col, int row, bool white) : Piece(col, row, white) {}

   char getLetter() const { return 'r'; }
   void display(ogstream gout) const {}
   std::list<Move> getMoves(const Board& board) const;
   virtual std::unique_ptr<Piece> clone() const { return std::make_unique<Rook>(*this); };
   void draw(ogstream& gout) const;
};