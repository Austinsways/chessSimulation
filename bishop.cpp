#include "bishop.h"
#include "move.h"
#include <list>


list<Move> Bishop::getMoves(const Board& board) const {
    list<Move> moves;
    Delta deltas[4]{ {1,1}, {1,-1}, {-1,-1}, {-1,1} };
    for (auto& delta : deltas)
    {
        auto slideMoves = getSlideMoves(board, delta);
        moves.splice(moves.end(), slideMoves);
        //moves.merge(slideMoves);
    }
    return moves;
}