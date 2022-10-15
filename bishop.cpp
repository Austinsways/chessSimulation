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
        //moves.merge(slideMoves);
    }
    return moves;
}

void Bishop::draw() const {
    Rect rectangles[] =
    {
       {-1,8,  -1,2,   1,2,   1,8 },   // center of head
       { 1,8,   1,2,   5,2,   5,5 },   // right part of head
       {-4,5,  -4,2,  -2,2,  -2, 6},   // left of head
       {-5,3,  -5,2,   5,2,   5,3 },   // base of head
       {-2,2,  -4,-5,  4,-5,  2,2 },   // neck
       { 6,-6, -6,-6, -6,-8,  6,-8}    // base
    };

    drawPiece(xFromPosition(position.getLocation()), yFromPosition(position.getLocation()), white, rectangles, 6);
}