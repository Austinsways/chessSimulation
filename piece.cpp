/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "piece.h"
#include "board.h"

using namespace std;

/**************************************************
 * PIECE :: JUST MOVED
 * Determine if a piece moved during the last turn
 **************************************************/
bool Piece::justMoved(const Board& board) const {
   return board.getCurrentMove() - lastMove == 1;
}

bool operator==(const Piece& lhs, char rhs)
{
   return lhs.getLetter() == rhs;
}

bool operator!=(const Piece& lhs, char rhs)
{
   return !(lhs == rhs);
}