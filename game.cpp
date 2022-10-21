/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/

#include <set>

#include "uiInteract.h"
#include "game.h"
#include "move.h"

using namespace std;

void Game::advance(Interface* pUI)
{
   if (winner != NONE) return;

   int prevPos = pUI->getPreviousPosition();
   int selectPos = pUI->getSelectPosition();
   if (prevPos >= 0 && prevPos < 64)
   {
      const Piece& previousPiece = board.get(prevPos);
      auto possibleMoves = previousPiece.getMoves(board);
      for (const auto& move : possibleMoves)
      {
         if (move.getDest() == Position(selectPos))
         {
            // If the king is captured, declare the winner
            const Piece& capture = board.get(selectPos);
            if (capture == 'k')
               winner = capture.isWhite() ? BLACK : WHITE;

            board.move(move);
            whiteTurn = !whiteTurn;
            pUI->clearSelectPosition();
            return;
         }
      }
   }

   if (selectPos >= 0 && selectPos < 64)
   {
      const Piece& selectedPiece = board.get(selectPos);
      if (selectedPiece == ' ' || selectedPiece.isWhite() != whiteTurn)
      {
         pUI->clearSelectPosition();
      }
   }


};

void Game::draw(Interface* pUI)
{
   board.draw(pUI, winner);
};

