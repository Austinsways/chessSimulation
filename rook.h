#include "piece.h"

using namespace::std;
class TestKing;

class Rook : public Piece{
public:
    friend TestKing;

    Rook() : Piece() {}
    Rook(int row, int col, bool white) : Piece(row, col, white) {}

    char getLetter() { return 'P'; }
   void display(ogstream gout) {}
   std::list<Move> getMoves(Board board) { return std::list<Move>(); }

};