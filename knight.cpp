#include "knight.h"
#include "move.h"
#include <list>


list<Move> Knight::getMoves(const Board& board) const {
    list<Move> moves;
    Delta deltas[8]{ {2,1}, {2,-1}, {1,2}, {1,-2}, {-2,1}, {-2,-1}, {-1, 2}, {-1,-2} };
    for (auto& delta : deltas)
    {
        //since the knight can jump over any piece it wishes, we do not use slide positioning. 
        Position possiblePosition(position);
        possiblePosition.adjustCol(delta.col);
        possiblePosition.adjustRow(delta.row);
        bool blocked = false; 
        checkPossibleMove(blocked, moves, possiblePosition, board); 
        
    }
    return moves;
}