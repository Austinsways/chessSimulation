/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include "pawn.h"
#include "move.h"
#include "board.h"

#include <list>

using namespace std;

/**************************************************
 * PAWN :: GET MOVES
 * Get all possible moves for the Pawn
 **************************************************/
list<Move> Pawn::getMoves(const Board& board) const
{
   list<Move> moves;
   int lastRow = white ? 7 : 0;

   // Normal move
   Position oneAhead(position);
   oneAhead.adjustRow(white ? 1 : -1);
   if (oneAhead.isValid() && board.get(oneAhead).getLetter() == ' ')
   {
      Move move(position, oneAhead, white);
      if (oneAhead.getRow() == lastRow)
         move.setPromotion('Q');
      moves.push_back(move);
   }

   // Move two spaces
   if (nMoves == 0)
   {
      Position twoAhead(position);
      twoAhead.adjustRow(white ? 2 : -2);
      if (twoAhead.isValid()
         && board.get(oneAhead).getLetter() == ' '
         && board.get(twoAhead).getLetter() == ' '
         )
         moves.push_back(Move(position, twoAhead, white));
   }

   // Diagonal capture
   Position diagonalLeft(oneAhead);
   diagonalLeft.adjustCol(-1);
   Position diagonalRight(oneAhead);
   diagonalRight.adjustCol(1);

   Position diagonals[2]{ diagonalLeft,diagonalRight };
   for (const auto& diagonal : diagonals)
   {
      if (diagonal.isValid())
      {
         const Piece& opponent = board.get(diagonal);
         if (opponent.getLetter() != ' ' && opponent.isWhite() != white)
         {
            Move move(position, diagonal, white);
            move.setCapture(opponent.getLetter());

            // Capture w/ promotion
            if (diagonal.getRow() == lastRow)
               move.setPromotion('Q');
            moves.push_back(move);
         }
      }
   }

   // En Passant
   struct EnPassant
   {
      Position pawnPos;
      Position attackPos;
   };

   int enpassantRow = white ? 4 : 3;
   if (position.getRow() == enpassantRow)
   {
      Position left(position);
      left.adjustCol(-1);
      Position right(position);
      right.adjustCol(1);
      EnPassant sides[2];
      sides[0].pawnPos = left;
      sides[0].attackPos = diagonalLeft;
      sides[1].pawnPos = right;
      sides[1].attackPos = diagonalRight;
      for (const auto& side : sides)
      {
         if (side.pawnPos.isValid())
         {
            const Piece& opponent = board.get(side.pawnPos);
            if (opponent.getLetter() == 'p'
               && opponent.isWhite() != white
               && opponent.justMoved(board)
               )
            {
               Move move(position, side.attackPos, white);
               move.setEnPassant(true);
               moves.push_back(move);
            }
         }
      }
   }
   
   return moves;
}

void Pawn::draw() const {
    Rect rectangles[] =
    {
       { 1,7,  -1,7,  -2,5,  2,5 }, // top of head
       { 3,5,  -3,5,  -3,3,  3,3 }, // bottom of head
       { 1,3,  -1,3,  -2,-3, 2,-3}, // neck
       { 4,-3, -4,-3, -4,-5, 4,-5}  // base
    };

    drawPiece(xFromPosition(position.getLocation()), yFromPosition(position.getLocation()), white, rectangles, 4);
}