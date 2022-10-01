#pragma once

#include "king.h"
#include "board.h"

class TestKing
{
public:
   void run()
   {
      getMoves__free();
   }

private:
   void getMoves__free()
   {
      // setup
      Board board;
      King king;


      // exercise
      auto moves = king.getMoves(board);

      // verify

   }  // cleanup
};
