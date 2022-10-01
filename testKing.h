#pragma once

#include "king.h"
#include "board.h"

class TestKing
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
      King king;


      // exercise
      auto moves = king.getMoves(board);

      // verify

   }  // cleanup
};
