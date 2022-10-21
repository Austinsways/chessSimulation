#include "bishop.h"
#include "move.h"
#include <list>


std::list<Move> Bishop::getMoves(const Board& board) const {
    std::list<Move> moves;
    Delta deltas[4]{ {1,1}, {1,-1}, {-1,-1}, {-1,1} };
    for (auto& delta : deltas)
    {
        auto slideMoves = getSlideMoves(board, delta);
        moves.splice(moves.end(), slideMoves);
    }
    return moves;
}

void Bishop::draw(ogstream& gout) const {
   gout.drawBishop(position.getLocation(), !white);
}