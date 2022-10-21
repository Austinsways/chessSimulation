/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "queen.h"
#include "move.h"

#include <list>

using namespace std;

list<Move> Queen::getMoves(const Board& board) const
{
   list<Move> moves;
   Delta deltas[8]{ {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };
   for (auto& delta : deltas)
   {
      auto slideMoves = getSlideMoves(board, delta);
      moves.splice(moves.end(), slideMoves);
   }
   return moves;
}

void Queen::draw(ogstream& gout) const {
   gout.drawQueen(position.getLocation(), !white);
}


