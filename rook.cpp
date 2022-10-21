/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "rook.h"
#include "move.h"

#include <list>

using namespace std;

/**************************************************
 * ROOK :: GET MOVES
 * Get all possible moves for the Rook
 **************************************************/
list<Move> Rook::getMoves(const Board& board) const
{
   list<Move> moves;
   Delta deltas[4]{ {0,1}, {1,0}, {0,-1}, {-1,0} };
   for (auto& delta : deltas)
   {
      auto slideMoves = getSlideMoves(board, delta);
      moves.splice(moves.end(), slideMoves);
   }
   return moves;
}

/**************************************************
 * ROOK :: DRAW
 **************************************************/
void Rook::draw(ogstream& gout) const
{
   gout.drawRook(position.getLocation(), !white);
}