/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "king.h"
#include "move.h"

#include <list>

using namespace std;

/**************************************************
 * KING :: GET MOVES
 * Get all possible moves for the King
 **************************************************/
list<Move> King::getMoves(const Board& board) const
{
   list<Move> moves;
   int lastRow = white ? 7 : 0;

   // Normal forward and backwards move
   Position oneAhead(position);
   oneAhead.adjustRow(white ? 1 : -1);
   if (oneAhead.isValid() && board.get(oneAhead).getLetter() == ' ')
   {
      Move move(position, oneAhead, white);
      moves.push_back(Move(position, oneAhead, white));
   }

   Position oneBack(position);
   oneBack.adjustRow(white ? -1 : 1);
   if (oneBack.isValid() && board.get(oneBack).getLetter() == ' ')
   {
      Move move(position, oneBack, white);
      moves.push_back(Move(position, oneBack, white));
   }

   //normal sideways moves
   Position sideRight(position);
   sideRight.adjustCol(white ? 1 : -1);
   if (sideRight.isValid() && board.get(sideRight).getLetter() == ' ')
   {
      Move move(position, sideRight, white);
      moves.push_back(Move(position, sideRight, white));
   }
   Position sideLeft(position);
   sideLeft.adjustCol(white ? -1 : 1);
   if (sideLeft.isValid() && board.get(sideLeft).getLetter() == ' ')
   {
      Move move(position, sideLeft, white);
      moves.push_back(Move(position, sideLeft, white));
   }

   //diagonal moves
   Position sideRightUp(position);
   sideRightUp.adjustCol(white ? 1 : -1);
   sideRightUp.adjustRow(white ? 1 : -1);

   if (sideRightUp.isValid() && board.get(sideRightUp).getLetter() == ' ')
   {
      Move move(position, sideRightUp, white);
      moves.push_back(Move(position, sideRightUp, white));
   }

   Position sideLeftUp(position);
   sideLeftUp.adjustCol(white ? 1 : -1);
   sideLeftUp.adjustRow(white ? -1 : 1);

   if (sideLeftUp.isValid() && board.get(sideLeftUp).getLetter() == ' ')
   {
      Move move(position, sideLeftUp, white);
      moves.push_back(Move(position, sideLeftUp, white));
   }

   Position sideRightDown(position);
   sideRightDown.adjustCol(white ? -1 : 1);
   sideRightDown.adjustRow(white ? 1 : -1);

   if (sideRightDown.isValid() && board.get(sideRightDown).getLetter() == ' ')
   {
      Move move(position, sideRightDown, white);
      moves.push_back(Move(position, sideRightDown, white));
   }

   Position sideLeftDown(position);
   sideLeftDown.adjustCol(white ? -1 : 1);
   sideLeftDown.adjustRow(white ? -1 : 1);

   if (sideLeftDown.isValid() && board.get(sideLeftDown).getLetter() == ' ')
   {
      Move move(position, sideLeftDown, white);
      moves.push_back(Move(position, sideLeftDown, white));
   }

   // captures

   Position diagonals[8]{ sideRightUp,sideLeftUp, sideLeftDown, sideRightDown, sideRight, sideLeft, oneAhead, oneBack };
   for (const auto& diagonal : diagonals)
   {
      if (diagonal.isValid())
      {
         const Piece& opponent = board.get(diagonal);
         if (opponent.getLetter() != ' ' && opponent.isWhite() != white)
         {
            Move move(position, diagonal, white);
            move.setCapture(opponent.getLetter());
            moves.push_back(move);
         }
      }
   }

   //castle
   if (nMoves == 0)
   {
      // king side
      bool canCastle = true;
      Position checkPos(position);
      checkPos.adjustCol(1);
      while (checkPos.getCol() < 7)
      {
         if (board.get(checkPos) != ' ')
            canCastle = false;
         checkPos.adjustCol(1);
      }
      const Piece& rook = board.get(checkPos);
      if (canCastle
         && rook == 'r'
         && rook.getNMoves() == 0
         && white == rook.isWhite()
         )
      {
         Position dest(position);
         dest.adjustCol(2);
         Move move(position, dest, white);
         move.setCastleK(true);
         moves.push_back(move);
      }
   }

   if (nMoves == 0)
   {
      // queen side
      bool canCastle = true;
      Position checkPos(position);
      checkPos.adjustCol(-1);
      while (checkPos.getCol() > 0)
      {
         if (board.get(checkPos) != ' ')
            canCastle = false;
         checkPos.adjustCol(-1);
      }
      const Piece& rook = board.get(checkPos);
      if (canCastle
         && rook == 'r'
         && rook.getNMoves() == 0
         && white == rook.isWhite()
         )
      {
         Position dest(position);
         dest.adjustCol(-2);
         Move move(position, dest, white);
         move.setCastleQ(true);
         moves.push_back(move);
      }

   }

   return moves;
}

/**************************************************
 * KING :: DRAW
 **************************************************/
void King::draw(ogstream& gout) const
{
   gout.drawKing(position.getLocation(), !white);
}
