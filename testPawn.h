#pragma once

#include "pawn.h"
#include "board.h"

class TestPawn
{
public:
   void run()
   {
      getMoves__blocked();
   }

private:
   void getMoves__blocked()
   {
      // setup
      Board board;
      Pawn pawn;


      // exercise
      auto moves = pawn.getMoves(board);

      // verify

   }  // cleanup
};
