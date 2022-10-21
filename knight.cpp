/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "knight.h"
#include "move.h"
#include <list>

using namespace std;

/**************************************************
 * KNIGHT :: GET MOVES
 * Get all possible moves for the Knight
 **************************************************/
list<Move> Knight::getMoves(const Board& board) const
{
   list<Move> moves;
   Delta deltas[8]{ {2,1}, {2,-1}, {1,2}, {1,-2}, {-2,1}, {-2,-1}, {-1, 2}, {-1,-2} };
   for (auto& delta : deltas)
   {
      Position possiblePosition(position);
      possiblePosition.adjustCol(delta.col);
      possiblePosition.adjustRow(delta.row);
      if (possiblePosition.isValid()
         && (board.get(possiblePosition).getLetter() == ' '
            || board.get(possiblePosition).isWhite() != this->isWhite())
         )
      {
         Move move(position, possiblePosition, white);
         if (board.get(possiblePosition).getLetter() != ' ')
         {
            move.setCapture(board.get(possiblePosition).getLetter());
         }
         moves.push_back(move);
      }
   }
   return moves;
}

/**************************************************
 * KNIGHT :: DRAW
 **************************************************/
void Knight::draw(ogstream& gout) const
{
   gout.drawKnight(position.getLocation(), !white);
}
