#include "rook.h"
#include "move.h"
#include <list>


list<Move> Rook::getMoves(const Board& board) const {
    list<Move> moves;
    Delta deltas[4]{ {0,1}, {1,0}, {0,-1}, {-1,0} };
    for (auto& delta : deltas)
    {
        auto slideMoves = getSlideMoves(board, delta);
        moves.splice(moves.end(), slideMoves);
        //moves.merge(slideMoves);
    }
    return moves;
}

void Rook::draw(ogstream& gout) const {
   gout.drawRook(position.getLocation(), !white);
}