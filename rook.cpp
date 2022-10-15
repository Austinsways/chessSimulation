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

void Rook::draw() const {
    Rect rectangles[] =
    {
       {-8,7,  -8,4,  -4,4,  -4,7},   // left battlement
       { 8,7,   8,4,   4,4,   4,7},   // right battlement
       { 2,7,   2,4,  -2,4,  -2,7},   // center battlement
       { 4,3,   4,-5, -4,-5, -4,3},   // wall
       { 6,-6, -6,-6, -6,-8,  6,-8}   // base
    };

    drawPiece(xFromPosition(position.getLocation()), yFromPosition(position.getLocation()), white, rectangles, 5);
}