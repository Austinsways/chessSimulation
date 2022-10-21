/**************************************************
 * Authors:
 *    Austin Eldredge
 *    Lehi Lopez
 *    Eddie McConkie
 **************************************************/
#pragma once

#include "uiInteract.h"
#include "board.h"

enum Winner
{
   WHITE,
   BLACK,
   NONE
};

/**************************************************
 * GAME
 * Contains the logic to run the Chess game
 **************************************************/
class Game
{
public:
   Game()
   {
      whiteTurn = true;
      board.reset();
      winner = NONE;
   }
   void advance(Interface* pUI);
   void draw(Interface* pUI);
   bool getWhiteTurn() { return whiteTurn; };

private:
   bool whiteTurn;
   Board board;
   Winner winner;
};
